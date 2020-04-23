#include "AstarItem.h"
#include <QBrush>
#include <QPainter>
#include <QDebug>

const QColor AstarItem::mColors[6]
{
    Qt::white, Qt::black, Qt::blue,Qt::cyan ,Qt::green, Qt::red
};

AstarItem::AstarItem(QRectF rect, QPoint pos)
    : mState(WAY), mPosition(pos), mRect(rect)
{

}


void AstarItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    auto rect = boundingRect();
    QBrush brush(Qt::white);
    brush.setColor(mColors[mState]);
    painter->fillRect(rect, brush);
    painter->drawRect(rect);
}

QPoint AstarItem::GetPosition()
{
    return mPosition;
}

AstarItem::eState AstarItem::GetState()
{
    return mState;
}

void AstarItem::SetState(AstarItem::eState state)
{
    mState = state;
    update();
}

void AstarItem::SetRect(QRect rect)
{
    mRect = rect;
    update();
}

QRectF AstarItem::boundingRect() const
{
    return mRect;
}
