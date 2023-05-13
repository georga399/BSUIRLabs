#include <iostream>
#include <math.h>
#include <iomanip>
int main(){
    double h;
    double t;
    std::cout<<"Enter height: ";
    std::cin>>h;
    t=sqrt(h*2/9.8);
    std::cout<<"falling time is "<<std::setprecision(10)<<t;

}
