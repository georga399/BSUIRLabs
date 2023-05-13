#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <QString>
class Calculator
{
public:
    Calculator();
    static QString addZero(QString str);
    static QString convertToPostfix(QString str);
    static double countPostfix(QString str);
};

#endif // CALCULATOR_H
