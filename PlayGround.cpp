#include "PlayGround.h"
#include <QGraphicsItem>
#include <QDebug>

PlayGround::PlayGround(QWidget* parent)
    : QGraphicsView(parent), mScene(parent)
    , mBoardSize(5), mBlockSize(10), mIsPlaying(false)
    , mpStartItem(nullptr), mpEndItem(nullptr)
{
    QGraphicsView::setMouseTracking(true);
    setScene(&mScene);
    draw();
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

}

void PlayGround::OnPause()
{

}

void PlayGround::OnStart()
{

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


void PlayGround::resizeEvent(QResizeEvent* event)
{
}
