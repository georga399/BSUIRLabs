#ifndef VAR8TASK1_H
#define VAR8TASK1_H

#include <QWidget>
#include "custvector.h"
#include "product.h"
namespace Ui {
class Var8Task1;
}

class Var8Task1 : public QWidget
{
    Q_OBJECT

public:
    explicit Var8Task1(QWidget *parent = nullptr);
    ~Var8Task1();

private slots:

    void on_OpnBtn_clicked();

    void on_SaveBtn_clicked();

    void on_NewBtn_clicked();

    void on_ChangeBtn_clicked();

    void on_DeleteBtn_clicked();

    void on_SortBtn_clicked();

    void on_FindForName_clicked();

private:
    Ui::Var8Task1 *ui;
    CustVector<Product> lst;
    void UpdateTable();
};

#endif // VAR8TASK1_H
