#pragma once
#include "expression.h"
class BinaryOperation : public Expression 
{
private:
    Expression *left;
    Expression *right;
    char operation;
public:
    BinaryOperation(/* args */);
    BinaryOperation(Expression *left, char sign, Expression *right);
    double evaluate() override;
    ~BinaryOperation();
};

BinaryOperation::BinaryOperation(/* args */)
{
    left = nullptr;
    right = nullptr;
    operation = 0;
    id_ = 3;
}

BinaryOperation::BinaryOperation(Expression *left, char sign, Expression *right)
{
    this->left = left;
    this->right = right;
    operation = sign;
}

double BinaryOperation::evaluate()
{
    if(operation == '+')
    {
        return left->evaluate() + right->evaluate();
    }
    else if(operation == '-')
    {
        return left->evaluate() - right->evaluate();
    }
    else if(operation == '*')
    {
        return left->evaluate() * right->evaluate();
    }
    else if(operation == '/')
    {
        return left->evaluate() / right->evaluate();
    }
    else return DBL_MIN;
}

BinaryOperation::~BinaryOperation()
{
    delete left;
    delete right;
}
