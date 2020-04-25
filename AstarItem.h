#ifndef ASTARITEM_H
#define ASTARITEM_H
#include <QGraphicsItem>
class PlayGround;

class AstarItem : public QGraphicsItem
{
    friend PlayGround;
public:
    enum eState { WAY, WALL, START, END, OPENED, CLOSED, PATH };

public:
    AstarItem(QRectF rect, QPoint pos);
    eState GetState();
    QPoint GetPosition();
    void SetState(eState state);
    void SetRect(QRect rect);

public: // overrides
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

private:
    eState mState;
    QPoint mPosition;
    QRectF mRect;

    static const QColor mColors[7];
};

#endif // ASTARITEM_H
