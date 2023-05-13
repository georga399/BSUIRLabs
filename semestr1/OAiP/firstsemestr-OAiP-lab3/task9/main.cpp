#include <iostream>
int mypow(int val, int exp)
{
    int res =1;
    for(int i=0; i<exp; i++)
    {
        res*=val;
    }
    return val;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    int a, n;
    int S = 0;
    std::cout<<"Введите n(Количество элементов): ";
    std::cin>>n;
    std::cout<<"Введите a(Первый член последовательности): ";
    std::cin>>a;
    for (int i = 1; i<=n; i++)
    {
        //std::cout<<i<<std::endl;
        S+=mypow(2, i-1)*mypow(-1, i-1)*a;
    }
    std::cout<<"Сумма последовательности равна "<<S;
}