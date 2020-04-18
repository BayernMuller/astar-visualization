#include "AstarItem.h"
#include <QBrush>
#include <QPainter>
#include <QDebug>

AstarItem::AstarItem(QRectF rect)
    : mRect(rect), mIsClicked(false)
{

}

bool AstarItem::IsSelected()
{
    return mIsClicked;
}

void AstarItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    auto rect = boundingRect();
    QBrush brush(Qt::white);
    if (IsSelected())
    {
        brush.setColor(Qt::black);
    }
    painter->fillRect(rect, brush);
    painter->drawRect(rect);
}

void AstarItem::SetSelected(bool enable)
{
    mIsClicked = enable;
    update();
}

QRectF AstarItem::boundingRect() const
{
    return mRect;
}
