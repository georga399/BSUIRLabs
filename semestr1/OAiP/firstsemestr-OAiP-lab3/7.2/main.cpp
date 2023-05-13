#include <iostream>
#include <iomanip>
#include <cmath>
long double mypowl(long double val, int exp)
{
    long double res=1;
    for(int i = 0; i<exp; i++)
    {
        res*=val;
    }
    if ( exp<0)
    {
        for(int i = 0; i<exp; i++)
        {
            res/=val;
        }  
    }
    return res;
}
int factorial(int N)
{
	int F = 1; 
	
	for(int i=1; i<=N; ++i)
	{
		F *= i; 
	}
	return F; 
}
long double myfabsl(long double val)
{
    return (val<0)? -val : val;
}
int main()
{
    long double x;
    std::cin>>x;
    long double sinx = 0, cosx = 0, log = 0;
    for(int i = 1; i<10; i++)
    {
        sinx+=mypowl(-1, i-1)*mypowl(x, 2*(i-1)+1)/factorial(2*(i-1)+1);
        cosx+=mypowl(-1, i-1)*mypowl(x, 2*(i-1))/factorial(2*(i-1));
        log +=mypowl(-1, i-1)*mypowl((myfabsl(x)-1), i)/i;
    }
    std::cout<<sinx<<std::endl;
    std::cout<<cosx<<std::endl;
    std::cout<<log<<std::endl; 
    if(sinx<=cosx && sinx<=log)
    {
        std::cout<<sinx;
        return 0;
    }
    if(cosx<=sinx && cosx<=log)
    {
        std::cout<<cosx;
        return 0;
    }
    if(log<=cosx && log<=sinx)
    {
        std::cout<<log;
        return 0;
    }
}