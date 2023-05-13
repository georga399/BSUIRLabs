#include <iostream>
int main(){
    int h1;
    int min1;
    int h2;
    int min2;
    int min;
    int h;
    std::cout<<"Input h1: ";
    std::cin>>h1;
    std::cout<<"Input min1: ";
    std::cin>>min1;
    std::cout<<"Input h2: ";
    std::cin>>h2;
    std::cout<<"Input min2: ";
    std::cin>>min2;
    min1 = h1*60 + min1;
    min2 = h2*60 + min2;
    min = min2 - min1;
    if (!(min>0)){
        std::cout<<"ERROR";
        return 0;
    }
    h = min/60;
    min = min%60;
    std::cout<<h<<"h "<<min<<"min";
    return 0;
}