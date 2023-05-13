#include <iostream>
#include <cmath>
/*long double mysqrtl(long double val)
{   long double res = 0;
    while(res*res < val)
    {
        res+=0.00001;
    }
    return res;
}*/
long double sgn(long double val)
{
   return (val>0)?(1):((val<0)?(-1):(0));
}
int main()
{   
    const long double PI = acosl(-1);
    long double a, b, c, p, q, x;
    std::cout<<"Input a: ";
    std::cin>>a;
    std::cout<<"Input b: ";
    std::cin>>b;
    std::cout<<"Input c: ";
    std::cin>>c;
    std::cout<<"Input p: ";
    std::cin>>p;
    std::cout<<"Input q: ";
    std::cin>>q;

    //7.1
    std::cout<<"solutions to the equation 7.1 : ";
    long double D;
    long double squarex1, squarex2;
    bool existsquarex1 = 0, existsquarex2 = 0; 
    if(a == 0)
    {
        if(b == 0)
        {
            std::cout<<"any x"<<std::endl;
            existsquarex1 = 1;
            existsquarex2 = 1;
        }
        else
        {
            squarex1 = -c/b;
            if(squarex1>=0)
            {
                std::cout<<sqrtl(squarex1)<<' '<<-sqrtl(squarex1)<<' ';
                existsquarex1 = 1;
            }
        }
    }
    else{
    
    D = b*b - 4*a*c;
    if(D>=0)
    {
        squarex1 = (-b - sqrtl(D))/(2*a);
        squarex1 = (-b + sqrtl(D))/(2*a);
        if(squarex1>=0)
        {
            std::cout<<sqrtl(squarex1)<<' '<<-sqrtl(squarex1)<<' ';
            existsquarex1 = 1;
        }
        if(squarex2>=0)
        {
            std::cout<<sqrtl(squarex2)<<' '<<-sqrtl(squarex2)<<' ';
            existsquarex2 = 1;
        }
    }
    }
    if(existsquarex1 == 0 && existsquarex2 == 0)
    {
        std::cout<<"solutions doesn't exist";
    }

    //7.2
    std::cout<<"solutions to the equation 7.2 : ";
    long double t1, t2;
    D = b*b - 4*a*(c-2*a);
    if (D >= 0)
    {
        t1 = (-b + sqrtl(D))/(2*a);
        t2 = (-b - sqrtl(D))/(2*a);
        D = t1*t1-4;
        if (D>=0){
            std::cout<<(t1 - sqrtl(D))/2<<' '<<(t1 + sqrtl(D))/2<<std::endl;
        }
        if(t1!=t2){
            D = t2*t2-4;
            if (D>=0){
                std::cout<<(t2 - sqrtl(D))/2<<' '<<(t2 + sqrtl(D))/2<<std::endl;
            }   
        }
    }
    else 
    {
        std::cout<<"solutions doesn't exist";
    }
    

    //7.3
    std::cout<<"solutions to the equation 7.3 : ";
    long double Q, R,S, f, T;
    Q = -3*p/9;
    R = 27*q/54; 
    S = Q*Q*Q - R*R;   
    if(S>0)
    {
        f = acos(R/powl(Q, 1/3))/3;
        std::cout<<-2*sqrtl(Q)*cos(f)- a/3<<' '<<-2*sqrtl(Q)*cos(f + 2*PI/3)- a/3<<' '<<-2*sqrtl(Q)*cos(f - 2*PI/3)- a/3<<std::endl;
    }
    else if (S<0)
    {
        f = acosh(R / sqrtl(fabsl(Q*Q*Q)));
        T = sgn(R)*sqrtl(fabsl(Q))*cosh(f);
        std::cout<<-2*T - a/3<<std::endl;
    }
    else 
    {
        T = sgn(R)*sqrtl(fabsl(Q));
        std::cout<<-2*T - a/3<<' '<<T - a/3<<std::endl;
    }
    
}