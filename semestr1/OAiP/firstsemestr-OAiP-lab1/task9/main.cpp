#include <iostream>
int main(){
    long long a, b;
    std::cout<<"Input a: ";
    std::cin>>a;
    std::cout<<"Input b: ";
    std::cin>>b;
    if (a>b){
        b = a^b;
        std::cout<<"b = a xor b = "<<b<<std::endl;
        a = a^b;
        std::cout<<"a = a xor b = "<<a<<std::endl;
        b = a + b;
        std::cout<<"b = a + b = "<<b<<std::endl;
    }
    else {
        a = a^b;
        std::cout<<"a = a xor b = "<<a<<std::endl;
        b = b^a;
        std::cout<<"b = b xor a = "<<b<<std::endl; 
        a = b+a;
        std::cout<<"a = b + a = "<<a<<std::endl;
    }
    return 0;
}