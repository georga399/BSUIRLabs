#include <iostream>
long double myabsl(long double val)
{   
    return (val<0) ? -val : val;
}
long double mysqrtl(long double val)
{   long double res =0;
    while(res<val)
    {
        res+=0.0001;
    }
    return res;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    long double x1, y1, x2, y2, r, R;
    long double dist;
    std::cout<<"Input x1: ";
    std::cin>>x1;
    std::cout<<"Input y1: ";
    std::cin>>y1;
    std::cout<<"Input x2: ";
    std::cin>>x2;
    std::cout<<"Input y2: ";
    std::cin>>y2;
    std::cout<<"Input r: ";
    std::cin>>r;
    std::cout<<"Input R: ";
    std::cin>>R;
    dist = mysqrtl(myabsl(x1 - x2)*myabsl(x1 - x2) + myabsl(y1-y2)*myabsl(y1 - y2));
    if (dist + r <= R)
    {
        std::cout<<"Да";
        return 0;
    }
    if (dist + R <= r)
    {
        std::cout<<"Да, но справедливо обратное для двух фигур";
        return 0;
    }
    if (dist < r + R)
    {
        std::cout<<"Круги пересекаются, но не поглощают друг друга";
        return 0;
    }
    std::cout<<"Ни одно условие не выполнено";
    return 0;
}