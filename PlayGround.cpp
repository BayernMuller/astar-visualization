#include "PlayGround.h"
#include <QGraphicsItem>
#include <QDebug>
#include <chrono>

PlayGround::PlayGround(QWidget* parent)
    : QGraphicsView(parent), mScene(parent)
    , mBoardSize(5), mBlockSize(10), mIsPlaying(false)
    , mpStartItem(nullptr), mpEndItem(nullptr), mpMap(nullptr)
    , mpThread(nullptr), mSpeed(5)
{
    QGraphicsView::setMouseTracking(true);
    setScene(&mScene);
    draw();
}

PlayGround::~PlayGround()
{
    if (mpThread)
    {
        mIsPlaying = false;
        mpThread->join();
        delete mpThread;
    }
    releaseMap();
}

void PlayGround::OnSpeedChange(int speed)
{
    mSpeed = speed;
}

void PlayGround::OnBoardResize(int size)
{
    mBoardSize = size;
    draw();
}

void PlayGround::OnBlockResize(int size)
{
    mBlockSize = size;
    draw();
}

void PlayGround::OnClear()
{
    for (auto graphicItem : items())
    {
        auto item = reinterpret_cast<AstarItem*>(graphicItem);
        item->SetState(AstarItem::eState::WAY);
    }
}

void PlayGround::OnPause()
{

}

void PlayGround::OnStart()
{
    allocateMap();
    mIsPlaying = true;
    mpThread = new std::thread(wayThread, this);
}

void PlayGround::allocateMap()
{
    releaseMap();
    mpMap = new AstarItem**[mBoardSize];
    for (int i = 0; i < mBoardSize; i++)
    {
        mpMap[i] = new AstarItem*[mBoardSize];
    }
    for (auto graphicItem : items())
    {
        auto item = reinterpret_cast<AstarItem*>(graphicItem);
        if (item->GetState() == AstarItem::eState::PATH)
            item->SetState(AstarItem::eState::WAY);
        auto pt = item->GetPosition();
        mpMap[pt.y()][pt.x()] = item;
    }
}

void PlayGround::releaseMap()
{
    if (!mpMap)
        return;
    for (int i = 0; i < mBoardSize; i++)
    {
        delete[] mpMap[i];
    }
    delete[] mpMap;
}

void PlayGround::draw()
{
    QPointF pivot = QWidget::rect().center();
    const int& side = mBlockSize;
    pivot.setX(-(mBoardSize * 0.5) * side);
    pivot.setY(-(mBoardSize * 0.5) * side);
    mScene.clear();
    mpEndItem = mpStartItem = nullptr;
    for (int i = 0; i < mBoardSize; i++)
    {
        for (int j = 0; j < mBoardSize; j++)
        {
            auto* item = new AstarItem(QRect(pivot.x() + i * side, pivot.y() + j * side, side, side), {i, j});
            mScene.addItem(item);
        }
    }
}

void PlayGround::mousePressEvent(QMouseEvent *event)
{
    if (mIsPlaying)
        return;
    auto item = reinterpret_cast<AstarItem*>(itemAt(event->pos()));
    if (!item)
        return;
    switch (event->modifiers())
    {
    case Qt::ShiftModifier:
        if (mpStartItem)
            mpStartItem->SetState(AstarItem::eState::WAY);
        item->SetState(AstarItem::eState::START);
        mpStartItem = item;
        break;
    case Qt::ControlModifier:
        if (mpEndItem)
            mpEndItem->SetState(AstarItem::eState::WAY);
        item->SetState(AstarItem::eState::END);
        mpEndItem = item;
        break;
    }
}

void PlayGround::mouseMoveEvent(QMouseEvent* event)
{
    if (mIsPlaying)
        return;
    if (event->buttons() & ~Qt::NoButton)
    {
        auto item = reinterpret_cast<AstarItem*>(itemAt(event->pos()));
        if (!item)
            return;
        if (mpStartItem == item)
        {
            mpStartItem->SetState(AstarItem::eState::WAY);
            mpStartItem = nullptr;
        }
        if (mpEndItem == item)
        {
            mpEndItem->SetState(AstarItem::eState::WAY);
            mpEndItem = nullptr;
        }
        if (event->buttons() & Qt::RightButton)
        {
            item->SetState(AstarItem::eState::WAY);
            return;
        }
        item->SetState(AstarItem::eState::WALL);
    }
}


uint PlayGround::wayThread(PlayGround *pThis)
{
    point start{pThis->mpStartItem->GetPosition().y(), pThis->mpStartItem->GetPosition().x()};
    point end{pThis->mpEndItem->GetPosition().y(), pThis->mpEndItem->GetPosition().x()};
    Astar astar(pThis->mBoardSize, pThis->mBoardSize, pThis->mpMap, start, end);
    astar.Init();
    int n = 0;
    node* path = nullptr;
    while (pThis->mIsPlaying && !astar.GetOpenList().empty())
    {
        path = astar.OneStep();
        if (path)
            break;

        for (auto n : astar.GetOpenList())
        {
            pThis->mpMap[n->pt.first][n->pt.second]->SetState(AstarItem::eState::OPENED);
        }
        for (auto n : astar.GetCloseList())
        {
            pThis->mpMap[n->pt.first][n->pt.second]->SetState(AstarItem::eState::CLOSED);
        }
        qDebug() << "step " << n++;
        std::this_thread::sleep_for(std::chrono::milliseconds(500 - pThis->mSpeed * 10));
    }
    while (path)
    {
        pThis->mpMap[path->pt.first][path->pt.second]->SetState(AstarItem::eState::PATH);
        path = path->parent;
    }
    pThis->mIsPlaying = false;
    pThis->OnEndFind();
    return 0;
}
