#include "PlayGround.h"
#include <QGraphicsItem>
#include <QDebug>

PlayGround::PlayGround(QWidget* parent)
    : QGraphicsView(parent), mScene(parent)
    , mBoardSize(5), mBlockSize(10)
{
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
            auto item = mScene.addRect(pivot.x() + i * side, pivot.y() + j * side, side, side);
        }
    }
}

void PlayGround::mousePressEvent(QMouseEvent *event)
{

}

void PlayGround::resizeEvent(QResizeEvent* event)
{


}
