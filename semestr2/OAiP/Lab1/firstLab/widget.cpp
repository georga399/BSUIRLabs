#include "widget.h"
#include "./ui_widget.h"

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


void Widget::on_ButtonTask_1_clicked()
{
    task1 = new WidgTask1();
    task1->show();

}


void Widget::on_ButtonTask_2_clicked()
{
    task2 = new WidgTask2();
    task2->show();
}

