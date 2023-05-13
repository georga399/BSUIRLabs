#include "dialognewconv.h"
#include "ui_dialognewconv.h"
#include <QMessageBox>

DialogNewConv::DialogNewConv(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogNewConv)
{
    ui->setupUi(this);
}

DialogNewConv::~DialogNewConv()
{
    delete ui;
}



void DialogNewConv::on_confBtn_clicked()
{
    if(ui->cityEd->text() == "")
    {
        QMessageBox::warning(this, "Exception","Enter city");
        return;
    }
    if(ui->durationSpinBox->value() == 0)
    {
        QMessageBox::warning(this, "Exception","Enter duration");
        return;
    }
    if(ui->tariffSpinBox->value() == 0)
    {
        QMessageBox::warning(this, "Exception","Enter tarrif");
        return;
    }
    QString str = ui->dateEd->text();
    while (!str.isEmpty() && str[str.size()-1] == ' ') str.erase(str.end()-1, str.end());

    if(str == "" || str.size() != 10)
    {
        QMessageBox::warning(this, "Exception","Error type of date");
        return;
    }
    QDate tempDt;
    char ch;
    ch = str[0].toLatin1();
    if(!isdigit(ch))
    {
        QMessageBox::warning(this, "Exception","Error type of date");
        return;
    }
    int day = (ch-48)*10;
    ch = str[1].toLatin1();
    if(!isdigit(ch))
    {
        QMessageBox::warning(this, "Exception","Error type of date");
        return;
    }
    day += ch-48;
    ch = str[2].toLatin1();
    if(ch != ' ' && ch != '.' && ch != '/')
    {
        QMessageBox::warning(this, "Exception","Error type of date");
        return;
    }
    ch = str[3].toLatin1();
    if(!isdigit(ch))
    {
        QMessageBox::warning(this, "Exception","Error type of date");
        return;
    }
    int month = (ch-48)*10;
    ch = str[4].toLatin1();
    if(!isdigit(ch))
    {
        QMessageBox::warning(this, "Exception","Error type of date");
        return;
    }
    month += ch-48;
    ch = str[5].toLatin1();

    if(ch != ' ' && ch != '.' && ch != '/')
    {
        QMessageBox::warning(this, "Exception","Error type of date");
        return;
    }
    ch = str[6].toLatin1();
    if(!isdigit(ch))
    {
        QMessageBox::warning(this, "Exception","Error type of date");
        return;
    }
    int year = (ch-48)*1000;
    ch = str[7].toLatin1();
    if(!isdigit(ch))
    {
        QMessageBox::warning(this, "Exception","Error type of date");
        return;
    }
    year += (ch-48)*100;
    ch = str[8].toLatin1();
    if(!isdigit(ch))
    {
        QMessageBox::warning(this, "Exception","Error type of date");
        return;
    }
    year += (ch-48)*10;
    ch = str[9].toLatin1();
    if(!isdigit(ch))
    {
        QMessageBox::warning(this, "Exception","Error type of date");
        return;
    }
    year += (ch-48);
    tempDt.setDate(year, month, day);
    if(tempDt.day() == 0)
    {
        QMessageBox::warning(this, "Exception","Error type of date");
        return;
    }
    QString numTo = ui->numToEd->text();
    while(!numTo.isEmpty() && numTo[numTo.size()-1] == ' ') numTo.erase(numTo.end()-1, numTo.end());
    QString numFrom = ui->numFromEd->text();
    while(!numFrom.isEmpty() && numFrom[numFrom.size()-1] == ' ') numFrom.erase(numFrom.end()-1, numFrom.end());
    if(numFrom.size() != 6 || numFrom.size() != 6)
    {
        QMessageBox::warning(this, "Exception","Error type of number");
        return;
    }
    for(int i = 0; i<6; i++)
    {
        if(!isdigit(numFrom[i].toLatin1()) || !isdigit(numTo[i].toLatin1()))
        {
            QMessageBox::warning(this, "Exception","Error type of number");
            return;
        }
    }
    this->close();
    this->toChange = true;
    this->conv.city = ui->cityEd->text();
    this->conv.date = tempDt;
    this->conv.numberOfCallerFrom = numFrom;
    this->conv.numberOfCallerTo = numTo;
    this->conv.seconds = ui->durationSpinBox->value();
    this->conv.tariff = ui->tariffSpinBox->value();
}


Conversation  DialogNewConv::getConversation()
{
    return this->conv;
}

bool DialogNewConv::correctInput()
{
    return this->toChange;
}

void DialogNewConv::on_backBtn_clicked()
{
    this->toChange = false;
    this->close();
}

