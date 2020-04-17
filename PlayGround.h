#ifndef PLAYGROUND_H
#define PLAYGROUND_H

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>

class PlayGround : public QGraphicsView
{
    Q_OBJECT

public:
    PlayGround(QWidget* parent = nullptr);

public slots:
    void mousePressEvent(QMouseEvent *event);
    void OnBoardResize(int size);
    void OnBlockResize(int size);
    void OnClear();
    void OnStart();
    void OnPause();

private:
    void draw();

private:
    QGraphicsScene mScene;
    int mBlockSize;
    int mBoardSize;
};

#endif // PLAYGROUND_H
