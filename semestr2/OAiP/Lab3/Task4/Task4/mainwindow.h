#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
    void on_actionemplace_back_triggered();

    void on_actionemplace_triggered();

    void on_actionclear_triggered();

    void on_actionsort_triggered();

    void on_actionclear_2_triggered();

    void on_actionresize_triggered();

    void on_actionreserve_triggered();

    void on_actionChange_value_triggered();

    void on_tabWidget_tabBarClicked(int index);

    void on_actionSwap_2_triggered();

    void on_actionAsign_from_another_triggered();

private:
    Ui::MainWindow *ui;
    ctl::cvector<QString> arr;
    ctl::cvector<QString> arr2;
    void Update(int);
};
#endif // MAINWINDOW_H
