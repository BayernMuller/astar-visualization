#ifndef PLAYGROUND_H
#define PLAYGROUND_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QResizeEvent>
#include <thread>
#include "AstarItem.h"
#include "Astar.h"

class PlayGround : public QGraphicsView
{
    Q_OBJECT

public:
    PlayGround(QWidget* parent = nullptr);
    virtual ~PlayGround();

public slots:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void OnSpeedChange(int speed);
    void OnBoardResize(int size);
    void OnBlockResize(int size);
    void OnClear();
    void OnStart();
    void OnPause();

signals:
    void OnEndFind();

private:
    void draw();
    void releaseMap();
    void allocateMap();

    static uint wayThread(PlayGround* pThis);

private:
    std::thread* mpThread;
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
