#include <iostream>
#include <math.h>
int main()
{
    long double a, z, x, f, y;
    int n;
    std::cout<<"Input a: ";
    std::cin>>a;
    std::cout<<"Input z: ";
    std::cin>>z;
    std::cout<<"Choose function \nf(x)=2x - enter 1 \nf(x)=x^3 - enter 2 \nf(x)=x/3 - enter 3\n";
    std::cin>>n;
    if(z<1)
    {
        x= z*z;
    }
    else
    {
        x = z+1;
    }
    switch(n)
    {
        
        case 1:
            f = 2*x;
            std::cout<<"You choose f(x)=2x\n";
            break;
        case 2:
            f = x*x*x;
            std::cout<<"You choose f(x)=x^3\n";
            break;
        case 3:
            f = x/3;
            std::cout<<"You choose f(x)=x/3\n";
            break;
        default:
            return 0;
    }
    y = a*log(1 + powl(x, 1/5)) + cosl(f+1)*cosl(f+1);
    std::cout<<"y = "<<y;
    
}