#pragma once
#include <exception>
#include <iostream>
template <typename T>
class CustList
{
private:

    struct _Node
    {
        _Node* next = nullptr;
        _Node* prev = nullptr;
        T val = T();
    };
    _Node *head;
    _Node *end;
    int _length;

public:
    CustList(/* args */);
    ~CustList();
    void push_back(T val);
    T& operator[](int ind);
    void erase(int ind);
    void pop_back();
    void push_front(T val);
    void pop_front();
    int size();
    void mergeSort(int b, int e, bool (*f)(T t1, T t2));

};

template <typename T>
CustList<T>::CustList(/* args */): _length(0)
{
    head = nullptr;
    end = nullptr;
}

template <typename T>
CustList<T>::~CustList()
{
    while (_length)
    {
        pop_back();
    }
}

template <typename T>
int CustList<T>::size()
{
    return _length;
}

template <typename T>
void CustList<T>::pop_back()
{
    if(_length == 0) throw std::exception();
    else if(_length == 1)
    {
        delete this->head;
        this->head = nullptr;
        this->end = nullptr;
        _length--;
    }
    else
    {
//        _Node* temp = this->end->prev;
//        temp->next = nullptr;
//        delete this->end;
//        this->end = temp;
//        _length--;
        _length--;
         this->end = this->end->prev;
         delete this->end->next;
         this->end->next = nullptr;
    }
}

template <typename T>
void CustList<T>::push_back(T val)
{
    if(_length == 0)
    {
        this->head = new _Node;
        this->end = this->head;
        this->head->val = val;
    }
    else
    {
        _Node* temp = new _Node;
        temp->prev = this->end;
        this->end->next = temp;
        this->end = temp;
        this->end->val = val;
    }
    _length++;
}

template <typename T>
void CustList<T>::push_front(T val)
{
    if(_length == 0)
    {
        this->head = new _Node();
        this->end = this->head;
        this->head->val = val;
        _length++;
    }
    else
    {
        _Node* temp = new _Node();
        this->head->prev = temp;
        temp->next = this->head;
        this->head = temp;
        this->head->val = val;
        _length++;
    }
}

template <typename T>
void CustList<T>::pop_front()
{
    if(_length == 0) throw std::exception();
    else if(_length == 1)
    {
        delete this->head;
        this->head = nullptr;
        this->end = nullptr;
        _length--;
    }
    else
    {
//        this->head->next->prev = nullptr;
//        _Node *temp = this->head->next;

         head = head->next;
         delete head->prev;
         head->prev = nullptr;

//        delete this->head;
//        this->head = temp;
        _length--;
    }
}

template <typename T>
void CustList<T>::erase(int ind)
{
    if(ind <0 || ind>= _length) throw std::exception();
    else if(_length == 1)
    {
        pop_back();
    }
    else if(_length == 2)
    {
        if(ind == 0)
        {
            pop_front();
        }
        else pop_back();
    }
    else
    {
        if(ind == 0)
        {
            pop_front();
        }
        else if(ind == _length-1)
        {
            pop_back();
        }
        else
        {
            _Node *temp;
            if(ind < _length/2)
            {
               temp = this->head;
               for(int i = 0; i<ind; i++)
               {
                   temp = temp->next;
               }
            }
            else
            {
               temp = this->end;
               for(int i = _length-1; i!=ind; i--)
               {
                   temp = temp->prev;
               }
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            _length--;
        }

    }
}

template <typename T>
T& CustList<T>::operator[](int ind)
{
    if(ind < 0 || ind >= _length) throw std::exception();
    else
    {
        if(ind < _length/2)
        {
            _Node *temp = this->head;
            for(int i = 0; i<ind; i++)
            {
                temp = temp->next;
            }
            return temp->val;
        }
        else
        {
            _Node *temp = this->end;
            for(int i = _length-1; i!=ind; i--)
            {
                temp = temp->prev;
            }
            return temp->val;
        }
    }
}

template <typename T>
void CustList<T>::mergeSort(int b, int e, bool (*f)(T t1, T t2))
{
    if(b>=e || b<0 || e<0) return;
    mergeSort( b, (e+b)/2, f );
    mergeSort( (e+b)/2 + 1, e, f );
    T* temparr = new T[e-b+1];
    _Node* cur = this->head;
    for(int i = 0; i < b; i++)
    {
//        int val = cur->val;
        cur = cur->next;
    }
    int l = b, r = (e+b)/2 + 1;
    _Node *lp = this->head;
    _Node *rp;
    for(int i = 0; i!=b; i++)
    {
        lp = lp->next;
    }
    rp = lp->next;
    for(int i = b+1; i < (b+e)/2 + 1; i++)
    {
        rp = rp->next;
    }
    if(e-b+1 == 5)
    {
        std::cout << 5 << std::endl;
    }
    for(int i =0 ; i<e-b+1; i++)
    {
        if( l > (e+b)/2 )
        {
          temparr[i] = rp->val;
          r++;
          rp = rp->next;
        }
        else if( r > e )
        {
            temparr[i] = lp->val;
            l++;
            lp = lp->next;
        }
        else if(f(lp->val, rp->val))
        {
            temparr[i] = lp->val;
            l++;
            lp = lp->next;
        }
        else
        {
            temparr[i] = rp->val;
            r++;
            rp = rp->next;
        }
    }



    cur = this->head;
    for(int i = 0; i<b; i++)
    {
        cur = cur->next;
    }
    for(int i = 0; i<e-b+1; i++)
    {
        cur->val = temparr[i];
        cur = cur->next;
    }
}
