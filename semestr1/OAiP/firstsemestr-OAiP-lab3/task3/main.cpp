#include <iostream>
#include <cmath>
int main()
{
    const long double PI = acosl(-1);
    long double A = 0;
    long double B = PI/2;
    long double M = 20;
    long double H = (B - A)/M;
    long double X = A;
    for (int i = 1; X<=B; i++)
    {
        
        std::cout<<sinl(X) - cosl(X)<<std::endl;
        X = A + i*H;
    }
    
}