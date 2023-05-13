#include "calculator.h"
#include "custlist.h"
#include <string>
#include <sstream>
Calculator::Calculator()
{}

QString Calculator::addZero(QString str)
{
    QString res = str;
    char prev = 0;
    for(int i = 0; i<str.size(); i++)
    {
        if(res[i].toLatin1() == '-')
        {
            if(!prev)
            {
                res.insert(i, '0');
                prev = '0';
            }
        }
        else if(res[i].toLatin1() == '(') prev = 0;
        else if(res[i].toLatin1() == ' ') continue;
        else prev = res[i].toLatin1();
    }
    return res;
}

QString Calculator::convertToPostfix(QString str)
{
    str+=" ";
    QString res;
    CustList<char> operations;
    char prev = 0;
    for(int i = 0; i<str.size();i++)
    {
        if(isdigit(str[i].toLatin1()) || str[i] == '.')
        {
            res+=str[i];
            prev = str[i].toLatin1();
            continue;
        }

        else if(str[i].toLatin1() != ' ')
        {
            if(prev)
            {
                res +=" ";
                prev = 0;
            }
            char el = str[i].toLatin1();
            if(operations.empty()) operations.push_front(str[i].toLatin1());
            else if(el == '(') operations.push_front(str[i].toLatin1());
            else if(el == ')')
            {
                while(operations[0] != '(')
                {
                    res += QString(operations[0]) + " ";
                    operations.pop_front();
                }
                operations.pop_front();
            }
            else if(el == '*' || el == '/')
            {
                while(!operations.empty() && (operations[0] == '*' || operations[0] == '/'))
                {
                    res += QString(operations[0]) + " ";
                    operations.pop_front();
                }
                operations.push_front(el);

            }
            else if(el == '+' || el == '-')
            {
                while(!operations.empty() && operations[0]!='(')
                {
                    res += QString(operations[0]) + " ";
                    operations.pop_front();
                }
                operations.push_front(el);
            }
        }
    }
    if(prev) res +=" ";
    while(!operations.empty())
    {
        res += QString(operations[0]) + " ";
        operations.pop_front();
    }

    return res;
}
double Calculator::countPostfix(QString str)
{
    CustList<double> stck;
    std::stringstream ss;
    ss << str.toStdString();
    while(!ss.eof())
    {
        std::string s;
        ss >> s;
        if(s == "+")
        {
            long double sum = stck[0]; stck.pop_front();
            sum += stck[0]; stck.pop_front(); stck.push_front(sum);
        }
        else if(s == "-")
        {
            long double res = - stck[0]; stck.pop_front();
            res += stck[0]; stck.pop_front(); stck.push_front(res);
        }
        else if(s == "*")
        {
            long double res = stck[0]; stck.pop_front();
            res *= stck[0]; stck.pop_front(); stck.push_front(res);
        }
        else if(s == "/")
        {
            long double res = stck[0]; stck.pop_front();
            res = stck[0]/res; stck.pop_front(); stck.push_front(res);
        }
        else
        {
            if(s!="") stck.push_front(std::stold(s));
        }
    }
    return stck[0];
}
