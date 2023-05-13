#include "task1widget.h"
#include "./ui_task1widget.h"
#include "var1task1.h"
#include "var8task1.h"
Task1Widget::Task1Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Task1Widget)
{
    ui->setupUi(this);
}

Task1Widget::~Task1Widget()
{
    delete ui;
}


void Task1Widget::on_pushButton_clicked()
{
    var1task1 *task11 = new var1task1();
    task11->show();
}


void Task1Widget::on_pushButton_2_clicked()
{
    Var8Task1 *task18 = new Var8Task1();
    task18->show();
}

