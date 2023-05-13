#include <iostream>
int main()
{   int i = 1;
    int a, b;
    int res=0;
    while(i<=30)
    {
        a = (i%2 == 0)? i/2 : i;
        b = (i&2 == 0)? i*i*i : i*i;
        res+= (a-b)*(a-b);
        i++;
    }
    std::cout<<res;
}