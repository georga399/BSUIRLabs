#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../SwapableAVL.h"
#include <QTreeWidgetItem>
#include <utility>
#include <memory>
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
    void on_Add_btn_clicked();

    void on_Find_btn_clicked();

    void on_Delete_btn_clicked();

    void on_Swap_Btn_clicked();

    void on_actionPre_triggered();

    void on_actionPost_triggered();

    void on_actionInfix_triggered();

private:
    Ui::MainWindow *ui;
    void Update();
    void PrintTree(std::shared_ptr<AVLTree::Node> root, QTreeWidgetItem * parentItem, int counter = 0);
    SwapableAVL avl;
    std::pair<int, std::string> Input();
    void prefix_foreach(std::shared_ptr<AVLTree::Node> node, QString& str);
    void postfix_foreach(std::shared_ptr<AVLTree::Node> node, QString& str);
    void infix_foreach(std::shared_ptr<AVLTree::Node> node, QString& str);
};
#endif // MAINWINDOW_H
