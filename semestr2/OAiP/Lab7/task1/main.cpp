#include <iostream>
// #include "cshared_ptr.h"
#include "array_heap.h"
#include <memory>
int main()
{   
    std::cout << "begin" << std::endl;
    array_heap<int> a;
    for(int i = 0; i<10; i++)
    {
        a.insert(i);
    }
    for(int i = 0; i<a.size(); i++)
    {
        std::cout << a[i] << std::endl;
    }
    std::cout << "Start" << std::endl;
    

}
