#ifndef DIALOGFINDEDPRODUCTS_H
#define DIALOGFINDEDPRODUCTS_H

#include <QDialog>
#include "custvector.h"
#include "product.h"
namespace Ui {
class DialogFindedProducts;
}

class DialogFindedProducts : public QDialog
{
    Q_OBJECT

public:
    explicit DialogFindedProducts(CustVector<Product> *lst, QWidget *parent = nullptr);
    ~DialogFindedProducts();

private:
    Ui::DialogFindedProducts *ui;
    CustVector<Product> *lst;
};

#endif // DIALOGFINDEDPRODUCTS_H
