#include "PlayGround.h"
#include <QDebug>

PlayGround::PlayGround(QWidget* parent)
    : QGraphicsView(parent)
{

}

void PlayGround::mousePressEvent(QMouseEvent *event)
{
    qDebug() << event->pos();
}
