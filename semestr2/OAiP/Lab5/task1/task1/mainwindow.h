#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../cqueue.h"
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
    void on_actionAdd_new_elements_triggered();

    void on_actionSet_min_value_to_the_begin_triggered();

private:
    Ui::MainWindow *ui;
    void UpdateListWidg();
    ctl::cqueue<int> cq;
};
#endif // MAINWINDOW_H
