#include <iostream>
#include <iomanip>
int main(){
    
    long double x;
    long double a, b, c;
    long double res1, res2;
    std::cout<<"Input x: ";
    std::cin>>x;
    a = 23*x*x + 32; // +3 операции
    b = 3*a - 88; // +2 операции
    c = a*x; // + 1 операция
    res1 = b + c;// + 1 операция
    res2 = b - c ;// +1 операция
    std::cout<<std::setprecision(10);
    std::cout<<"23x^3 + 69x^2 + 32x + 8 = "<<res1<<std::endl;
    std::cout<<"-23x^3 + 69x^2 - 32x + 8 = "<<res2<<std::endl;

}