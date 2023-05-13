#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <stdlib.h>
#include <QDateTime>
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


void MainWindow::on_actionAdd_new_elements_triggered()
{
    qDebug() << "Adding new elements";
    srand(QDateTime::currentMSecsSinceEpoch());
    cq.push(rand());
    qDebug() << "Added element" << cq.back();
    UpdateListWidg();
}

void MainWindow::UpdateListWidg()
{
    auto q = cq;
    ui->listWidget->clear();
    while(!q.empty())
    {
        ui->listWidget->addItem(QString::number(q.front()));
        q.pop();
    }
}

void MainWindow::on_actionSet_min_value_to_the_begin_triggered()
{
    qDebug() << "Set min val to the begin";
    if(cq.size() == 0) return;
    auto q = cq;
    int min = INT_MAX;
    int minPos = 0;
    int i = 0;
    while (!q.empty())
    {
        if(min > q.front())
        {
            min = q.front();
            minPos = i;
        }
        i++;
        q.pop();
    }
    i = 0;
    q.push(min);
    int l = cq.size();
    for(;i<l; i++)
    {
        qDebug() << i << ": " << cq.front();
        if( i != minPos)
            q.push(cq.front());
        cq.pop();
    }
    cq = q;
    UpdateListWidg();
}

