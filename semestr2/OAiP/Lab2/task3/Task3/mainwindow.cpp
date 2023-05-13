#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "calculator.h"
#include <exception>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Task 3");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString str = ui->lineEdit->text();
    str = Calculator::addZero(str);
    QString postfix = Calculator::convertToPostfix(str);
    long double res;
    try
    {
        res = Calculator::countPostfix(postfix);
    }
    catch(std::exception &e)
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","An error has occured !");
        return;
    }
    QMessageBox messagebox;

    messagebox.setText(QString("Input form: ") + str + \
                       QString("\nPostfix form: ") + postfix +\
                               QString("\nResult: ") + QString::number(res, 'g', 6));
    messagebox.exec();

}

