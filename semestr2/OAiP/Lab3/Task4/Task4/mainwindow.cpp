#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "dialog.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Update(int i)
{

    QTableWidget* tableWidg;
    ctl::cvector<QString>* a;
//    qDebug() << ui->tabWidget->currentWidget()->objectName();
    if(i == 0)
    {
        tableWidg = ui->tableWidget;
        a = &arr;
    }
    else
    {
        tableWidg = ui->tableWidget_2;
        a = &arr2;
    }
    QString lbl;
    lbl = QString("size: ") + QString::number(a->size()) + QString(" capacity: ") + QString::number(a->capacity());
    ui->label->setText(lbl);
    tableWidg->clear();
    tableWidg->setRowCount(0);
    tableWidg->setColumnCount(2);
    for(auto it = a->begin(); it != a->end(); ++it)
    {
        tableWidg->insertRow(it - a->begin());
        tableWidg->setItem(it - a->begin(), 0, new QTableWidgetItem(*it));
        tableWidg->setItem(it-a->begin(), 1, new QTableWidgetItem(QString( "0x%1" ).arg( reinterpret_cast<quintptr>(it.cbase()),
                                                                                               QT_POINTER_SIZE * 2, 16, QChar('0') )));
    }
}

void MainWindow::on_actionemplace_back_triggered()
{
    Dialog* dial = new Dialog();
    dial->SetLbl("String");
    dial->setModal(true);
    dial->exec();
    QString res = dial->GetText();
    if(res == "") return;
    if(ui->tabWidget->currentWidget()->objectName() == "tab")
        arr.emplace_back(res);
    else
        arr2.emplace_back(res);
    Update(ui->tabWidget->currentIndex());
}


void MainWindow::on_actionemplace_triggered()
{
    QTableWidget* tableWidg;
    ctl::cvector<QString>* a;
    if(ui->tabWidget->currentWidget()->objectName() == "tab")
    {
        a = &arr;
        tableWidg = ui->tableWidget;
    }
    else
    {
        a = &arr2;
        tableWidg = ui->tableWidget_2;
    }
    QModelIndex index = tableWidg->selectionModel()->currentIndex();
    if(index.row() == -1 || index.column() == -1)
    {
        return;
    }
    Dialog* dial = new Dialog();
    dial->SetLbl("String");
    dial->setModal(true);
    dial->exec();
    QString res = dial->GetText();
    if(res == "") return;
    a->emplace(a->begin() + index.row(),res);
    Update(ui->tabWidget->currentIndex());
}


void MainWindow::on_actionclear_triggered()
{
    ctl::cvector<QString>* a;
    if(ui->tabWidget->currentWidget()->objectName() == "tab")
    {
        a = &arr;
    }
    else
    {
        a = &arr2;
    }
    if(a->size() == 0) return;
    a->pop_back();
    Update(ui->tabWidget->currentIndex());
}


void MainWindow::on_actionsort_triggered()
{
    QTableWidget* tableWidg;
    ctl::cvector<QString>* a;
    if(ui->tabWidget->currentWidget()->objectName() == "tab")
    {
        a = &arr;
        tableWidg = ui->tableWidget;
    }
    else
    {
        a = &arr2;
        tableWidg = ui->tableWidget_2;
    }
    QModelIndex index = tableWidg->selectionModel()->currentIndex();
    if(index.row() == -1 || index.column() == -1)
    {
        return;
    }
    a->erase(a->begin()+ index.row(), a->begin() + index.row() + 1);
    Update(ui->tabWidget->currentIndex());
}


void MainWindow::on_actionclear_2_triggered()
{
    ctl::cvector<QString>* a;
    if(ui->tabWidget->currentWidget()->objectName() == "tab")
    {
        a = &arr;
    }
    else
    {
        a = &arr2;
    }
    a->clear();
    Update(ui->tabWidget->currentIndex());
}


void MainWindow::on_actionresize_triggered()
{
    ctl::cvector<QString>* a;
    if(ui->tabWidget->currentWidget()->objectName() == "tab")
    {
        a = &arr;
    }
    else
    {
        a = &arr2;
    }
    Dialog* dial = new Dialog();
    dial->SetLbl("Size");
    dial->setModal(true);
    dial->exec();
    QString res = dial->GetText();
    if(res == "") return;
    size_t size = 0;
    try
    {
        size = res.toULongLong();
        qDebug() << size;
    }
    catch(...)
    {
        QMessageBox::warning(this, "Exception","Error type");
        return;
    }
    Dialog* dial2 = new Dialog();
    dial2->SetLbl("String");
    dial2->setModal(true);
    dial2->exec();
    res = dial2->GetText();
    try
    {
        a->resize(size, res);
    }
    catch(...)
    {
        QMessageBox::warning(this, "Exception","System sucks");
        return;
    }

    Update(ui->tabWidget->currentIndex());
}


void MainWindow::on_actionreserve_triggered()
{
    ctl::cvector<QString>* a;
    if(ui->tabWidget->currentWidget()->objectName() == "tab")
    {
        a = &arr;
    }
    else
    {
        a = &arr2;
    }
    Dialog* dial = new Dialog();
    dial->setModal(true);
    dial->exec();
    QString res = dial->GetText();
    if(res == "") return;
    size_t size = 0;
    try
    {

        size = res.toULongLong();
        qDebug() << size;
    }
    catch(...)
    {
        QMessageBox::warning(this, "Exception","Error type");
        return;
    }
    try
    {
        a->reserve(size);
    }
    catch(...)
    {
        QMessageBox::warning(this, "Exception","System sucks");
        return;
    }

    Update(ui->tabWidget->currentIndex());
}


void MainWindow::on_actionChange_value_triggered()
{
    QTableWidget* tableWidg;
    ctl::cvector<QString>* a;
    if(ui->tabWidget->currentWidget()->objectName() == "tab")
    {
        a = &arr;
        tableWidg = ui->tableWidget;
    }
    else
    {
        a = &arr2;
        tableWidg = ui->tableWidget_2;
    }
    QModelIndex index = tableWidg->selectionModel()->currentIndex();
    if(index.row() == -1 || index.column() == -1)
    {
        return;
    }
    Dialog* dial = new Dialog();
    dial->setModal(true);
    dial->exec();
    QString res = dial->GetText();
    if(res == "") return;
    (*a)[index.row()] = res;
    Update(ui->tabWidget->currentIndex());
}


void MainWindow::on_tabWidget_tabBarClicked(int index)
{
    qDebug() << "Changed tab";
    QString lbl;
    ctl::cvector<QString>* a;
    if(ui->tabWidget->currentIndex() == 1) a = &arr;
    else a = &arr2;
    lbl = QString("size: ") + QString::number(a->size()) + QString(" capacity: ") + QString::number(a->capacity());
    ui->label->setText(lbl);
}


void MainWindow::on_actionSwap_2_triggered()
{
    arr.swap(arr2);
    Update(0);
    Update(1);
}


void MainWindow::on_actionAsign_from_another_triggered()
{
    ctl::cvector<QString>* a;
    ctl::cvector<QString>* b;
    if(ui->tabWidget->currentIndex() == 0)
    {
        a = &arr;
        b = &arr2;
    }
    else
    {
        a = &arr2;
        b = &arr;
    }

    Dialog* dial = new Dialog();
    dial->SetLbl("begin");
    dial->setModal(true);
    dial->exec();
    QString resb = dial->GetText();
    Dialog* dial2 = new Dialog();
    dial2->SetLbl("end");
    dial2->setModal(true);
    dial2->exec();
    QString rese = dial2->GetText();
    if(rese == "" || resb == "") return;
    size_t beg = 0;
    size_t end = 0;
    try
    {
        beg = resb.toULongLong();
        end = rese.toULongLong();
        if(beg>= b->size() || end > b->size() || end <= beg) throw std::exception();
    }
    catch(...)
    {
        QMessageBox::warning(this, "Exception","Error type");
        return;
    }


    try
    {
        a->assign(b->begin() + beg, b->begin() + end);
    }
    catch(...)
    {
        QMessageBox::warning(this, "Exception","System sucks");
        return;
    }
    Update(ui->tabWidget->currentIndex());
}

