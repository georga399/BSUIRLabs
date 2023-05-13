#include "mainwindow.h"
#include "./ui_mainwindow.h"
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
    delete table;
}


void MainWindow::on_AddRand_Btn_clicked()
{
    delete table;
    table = new HashTable<char>(30);
    for(int i = 0; i<100; i++)
    {
        char ch = '#';
        int a = rand();
        table->insert(a%50 * ((a%2) ? -1 : 1), ch);
    }
    Update();
}

void MainWindow::Update()
{
    QString str;
    int counter = 1;
    for(int i = 0; i<table->GetTableSize(); i++)
    {
        auto stck = table->GetStack(i);
        while(!stck.empty())
        {
            str += QString::number(stck.top().first) + QString(stck.top().second) + " ";
            stck.pop();
            counter++;
        }
        str+="\n";
    }
    ui->label->setText(str);
}


void MainWindow::on_Split_btn_clicked()
{
    HashTable<char>* posTable, *nonposTable;
    posTable = new HashTable<char>(30);
    nonposTable = new HashTable<char>(30);
    for(int i = 0; i<table->GetTableSize(); i++)
    {
        auto stck = table->GetStack(i);
        while(!stck.empty())
        {
            if(stck.top().first > 0) posTable->insert(stck.top().first, stck.top().second);
            else nonposTable->insert(stck.top().first, stck.top().second);
            stck.pop();
        }
    }
    QString strWithPos, strWithNonpos;
    int counter = 1;
    for(int i = 0; i<posTable->GetTableSize(); i++)
    {
        auto stck = posTable->GetStack(i);
        while(!stck.empty())
        {
            qDebug() << stck.top().first;
            strWithPos += QString::number( stck.top().first) + QString(stck.top().second) + " ";
            stck.pop();
            counter++;
        }
        strWithPos += "\n";
    }
    QMessageBox mb1;
    mb1.information(0, "Positive", strWithPos);
    counter = 1;
    for(int i = 0; i<nonposTable->GetTableSize(); i++)
    {
        auto stck = nonposTable->GetStack(i);
        while(!stck.empty())
        {
            strWithNonpos += QString::number( stck.top().first) + QString(stck.top().second) + " ";
            stck.pop();
            counter++;
        }
        strWithNonpos += "\n";
    }
    QMessageBox mb2;
    mb2.information(0, "Nonpositive", strWithNonpos);
    delete posTable;
    delete nonposTable;
}


void MainWindow::on_Add_Btn_clicked()
{
    std::string str = ui->lineEdit->text().toStdString();
    int k;
    try
    {
        k = std::stoi(str);
    }
    catch(...)
    {
        QMessageBox mb2;
        mb2.critical(0, "Error type", "error type");
        return;
    }
    table->insert(k, '%');
    Update();
}


void MainWindow::on_Find_Btn_clicked()
{
    std::string str = ui->lineEdit->text().toStdString();
    int k;
    try
    {
        k = std::stoi(str);
    }
    catch(...)
    {
        QMessageBox mb2;
        mb2.critical(0, "Error type", "error type");
        return;
    }
    char ch = table->find(k);
    QMessageBox mb;
    mb.information(0, "Information", QString::number(k) + " : " + QString(ch));
}

