#pragma once
#include "../../Lab5/task2/cdeque.h"
template <typename T>
class cstack: private ctl::cdeque<T>
{   
public:
    void pop()
    {
        this->pop_back();
    }
    void push(T val)
    {
        this->push_back(val);
    }
    size_t size()
    {
        return ctl::cdeque<T>::size();
    }
    bool empty()
    {
        return ctl::cdeque<T>::empty();
    }
    T& top()
    {
        if(this->size()==0) throw std::out_of_range("Stack is empty");
        return this->operator[](this->size() - 1);
    }  
};