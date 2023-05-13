#include "product.h"


Product::Product(QString grp, QString cd, QString name, QString model, double cst, int cnt)
{
    this->group = grp;
    this->code = cd;
    this->nameOfProduct = name;
    this->model = model;
    this->cost = cst;
    this->count = cnt;
}

void Product::SetGroup(QString grp)
{
    this->group = grp;
}

void Product::SetCode(QString cd)
{
    this->code = cd;
}

void Product::SetName(QString name)
{
    this->nameOfProduct = name;
}

void Product::SetModel(QString model)
{
    this->model = model;
}

void Product::SetCost(double cst)
{
    this->cost = cst;
}

void Product::SetCount(int cnt)
{
    this->count = cnt;
}

QString Product::GetGroup()
{
    return group;
}

QString Product::GetCode()
{
    return code;
}

QString Product::GetName()
{
    return nameOfProduct;
}

QString Product::GetModel()
{
    return model;
}

double Product::GetCost()
{
    return cost;
}

int Product::GetCount()
{
    return count;
}

