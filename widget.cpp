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
    ui->sizeNum->setNum(value);
}

void Widget::on_speedSlider_valueChanged(int value)
{
    ui->speedNum->setNum(value);
}
