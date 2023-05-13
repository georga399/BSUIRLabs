#pragma once
#include "cshared_ptr.h"
#include <stdexcept>
// #include <memory>
template <typename T>
class array_heap
{
private:
    ctl::cshared_ptr<T[]> arr;
    size_t _capacity;
    size_t _length;
public:
    array_heap(int n = 0);
    void insert(T val);
    void heapify(int i);
    void build_heap();
    size_t capacity();
    size_t size();
    void reserve(int n);
    T operator[](int i);
};
template <typename T>
array_heap<T>::array_heap(int n)
{
    // arr = std::shared_ptr<T[]>(new T[n]);
    arr = ctl::make_cshared<T[]>(n);
    _capacity = n;
    _length = 0;
}
template <typename T>
size_t array_heap<T>::capacity()
{
    return _capacity;
}
template <typename T>
size_t array_heap<T>::size()
{
    return _length;
}
template <typename T>
void array_heap<T>::reserve(int n)
{
    if(n>_capacity)
    {
        auto t = ctl::make_cshared<T[]>(n);
        for(int i = 0; i<_length; i++)
        {
            t[i] = arr[i];
        }
        arr = t;
    }
}
template <typename T>
T array_heap<T>::operator[](int i)
{
    return arr[i];
}
template <typename T>
void array_heap<T>::insert(T val)
{
    if(_length == _capacity) reserve(_length*2 + 1);
    arr[_length] = val;
    int i = _length;
    while(i>0 && arr[i] > arr[(i-1)/2]) 
    {
        std::swap(arr[i], arr[(i-1)/2]);
        i = (i-1)/2;
    }
    _length++;
}

template <typename T>
void array_heap<T>::heapify(int i)
{
    if(i < 0 || i>=_length) throw std::out_of_range("Bad heapify");
    int l = 2*i + 1;
    int r = 2*i + 2;
    int largest = i;
    if(l < _length && arr[l] > arr[largest])
    {
        largest = l;
    }
    if(r < _length && arr[r] > arr[largest])
    {
        largest = r;
    }
    if(largest != i)
    {
        std::swap(arr[i], arr[largest]);
        heapify(largest);
    }
}

template <typename T>
void array_heap<T>::build_heap()
{
    if(_length == 0) return;
    for(int i = _length; i>0; i--)
    {
        heapify(i);
    }
}