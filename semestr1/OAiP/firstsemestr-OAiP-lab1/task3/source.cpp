#include <iostream>
#include <iomanip>
int main(){
    long double t;
    long double a;
    long double v0;
    long double s;
    std::cout<<"Enter time: ";
    std::cin>>t;
    std::cout<<"Enter acceleration: ";
    std::cin>>a;
    std::cout<<"Enter initial velocity: ";
    std::cin>>v0;
    s = v0*t + a*t*t/2;
    std::cout<<"s = "<<std::setprecision(10)<<s;
    

}