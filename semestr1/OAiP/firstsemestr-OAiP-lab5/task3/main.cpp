#include <iostream>
#include <Windows.h>
int main()
{
    HINSTANCE load = LoadLibrary("libsum.dll");
    typedef int (*sum) (int, int);
    sum Sum = (sum)GetProcAddress(load, "sum"); 
    std::cout << "Hello from main.";
    std::cout << Sum(12,2);
}