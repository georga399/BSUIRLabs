#include <iostream>
const long double ln2 = 0.69314718056;
const long double PI = 3.14159265358979;
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
// long double convert2PI(long double x)
// {
//     long double t = 2*PI;
//     while(t<x/10)
//     {
//         t*=10;
//     }
//     x = (x-t)/10 - 2*PI*((unsigned long long)((x-t)/(20*PI)));
//     return x;
// }
long double sin(long double x)
{   
    int sign = (x < 0) ? -1 : 1;
    x = myfabsl(x);
    x = x - 2*PI*((unsigned long long)(x/(2*PI)));
    //x = convert2PI(x);
    if (x > PI) 
    { 
        x -= PI; 
        sign *= -1;
    }
    if (x > PI/2) 
    {
        x = PI - x;
    }
    long double sinx = 0;
    
    for(int i=0; i<10; i++)
    {
        sinx+=mypowl(-1, i)*mypowl(x, 2*i+1)/factorial(2*i+1);
    }
    return sign*sinx;
}
long double cos(long double x)
{
    long double cosx = sin(PI/2 - x);
    return cosx;
}
long double ln(long double x)
{
    long double logx = 0;
    x = myfabsl(x);
    // if ( x >= 0 && x <= 2)
    // {
    //     x -= 1;
    //     for ( int i = 1; i < 5000; i += 2 )
    //     {
    //         logx += (mypowl(x, i)/(long double)i - mypowl(x, i+1)/(long double)(i+1));
    //     }
    // }
    // else if ( x > 2 )
    // {
    //     x = (x / (x - 1));
    //     for ( int i = 1; i < 1000; i ++ )
    //     {
    //         logx += 1.0 / ( i*mypowl(x,i) );
    //     }
    // }
    if(x<=2 && x>=0.1)
    {   
        x-=1;
        for ( int i = 1; i < 5000; i += 2 )
        {
            logx += (mypowl(x, i)/(long double)i - mypowl(x, i+1)/(long double)(i+1));
        }
    }else if(x>2)
    {   long double k = 0;
        while (x>2)
        {
            
            x/=2;
            k++;
        }
        
        x-=1;
        for ( int i = 1; i < 5000; i += 2 )
        {
            logx += (mypowl(x, i)/(long double)i - mypowl(x, i+1)/(long double)(i+1));
        }
        logx+=k*ln2;
    }
    else if(x<0.1)
    {   int k = 0;
        while (x<0.1)
        {
            
            x*=2;
            k--;
        }
        
        x-=1;
        for ( int i = 1; i < 5000; i += 2 )
        {
            logx += (mypowl(x, i)/(long double)i - mypowl(x, i+1)/(long double)(i+1));
        }
        logx+=k*ln2;
    }
    return logx;
}
int main()
{
    long double x;
    std::cin >> x;
    long double sinx = sin(x);
    long double cosx = cos(x);
    long double log = ln(x);
    // for(int i = 1; i<10; i++)
    // {
    //     sinx+=mypowl(-1, i-1)*mypowl(x, 2*(i-1)+1)/factorial(2*(i-1)+1);
    //     //cosx+=mypowl(-1, i-1)*mypowl(x, 2*(i-1))/factorial(2*(i-1));
    //     cosx+=mypowl(-1, i-1)*mypowl(PI/2-x, 2*(i-1)+1)/factorial(2*(i-1)+1);
        // log +=mypowl(-1, i-1)*mypowl((myfabsl(x)-1), i)/i;
    // }
    // std::cout<<sinx<<std::endl;
    // std::cout<<cosx<<std::endl;
    std::cout<<log<<std::endl;
    
    if(sinx<=cosx && sinx<=log)
    {
        std::cout << sinx;
        return 0;
    }
    if(cosx<=sinx && cosx<=log)
    {
        std::cout << cosx;
        return 0;
    }
    if(log<=cosx && log<=sinx)
    {
        std::cout << log;
        return 0;
    }
}