#include <iostream>
#include <iomanip>
#include <cmath>
int main (){
    //1
    long double A, S, b,x, D;
    std::cout<<"Input x: ";
    std::cin>>x;
    std::cout<<"Input D: ";
    std::cin>>D;
    b = x + D;
    A = D*x/b;
    S = (A*A + b*cos(x))/(powl(D, 3)+ (A + D -b));
    std::cout<<std::setprecision(10)<<"Вариант 1. S = "<<S<<std::endl;

    //2
    long double K, p, Y, B, C;
    std::cout<<"Input K: ";
    std::cin>>K;
    std::cout<<"Input p: ";
    std::cin>>p;
    std::cout<<"Input C: ";
    std::cin>>C;
    B = exp(K);
    A = x + sin(p);
    Y = 1 + K*K/(2*A*B) - B + D*C;
    std::cout<<"Вариант 2. Y = "<<Y<<std::endl;

    //3
    long double Q,n;
    std::cout<<"Input n:";
    std::cin>>n;
    B = cos(x);
    C = p-n;
    Q = B*B /(K*D)+ B*powl(C, 3);
    std::cout<<"Вариант 3. Q = "<<Q<<std::endl;

    //4
    long double y, z, T;
    std::cout<<"Input y:";
    std::cin>>y;
    std::cout<<"Input z:";
    std::cin>>z;
    A=x-y;
    B=sqrt(z);
    T = cos(x)+ A*A/(K-C*D) - B;
    std::cout<<"Вариант 4. T = "<<T<<std::endl;

    //5
    long double m;
    std::cout<<"Input m:";
    std::cin>>m;
    A= fabs(n+m);
    D = tan(x);
    Y = 1,29 + K/A + D*D;
    std::cout<<"Вариант 5. Y = "<<Y<<std::endl;

    //6
    A = x+ y;
    D= fabs(C-A);
    S = 10,1 + A/C + D/(K*K);
    std::cout<<"Вариант 6. S = "<<S<<std::endl;
    
    //7
    long double h;
    std::cout<<"Input h:";
    std::cin>>h;
    A = x-p;
    B=log(h);
    Y = 0,78*B + powl(A, 3)/(K*C*D);
    std::cout<<"Вариант 7. Y = "<<Y<<std::endl;

    //8
    long double d;
    std::cout<<"Input d:";
    std::cin>>d;
    A=log10(x);
    B = x + exp(d);
    Y = (A+B)- C*C/K;
    std::cout<<"Вариант 8. Y = "<<Y<<std::endl;

    //9
    A = sin(x) - z;
    B = fabs(p-x);
    Y= (A+B)*(A+B) - K/(C*D);
    std::cout<<"Вариант 9. Y = "<<Y<<std::endl;

    //10
    long double k;
    std::cout<<"Input k:";
    std::cin>>k;
    A=log(x) - k;
    B = sqrt(z);
    Y = D*D + C*C/(0,75*A)+B;
    std::cout<<"Вариант 10. Y = "<<Y<<std::endl;


}
