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
    connect(ui->startButton, SIGNAL(clicked()), ui->graphicsView, SLOT(OnStart()));
    connect(ui->clearButton, SIGNAL(clicked()), ui->graphicsView, SLOT(OnClear()));
    connect(ui->pauseButton, SIGNAL(clicked()), ui->graphicsView, SLOT(OnPause()));

    ui->pauseButton->setEnabled(false);
    ui->stepButton->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
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

void Widget::on_autoRadio_pressed()
{
    ui->speedSlider->setEnabled(true);
}

void Widget::on_stepRadio_pressed()
{
    ui->speedSlider->setEnabled(false);
}

void Widget::on_startButton_clicked()
{

    ui->blockSlider->setEnabled(false);
    ui->boardSlider->setEnabled(false);
}
