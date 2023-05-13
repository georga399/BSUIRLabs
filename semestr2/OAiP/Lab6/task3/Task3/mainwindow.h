#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../HashTable.h"
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
    void on_AddRand_Btn_clicked();

    void on_Split_btn_clicked();

    void on_Add_Btn_clicked();

    void on_Find_Btn_clicked();

private:
    Ui::MainWindow *ui;
    HashTable<char>* table = new HashTable<char>(30);
    void Update();
};
#endif // MAINWINDOW_H
