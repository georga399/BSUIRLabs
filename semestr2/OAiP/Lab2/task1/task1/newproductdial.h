#ifndef NEWPRODUCTDIAL_H
#define NEWPRODUCTDIAL_H

#include <QDialog>
#include "product.h"
namespace Ui {
class NewProductDial;
}

class NewProductDial : public QDialog
{
    Q_OBJECT

public:
    explicit NewProductDial(QWidget *parent = nullptr);
    bool CheckInput();
    Product GetProd();
    ~NewProductDial();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::NewProductDial *ui;
    bool validInput = 0;
};

#endif // NEWPRODUCTDIAL_H
