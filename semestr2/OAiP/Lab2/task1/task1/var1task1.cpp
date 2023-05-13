#include "var1task1.h"
#include "ui_var1task1.h"
#include "dialognewconv.h"
#include "inputtextdialog.h"
#include "findedelemdialog.h"
#include <fstream>
#include <QFileDialog>
#include <QString>
#include <QMessageBox>
#include "custvector.h"
var1task1::var1task1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::var1task1)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Date" << "City" << "Duration (sec)" << "Tariff" << "From" << "To");

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

var1task1::~var1task1()
{
    delete ui;
}

void var1task1::UpdateTable()
{
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Date" << "City" << "Duration (sec)" << "Tariff" << "From" << "To");

    for(int i = 0; i<lst.size(); i++)
    {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem( QString::number(lst[i].date.day()) + "." + QString::number(lst[i].date.month()) + "." + QString::number(lst[i].date.year())  ) );
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(lst[i].city));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(lst[i].seconds)));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(lst[i].tariff)));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem((lst[i].numberOfCallerFrom )));
        ui->tableWidget->setItem(i, 5, new QTableWidgetItem((lst[i].numberOfCallerTo )));
    }
}



void var1task1::on_OpenBtn_clicked()
{
    while(true)
    {
        QString path = QFileDialog::getOpenFileName(0, "Открыть", "", "*txt");
        if(path == "") break;
        else
        {
            std::fstream ftxt;
            ftxt.open(path.toStdString(), std::ios::in);
            if(ftxt.is_open())
            {
                while(lst.size()) lst.pop_back();
                int size;
                ftxt>>size;
                QDate date;
                if(ftxt.bad() || ftxt.fail() || ftxt.eof())
                {
                    QMessageBox::warning(this, "Exception","Error type");
                    continue;
                }
                int i = 0;
                for(;i<size; i++)
                {
                    int day;
                    ftxt>>day;
                    if(ftxt.bad() || ftxt.fail() || ftxt.eof())
                    {
                        QMessageBox::warning(this, "Exception","Error type");
                        break;
                    }
                    int month;
                    ftxt>>month;
                    if(ftxt.bad() || ftxt.fail() || ftxt.eof())
                    {
                        QMessageBox::warning(this, "Exception","Error type");
                        break;
                    }
                    int year;
                    ftxt>>year;
                    if(ftxt.bad() || ftxt.fail() || ftxt.eof())
                    {
                        QMessageBox::warning(this, "Exception","Error type");
                        break;
                    }
                    date.setDate(year, month, day);
                    if(date.year() == 0)
                    {
                        QMessageBox::warning(this, "Exception","Error type");
                        break;
                    }
                    QString city;
                    std::string str;
                    ftxt>>str;
                    city = QString::fromStdString(str);
                    if(ftxt.bad() || ftxt.fail() || ftxt.eof())
                    {
                        QMessageBox::warning(this, "Exception","Error type");
                        break;
                    }
                    int duration;
                    ftxt>>duration;
                    if(ftxt.bad() || ftxt.fail() || ftxt.eof() || duration <= 0)
                    {
                        QMessageBox::warning(this, "Exception","Error type");
                        break;
                    }
                    int tariff;
                    ftxt>>tariff;
                    if(ftxt.bad() || ftxt.fail() || ftxt.eof())
                    {
                        QMessageBox::warning(this, "Exception","Error type");
                        break;
                    }
                    QString callTo;
                    str="";
                    ftxt>>str;
                    callTo = QString::fromStdString(str);
                    if(ftxt.bad() || ftxt.fail() || ftxt.eof() || callTo.size() != 6) // TODO: Check valid
                    {
                        QMessageBox::warning(this, "Exception","Error type");
                        break;
                    }
                    for(int i = 0; i<6; i++)
                    {
                        if(!isdigit(callTo[i].toLatin1()))
                        {
                            QMessageBox::warning(this, "Exception","Error type");
                            break;
                        }
                    }
                    QString callFrom;
                    str = "";
                    ftxt>>str;
                    callFrom = QString::fromStdString(str);
                    if(callFrom.size() != 6)
                    {
                        QMessageBox::warning(this, "Exception","Error type");
                        break;
                    }
                    for(int i = 0; i<6; i++)
                    {
                        if(!isdigit(callFrom[i].toLatin1()))
                        {
                            QMessageBox::warning(this, "Exception","Error type");
                            break;
                        }
                    }
                    qDebug() << city << date.day() << date.month() << date.year() << callFrom << callTo;
                    Conversation conv;
                    conv.city = city;
                    conv.date = date;
                    conv.seconds = duration;
                    conv.tariff = tariff;
                    conv.numberOfCallerFrom = callFrom;
                    conv.numberOfCallerTo = callTo;
                    lst.push_back(conv);
                }
                if(i == size)
                {
                    UpdateTable();
                    break;
                }
                ftxt.close();                
            }



        }
    }

}


void var1task1::on_RewrFileBtn_clicked()
{

    QString path = QFileDialog::getOpenFileName(0, "Открыть", "", "*txt");
    if(path == "") return;
    std::fstream ftxt;
    ftxt.open(path.toStdString(), std::ios::in|std::ios::out|std::ios::trunc);
    if(ftxt.is_open())
    {
        ftxt<<lst.size();
        ftxt<<std::endl;
        for(int i = 0; i<lst.size(); i++)
        {
            ftxt << lst[i].date.day() << ' ' << lst[i].date.month() << ' ' << lst[i].date.year() << std::endl;
            ftxt << lst[i].city.toStdString() << ' ' << lst[i].seconds << ' ' << lst[i].tariff << ' ' \
                 << lst[i].numberOfCallerTo.toStdString() << ' ' \
                 << lst[i].numberOfCallerFrom.toStdString() << std::endl;
        }
        ftxt.close();
    }
    else
    {
        QMessageBox::warning(this, "Exception","Not open");
    }
}


void var1task1::on_NewConvBtn_clicked()
{
    DialogNewConv *dial = new DialogNewConv();
    dial->setModal(true);
    dial->exec();
    if(dial->correctInput())
    {
        lst.push_back(dial->getConversation());
        UpdateTable();
    }

}


void var1task1::on_DeleteConvBtn_clicked()
{
    QModelIndex index = ui->tableWidget->selectionModel()->currentIndex();
    if(index.column() == -1 || index.row() == -1)
    {
        return;
    }
    int i = index.row();
    lst.erase(i);
    qDebug() << lst.size();
    UpdateTable();
}


void var1task1::on_CityFindBtn_clicked()
{
    InputTextDialog dial("City");
    dial.setModal(true);
    dial.exec();
    if(dial.checkInput())
    {
        QString city = dial.getText();
        qDebug() << city;
        int k = 0;
        CustVector<Conversation> newlst; //// TODO: Change to linked list
        for(int i = 0; i<lst.size(); i++)
        {
            if(lst[i].city == city)
            {
                newlst.push_back(lst[i]);
            }
        }
        FindedElemDialog newtable(&newlst);
        newtable.setModal(true);
        newtable.exec();
    }
}


void var1task1::on_NumbFindBtn_clicked()
{
    InputTextDialog dial("Number(000000)");
    dial.setModal(true);
    dial.exec();
    if(dial.checkInput())
    {
        QString num = dial.getText();
        while(!num.isEmpty() && num[num.size()-1].toLatin1() == ' ') num.erase(num.end()-1, num.end());
        qDebug() << num;
        if(num.size() != 6)
        {
            QMessageBox::warning(this, "Exception","Error type of number");
            return;
        }
        for(int i = 0; i<num.size(); i++)
        {
            if(!isdigit(num[i].toLatin1()))
            {
                QMessageBox::warning(this, "Exception","Error type of number");
                return;
            }
        }
        CustVector<Conversation> newlst; //// TODO: Change to linked list
        for(int i = 0; i<lst.size(); i++)
        {
            if(lst[i].numberOfCallerFrom == num || lst[i].numberOfCallerTo == num)
            {
                newlst.push_back(lst[i]);
            }
        }
        FindedElemDialog newtable(&newlst);
        newtable.setModal(true);
        newtable.exec();
    }
}


void var1task1::on_DelAbBtn_clicked()
{
    InputTextDialog dial("Number(000000)");
    dial.setModal(true);
    dial.exec();
    if(dial.checkInput())
    {
        QString num = dial.getText();
        while(!num.isEmpty() && num[num.size()-1].toLatin1() == ' ') num.erase(num.end()-1, num.end());
        qDebug() << num;
        if(num.size() != 6)
        {
            QMessageBox::warning(this, "Exception","Error type of number");
            return;
        }
        for(int i = 0; i<num.size(); i++)
        {
            if(!isdigit(num[i].toLatin1()))
            {
                QMessageBox::warning(this, "Exception","Error type of number");
                return;
            }
        }
        for(int i = 0; i<lst.size(); )
        {
            if(lst[i].numberOfCallerFrom == num || lst[i].numberOfCallerTo == num)
            {
//                lst.erase(lst.begin() + i, lst.begin() + i +1); ////TODO: Change for linked list
                  lst.erase(i);
            }
            else
            {
                i++;
            }
        }
        UpdateTable();
    }
}

void var1task1::on_SortBtn_clicked()
{

    lst.mergeSort(0, lst.size()-1, [](Conversation c1, Conversation c2)
    {
        return c1.tariff > c2.tariff;
    });
    UpdateTable();
}



void var1task1::on_ChangeBtn_clicked()
{
    QModelIndex index = ui->tableWidget->selectionModel()->currentIndex();
    if(index.column() <0 || index.row() < 0)
    {
        QMessageBox::warning(this, "Exception","Error type of number");
        return;
    }
    if(index.column() == 0)
    {
        InputTextDialog dial("Date");
        dial.setModal(true);
        dial.exec();
        if(dial.checkInput())
        {
            QString strdate = dial.getText();
            while(!strdate.isEmpty() && strdate[strdate.size()-1].toLatin1() == ' ') strdate.erase(strdate.end()-1, strdate.end());
            if(strdate.size() != 10 )
            {
                QMessageBox::warning(this, "Exception","Error type of date");
                return;
            }
            QDate dt = QDate::fromString(strdate, "dd.MM.yyyy");
            if(dt.day() == 0)
            {
                QMessageBox::warning(this, "Exception","Error type of date");
                return;
            }
            lst[index.row()].date = dt;

        }
    }
    else if(index.column() == 1)
    {
        InputTextDialog dial("City");
        dial.setModal(true);
        dial.exec();
        if(dial.checkInput())
        {
            QString city = dial.getText();
            while(!city.isEmpty() && city[city.size()-1].toLatin1() == ' ') city.erase(city.end()-1, city.end());
            if(city == "")
            {
                QMessageBox::warning(this, "Exception","Error type of number");
                return;
            }
            else
            {
                lst[index.row()].city = city;
            }
        }
    }
    else if(index.column() == 2 || index.column() == 3)
    {
        qDebug() << index.column();
        InputTextDialog dial(((index.column() == 3) ? "Tariff" : "Duration" ));
        dial.setModal(true);
        dial.exec();
        if(dial.checkInput())
        {
            QString txt = dial.getText();
            while(!txt.isEmpty() && txt[txt.size()-1].toLatin1() == ' ') txt.erase(txt.end()-1, txt.end());////TODO: Change for linked list
            if(txt == "")
            {
                QMessageBox::warning(this, "Exception","Error type");
                return;
            }
            int val = txt.toInt();
            if(val == 0)
            {
                QMessageBox::warning(this, "Exception","Error type");
                return;
            }
            if(index.column() == 3) lst[index.row()].tariff = val;
            else lst[index.row()].seconds = val;
        }
    }
    else if(index.column() == 4 || index.column() == 5)
    {
        qDebug() << index.column();
        InputTextDialog dial("Number");
        dial.setModal(true);
        dial.exec();
        if(dial.checkInput())
        {
            QString txt = dial.getText();
            while(!txt.isEmpty() && txt[txt.size()-1].toLatin1() == ' ') txt.erase(txt.end()-1, txt.end());
            if(txt.size() != 6)
            {
                QMessageBox::warning(this, "Exception","Error type");
                return;
            }
            for(int i = 0; i<txt.size(); i++)
            {
               if(!isdigit(txt[i].toLatin1()))
               {
                   QMessageBox::warning(this, "Exception","Error type");
                   return;
               }
            }
            qDebug() << txt;
            if(index.column() == 4) lst[index.row()].numberOfCallerFrom = txt;
            else lst[index.row()].numberOfCallerTo = txt;

        }
    }
    UpdateTable();
}

