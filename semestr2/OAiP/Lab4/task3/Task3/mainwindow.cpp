#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <fstream>
#include <regex>
#include "../parser.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionOpen_triggered()
{
    qDebug() << "Openning";
    QString filename = QFileDialog::getOpenFileName(0, "Open", "", tr("*.cpp *.h"));
    if(filename.size())
    {
        std::ifstream ftxt;
        ftxt.open(filename.toStdString());
        if(ftxt.is_open())
        {
            QString allText;

            while(!ftxt.eof())
            {
                std::string str;
                std::getline(ftxt, str);
                allText += QString::fromStdString(str) + QString("\n");
            }
            ui->plainTextEdit->setPlainText(allText);
        }
        else
        {
            QMessageBox messageBox;
            messageBox.critical(0,"Error","An error has occured !");
        }
    }
}


void MainWindow::on_actionGet_all_variables_triggered()
{
    qDebug() << "Get all variables";
    QString res = GetAllVars( ui->plainTextEdit->toPlainText());
    QMessageBox messageBox;
    messageBox.information(0, "All variables", res);
}


void MainWindow::on_actionCount_of_classes_triggered()
{
    qDebug() << "Get count of classes and structs";
    QMessageBox messageBox;
    messageBox.information(0, "Count of classes|structs", GetAllClassesStructs(ui->plainTextEdit->toPlainText()));
}


void MainWindow::on_actionCount_of_arrays_triggered()
{
    qDebug() << "Get count of arrays";
    QMessageBox messageBox;
    messageBox.information(0, "Count of arrays", GetAllArrays(ui->plainTextEdit->toPlainText()));
}


void MainWindow::on_actionGet_prototypes_of_func_triggered()
{
    qDebug() << "Get all protos of funcs";
    QMessageBox messageBox;
    messageBox.information(0, "Fun protos", GetAllFunProto(ui->plainTextEdit->toPlainText()));
}


void MainWindow::on_actionGet_all_positions_of_changing_vars_and_arrays_triggered()
{
    qDebug() << "Get all pos of changing";
    QMessageBox messageBox;
    messageBox.information(0, "", GetAllChanges(ui->plainTextEdit->toPlainText()));
}


void MainWindow::on_actionGet_local_vars_triggered()
{
    qDebug() << "Get all variables";
    QString res = GetAllLocalVars( ui->plainTextEdit->toPlainText());
    QMessageBox messageBox;
    messageBox.information(0, "All variables", res);
}


void MainWindow::on_actionGet_overrided_funcs_triggered()
{
    qDebug() << "Get override funcs";
    QString res = GetOverrideFuncs( ui->plainTextEdit->toPlainText());
    QMessageBox messageBox;
    messageBox.information(0, "", res);
}


void MainWindow::on_actionDeeps_of_branches_triggered()
{
    qDebug() << "Get override funcs";
    QString res = GetDeepBranches( ui->plainTextEdit->toPlainText());
    QMessageBox messageBox;
    messageBox.information(0, "", res);
}


void MainWindow::on_actionLogic_warnings_triggered()
{
    qDebug() << "Get override funcs";
    QString res = GetLogicalWarns( ui->plainTextEdit->toPlainText());
    QMessageBox messageBox;
    messageBox.information(0, "", res);
}

