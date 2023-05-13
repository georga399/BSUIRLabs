#include <iostream>
#include <cmath>

// long double mypowl(long double val, int exp)
// {
//     long double res = 1;
//     int i=0;
//     do
//     {
//         i++;
//         res*=val;
//     } 
//     while (i<exp);
//     return res;
// }

int main()
{   long double res = 0;
    int n=0;
    //std::cin>>n;
    long double d;
    do
    {
        n++; 
        d = (powl(0.5, n) + powl((long double)(1.0)/3, n));
        res+=d;   
    } 
    while (d>=0.001);
    std::cout<<res;

    
}