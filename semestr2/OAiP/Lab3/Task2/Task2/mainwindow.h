#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../cpair/cpair.h"
#include "../../cvector/cvector.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();
    void on_actionAll_data_triggered();

private:
    Ui::MainWindow *ui;
    ctl::cvector<ctl::cpair<ctl::cvector<int>, ctl::cvector<ctl::cpair<int, double>>>> arr;

};
#endif // MAINWINDOW_H
