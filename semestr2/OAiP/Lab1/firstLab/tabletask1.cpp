#include "tabletask1.h"
#include "ui_tabletask1.h"
#include <fstream>
#include <QMessageBox>

TableTask1::TableTask1(QVector<Date> *dates, QString &path, Date &birthdate, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TableTask1)
{
    ui->setupUi(this);
    this->dates = dates;
    this->filepath = path;
    this->birth = birthdate;
    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setShowGrid(true);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "date" << "next day date" << "previous day date" << "is leap year?" << "Week number" << "days till birthday" << "duration between this and next date");
    for(int i = 0; i<this->dates.size(); i++)
    {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(*(this->dates)[i].day()) + "." + QString::number(*(this->dates)[i].month()) + "." + QString::number(*(this->dates)[i].year()) ));
        Date tempdate = *(this->dates)[i].NextDay();
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(tempdate.day()) + "." + QString::number(tempdate.month()) + "." + QString::number(tempdate.year()) ));
        tempdate = *(this->dates)[i].PreviousDay();
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(tempdate.day()) + "." + QString::number(tempdate.month()) + "." + QString::number(tempdate.year()) ));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem((this->dates[i].IsLeap()) ? (QString("YES")) : (QString("NO"))));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::number(this->dates[i].WeekNumber())));
        ui->tableWidget->setItem(i, 5, new QTableWidgetItem(QString::number(this->dates[i].DaysTillYourBirthday(birth))));
        if(i != this->dates.size() - 1)
        {
            ui->tableWidget->setItem(i, 6, new QTableWidgetItem(QString::number(this->dates[i].Duration(this->dates[i+1]))));
        }
    }
    ui->tableWidget->setUpdatesEnabled(true);
    ui->dateEdit->setMinimumDate(QDate(100, 1, 1));
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);


}

void TableTask1::SetDates(QVector<Date> &dates)
{
    this->dates = dates;
}

void TableTask1::SetFilePath(QString &path)
{
    this->filepath = path;
}

TableTask1::~TableTask1()
{
    qDebug() << "Exit";
    delete ui;
}

void TableTask1::on_pushButton_clicked()
{
    Date newdate;
    newdate.setDate(ui->dateEdit->date().year(), ui->dateEdit->date().month(), ui->dateEdit->date().day());
    if(this->filepath !="")
    {
        std::fstream ftxt;
        ftxt.open(filepath.toStdString(), std::ios::in|std::ios::out|std::ios::binary);
        if(ftxt.is_open())
        {
            ftxt.seekg(-1, std::ios::end);
            char ch;
            ftxt.read(&ch, sizeof(char));
            if(isdigit(ch))
            {
                ch = ' ';
                ftxt.write(&ch, sizeof(char));
            }
            ch = newdate.day()/10 + 48;
            ftxt.write(&ch, sizeof(char));
            ch = newdate.day()%10 + 48;
            ftxt.write(&ch, sizeof(char));
            ch = '.';
            ftxt.write(&ch, sizeof(char));
            ch = newdate.month()/10 + 48;
            ftxt.write(&ch, sizeof(char));
            ch = newdate.month()%10 + 48;
            ftxt.write(&ch, sizeof(char));
            ch = '.';
            ftxt.write(&ch, sizeof(char));
            ch = newdate.year()/1000 + 48;
            ftxt.write(&ch, sizeof(char));
            ch = (newdate.year()%1000)/100 + 48;
            ftxt.write(&ch, sizeof(char));
            ch = (newdate.year()%100)/10 + 48;
            ftxt.write(&ch, sizeof(char));
            ch = newdate.year()%10 + 48;
            ftxt.write(&ch, sizeof(char));
            ch = ' ';
            ftxt.write(&ch, sizeof(char));

            ///
            ///

            ui->tableWidget->insertRow(dates.size());
            dates.push_back(newdate);
            if(dates.size()>1)
            {
                ui->tableWidget->setItem(dates.size()-2, 6, new QTableWidgetItem(QString::number(this->dates[dates.size()-2].Duration(newdate))));
            }
            ui->tableWidget->setItem(dates.size()-1, 0, new QTableWidgetItem(QString::number(newdate.day()) + "." + QString::number(newdate.month()) + "." + QString::number(newdate.year()) ));
            Date tempdate = newdate.NextDay();
            ui->tableWidget->setItem(dates.size()-1, 1, new QTableWidgetItem(QString::number(tempdate.day()) + "." + QString::number(tempdate.month()) + "." + QString::number(tempdate.year()) ));
            tempdate = newdate.PreviousDay();
            ui->tableWidget->setItem(dates.size()-1, 2, new QTableWidgetItem(QString::number(tempdate.day()) + "." + QString::number(tempdate.month()) + "." + QString::number(tempdate.year()) ));
            ui->tableWidget->setItem(dates.size()-1, 3, new QTableWidgetItem((newdate.IsLeap()) ? (QString("YES")) : (QString("NO"))));
            ui->tableWidget->setItem(dates.size()-1, 4, new QTableWidgetItem(QString::number(newdate.WeekNumber())));
            ui->tableWidget->setItem(dates.size()-1, 5, new QTableWidgetItem(QString::number(newdate.DaysTillYourBirthday(birth))));
            this->dates->push_back(newdate);
            ftxt.close();
            qDebug() << "Added new date";
            ui->tableWidget->update();
        }
        else
        {
            QMessageBox::warning(this,"Error", "Error format file");
        }
    }


}


void TableTask1::on_pushButton_2_clicked()
{
    QModelIndex index = ui->tableWidget->selectionModel()->currentIndex();
    qDebug() << index.row() << index.column();
    if(index.column() == 0)
    {
        Date newdate;
        newdate.setDate(ui->dateEdit->date().year(), ui->dateEdit->date().month(), ui->dateEdit->date().day());
        std::fstream ftxt;
        ftxt.open(filepath.toStdString(), std::ios::in|std::ios::out|std::ios::binary);
        if(ftxt.is_open())
        {
            ftxt.seekg(index.row()*11, std::ios::beg);
            char ch;
            ch = newdate.day()/10 + 48;
            qDebug() << ch;
            ftxt.write(&ch, sizeof(char));
            ch = newdate.day()%10 + 48;
            qDebug() << ch;
            ftxt.write(&ch, sizeof(char));
            ch = '.';
            qDebug() << ch;
            ftxt.write(&ch, sizeof(char));
            ch = newdate.month()/10 + 48;
            qDebug() << ch;
            ftxt.write(&ch, sizeof(char));
            ch = newdate.month()%10 + 48;
            qDebug() << ch;
            ftxt.write(&ch, sizeof(char));
            ch = '.';
            qDebug() << ch;
            ftxt.write(&ch, sizeof(char));
            ch = newdate.year()/1000 + 48;
            qDebug() << ch;
            ftxt.write(&ch, sizeof(char));

            ch = (newdate.year()%1000)/100 + 48;
            qDebug() << ch;
            ftxt.write(&ch, sizeof(char));
            ch = (newdate.year()%100)/10 + 48;
            qDebug() << ch;
            ftxt.write(&ch, sizeof(char));
            ch = newdate.year()%10 + 48;
            qDebug() << ch;
            ftxt.write(&ch, sizeof(char));
            ch = ' ';
            ftxt.write(&ch, sizeof(char));

            ///
            ///
            if(index.row()>=1)
            {
                ui->tableWidget->setItem(index.row()-1, 6, new QTableWidgetItem(QString::number(this->dates[index.row()-1].Duration(newdate))));
            }
            ui->tableWidget->setItem(index.row(), 0, new QTableWidgetItem(QString::number(newdate.day()) + "." + QString::number(newdate.month()) + "." + QString::number(newdate.year()) ));
            Date tempdate = newdate.NextDay();
            ui->tableWidget->setItem(index.row(), 1, new QTableWidgetItem(QString::number(tempdate.day()) + "." + QString::number(tempdate.month()) + "." + QString::number(tempdate.year()) ));
            tempdate = newdate.PreviousDay();
            ui->tableWidget->setItem(index.row(), 2, new QTableWidgetItem(QString::number(tempdate.day()) + "." + QString::number(tempdate.month()) + "." + QString::number(tempdate.year()) ));
            ui->tableWidget->setItem(index.row(), 3, new QTableWidgetItem((newdate.IsLeap()) ? (QString("YES")) : (QString("NO"))));
            ui->tableWidget->setItem(index.row(), 4, new QTableWidgetItem(QString::number(newdate.WeekNumber())));
            ui->tableWidget->setItem(index.row(), 5, new QTableWidgetItem(QString::number(newdate.DaysTillYourBirthday(birth))));
            *(this->dates)[index.row()] = newdate;
            ftxt.close();
            qDebug() << "Changed element";
            ui->tableWidget->update();
        }
        else
        {
            QMessageBox::warning(this,"Error", "Cannot open file");
        }
    }
}

