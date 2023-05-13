#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <stdexcept>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::UpdateListWidg()
{
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(2);
    int i = 0;
    for(auto it = cd.begin(); it != cd.end(); ++it, i++)
    {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(*it));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString( "0x%1" ).arg( reinterpret_cast<quintptr>(it.data()),
                                                                                               QT_POINTER_SIZE * 2, 16, QChar('0') )));
    }
}



void MainWindow::on_PushBack_Btn_clicked()
{
    if(!ui->lineEdit->text().isEmpty())
    {
        cd.push_back(ui->lineEdit->text());
    }
    UpdateListWidg();
}


void MainWindow::on_PushFront_Btn_clicked()
{
    if(!ui->lineEdit->text().isEmpty())
    {
        cd.push_front(ui->lineEdit->text());
    }
    UpdateListWidg();
}


void MainWindow::on_Clear_Btn_clicked()
{
    cd.clear();
    UpdateListWidg();
}


void MainWindow::on_PopBack_Btn_clicked()
{
    try
    {
        cd.pop_back();
        UpdateListWidg();
    }
    catch(std::out_of_range &ex)
    {
        qDebug() << ex.what();
        QMessageBox::warning(this, "Exception", ex.what());
    }
}


void MainWindow::on_PopFront_Btn_clicked()
{
    try
    {
        cd.pop_front();
        UpdateListWidg();
    }
    catch(std::out_of_range &ex)
    {
        qDebug() << ex.what();
        QMessageBox::warning(this, "Exception", ex.what());
    }
}

