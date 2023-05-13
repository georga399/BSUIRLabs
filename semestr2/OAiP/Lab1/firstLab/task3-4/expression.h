#pragma once
#include <iostream>
class Expression
{
    friend bool check_equals(Expression *left, Expression *right);
protected:
    int id_; 
public:
    Expression(/* args */);
    virtual double evaluate() = 0;
    
};

Expression::Expression(/* args */)
{
    id_ = 1;
}
