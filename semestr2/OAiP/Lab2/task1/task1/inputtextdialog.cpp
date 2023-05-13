#include "inputtextdialog.h"
#include "ui_inputtextdialog.h"

InputTextDialog::InputTextDialog(QString lbl, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InputTextDialog)
{
    ui->setupUi(this);
    ui->label->setText(lbl);
}

InputTextDialog::~InputTextDialog()
{
    delete ui;
}

bool InputTextDialog::checkInput()
{
    return this->validInput;
}

QString InputTextDialog::getText()
{
    return this->text;
}


void InputTextDialog::on_confBtn_clicked()
{
    this->validInput = true;

    this->text = ui->lineEdit->text();
    this->close();
}


void InputTextDialog::on_backBtn_clicked()
{
    this->validInput = false;
    this->close();
}

