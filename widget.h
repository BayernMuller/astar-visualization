#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_boardSlider_valueChanged(int value);
    void on_blockSlider_valueChanged(int value);
    void on_speedSlider_valueChanged(int value);
    void on_startButton_clicked();
    void OnEndFind();
private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
