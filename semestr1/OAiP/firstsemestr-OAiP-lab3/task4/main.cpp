#include <iostream>
#include <cmath>
int sumofevenpos1(int n)
{
    int h = n/2;
    int S=0;
    for(int i=0; i<=h; i++)
    {
        S+=i*2;
    }
    return S;
}
int sumofeven2(int n)
{
    int h=abs(n/2); //колво членов
    if(n>1)
    {
        return (2 + 2 + 2*(h - 1))*h/2;
    }
    else if(n<-1)
    {
        return -(2 + 2 + 2*(h - 1))*h/2;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int n;
    std::cin>>n;
    //1
    if(n<0)
    {
        std::cout<<-sumofevenpos1(-n);
    }
    else
    {
        std::cout<<sumofevenpos1(n);
    }
    //2
    std::cout<<'\t'<<sumofeven2(n);
    
}