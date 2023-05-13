#include "custvector.h"
#include <exception>
#include <QDebug>

template <typename T>
CustVector<T>::CustVector(int n)
{
    //this->array = (T*)malloc(sizeof(T)*n);
    this->array = new T[n];
    this->capacity = n;
}

template <typename T>
void CustVector<T>::push_back(T el)
{
    if(this->capacity>this->length)
    {
        this->array[length] = el;
    }
    else
    {
        T* temp = new T[(capacity+=5)];
        for(int i = 0; i<this->length; i++)
        {
            temp[i] = this->array[i];
        }
        delete [] array;
        temp[this->length] = el;
        this->array = temp;
    }
    this->length++;
}

template <typename T>
void CustVector<T>::pop_back()
{
   if(this->length > 0) this->length--;
   else throw std::exception();
}

template <typename T>
void CustVector<T>::erase(int pos)
{
    if(pos + 1 > this->length || pos < 0)
    {
        throw std::exception();
    }
    else
    {
        for(int i = pos; i+1<this->length; i++)
        {
            this->array[i] = this->array[i+1];
        }
        this->length--;
    }
}

template <typename T>
int CustVector<T>::size()
{
    return this->length;
}

template <typename T>
CustVector<T>::~CustVector()
{
    delete [] this->array;
}


