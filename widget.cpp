#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_sizeSlider_valueChanged(int value)
{
    QString str = QString::number(value).rightJustified(2, '0');
    ui->sizeNum->setText(str);
}

void Widget::on_speedSlider_valueChanged(int value)
{
    QString str = QString::number(value).rightJustified(2, '0');
    ui->sizeNum->setText(str);
}
