#ifndef PLAYGROUND_H
#define PLAYGROUND_H

#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>

class PlayGround : public QGraphicsView
{
public:
    PlayGround(QWidget* parent);

public slots:
    void mousePressEvent(QMouseEvent *event);
};

#endif // PLAYGROUND_H
