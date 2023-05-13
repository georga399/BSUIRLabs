#include <iostream>
int main(){
    long long X, Y;
    long double A, B, C, K;
    std::cout<<"Введите X: ";
    std::cin>>X;
    std::cout<<"Введите Y: ";
    std::cin>>Y;
    std::cout<<"Введите A: ";
    std::cin>>A;
    std::cout<<"Введите B: ";
    std::cin>>B;
    std::cout<<"Введите C: ";
    std::cin>>C;
    std::cout<<"Введите K: ";
    std::cin>>K;
    if (X==Y){
        X=0;
        Y=0;
    }
    if (X > Y) Y = 0;
    if (Y > X) X = 0;
    if (A > B && A > C){
        A -=K;
    }else if(B > A && B > C){
        B -= K;
    }
    else {
        C-=K;
    }
    std::cout<<"X = "<<X<<std::endl;
    std::cout<<"Y = "<<Y<<std::endl;
    std::cout<<"A = "<<A<<std::endl;
    std::cout<<"B = "<<B<<std::endl;
    std::cout<<"C = "<<C<<std::endl;
   
}