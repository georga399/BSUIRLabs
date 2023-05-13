#ifndef PRODUCT_H
#define PRODUCT_H
#include <QString>

class Product
{
public:
//    Product();
    Product(QString grp = "", QString cd = "", QString name = "", QString model = "", double cst = 0, int cnt = 0);
    void SetGroup(QString grp);
    void SetCode(QString cd);
    void SetName(QString name);
    void SetModel(QString model);
    void SetCost(double cst);
    void SetCount(int cnt);
    QString GetGroup();
    QString GetCode();
    QString GetName();
    QString GetModel();
    double GetCost();
    int GetCount();
private:
    QString group;
    QString code;
    QString nameOfProduct;
    QString model;
    double cost;
    int count;
};

#endif // PRODUCT_H
