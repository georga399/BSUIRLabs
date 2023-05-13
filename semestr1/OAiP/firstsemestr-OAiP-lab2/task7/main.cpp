#include <iostream>
int main()
{
    long double a, b, c, Y;
    int N;
    std::cout<<"Input a: ";
    std::cin>>a;
    std::cout<<"Input b: ";
    std::cin>>b;
    std::cout<<"Input c: ";
    std::cin>>c;
    std::cout<<"Input N: ";
    std::cin>>N;
    switch(N)
    {
        case 2:
            Y = b*c - a*a;
            break;
        case 3:
            Y = a - b*c;
            break;
        case 7:
            Y = a*a +c;
            break;
        case 56:
            Y = b*c;
            break;
        default:
            Y = (a+b)*(a+b)*(a+b);
            break;
    }
    std::cout<<"Y = "<<Y;
}