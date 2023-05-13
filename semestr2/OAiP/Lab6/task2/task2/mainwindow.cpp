#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QElapsedTimer>
MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)

{
    btn16 = new QPushButton("16");
    btn64 = new QPushButton("64");
    btn128 = new QPushButton("128");
    btn2048 = new QPushButton("2048");
    QVBoxLayout* pvbxLayout = new QVBoxLayout();
    pvbxLayout->addWidget(btn16);
    pvbxLayout->addWidget(btn64);
    pvbxLayout->addWidget(btn128);
    pvbxLayout->addWidget(btn2048);
    pvbxLayout->addWidget(plot);
    setLayout(pvbxLayout);
    QObject::connect(btn16, SIGNAL(clicked()), SLOT(Print16()));
    QObject::connect(btn64, SIGNAL(clicked()), SLOT(Print64()));
    QObject::connect(btn128, SIGNAL(clicked()), SLOT(Print128()));
    QObject::connect(btn2048, SIGNAL(clicked()), SLOT(Print2048()));
}

void MainWindow::Print16()
{
    QElapsedTimer * timer = new QElapsedTimer();
    int s = 16;
    HashTable<char> table(s);
    QVector<double> x(s), x1(s), y(s);
    for(int i = 0; i<s; i++)
    {
        double r = rand();
        x[i] = r;
        x1[i] = i;
        table.insert(r, 1);
    }
    timer->start();
    for(int i = 0; i<s; i++)
    {
        char ch = table.find(x[i]);
        y[i] = timer->nsecsElapsed();
    }

    graph->setData(x1, y);

    plot->rescaleAxes();// автоматическое масштабировани осей

    plot->replot();// обновление графика

}

void MainWindow::Print64()
{
    QElapsedTimer * timer = new QElapsedTimer();
    int s = 64;
    HashTable<char> table(s);
    QVector<double> x(s), x1(s), y(s);
    for(int i = 0; i<s; i++)
    {
        double r = rand();
        x[i] = r;
        x1[i] = i;
        table.insert(r, 1);
    }
    timer->start();
    for(int i = 0; i<s; i++)
    {
        char ch = table.find(x[i]);
        y[i] = timer->nsecsElapsed();
    }
//    QCPGraph *graph = this->plot->graph(0);

    graph->setData(x1, y);

    plot->rescaleAxes();// автоматическое масштабировани осей

    plot->replot();// обновление графика
}
void MainWindow::Print128()
{
    QElapsedTimer * timer = new QElapsedTimer();
    int s = 128;
    HashTable<char> table(s);
    QVector<double> x(s), x1(s), y(s);
    for(int i = 0; i<s; i++)
    {
        double r = rand();
        x[i] = r;
        x1[i] = i;
        table.insert(r, 1);
    }
    timer->start();
    for(int i = 0; i<s; i++)
    {
        char ch = table.find(x[i]);
        y[i] = timer->nsecsElapsed();
    }
//    QCPGraph *graph = this->plot->graph();

    graph->setData(x1, y);

    plot->rescaleAxes();// автоматическое масштабировани осей

    plot->replot();// обновление графика
}
void MainWindow::Print2048()
{
    QElapsedTimer * timer = new QElapsedTimer();
    int s = 2048;
    HashTable<char> table(s);
    QVector<double> x(s), x1(s), y(s);
    for(int i = 0; i<s; i++)
    {
        double r = rand();
        x[i] = r;
        x1[i] = i;
        table.insert(r, 1);
    }
    timer->start();
    for(int i = 0; i<s; i++)
    {
        char ch = table.find(x[i]);
        y[i] = timer->nsecsElapsed();
    }

    graph->setData(x1, y);

    plot->rescaleAxes();// автоматическое масштабировани осей

    plot->replot();// обновление графика
}
MainWindow::~MainWindow()
{
//    delete ui;
}

