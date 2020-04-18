#include "PlayGround.h"
#include "AstarItem.h"
#include <QGraphicsItem>
#include <QDebug>

PlayGround::PlayGround(QWidget* parent)
    : QGraphicsView(parent), mScene(parent)
    , mBoardSize(5), mBlockSize(10)
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
    mScene.clearSelection();
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
    for (int i = 0; i < mBoardSize; i++)
    {
        for (int j = 0; j < mBoardSize; j++)
        {
            auto* item = new AstarItem(QRect(pivot.x() + i * side, pivot.y() + j * side, side, side));
            mScene.addItem(item);
        }
    }
}

void PlayGround::mousePressEvent(QMouseEvent *event)
{
    qDebug() << event->modifiers();
}

void PlayGround::mouseMoveEvent(QMouseEvent* event)
{
    if (event->buttons() & ~Qt::NoButton)
    {
        for (auto i : items(event->pos()))
        {
            auto item = reinterpret_cast<AstarItem*>(i);
            item->SetSelected(event->buttons() & Qt::LeftButton);
            // LeftButton = enable, OtherButton = disable
            break; // Only Use one item.
        }
    }
}


void PlayGround::resizeEvent(QResizeEvent* event)
{


}
