#include "dialogfindedproducts.h"
#include "ui_dialogfindedproducts.h"

DialogFindedProducts::DialogFindedProducts(CustVector<Product> *lst, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogFindedProducts)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Name" << "Count" << "Factory num");
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->lst = lst;
    for(int i = 0; i<lst->size(); i++)
    {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem((*lst)[i].name));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number((*lst)[i].count)));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number((*lst)[i].numOfFactory)));
    }
}

DialogFindedProducts::~DialogFindedProducts()
{
    delete ui;
}
