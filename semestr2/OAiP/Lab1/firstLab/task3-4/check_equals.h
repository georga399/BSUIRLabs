#pragma once
#include "binaryoperation.h"
#include "number.h"
#include <iostream>
bool check_equals(Expression *left, Expression *right)
{
    return (left->id_ == right->id_);
    
}