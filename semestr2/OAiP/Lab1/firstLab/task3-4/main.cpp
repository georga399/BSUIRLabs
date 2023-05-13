#include "number.h"
#include "binaryoperation.h"
#include "check_equals.h"
#include <iostream>
int main()
{
    Expression* sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
    Expression* expr = new BinaryOperation(new Number(3), '+', sube);
    std::cout << expr->evaluate() << std::endl;
    Expression *ex1 = new Number();

    std::cout << check_equals(sube, expr) << std::endl;
    std::cout << check_equals(ex1, sube) << std::endl;
    delete expr;

}