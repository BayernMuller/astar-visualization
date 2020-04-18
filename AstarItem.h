#ifndef ASTARITEM_H
#define ASTARITEM_H
#include <QGraphicsItem>
class PlayGround;

class AstarItem : public QGraphicsItem
{
    friend PlayGround;
public:
    AstarItem(QRectF rect);
    bool IsSelected();

public: // overrides
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

private:
    void SetSelected(bool enable);

private:
    QRectF mRect;
    bool mIsClicked;
};

#endif // ASTARITEM_H
