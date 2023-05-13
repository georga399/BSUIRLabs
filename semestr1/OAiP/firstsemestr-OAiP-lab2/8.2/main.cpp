#include <iostream>
#include <cmath>
const long double PI = acosl(-1);
long double sgn(long double val)
{
   return (val>0)?(1):((val<0)?(-1):(0));
}
void square(long double a, long double b, long double c)
{
    if(a==0 && b==0 && c==0)
    {
        std::cout<<"any x";
        return;
    }
    if(a==0 && b==0 && c!=0)
    {
        std::cout<<" ";
        return;
    }
    if(a==0 && b!=0)
    {
        std::cout<<-c/b<<' ';
        return;
    }
    if (a!=0 && b==0 && c==0)
    {
        std::cout<<0<<' ';
        return;
    }
    if (a!=0 && b!=0 && c==0)
    {
        std::cout<<0<<' '<<-b/a<<' ';
        return;
    }
    if (a!=0 && b!=0 && c!=0)
    {
        long double D = b*b - 4*a*c;
        if(D > 0)
        {
            std::cout<<(-b-sqrtl(D))/(2*a)<<' '<<(-b+sqrtl(D))/(2*a)<<' ';
            return;
        }
        else if(D==0)
        {
            std::cout<<-b/(2*a)<<' ';
            return;
        }
        else 
        {
            std::cout<<" ";
            return;
        }
        std::cout<<"ERROR";
        return;
    }
}
void bisquare(long double a, long double b, long double c)
{
    if (a==0 && b==0 && c==0)
    {
        std::cout<<"any x";
        return;
    }
    if (a==0 && b==0 && c!=0)
    {
        std::cout<<" ";
        return;
    }
    if(a==0 && b!=0)
    {
        long double x2= -c/b;
        if(x2<0){
            std::cout<<" ";
            return;
        }
        else if(x2==0)
        {
            std::cout<<0;
            return;
        }
        else
        {
            std::cout<<sqrt(x2)<<' '<<-sqrt(x2);
            return;
        }
        std::cout<<"ERROR";
        return;
    }
    if(a!=0 && b == 0)
    {
        long double x4 = -c/a;
        if(x4<0){
            std::cout<<" ";
            return;
        }
        else if(x4==0)
        {
            std::cout<<0;
            return;
        }
        else
        {
            std::cout<<-sqrt(sqrt(x4))<<' '<<sqrt(sqrt(x4));
            return;
        }
        std::cout<<"ERROR";
        return;
    }
    if(!(a==0) && !(b==0) && c==0)
    {
        std::cout<<0<<' ';
        long double x2 = -b/a;
        if(x2>0)
        {
            std::cout<<-sqrt(x2)<<' '<<sqrt(x2);

        } 
        return;
    }
    if(a!=0 && b!=0 && c!=0)
    {   long double x21, x22;
        long double D = b*b - 4*a*c;
        if (D<0)
        {
            std::cout<<" ";
            return;
        }
        else if(D==0)
        {
            x21 = -b/(2*a);
            if(x21>0)
            {
                std::cout<<-sqrtl(x21)<<' '<<sqrtl(x21);
                return;
            }
            else if (x21 == 0)
            {
                std::cout<<0;
                return;
            }
        }
        else
        {
            x21=(-b + sqrtl(D))/(2*a);
            x22=(-b - sqrtl(D))/(2*a);
            if(x21>0)
            {
                std::cout<<-sqrtl(x21)<<' '<<sqrtl(x21)<<' ';
                
            }
            if(x22>0)
            {
                std::cout<<-sqrtl(x22)<<' '<<sqrtl(x22)<<' ';
                
            }
            return;
        }
    }
}
void evaluation82(long double a, long double b, long double c)
{
    if(b==0)
    {
        bisquare(a, c, a);
        return;
    }
    if(b!=0 && a ==0)
    {
        std::cout<<0<<' ';
        square(b, c, b);
        return;
    }
    if(b!=0 && a!=0)
    {
        long double t1, t2, D;
        D = b*b - 4*a*(c-2*a);
        if (D<0)
        {
            std::cout<<" ";
            return;
        }   
        else if(D>0)
        {
            t1 = (-b - sqrtl(D))/(2*a);
            t2 = (-b + sqrtl(D))/(2*a);
            square(1, -t1, 1);
            square(1, -t2, 1);
            return;
        } 
        else
        {
            t1 = -b/(2*a);
            square(1, -t1, 1);
            return;
        }
        
    }

}
void evaluation83(long double p, long double q)
{
    if (p == 0 && q == 0)
    {
        std::cout<<0;
        return;
    }
    if (p==0)
    {
        std::cout<<powl(-q, 1/3);
        return;
    }
    if (q==0)
    {
        std::cout<<0<<' ';
        square(1, 0, p);
        return;
    }
    long double Q, R,S, f, T;
    Q = 3*p/9;
    R = -27*q/54; 
    S = Q*Q*Q + R*R;   
    if(S<0)
    {   
        f = acos(R/powl(-Q*Q*Q, 3.0/2));

        // f = acos(R/powl(Q, 1/3))/3;
        std::cout<<2*sqrtl(-Q)*cos(f)<<' '<<2*sqrtl(-Q)*cos(f + 2*PI/3)<<' '<<2*sqrtl(-Q)*cos(f - 2*PI/3)<<std::endl;
    }
    else if (S>0)
    {   if(Q>0)
        {
            f = acosh(fabsl(R)/powl(Q, 3.0/2));
            std::cout<<-2*sgn(R)*sqrtl(Q)*cosh(f)<<' ';
        }
        else if(Q<0)
        {
            f = asinh(fabsl(R)/powl(Q, 3.0/2));
            std::cout<<-2*sgn(R)*sqrtl(fabsl(Q))*sinh(f)<<' ';
        }
        else{
            std::cout<<-1*powl(q, 1.0/3)<<' ';
        }
        // f = acosh(R / sqrtl(fabsl(Q*Q*Q)));
        // T = sgn(R)*sqrtl(fabsl(Q))*cosh(f);
        // std::cout<<-2*T<<std::endl;
    }
    else 
    {
        //T = sgn(R)*sqrtl(fabsl(Q));
        std::cout<<-2*sgn(R)*sqrtl(Q)<<' '<<sgn(R)*sqrtl(Q)<<std::endl;
    }

}
int main()
{
    long double a, b, c, p, q;
    std::cin>>a>>b>>c>>p>>q;
    std::cout<<"evaluation 8.1: ";
    bisquare(a, b, c);
    std::cout<<"\nevaluation 8.2: ";
    evaluation82(a, b, c);
    std::cout<<"\nevaluation 8.3: ";
    evaluation83(p, q);

    return 0;
}