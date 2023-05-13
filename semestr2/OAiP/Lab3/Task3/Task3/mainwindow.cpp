#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "../../cvector/cvector.h"
#include <QFileDialog>
#include <fstream>
#include <algorithm>
#include <QMessageBox>

void GetMedians(ctl::cvector<int>& all, ctl::cvector<int>& res)
{
    if(all.empty()) return;
    res.clear();
    int i = 0;
    for(; i<all.size()/3; i++)
    {
        std::qsort(all.data() + i*3, 3, sizeof(all[0]), [](const void* x, const void* y)
             {
                 const int arg1 = *static_cast<const int*>(x);
                 const int arg2 = *static_cast<const int*>(y);
                 if(arg1<arg2) return -1;
                 else if(arg1>arg2) return 1;
                 return 0;
             });
    }
    for(int j = 0; j<all.size()/3; j++)
    {
        res.push_back(all[j*3+1]);
    }
    if((i)*3 != all.size())
    {
        int el1 = 0, el2 = 0;
        el1 = all[i*3];
        if((i*3)+2 == all.size())el2 = all[i*3+1];
        res.push_back((el1+el2)/2);
    }
}

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


void MainWindow::on_actionOpen_file_triggered()
{
    qDebug() << "Open file";
    QString path =  QFileDialog::getOpenFileName(0, "Open", "", "*txt");
    try
    {
        ctl::cvector<int> arr;
        if(path.isEmpty()) return;
        std::ifstream in(path.toStdString());
        while(!in.eof())
        {
            int el;
            in >> el;
            arr.push_back(el);
        }
        in.close();
        ctl::cvector<int> med;
        GetMedians(arr, med);
        QString txt;

        for(int i = 0; i<med.size(); i++)
        {
            txt+=QString::number(med[i]) + " ";
        }
        ui->label->setText(txt);
        qDebug() << txt;
    }
    catch(...)
    {
        QMessageBox::warning(this, "Exception", "Wrong");
    }
}

