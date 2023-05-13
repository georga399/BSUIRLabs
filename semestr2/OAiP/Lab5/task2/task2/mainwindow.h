#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../cdeque.h"
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
    void on_PushBack_Btn_clicked();

    void on_PushFront_Btn_clicked();

    void on_Clear_Btn_clicked();

    void on_PopBack_Btn_clicked();

    void on_PopFront_Btn_clicked();

private:
    Ui::MainWindow *ui;
    void UpdateListWidg();
    ctl::cdeque<QString> cd;
};
#endif // MAINWINDOW_H
