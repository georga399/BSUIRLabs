#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog( QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
//    ui->label->setText(lbl);
    ui->setupUi(this);
}
void Dialog::SetLbl(QString txt)
{
    ui->label->setText(txt);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonBox_accepted()
{
    text = ui->lineEdit->text();
    this->close();
}

QString Dialog::GetText()
{
    return text;
}
void Dialog::on_buttonBox_rejected()
{
    text = "";
    this->close();
}

