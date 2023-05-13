#include "newproductdial.h"
#include "ui_newproductdial.h"

NewProductDial::NewProductDial(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewProductDial)
{
    ui->setupUi(this);
}

NewProductDial::~NewProductDial()
{
    delete ui;
}

void NewProductDial::on_buttonBox_accepted()
{
    QString name = ui->NameEdit->text();
    if(name.size()!=0 && name[name.size()-1].toLatin1() != ' ')
    {
        validInput = 1;
    }
    this->close();
}


void NewProductDial::on_buttonBox_rejected()
{
    validInput = 0;
    this->close();
}

bool NewProductDial::CheckInput()
{
    return validInput;
}
Product NewProductDial::GetProd()
{
    Product prod;
    prod.name = ui->NameEdit->text();
    prod.count = ui->CountSpin->value();
    prod.numOfFactory = ui->NewFactory->value();
    return prod;
}

