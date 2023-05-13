#include <iostream>
#include <cmath>
int getlength(long val)
{   int counter = (val>0) ?1: 0;
    while(val>=10)
    {
        val/=10;
        counter++;
    }
    return counter;
}
long sumofdig(long val)
{
    long sum = 0;
    long a = val;
    long b = val%10;
    int l = getlength(val);
    for(int i =0; i<l; i++)
    {
        b = a%10;
        a /=10;
        sum+=pow(b, l);
    }
    return sum;
}
int main()
{   
    long val;
    long t;
    std::cin>>val;
    for(long i = 1; i<=val; i++)
    {
        t = sumofdig(i);
        if (i==t)
        {
            std::cout<<t<<std::endl;
        }
    }
    
}