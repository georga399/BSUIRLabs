#ifndef WIDGTASK2_H
#define WIDGTASK2_H

#include <QWidget>
#include "custvector.h"
#include "product.h"
namespace Ui {
class WidgTask2;
}

class WidgTask2 : public QWidget
{
    Q_OBJECT

public:
    explicit WidgTask2(QWidget *parent = nullptr);
    ~WidgTask2();

private slots:
    void on_LoadFromBtn_clicked();

    void on_SaveToBtn_clicked();

    void on_AddBtn_clicked();

    void on_ChangeBtn_clicked();

    void on_DeleteBtn_clicked();

    void on_FindBtn_clicked();

    void on_SortBtn_clicked();

private:
    Ui::WidgTask2 *ui;
    CustVector<Product> vctr;
    void ChangeTable();
    void SpaceDeleter(QString &str);
    void SortByGroup(int b, int e);
    void SortByName(int b, int e);
    void SortByCode(int b, int e);
    void SortByCost(int b, int e);
    void (WidgTask2::*sorting)(int, int);

};

#endif // WIDGTASK2_H
