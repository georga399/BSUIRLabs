#include "findedelemdialog.h"
#include "ui_findedelemdialog.h"

FindedElemDialog::FindedElemDialog(CustVector<Conversation> *lst, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindedElemDialog)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Date" << "City" << "Duration (sec)" << "Tariff" << "From" << "To");
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->lst = lst;
    for(int i = 0; i<lst->size(); i++)
    {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem( QString::number((*lst)[i].date.day()) + "." + QString::number((*lst)[i].date.month()) + "." + QString::number((*lst)[i].date.year())  ) );
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem((*lst)[i].city));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number((*lst)[i].seconds)));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number((*lst)[i].tariff)));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(((*lst)[i].numberOfCallerFrom )));
        ui->tableWidget->setItem(i, 5, new QTableWidgetItem(((*lst)[i].numberOfCallerTo )));
    }
}

FindedElemDialog::~FindedElemDialog()
{
    delete ui;
}
