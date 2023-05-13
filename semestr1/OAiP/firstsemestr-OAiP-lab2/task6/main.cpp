#include <iostream>
int main()
{
    long double Z, a, b, c, d;
    std::cout<<"Input a: ";
    std::cin>>a;
    std::cout<<"Input b: ";
    std::cin>>b;
    std::cout<<"Input c: ";
    std::cin>>c;
    std::cout<<"Input d: ";
    std::cin>>d;
    if (c>=d && a<d)
    {
        Z= a +b/c;
    }
    else if (c<d && a>=d)
    {
        Z=a-b/c;
    }
    else 
    {
        Z=0;
    }
    std::cout<<"Z = "<<Z;
    return 0;
}