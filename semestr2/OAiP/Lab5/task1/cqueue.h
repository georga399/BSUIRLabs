#ifndef _CQEUE
#define _CQEUE
#include "cshared_ptr.h"
#include <stdexcept>
#include <memory>
#include <iostream>
namespace ctl
{
    using size_t = unsigned long long;
    template <class T>
    class cqueue
    {
    private:
        struct Node
        {
            T data;
            cshared_ptr<Node> prev;
            Node(T val): data(val){}
        };
        size_t _length = 0;
        cshared_ptr<Node> _front;
        cshared_ptr<Node> _end;
    public:
        cqueue();
        cqueue(cqueue&);
        cqueue(cqueue&&);
        ~cqueue();
        void pop();
        void push(T val);
        T& front();
        T& back();
        size_t size();
        bool empty();
        cqueue& operator=(cqueue& q);
        cqueue& operator=(cqueue&& q);
    };
    
    template <class T>
    cqueue<T>::cqueue(){}

    template <class T>
    cqueue<T>::~cqueue(){}

    template <class T>
    cqueue<T>::cqueue(cqueue& q){
        if(q._length>0)
        {
            cshared_ptr<Node> ptr = q._front;
            while((ptr != q._end))
            {
                push(ptr->data);
                ptr = ptr->prev;
            }
            if(ptr == q._end) push(ptr->data);
            _length = q._length;
        }
    }
    template <class T>
    void cqueue<T>::push(T val){
        if(_length == 0)
        {
            _front = make_cshared<Node>(val);
            _end = _front;
        }
        else 
        {
            auto p = make_cshared<Node>(val);
            _end->prev = p;
            _end = p;
        }
        _length++;
    }
    template <class T>
    void cqueue<T>::pop()
    {
        if(_length == 0) throw std::exception();
        _front = _front->prev;
        _length--;
    } 
    template <class T>
    T& cqueue<T>::front()
    {
        return _front->data;
    }
    template <class T>
    T& cqueue<T>::back()
    {
        return _end->data;
    }
    template <class T>
    size_t cqueue<T>::size()
    {
        return _length;
    }
    template <class T>
    bool cqueue<T>::empty()
    {
        return (_length == 0);
    }
    template <class T>
    cqueue<T>::cqueue(cqueue&& q)
    {
        _front = q._front;
        _end = q._end;
        _length = q._length;
    }
    template <class T>
    cqueue<T>& cqueue<T>::operator=(cqueue<T>& q)
    {
        while(_length) pop();
        if(q._length>0)
        {
            auto ptr = q._front;
            while(ptr != q._end)
            {
                push(ptr->data);
                ptr = ptr->prev;
            }
            if(ptr == q._end) push(ptr->data);
        }
        return *this;
    }
    template <class T>
    cqueue<T>& cqueue<T>::operator=(cqueue<T>&& q)
    {
        while(_length) pop();
        _front = q._front;
        _end = q._end;
        _length = q._length;
        return *this;
    }
}
#endif 