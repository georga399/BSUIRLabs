#include <iostream>
#include <iomanip>
//#include <cmath>

long double myfabsl(long double val)
{
    return (val<0 ? -val : val);
}

long double mysqrtl(long double val)
{
    long double sqrt = 0;
    while (sqrt*sqrt < val)
    {
        sqrt+=0.00001;
    }
    return sqrt;
}

int main()
{   setlocale(LC_ALL, "Russian");
    long double k, x, y;
    long double l1 = -1, l2 = -1, l3 = -1, l4 = -1;
    std::cin >> k >> x >> y;
    if (k < 0)
    {
        k *= -1;
        x *= -1;
        y *= -1;
    } 
    if (k == 0)
    {
        std::cout<<"K = 0";
        return 0;
    }
    if (!(y >= 0 && y <= k && x >= 0 && x <= k))
    {
        std::cout<<"Точка лежит за пределами квадрата."<<std::endl;
    }
    if (y >= 0 && y <= k)
    {
        l1 = myfabsl(x);
        l3 = myfabsl(k - x);
    }
    if (x >= 0 && x <= k)
    {
        l2 = myfabsl(y);
        l4 = myfabsl(k - y);
    }
    if (l1 == -1)
    {
        l1 = mysqrtl((y - k) * (y - k) + x * x);
    }
    if (l2 == -1)
    {
        l2 = mysqrtl((y - k) * (y - k) + (k - x) * (k - x));
    }
    if (l3 == -1)
    {
        l3 = mysqrtl(y * y + (k - x) * (k - x));
    }
    if (l4 == -1)
    {
        l4 = mysqrtl(y * y + x * x);
    }
    
   // std::cout << std::setprecision(22);
    std::cout<<"Наименьшее расстояние от точки до стороны квадрата равно ";
    if (l1 <= l2 && l1 <= l3 && l1 <= l4)
    {
        std::cout << l1;
        return 0;
    }
    if (l2 <= l1 && l2 <= l3 && l2 <= l4)
    {
        std::cout << l2;
        return 0;
    }
    if (l3 <= l2 && l3 <= l1 && l3 <= l4)
    {
        std::cout << l3;
        return 0;
    }
    if (l4 <= l2 && l4 <= l3 && l4 <= l1)
    {
        std::cout << l4;
        return 0;
    }
}