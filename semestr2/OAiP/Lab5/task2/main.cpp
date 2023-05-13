#include <iostream>
#include <deque>
#include "cdeque.h"
int main()
{
    ctl::cdeque<double> cd;
    for(int i = 0; i<100; i++)
    {
        cd.push_front(i);
    }
    auto it = cd.end();
    --it;
    for(;it!=cd.begin() ;--it)
    {
        std::cout << *it.data() << std::endl;
    }
    std::cout << *it.data() << std::endl;
    std::cout << *(it+10).data() << std::endl;
    it = cd.end();
    std::cout << *(it-20).data()  << std::endl;
    // for(int i = 0; i<cd.size(); i++)
    // {
    //     std::cout << cd[i] << std::endl;
    // }
    // std::cout << "^^^^^^^^^^^^" << std::endl;
    // for(int i = 0; i<95; i++)
    // {
    //     cd.pop_front();
    // }
    // for(int i = 0; i<20; i++)
    // {
    //     cd.push_front(i);
    // }
    // for(int i = 0; i<cd.size(); i++)
    // {
    //     std::cout << cd[i] << std::endl;
    // }
    // std::cout << "Ok";    
}