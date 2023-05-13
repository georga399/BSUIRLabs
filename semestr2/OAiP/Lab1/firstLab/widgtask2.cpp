#include "widgtask2.h"
#include "ui_widgtask2.h"
#include <fstream>
#include <QFileDialog>
#include <QMessageBox>
#include <string>
#include "dialogfindtask2.h"
WidgTask2::WidgTask2(QWidget *parent) :QWidget(parent),
    ui(new Ui::WidgTask2)
{
    ui->setupUi(this);
    ui->spinBox->setMinimum(1);
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setShowGrid(false);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Group" << "Code" << "Name" << "Model" << "Cost" << "Count" );
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

WidgTask2::~WidgTask2()
{
    delete ui;
}

void WidgTask2::on_LoadFromBtn_clicked()
{
    QString path = "";
    while(true)
    {
        path = QFileDialog::getOpenFileName(0, "Открыть", "", "*txt");
        if(path!="")
        {
            while(vctr.size())
            {
                vctr.pop_back();
            }
            std::fstream ftxt;
            ftxt.open(path.toStdString(), std::ios::in);
            if(ftxt.is_open())
            {
                int s;
                ftxt>>s;
                if(ftxt.bad() || ftxt.fail() || ftxt.eof())
                {
                    QMessageBox::warning(this, "Exception","Error type");
                    continue;

                }
                int i = 0;
                for(; i<s; i++)
                {
                    Product temp;
                    std::string tstr;
                    ftxt>>tstr;
                    if(ftxt.bad() || ftxt.fail() || ftxt.eof())
                    {
                        QMessageBox::warning(this, "Exception","Error type");
                        while(vctr.size())
                        {
                            vctr.pop_back();
                        }
                        break;

                    }
                    temp.SetGroup(QString::fromStdString(tstr));
                    ftxt>>tstr;
                    if(ftxt.bad() || ftxt.fail() || ftxt.eof())
                    {
                        QMessageBox::warning(this, "Exception","Error type");
                        while(vctr.size())
                        {
                            vctr.pop_back();
                        }
                        break;

                    }
                    temp.SetCode(QString::fromStdString(tstr));
                    ftxt>>tstr;
                    if(ftxt.bad() || ftxt.fail() || ftxt.eof())
                    {
                        QMessageBox::warning(this, "Exception","Error type");
                        while(vctr.size())
                        {
                            vctr.pop_back();
                        }
                        break;

                    }
                    temp.SetName(QString::fromStdString(tstr));
                    ftxt>>tstr;
                    if(ftxt.bad() || ftxt.fail() || ftxt.eof())
                    {
                        QMessageBox::warning(this, "Exception","Error type");
                        while(vctr.size())
                        {
                            vctr.pop_back();
                        }
                        break;

                    }
                    temp.SetModel(QString::fromStdString(tstr));
                    double cost;
                    ftxt>>cost;
                    if(ftxt.bad() || ftxt.fail() || ftxt.eof())
                    {
                        QMessageBox::warning(this, "Exception","Error type");
                        while(vctr.size())
                        {
                            vctr.pop_back();
                        }
                        break;

                    }
                    temp.SetCost(cost);
                    int count;
                    ftxt>>count;
                    if(ftxt.bad() || ftxt.fail())
                    {
                        QMessageBox::warning(this, "Exception","Error type");
                        while(vctr.size())
                        {
                            vctr.pop_back();
                        }
                        break;

                    }
                    temp.SetCount(count);
                    vctr.push_back(temp);
                }
                ftxt.close();
                if(i == s)
                {
                    break;

                }
            }
            else
            {
              QMessageBox::warning(this, "Exception","Cannot open file");
            }

        }
        else
        {
            break;
        }
    }
    ChangeTable();
}

void WidgTask2::ChangeTable()
{
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Group" << "Code" << "Name" << "Model" << "Cost" << "Count" );
    for(int i = 0; i<vctr.size(); i++)
    {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(vctr[i].GetGroup()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(vctr[i].GetCode()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(vctr[i].GetName()));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(vctr[i].GetModel()));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::number(vctr[i].GetCost())));
        ui->tableWidget->setItem(i, 5, new QTableWidgetItem(QString::number(vctr[i].GetCount())));
    }
}


void WidgTask2::on_SaveToBtn_clicked()
{
    QString path = "";
    path = QFileDialog::getOpenFileName(0, "Save", "", "*txt");
    if(path!="")
    {
        std::fstream ftxt;
        ftxt.open(path.toStdString(), std::ios::out|std::ios::trunc);
        if(ftxt.is_open())
        {
            ftxt<<vctr.size();
            for(int i = 0; i<vctr.size(); i++)
            {
                ftxt<<vctr[i].GetGroup().toStdString() << ' ' << vctr[i].GetCode().toStdString() << ' '<< \
                      vctr[i].GetName().toStdString() << ' ' << vctr[i].GetModel().toStdString() << ' ' << \
                      vctr[i].GetCost() << ' ' << vctr[i].GetCount() << std::endl;
            }
            ftxt.close();
        }
    }
}



void WidgTask2::on_AddBtn_clicked()
{
    QString group = ui->GroupEdit->text();
    QString code = ui->CodeEdit->text();
    QString name = ui->NameEdit->text();
    QString model = ui->ModelEdit->text();
    SpaceDeleter(group);
    SpaceDeleter(code);
    SpaceDeleter(name);
    SpaceDeleter(model);
    if(group=="")
    {
        QMessageBox::warning(this, "Exception","Enter group");

    }
    else if(code=="")
    {
        QMessageBox::warning(this, "Exception","Enter code");
    }
    else if(name == "")
    {
        QMessageBox::warning(this, "Exception","Enter name");

    }
    else if(model == "")
    {
        QMessageBox::warning(this, "Exception","Enter model");

    }
    else
    {
        Product temp(group, code, name, model, ui->doubleSpinBox->value(), ui->spinBox->value() );
        vctr.push_back(temp);

    }
    ChangeTable();
}

void WidgTask2::SpaceDeleter(QString &str)
{
    while(!str.isEmpty() && str[str.size()-1] == ' ')
        str.erase(str.end()-1, str.end());
}

void WidgTask2::on_ChangeBtn_clicked()
{
    if(ui->tableWidget->currentColumn() != -1 && ui->tableWidget->currentRow() != -1)
    {
        QString group = ui->GroupEdit->text();
        QString code = ui->CodeEdit->text();
        QString name = ui->NameEdit->text();
        QString model = ui->ModelEdit->text();
        SpaceDeleter(group);
        SpaceDeleter(code);
        SpaceDeleter(name);
        SpaceDeleter(model);
        if(ui->tableWidget->currentColumn() == 0 && group!="")
        {
            vctr[ui->tableWidget->currentRow()].SetGroup(group);
        }
        else if(ui->tableWidget->currentColumn() == 1 && code!="")
        {
            vctr[ui->tableWidget->currentRow()].SetCode(code);
        }
        else if(ui->tableWidget->currentColumn() == 2 && name!="")
        {
            vctr[ui->tableWidget->currentRow()].SetName(name);
        }
        else if(ui->tableWidget->currentColumn() == 3 && model!="")
        {
            vctr[ui->tableWidget->currentRow()].SetModel(model);
        }
        else if(ui->tableWidget->currentColumn() == 4)
        {
            vctr[ui->tableWidget->currentRow()].SetCost(ui->doubleSpinBox->value());
        }
        else if(ui->tableWidget->currentColumn() == 5)
        {
            vctr[ui->tableWidget->currentRow()].SetCount(ui->spinBox->value());
        }

    }
    ChangeTable();
}


void WidgTask2::on_DeleteBtn_clicked()
{
    if((ui->tableWidget->currentColumn() != -1 && ui->tableWidget->currentRow() != -1))
    {
        Product temp = vctr[ui->tableWidget->currentRow()];
        for(int i = 0; i<vctr.size(); i++)
        {
            if(temp.GetCode() == vctr[i].GetCode() && temp.GetGroup() == vctr[i].GetGroup() && temp.GetName() == vctr[i].GetName() && temp.GetModel() == vctr[i].GetModel() && temp.GetCost() == vctr[i].GetCost() && temp.GetCount() == vctr[i].GetCount())
            {
                vctr.erase(i);
                break;
            }
        }
    }
    ChangeTable();

}


void WidgTask2::on_FindBtn_clicked()
{
    DialogFindTask2 dial;
    dial.setModal(true);
    dial.exec();
    QString group = dial.GetGroup();
    QString name = dial.GetName();
    QString model = dial.GetModel();
    SpaceDeleter(group);
    SpaceDeleter(name);
    SpaceDeleter(model);
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Group" << "Code" << "Name" << "Model" << "Cost" << "Count" );
    int k = 0;
    for(int i = 0; i<vctr.size(); i++)
    {
        if((group=="" || group == vctr[i].GetGroup()) && (name=="" || name == vctr[i].GetName()) && (model=="" || model == vctr[i].GetModel()))
        {
            ui->tableWidget->insertRow(k);
            ui->tableWidget->setItem(k, 0, new QTableWidgetItem(vctr[i].GetGroup()));
            ui->tableWidget->setItem(k, 1, new QTableWidgetItem(vctr[i].GetCode()));
            ui->tableWidget->setItem(k, 2, new QTableWidgetItem(vctr[i].GetName()));
            ui->tableWidget->setItem(k, 3, new QTableWidgetItem(vctr[i].GetModel()));
            ui->tableWidget->setItem(k, 4, new QTableWidgetItem(QString::number(vctr[i].GetCost())));
            ui->tableWidget->setItem(k, 5, new QTableWidgetItem(QString::number(vctr[i].GetCount())));
            k++;
        }
    }
}

void WidgTask2::SortByGroup(int b, int e)
{
    int l = b, r = e;
      QString piv = vctr[(l + r) / 2].GetGroup();
      while (l <= r)
      {
        while (vctr[l].GetGroup() < piv)
          l++;
        while (vctr[r].GetGroup() > piv)
          r--;
        if (l <= r)
          std::swap (vctr[l++], vctr[r--]);
      }
      if (b < r)
        SortByGroup(b, r);
      if (e > l)
        SortByGroup(l, e);
}
void WidgTask2::SortByName(int b, int e)
{
    int l = b, r = e;
      QString piv = vctr[(l + r) / 2].GetName();
      while (l <= r)
      {
        while (vctr[l].GetName() < piv)
          l++;
        while (vctr[r].GetName() > piv)
          r--;
        if (l <= r)
          std::swap (vctr[l++], vctr[r--]);
      }
      if (b < r)
        SortByName(b, r);
      if (e > l)
        SortByName(l, e);
}
void WidgTask2::SortByCode(int b, int e)
{
    int l = b, r = e;
      QString piv = vctr[(l + r) / 2].GetCode();
      while (l <= r)
      {
        while (vctr[l].GetCode() < piv)
          l++;
        while (vctr[r].GetCode() > piv)
          r--;
        if (l <= r)
          std::swap (vctr[l++], vctr[r--]);
      }
      if (b < r)
        SortByCode(b, r);
      if (e > l)
        SortByCode(l, e);
}
void WidgTask2::SortByCost(int b, int e)
{
    int l = b, r = e;
      double piv = vctr[(l + r) / 2].GetCost();
      while (l <= r)
      {
        while (vctr[l].GetCost() < piv)
          l++;
        while (vctr[r].GetCost() > piv)
          r--;
        if (l <= r)
          std::swap (vctr[l++], vctr[r--]);
      }
      if (b < r)
        SortByCost(b, r);
      if (e > l)
        SortByCost(l, e);
}

void WidgTask2::on_SortBtn_clicked()
{
    if(vctr.size()>1)
    {
        SortByGroup(0, vctr.size()-1);
        int b = 0;
        if(ui->comboBox->currentIndex() == 0)
        {
            this->sorting = &WidgTask2::SortByCode;
        }
        else if(ui->comboBox->currentIndex() == 1)
        {
            this->sorting = &WidgTask2::SortByName;
        }
        else if(ui->comboBox->currentIndex() == 2)
        {
            this->sorting = &WidgTask2::SortByCost;
        }
        int i = 1;
        for(; i<vctr.size(); i++)
        {
            if(vctr[i].GetGroup() != vctr[i-1].GetGroup())
            {
                (this->*sorting)(b, i-1);
                b=i;
            }
        }
        if(i-1!=b) (this->*sorting)(b, i-1);

    }
    ChangeTable();
}

