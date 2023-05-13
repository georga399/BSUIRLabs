#include <iostream>
int main(){
    long double X, Y;
    std::cin>>X>>Y;
    bool res = X>Y;

    ///1
    res ? std::cout<<X<<std::endl : std::cout<<Y<<std::endl;

    ///2
    std::cout<< ((X>Y) ? X : Y)<<std::endl;
}