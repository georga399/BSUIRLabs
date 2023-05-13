#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <fstream>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionOpen_triggered()
{
    qDebug() << "Openning";
    QString path = QFileDialog::getOpenFileName(0, "Open","", "*txt");
    if(path =="") return;
    std::ifstream in(path.toStdString());
    arr.clear();
    while(!in.eof())
    {
        int el1, el2;
        double el3;
        in >> el1 >> el2 >> el3;
        if(el1 == -1 && el2 == -1)
        {
            arr.push_back(ctl::cpair<ctl::cvector<int>, ctl::cvector<ctl::cpair<int, double>>>());
            continue;
        }
        arr[arr.size()-1].first.push_back(el1);
        arr[arr.size()-1].second.push_back({el2, el3});
    }
    qDebug() << "End of reading";
    in.close();
}


void MainWindow::on_actionAll_data_triggered()
{
    qDebug() << "Show all data";
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "int" << "pair<int, " << "double>");

    int k = 0;
    for(int i=0; i<arr.size(); i++)
    {
        ui->tableWidget->insertRow(k);
        ui->tableWidget->setItem(k, 0, new QTableWidgetItem(QString("Matrix №") + QString::number(i+1)));
        k++;
        for(int j = 0; j<arr[i].first.size(); j++)
        {
            ui->tableWidget->insertRow(k);
            ui->tableWidget->setItem(k, 0, new QTableWidgetItem(QString::number(arr[i].first[j])));
            ui->tableWidget->setItem(k, 1, new QTableWidgetItem(QString::number(arr[i].second[j].first)));
            ui->tableWidget->setItem(k, 2, new QTableWidgetItem(QString::number(arr[i].second[j].second)));
            k++;
        }

    }
}

