#ifndef PLAYGROUND_H
#define PLAYGROUND_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QResizeEvent>
#include "AstarItem.h"
#include "Astar.h"

class PlayGround : public QGraphicsView
{
    Q_OBJECT

public:
    PlayGround(QWidget* parent = nullptr);

public slots:
    void resizeEvent(QResizeEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void OnBoardResize(int size);
    void OnBlockResize(int size);
    void OnClear();
    void OnStart();
    void OnPause();

public signals:
    void OnEndFind();

private:
    void draw();
    void releaseMap();
    void allocateMap();

private:
    Astar* mpAstar;
    AstarItem* mpStartItem;
    AstarItem* mpEndItem;
    AstarItem*** mpMap;
    QGraphicsScene mScene;
    bool mIsPlaying;
    int mBlockSize;
    int mBoardSize;
    int mSpeed;
};

#endif // PLAYGROUND_H
