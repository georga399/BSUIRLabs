#include <iostream>
unsigned long long modmult(unsigned long long a, unsigned long b, unsigned long long mod)
{
    unsigned long long res = 0;
    while(b)
    {
        if(b%2==1) res = (res+a)%mod;
        b/=2;
        a=(a+a)%mod;
    }
    return res;
}
unsigned long long modpow(unsigned long long a, unsigned long long b, unsigned long long t)
{
    unsigned long long mod = 1;
    for(int i=0; i<t; i++)
    {
        mod*=10;
    }
    unsigned long long res = 1;
    while(b)
    {
        if(b%2 == 1) res = modmult(res, a, mod);//(res*a)%mod; 
        b/=2;
        a = modmult(a,a,mod);//(a*a)%mod;
    }
    return res;
}
int main()
{
    unsigned long long k, n, t, res, counter;
    counter = 0;
    while (true)
    {
        std::cin >> k >> n >> t;
        if (k == 0 && n==0 && t==0 )
        {
            break;
        }
        res = modpow(k, n, t);
        counter++;
        std::cout << "Case #" << counter <<": " << res << std::endl;
    }
    
    
}