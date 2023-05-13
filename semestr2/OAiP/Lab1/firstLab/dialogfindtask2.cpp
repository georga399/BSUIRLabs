#include "dialogfindtask2.h"
#include "ui_dialogfindtask2.h"

DialogFindTask2::DialogFindTask2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogFindTask2)
{
    ui->setupUi(this);
}

DialogFindTask2::~DialogFindTask2()
{
    delete ui;
}

void DialogFindTask2::on_pushButton_clicked()
{
    this->close();
}

QString DialogFindTask2::GetGroup()
{
    return ui->lineEdit->text();
}
QString DialogFindTask2::GetName()
{
    return ui->lineEdit_2->text();
}
QString DialogFindTask2::GetModel()
{
    return ui->lineEdit_3->text();
}
