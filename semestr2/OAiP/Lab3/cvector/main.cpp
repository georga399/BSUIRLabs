#include <iostream>
#include "cvector.h"
int main()
{
    ctl::cvector<int> a;
    a.push_back(5);
    for(auto i: a) std::cout << i << ' ';
}