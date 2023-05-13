#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Update();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Update()
{
    ui->treeWidget->clear();
    PrintTree(avl.root, nullptr);
    ui->Key_ledit->clear();
    ui->Val_ledit->clear();
}

void MainWindow::PrintTree(std::shared_ptr<AVLTree::Node> root, QTreeWidgetItem * parentItem, int counter){
    if(!root) return;
    if(parentItem == nullptr)
    {
        parentItem = new QTreeWidgetItem(ui->treeWidget);
        parentItem->setText(0, QString::number(root->GetKey()) + ": "\
                            + QString::fromStdString(root->value));
        ui->treeWidget->addTopLevelItem(parentItem);
    }
    else
    {
        auto item = new QTreeWidgetItem(parentItem);
        item->setText(0, QString::number(root->GetKey()) + ": "\
                      + QString::fromStdString(root->value));
        parentItem->addChild(item);
        parentItem = item;
    }
    counter++;
    PrintTree(root->left, parentItem, counter);
    PrintTree(root->right, parentItem, counter);
}

std::pair<int, std::string> MainWindow::Input()
{
    std::string keyStr = ui->Key_ledit->text().toStdString();
    int key = std::stoi(keyStr);
    std::string valStr = ui->Val_ledit->text().toStdString();
    return std::pair<int, std::string>(key, valStr);
}

void MainWindow::on_Add_btn_clicked()
{
    std::pair<int, std::string> p;
    try
    {
        p = Input();
    }
    catch(...)
    {
        QMessageBox mb;
        mb.critical(0, "Exception", "Error type");
        return;
    }
    auto n = avl.find(p.first);
    if(n!=nullptr) return;
    avl.insert(p.first, p.second);
    Update();
}


void MainWindow::on_Find_btn_clicked()
{
    std::pair<int, std::string> p;
    try
    {
        p = Input();
    }
    catch(...)
    {
        QMessageBox mb;
        mb.critical(0, "Exception", "Error type");
        return;
    }
    auto n = avl.find(p.first);
    if(n == nullptr)
    {
        QMessageBox mb;
        mb.information(0, "", "Not found");
    }
    else
    {
        QMessageBox mb;
        mb.information(0, "", QString::number(n->GetKey()) + " :" + QString::fromStdString(n->value));
    }

}


void MainWindow::on_Delete_btn_clicked()
{
    std::pair<int, std::string> p;
    try
    {
        p = Input();
    }
    catch(...)
    {
        QMessageBox mb;
        mb.critical(0, "Exception", "Error type");
        return;
    }
    avl.remove(p.first);
    Update();
}


void MainWindow::on_Swap_Btn_clicked()
{
    avl.swapValuesOfMinMaxKeys();
    Update();
}


void MainWindow::on_actionPre_triggered()
{
    QString str;
    prefix_foreach(avl.root, str);
    QMessageBox mb;
    mb.information(0, "Prefix", str);
}


void MainWindow::prefix_foreach(std::shared_ptr<AVLTree::Node> node, QString& str)
{
    if(!node) return;
    str += QString::number(node->GetKey()) +  QString::fromStdString(node->value) + " ";
    prefix_foreach(node->left, str);
    prefix_foreach(node->right, str);
}

void MainWindow::infix_foreach(std::shared_ptr<AVLTree::Node> node, QString& str)
{
    if(!node) return;
    infix_foreach(node->left, str);
    str += QString::number(node->GetKey()) +  QString::fromStdString(node->value) + " ";
    infix_foreach(node->right, str);
}

void MainWindow::postfix_foreach(std::shared_ptr<AVLTree::Node> node, QString& str)
{
    if(!node) return;
    postfix_foreach(node->left, str);
    postfix_foreach(node->right, str);
    str += QString::number(node->GetKey()) + QString::fromStdString(node->value) + " ";

}
void MainWindow::on_actionPost_triggered()
{
    QString str;
    postfix_foreach(avl.root, str);
    qDebug() << str;
    QMessageBox mb;
    mb.information(0, "Postfix", str);
}


void MainWindow::on_actionInfix_triggered()
{
    {
        QString str;
        infix_foreach(avl.root, str);
        QMessageBox mb;
        mb.information(0, "Infix", str);
    }
}

