#include "var8task1.h"
#include "ui_var8task1.h"
#include "inputtextdialog.h"
#include "newproductdial.h"
#include <QFileDialog>
#include <QMessageBox>
#include <fstream>
#include "dialogfindedproducts.h"
void Var8Task1::UpdateTable()
{
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Name" << "Count" << "Number of factory");

    for(int i = 0; i<lst.size(); i++)
    {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(lst[i].name));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(lst[i].count)));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(lst[i].numOfFactory)));
    }
}

Var8Task1::Var8Task1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Var8Task1)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Name" << "Count" << "Factory number");

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

Var8Task1::~Var8Task1()
{
    delete ui;
}


void Var8Task1::on_OpnBtn_clicked()
{
    while(true)
    {
        QString path = QFileDialog::getOpenFileName(0, "Открыть", "", "*txt");
        if(path == "") break;
        else
        {
            std::fstream ftxt;
            ftxt.open(path.toStdString(), std::ios::in);
            if(ftxt.is_open())
            {
                while(lst.size()) lst.pop_back();
                int size;
                ftxt>>size;

                if(ftxt.bad() || ftxt.fail() || ftxt.eof())
                {
                    QMessageBox::warning(this, "Exception","Error type");
                    continue;
                }
                int i = 0;
                for(;i<size; i++)
                {
                    std::string name;
                    ftxt>>name;
                    if(ftxt.bad() || ftxt.fail() || ftxt.eof())
                    {
                        QMessageBox::warning(this, "Exception","Error type");
                        break;
                    }
                    int count;
                    ftxt>>count;
                    if(ftxt.bad() || ftxt.fail() || ftxt.eof())
                    {
                        QMessageBox::warning(this, "Exception","Error type");
                        break;
                    }
                    int numberOfFactory;
                    ftxt>>numberOfFactory;
                    if(ftxt.bad() || ftxt.fail() || ftxt.eof())
                    {
                        QMessageBox::warning(this, "Exception","Error type");
                        break;
                    }
                    if(numberOfFactory < 0 || count <0)
                    {
                        QMessageBox::warning(this, "Exception","Error type");
                        break;
                    }
                    qDebug() << QString::fromStdString(name) <<count<<numberOfFactory;
                    Product prod;
                    prod.name = QString::fromStdString(name);
                    prod.count = count;
                    prod.numOfFactory = numberOfFactory;
                    lst.push_back(prod);
                }
                if(i == size)
                {
                    UpdateTable();
                    break;
                }
                ftxt.close();
            }



        }
    }
}


void Var8Task1::on_SaveBtn_clicked()
{
    QString path = QFileDialog::getOpenFileName(0, "Открыть", "", "*txt");
    if(path == "") return;
    std::fstream ftxt;
    ftxt.open(path.toStdString(), std::ios::in|std::ios::out|std::ios::trunc);
    if(ftxt.is_open())
    {
        ftxt<<lst.size();
        ftxt<<std::endl;
        for(int i = 0; i<lst.size(); i++)
        {
            ftxt << lst[i].name.toStdString() << ' ' << lst[i].count << ' ' << lst[i].numOfFactory << std::endl;
        }
        ftxt.close();
    }
    else
    {
        QMessageBox::warning(this, "Exception","Not open");
    }
}


void Var8Task1::on_NewBtn_clicked()
{
    NewProductDial dial;
    dial.setModal(true);
    dial.exec();
    if(dial.CheckInput())
    {
        Product prod = dial.GetProd();
        lst.push_back(prod);
    }
    UpdateTable();
}


void Var8Task1::on_ChangeBtn_clicked()
{
    QModelIndex index = ui->tableWidget->selectionModel()->currentIndex();
    if(index.column() <0 || index.row() < 0)
    {
        QMessageBox::warning(this, "Exception","Error type of number");
        return;
    }
    if(index.column() == 0)
    {
        InputTextDialog dial("New name");
        dial.setModal(true);
        dial.exec();
        if(dial.checkInput())
        {
            QString str = dial.getText();
            while(!str.isEmpty() && str[str.size()-1].toLatin1() == ' ') str.erase(str.end()-1, str.end());
            if(!str.size())
            {
                QMessageBox::warning(this, "Exception","Error type of date");
                return;
            }
            lst[index.row()].name = str;

        }
    }
    else if(index.column() == 1)
    {
        InputTextDialog dial("New count");
        dial.setModal(true);
        dial.exec();
        if(dial.checkInput())
        {
            QString strcount = dial.getText();
            while(!strcount.isEmpty() && strcount[strcount.size()-1].toLatin1() == ' ') strcount.erase(strcount.end()-1, strcount.end());
            if(strcount == "" || strcount.size() > 8)
            {
                QMessageBox::warning(this, "Exception","Error type of number");
                return;
            }
            else
            {
                int j = 0;
                for(;j<strcount.size(); j++)
                {
                    if(!isdigit(strcount[j].toLatin1())) break;
                }
                if(j==strcount.size())lst[index.row()].count = strcount.toInt();
                else
                {
                    QMessageBox::warning(this, "Exception","Error type of number");
                    return;
                }
            }
        }
    }
    else if(index.column() == 2)
    {
        InputTextDialog dial("New num of factory");
        dial.setModal(true);
        dial.exec();
        if(dial.checkInput())
        {
            QString strcount = dial.getText();
            while(!strcount.isEmpty() && strcount[strcount.size()-1].toLatin1() == ' ') strcount.erase(strcount.end()-1, strcount.end());
            if(strcount == "" || strcount.size() > 8)
            {
                QMessageBox::warning(this, "Exception","Error type of number");
                return;
            }
            else
            {
                int j = 0;
                for(;j<strcount.size(); j++)
                {
                    if(!isdigit(strcount[j].toLatin1())) break;
                }
                if(j==strcount.size())lst[index.row()].numOfFactory = strcount.toInt();
                else
                {
                    QMessageBox::warning(this, "Exception","Error type of number");
                    return;
                }
            }
        }
    }

    UpdateTable();
}


void Var8Task1::on_DeleteBtn_clicked()
{
    QModelIndex index = ui->tableWidget->selectionModel()->currentIndex();
    if(index.column() == -1 || index.row() == -1)
    {
        return;
    }
    int i = index.row();
    lst.erase(i);
    qDebug() << lst.size();
    UpdateTable();
}

void mergeSort(CustVector<Product> &arr, int b, int e)
{
    if( b >= e || e < 0 || b < 0 ) return;
    mergeSort(arr, b, (b+e)/2);
    mergeSort(arr, (b+e)/2+1, e);
    int tempArrSize = e-b+1;
    Product *tempArr = new Product[tempArrSize];
    int k = b, l = (b+e)/2+1;
    for(int i = 0; i < tempArrSize; i++)
    {
        if(k > (b+e)/2)
        {
            tempArr[i] = arr[l];
            l++;
        }
        else if(l > e)
        {
            tempArr[i] = arr[k];
            k++;
        }
        else if(arr[l].count > arr[k].count)
        {
            tempArr[i] = arr[k];
            k++;
        }
        else
        {
            tempArr[i] = arr[l];
            l++;
        }
    }
    for(int i = 0; i<tempArrSize; i++)
    {
        arr[b+i] = tempArr[i];
    }
    delete []tempArr;
}

void Var8Task1::on_SortBtn_clicked()
{
   mergeSort(lst, 0, lst.size()-1);
   UpdateTable();
}


void Var8Task1::on_FindForName_clicked()
{
    InputTextDialog dial("Name");
    dial.setModal(true);
    dial.exec();
    if(dial.checkInput())
    {
        QString name = dial.getText();
        CustVector<Product> newlst;
        for(int i = 0; i<lst.size(); i++)
        {
            if(lst[i].name == name)
            {
                newlst.push_back(lst[i]);
            }
        }
        DialogFindedProducts newtable(&newlst);
        newtable.setModal(true);
        newtable.exec();
    }
}

