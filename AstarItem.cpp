#include "AstarItem.h"

AstarItem::AstarItem(QRectF rect)
    : mRect(rect), mIsClicked(false)
{

}

void AstarItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

}

void AstarItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    mIsClicked = not mIsClicked;
    update();
    QGraphicsItem::mousePressEvent(event);
}

QRectF AstarItem::boundingRect() const
{
    return mRect;
}
