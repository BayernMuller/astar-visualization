#include "PlayGround.h"
#include <QGraphicsItem>

PlayGround::PlayGround(QWidget* parent)
    : QGraphicsView(parent)
    , mBoardSize(5), mBlockSize(5)
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
    QSize halfSize = this->size() / 2;
    QPointF pivot;
    pivot.setX(halfSize.width() - (mBoardSize * 0.5) * mBlockSize);
    pivot.setY(halfSize.height() - (mBoardSize * 0.5) * mBlockSize);
    mScene.clear();
    for (int i = 0; i < mBoardSize; i++)
    {
        for (int j = 0; j < mBoardSize; j++)
        {
            mScene.addRect(pivot.x() + i * mBlockSize, pivot.y() + j * mBlockSize, mBlockSize, mBlockSize);

        }
    }
}

void PlayGround::mousePressEvent(QMouseEvent *event)
{
    auto block = mScene.items(event->pos()).front();
}
