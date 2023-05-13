#include <iostream>
#include <iomanip>
int main(){
    int n;
    double b1;
    double q;
    double s;
    std::cout<<"Your number: ";
    std::cin>>n;
    std::cout<<"Enter b1 : ";
    std::cin>>b1;
    q = (double)1/(n+1);
    s = b1/(1-q);
    std::cout<<"S = "<<std::setprecision(10)<<s<<std::endl;
    }