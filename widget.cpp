#include "widget.h"
#include "ui_widget.h"
#include "PlayGround.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->boardSlider, SIGNAL(valueChanged(int)), ui->graphicsView, SLOT(OnBoardResize(int)));
    connect(ui->blockSlider, SIGNAL(valueChanged(int)), ui->graphicsView, SLOT(OnBlockResize(int)));
    connect(ui->speedSlider, SIGNAL(valueChanged(int)), ui->graphicsView, SLOT(OnSpeedChange(int)));
    connect(ui->clearButton, SIGNAL(clicked()), ui->graphicsView, SLOT(OnClear()));
    connect(ui->graphicsView, SIGNAL(OnEndFind()), this, SLOT(OnEndFind()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::OnEndFind()
{
    ui->blockSlider->setEnabled(true);
    ui->boardSlider->setEnabled(true);
}

void Widget::on_blockSlider_valueChanged(int value)
{
    QString str = QString::number(value).rightJustified(2, '0');
    ui->blockNum->setText(str);
}

void Widget::on_speedSlider_valueChanged(int value)
{
    QString str = QString::number(value).rightJustified(2, '0');
    ui->speedNum->setText(str);
}

void Widget::on_boardSlider_valueChanged(int value)
{
    QString str = QString::number(value).rightJustified(2, '0');
    ui->boardNum->setText(str);
}

void Widget::on_startButton_clicked()
{
    if (ui->graphicsView->OnStart())
    {
        ui->blockSlider->setEnabled(false);
        ui->boardSlider->setEnabled(false);
    }
}
