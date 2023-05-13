#include <iostream>
int main (){
    long double a;
    long double b;
    long double c;
    std::cin>>a;
    std::cin>>b;
    std::cin>>c;
    if (a<b+c && b<a+c && c<a+b){
        std::cout<<"YES";
    }else std::cout<<"NO";
}