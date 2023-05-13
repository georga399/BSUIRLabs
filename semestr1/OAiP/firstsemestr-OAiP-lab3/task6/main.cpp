#include <iostream>
#include <cmath>
int main()
{   
    setlocale(LC_ALL, "Russian");
    int n;
    int i=0;
    std::cout<<"На сколько частей делить облатсь поиска: ";
    std::cin>>n;
    long double d = 1.0;
    long double l;
    long double res = 1e9;
    long double t;
    long double x;
    while(i<=n)
    {   
        l = (d/n)*i;
        t = sinl(l) + cosl(l) - 2*atan(l);
        if(fabsl(res)>fabsl(t))
        {
            res = t;
            x = l;
        }
        //std::cout<<t<<'\t'<<l<<std::endl;
        i++;
        
    }
    std::cout<<"Минимальное значение функции: "<<res<<"\tКорень: "<<x<<std::endl;
    // std::cout<<sinl(1) + cosl(1) - 2*atan(1);
    
    
    
}