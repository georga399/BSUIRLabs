#include <cmath>
extern "C" __declspec(dllexport) bool algo(long double A[], int b, int e)
{
    if(b == e)
    {
        return ((sinl(A[e])>0)? 1 : 0);
    }
    int l = (e - b)/2 + b;
    int r = (e - b)/2 + b+1;  
    return (algo(A , b, l)||algo(A, r, e));
}