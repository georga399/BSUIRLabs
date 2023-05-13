#include <iostream>
#include <iomanip>
int main(){
    double a1;
    double a100;
    int n;
    double d;
    double s;
    std::cin>>a1;
    std::cin>>a100;
    std::cin>>n;
    d = (a100 - a1)/99;
    std::cout<<std::setprecision(8)<<d<<std::endl;
    s = (2*a1 + d*(10+n-1))*(n+10)/2;
    std::cout<<std::setprecision(8)<<s;
}