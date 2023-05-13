#pragma once
#include "expression.h"
class Number: public Expression
{
private:
    double val;
    
public:
    Number(double val = 0);
    double evaluate() override;
    
};

Number::Number(double val)
{
    this->val = val;
    id_ = 2;
}

double Number::evaluate()
{
    return val;
}

