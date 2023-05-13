#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "qcustomplot.h"
#include "../HashTable.h"
#include <QVector>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QPushButton * btn16;
    QPushButton * btn64;
    QPushButton * btn128;
    QPushButton * btn2048;
    QCustomPlot * plot = new QCustomPlot(this);
    QCPGraph *graph = plot->addGraph();
private slots:
    void Print16();
    void Print64();
    void Print128();
    void Print2048();
};
#endif // MAINWINDOW_H
