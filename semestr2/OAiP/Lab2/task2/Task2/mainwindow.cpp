#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <fstream>
#include <string>
#include "bracket.h"
#include "custlist.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Task 2");
    QObject::connect(ui->actionOpen_file, SIGNAL(triggered()), this, SLOT(slotOpenFile()));
    QObject::connect(ui->actionSave_file, SIGNAL(triggered()), this, SLOT(slotSaveFile()));
    QObject::connect(ui->actionCheck_all_file, SIGNAL(triggered()), this, SLOT(slotCheck()));

}

void MainWindow::slotOpenFile()
{
    qDebug() << "Openning";
    QString filename = QFileDialog::getOpenFileName(0, "Open", "", "*txt");
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
            qDebug() << allText;
            ui->plainTextEdit->setPlainText(allText);
        }
        else
        {
            QMessageBox messageBox;
            messageBox.critical(0,"Error","An error has occured !");
        }
    }
}
void MainWindow::slotSaveFile() /// TODO
{
    qDebug() << "Saving";
    QString filename = QFileDialog::getOpenFileName(0, "Save", "", "*txt");
    if(filename.size())
    {
        std::fstream ftxt;
        ftxt.open(filename.toStdString(), std::ios::trunc|std::ios::out);
        if(ftxt.is_open())
        {
            QString allText = ui->plainTextEdit->toPlainText();
            ftxt << allText.toStdString();


        }
        else
        {
            QMessageBox messageBox;
            messageBox.critical(0,"Error","An error has occured !");
        }
    }

}
void MainWindow::slotCheck()
{
    qDebug() << "Checking";
    CustList<Bracket> stck;
    QString allText = ui->plainTextEdit->toPlainText();
    int curX = 1;
    int curY = 1;
    for(int i = 0; i<allText.size(); i++, curX++)
    {
        if(allText[i].toLatin1() == '(' || allText[i].toLatin1() == '[' || allText[i].toLatin1() == '{')
        {
            Bracket br; br.x = curX; br.y = curY; br.type = allText[i].toLatin1();
            stck.push_front(br);
        }
        else if((allText[i].toLatin1() == ')' && !stck.empty() && stck[0].type == '(') || \
                        (allText[i].toLatin1() == ']' && !stck.empty() && stck[0].type == '[') || \
                        (allText[i] == '}' && !stck.empty() && stck[0].type == '{') ) stck.pop_front();
        else if(allText[i].toLatin1() == '\n')
        {
            curX = 1;
            curY++;
        }
        else if(allText[i].toLatin1() == ')' ||\
                allText[i].toLatin1() == ']' ||\
                allText[i].toLatin1() == '}')
        {
            if(stck.empty())
            {
                QMessageBox messageBox;
                messageBox.warning(0,"Wrong",QString("It's not begin bracket for '") + allText[i] + "' col:" +\
                                   QString::number(curX) + " row:" + QString::number(curY));
                return;
            }
            else
            {
                QMessageBox messageBox;
                messageBox.warning(0,"Wrong",QString("Wrong brackets:\n first '") + QString::fromLatin1(&stck[0].type) + "' col:" +\
                                   QString::number(stck[0].x) + " row:" + QString::number(stck[0].y) + \
                        "\nsecond '" + allText[i] + "' col:" +\
                        QString::number(curX) + " row:" + QString::number(curY));
                return;
            }
        }
    }
    if(!stck.empty())
    {
        QMessageBox messageBox;
        messageBox.warning(0,"Wrong",QString("There is not found end bracket for ") + QString::fromLatin1(&stck[0].type) + "' col:" +\
                           QString::number(stck[0].x) + " row:" + QString::number(stck[0].y)  );
    }
    else
    {
       QMessageBox messageBox;
       messageBox.setText("Success");
       messageBox.exec();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

