#include <iostream>
int main()
{
    long double a, b, c, x, y;
    std::cout<<"Input a: ";
    std::cin>>a;
    std::cout<<"Input b: ";
    std::cin>>b;
    std::cout<<"Input c: ";
    std::cin>>c;
    std::cout<<"Input x: ";
    std::cin>>x;
    std::cout<<"Input y: ";
    std::cin>>y;
    if(!(a>0) || !(b>0) || !(c>0) || !(x>0) || !(y>0)){
        std::cout<<"Incorrect input";
        return 0;
    }
    if (a<=x){
        if (b<=y){
            std::cout<<"YES";
            return 0;
        }
        if (c<=y){
            std::cout<<"YES";
            return 0;
        }
    }
    if (b<=x){
        if (a<=y){
            std::cout<<"YES";
            return 0;
        }
        if (c<=y){
            std::cout<<"YES";
            return 0;
        }
    }
    if (c<=x){
        if (b<=y){
            std::cout<<"YES";
            return 0;
        }
        if (a<=y){
            std::cout<<"YES";
            return 0;
        }
    }
    std::cout<<"NO";
    return 0;
}   