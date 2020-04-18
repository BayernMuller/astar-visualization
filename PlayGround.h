#ifndef PLAYGROUND_H
#define PLAYGROUND_H

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QResizeEvent>

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

private:
    void draw();

private:
    QGraphicsScene mScene;
    int mBlockSize;
    int mBoardSize;
};

#endif // PLAYGROUND_H
