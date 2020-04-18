#ifndef ASTARITEM_H
#define ASTARITEM_H
#include <QGraphicsItem>

class AstarItem : public QGraphicsItem
{
public:
    AstarItem(QRectF rect);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

private:
    QRectF mRect;
    bool mIsClicked;
};

#endif // ASTARITEM_H
