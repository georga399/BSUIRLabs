#include <iostream>
#include <string>
long long F(long long n)
{
    if(n%10 > 0)
    {
        return n%10;
    }
    else if(n == 0)
    {
        return 0;
    }
    else 
    {
        return F(n/10);
    }
}
long long S(long long p, long long  q)
{
    long long sum =0;
    for(long long i = p; i<=q; i++)
    {
        sum+=F(i);
    }
    return sum;
}
int main()
{
    while (true)
    {
        
        long long p, q;
        std::cin >> p >> q;
        if (p==-1 && q == -1)
        {
            break;
        }
        std::cout << S(p, q)<<std::endl;
    }
    
}