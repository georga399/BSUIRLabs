#include <iostream>
#include <cmath>
unsigned long long f(unsigned long long n)
{
    unsigned long long j = n;
    if(j==1)
    {
        return 1;
    }
    unsigned long long k = 0;
    while(j%2 == 0)
    {
        j /=2;
        k++;
    }
    unsigned long res;
    if(j==n)
    {
        return j + f(n-1);
    }
    else
    return f(j)+(powl(4, k)-1)*j*j/3;
}
int main()
{
    unsigned long long n;
    int t; 
    std::cin>>t;
    for (int i = 0; i<t; i++)
    {
        std::cin >> n;
        std::cout << f(n) << std::endl;
    }
    

}