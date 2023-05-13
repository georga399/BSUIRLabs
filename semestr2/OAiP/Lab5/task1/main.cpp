#include <iostream>
#include <memory>
#include <queue>
#include "cqueue.h"
int main()
{
    std::queue<int> q2;
    ctl::cqueue<int> q;
    for(int i = 0; i<10; i++)
    {
        q.push(i);
    }   
    std::cout << q.front() << ' ' << q.back() << std::endl;
    auto cq = q;
    // std::forward()
    // std::cout << q.size() << ' '<< cq.front() << ' ' << cq.back() << std::endl;
    // for(int i = 0; i<10; i++)
    // {
    //     std::cout << q.front() <<  " size: " << q.size() << std::endl;
    //     q.pop();
    // }
    while (!cq.empty())
    {
        std::cout << cq.front() << std::endl;    
        cq.pop();
    }
    std::cout << "OK" << std::endl;
    
}