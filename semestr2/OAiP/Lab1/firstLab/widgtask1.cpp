#include "widgtask1.h"
#include "ui_widgtask1.h"
#include "tabletask1.h"
#include <QFileDialog>
#include <QMessageBox>
#include <fstream>
#include <QDebug>
WidgTask1::WidgTask1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgTask1)
{
    ui->setupUi(this);
    ui->dateEdit->setMinimumDate(QDate(100, 1, 1));

}

WidgTask1::~WidgTask1()
{
    delete ui;
}

void WidgTask1::on_buttonRead_clicked()
{
    bool correctInput = 0;
    while(!correctInput)
    {
        path = "";
        path = QFileDialog::getOpenFileName(0, "Открыть", "", "*txt");
        if(!Alldates.isEmpty())
        {
            Alldates.erase(Alldates.begin(), Alldates.end());
        }
        if(!path.isEmpty())
        {
            std::fstream ftxt;
            ftxt.open(path.toStdString(), std::ios::in|std::ios::binary);
            if(ftxt.is_open())
            {
                ftxt.seekg(0, std::ios::end);
                int size = ftxt.tellg();
                if(size%11 != 0 && size%11!=10)
                {
                    QMessageBox::warning(this, "Exception","Error type of dates");
                    qDebug() << "Error type of date";
                    continue;
                }
                ftxt.seekg(0);
                int countOfdates = (size +1)/11;
                int i = 0;
                for(; i<countOfdates; i++)
                {
                    char ch;
                    int day = 0;
                    ftxt.read(&ch, sizeof(char));
                    if(isdigit(ch))
                        day += (ch - 48)*10;
                    ftxt.read(&ch, sizeof(char));
                    if(isdigit(ch))
                        day += (ch - 48);

                    ftxt.read(&ch, sizeof(char));

                    int month = 0;
                    ftxt.read(&ch, sizeof(char));
                    if(isdigit(ch))
                        month += (ch - 48)*10;
                    ftxt.read(&ch, sizeof(char));
                    if(isdigit(ch))
                        month += (ch - 48);

                    ftxt.read(&ch, sizeof(char));

                    int year = 0;
                    ftxt.read(&ch, sizeof(char));
                    if(isdigit(ch))
                        year += (ch - 48)*1000;
                    ftxt.read(&ch, sizeof(char));
                    if(isdigit(ch))
                        year += (ch - 48)*100;
                    ftxt.read(&ch, sizeof(char));
                    if(isdigit(ch))
                        year += (ch - 48)*10;
                    ftxt.read(&ch, sizeof(char));
                    if(isdigit(ch))
                        year += (ch - 48);
                    ftxt.read(&ch, sizeof(char));

                    Date temp;
                    temp.setDate(year, month, day);
//                    qDebug() << year << month << day;
                    if(temp.year() == 0)
                    {
//                        qDebug() << year << month << day;
                        break;
                    }
                    else
                        Alldates.push_back(temp);
                }
                if(i!=countOfdates)
                {
                    Alldates.erase(Alldates.begin(), Alldates.end());
                    QMessageBox::warning(this, "Exception","Error type of dates");
                    qDebug() << "Error type of date";

                }
                else
                {
                    break;
                }
                ftxt.close();
            }
            else
            {
                qDebug() << "Error open";
            }
        }
        else
        {
            qDebug() << "Kill QFileDialog";
            break;
        }
    }

}


void WidgTask1::on_pushButton_clicked()
{
    birthday.setDate(ui->dateEdit->date().year(), ui->dateEdit->date().month(), ui->dateEdit->date().day());
    qDebug() << birthday.day() << birthday.month() << birthday.year();
    TableTask1 tablewidg(&Alldates, path, birthday);
    tablewidg.setWindowTitle("Table");
    tablewidg.setModal(true);
    tablewidg.exec();
    qDebug() << "End";
}


void WidgTask1::on_birthBtn_clicked()
{
    qDebug() << "Setting birth";
}

