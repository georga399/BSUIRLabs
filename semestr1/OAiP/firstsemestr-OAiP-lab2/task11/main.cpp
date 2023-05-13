#include <cmath>
#include <iostream>
int main()
{   setlocale(LC_ALL, "Russian");
    long double R, P, Q;
    std::cout<<"Введите значение радиуса окружности: ";
    std::cin>>R;
    std::cout<<"Введите значение стороны ромба: ";
    std::cin>>P;
    std::cout<<"Введите значение угла в радианах: ";
    std::cin>>Q;
    
    if(R>P*sinl(Q)/2)
    {
        std::cout<<"Шар не проходит в отверстие";
    }
    else
    {
        std::cout<<"Шар пройдёт в отверстие";

    }
    return 0;
}