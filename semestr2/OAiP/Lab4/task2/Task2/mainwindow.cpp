#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
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


void MainWindow::on_pushButton_clicked()
{
    char s1[100];
    char s2[100];
    ctl::memcpy(s1, ui->lineEdit->text().toStdString().c_str(), ui->lineEdit->text().size());
    ctl::memcpy(s2, ui->lineEdit_2->text().toStdString().c_str(), ui->lineEdit_2->text().size());
    ui->lineEdit_2->setText(s1);
    qDebug() << s1;
    qDebug() << s2;
}


void MainWindow::on_pushButton_2_clicked()
{
    char s1[100];
    char s2[100];
    ctl::memmove(s1, ui->lineEdit->text().toStdString().c_str(), ui->lineEdit->text().size());
    ctl::memmove(s2, ui->lineEdit_2->text().toStdString().c_str(), ui->lineEdit_2->text().size());
    ui->lineEdit_2->setText(s1);
    qDebug() << s1;
    qDebug() << s2;
}


void MainWindow::on_pushButton_3_clicked()
{
    char s1[100];
    char s2[100];
    ctl::strcpy(s1, ui->lineEdit->text().toStdString().c_str());
    ctl::strcpy(s2, ui->lineEdit_2->text().toStdString().c_str());
    ui->lineEdit_2->setText(s1);
    qDebug() << s1;
    qDebug() << s2;
}


void MainWindow::on_pushButton_5_clicked()
{
    char s1[100];
    char s2[100];
    ctl::strcpy(s1, ui->lineEdit->text().toStdString().c_str());
    ctl::strcpy(s2, ui->lineEdit_2->text().toStdString().c_str());
    ctl::strcat(s1, s2);
    ui->lineEdit->setText(s1);
    qDebug() << s1;
    qDebug() << s2;
}


void MainWindow::on_pushButton_7_clicked()
{
    int res = ctl::memcmp((void*)ui->lineEdit->text().toStdString().c_str(), (void*)ui->lineEdit_2->text().toStdString().c_str(), std::min(ui->lineEdit->text().size(), ui->lineEdit_2->text().size()));
    QMessageBox messageBox;
    messageBox.information(0, "Result", QString::number(res));
}


void MainWindow::on_pushButton_10_clicked()
{
    int res = ctl::strncmp(ui->lineEdit->text().toStdString().c_str(), ui->lineEdit_2->text().toStdString().c_str(), std::min(ui->lineEdit->text().size(), ui->lineEdit_2->text().size()));
    QMessageBox messageBox;
    messageBox.information(0, "Result", QString::number(res));
}


void MainWindow::on_pushButton_11_clicked()
{
    char delim[100], str[100];
    ctl::strcpy(str, ui->lineEdit->text().toStdString().c_str());
    ctl::strcpy(delim, ui->lineEdit_2->text().toStdString().c_str());
    qDebug() << str;
    qDebug() << delim;
    char* token = ctl::strtok(str, delim);
    QString res;
    while (token != NULL) {
        qDebug() << token;
        res += QString(token) + QString('\n');
        token = ctl::strtok(NULL, delim);
    }

    QMessageBox messageBox;
    messageBox.information(0, "Result", res);
}



void MainWindow::on_pushButton_14_clicked()
{
    qDebug() << ctl::strlen(ui->lineEdit->text().toStdString().c_str());
    qDebug() << ctl::strlen(ui->lineEdit_2->text().toStdString().c_str());
    QString res = QString("str 1: ") + \
            QString::number(ctl::strlen(ui->lineEdit->text().toStdString().c_str())) + \
            QString("\nstr 2: ") + \
            QString::number(ctl::strlen(ui->lineEdit_2->text().toStdString().c_str()));
    QMessageBox messageBox;
    messageBox.information(0, "Result", res);
}


void MainWindow::on_pushButton_8_clicked()
{
    QMessageBox messageBox;
    messageBox.information(0, "Result", QString::number(ctl::strcmp(ui->lineEdit->text().toStdString().c_str(), ui->lineEdit_2->text().toStdString().c_str())));
}


void MainWindow::on_pushButton_12_clicked()
{
    static int counter = 0;
    char str[100];
    ctl::strcpy(str, ui->lineEdit->text().toStdString().c_str());
    ctl::memset((void*)str, 'a' + counter, 20);
    str[20] = '\0';
    ui->lineEdit->setText(str);
    counter++;
    if(counter == 30) counter = 0;
}

