#ifndef _CVECTOR
#define _CVECTOR
#include <cstdint>
#include <exception>
#include "citerator/citerator.h"
#include <initializer_list>
namespace ctl // Custom template library
{

    template <typename T>
    class _cvector_rev_iterator : public base_citerator<T>
    {
    public: 
        _cvector_rev_iterator(T* obj): base_citerator<T>(obj)
        {
        }
        _cvector_rev_iterator<T> operator++()
        {
            return _cvector_rev_iterator<T>(--(this->_obj));
        }
        _cvector_rev_iterator<T> operator--()
        {
            return _cvector_rev_iterator<T>(++(this->_obj));
        }
        _cvector_rev_iterator<T> operator+(int shift)
        {
            return _cvector_rev_iterator<T>((this->_obj - shift));
        }
        _cvector_rev_iterator<T> operator-(int shift)
        {
            return _cvector_rev_iterator<T>((this->_obj + shift));
        }
        bool operator==(_cvector_rev_iterator<T> it2) 
        {
            return (this->_obj == it2._obj);
        }
        bool operator!=(_cvector_rev_iterator<T> it2) 
        {
            return (this->_obj != it2._obj);
        }
        
    };

    template <typename T>
    class _cvector_iterator : public base_citerator<T>
    {
    public: 
        using iterator_category = std::forward_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        using value_type        = T;
        using pointer           = T*;  // or also value_type*
        using reference         = T&;
        _cvector_iterator(T* obj): base_citerator<T>(obj)
        {
        }
        _cvector_iterator<T> operator++()
        {
            return _cvector_iterator<T>(++(this->_obj));
        }
        _cvector_iterator<T> operator--()
        {
            return _cvector_iterator<T>(--(this->_obj));
        }
        _cvector_iterator<T> operator+(int shift)
        {
            return _cvector_iterator<T>((this->_obj + shift));
        }
        _cvector_iterator<T> operator-(int shift)
        {
            return _cvector_iterator<T>((this->_obj - shift));
        }
        long long operator-(_cvector_iterator<T> it2)
        {
            return (this->_obj - it2._obj);
        }
         bool operator==(_cvector_iterator<T> it2)
         {
             return (this->_obj == it2._obj);
         }
         bool operator!=(_cvector_iterator<T> it2)
         {
             return (this->_obj != it2._obj);
         }bool operator>(_cvector_rev_iterator<T>& it2)
         {
             return (this->_obj > it2._obj);
         }
         bool operator<(_cvector_rev_iterator<T>& it2)
         {
             return (this->_obj < it2._obj);
         }
    };
    template <typename T>
    class cvector
    {
        using iterator = _cvector_iterator<T>;
        using reverse_iterator = _cvector_rev_iterator<T>; 
        using const_iterator = _cvector_iterator<const T>;
    private:
        size_t _length = 0;
        size_t _cpct = 0;
        T* _arr = nullptr;
    public:
        cvector(size_t n = 0, T val = T());
        cvector(cvector<T> & _old); 
        cvector(std::initializer_list<T> list);

        // cvector(cvector<T> && _old); 
        ~cvector();
        ctl::cvector<T>& operator=(ctl::cvector<T>& _old);
        ctl::cvector<T>& operator=(ctl::cvector<T>&& _old);
        T& operator[](int ind); 
        void reserve(size_t n);
        void resize(size_t n, T val = T()); 
        void assign(size_t n, T val); 
        void assign(_cvector_iterator<const T> b, _cvector_iterator<const T> e); 
        void assign(_cvector_iterator<T> b, _cvector_iterator<T> e);
        T& at(int ind);
        T& back(); 
        size_t capacity();
        _cvector_iterator<const T> cbegin();
        _cvector_iterator<const T> cend();
        void clear();
        T* data();
        void insert(_cvector_iterator<T> pos, T& val);
        void insert(_cvector_iterator<T> pos, T&& val);
        template <typename ... Args>
        void emplace(_cvector_iterator<T> pos, Args&&... args);
        template <typename ... Args>
        void emplace_back(Args&&... args);
        bool empty();
        _cvector_iterator<T> end();
        _cvector_iterator<T> begin();
        _cvector_iterator<T> erase(_cvector_iterator<T> f);

        _cvector_iterator<T> erase(_cvector_iterator<T> f, _cvector_iterator<T> e);
        T& front();
        size_t max_size(); 
        void pop_back();
        void push_back(T& val);
        void push_back(T&& val);
        _cvector_rev_iterator<T> rbegin();
        _cvector_rev_iterator<T> rend();
        size_t size();
        void swap(cvector<T> &sec); 
    };
    template <typename T>
    cvector<T>::cvector(size_t n, T val)
    {
        // std::cout << "_&_" << std::endl;
        reserve(n);
        int i = 0;
        try
        {
            for(; i<n; i++)
                new (_arr+i) T(val);
        }
        catch(const std::exception& e)
        {
            for(int j = 0; j<i; j++)
                (_arr+j)->~T();
            delete [] reinterpret_cast<int8_t*> (_arr);
            throw e;
        }
        _length = n;
    }
    template <typename T>
    void cvector<T>::reserve(size_t n)
    {
        if(n<=_cpct) return;
        T* newarr = reinterpret_cast<T*>(new int8_t[n*sizeof(T)]);
        int i = 0;
        try
        {
            for(; i<_length; i++)
                new (newarr+i) T(_arr[i]);        
        }
        catch(const std::exception& e)
        {
            for(int j = 0; j<i; j++)
                (newarr+j)->~T();
            delete [] reinterpret_cast<int8_t*> (newarr);
            throw e;
        }
        for(int i = 0; i<_length; i++)
        {
            (_arr+i)->~T();
        }
        delete[] reinterpret_cast<int8_t*> (_arr);
        _arr = newarr;
        _cpct = n;
    }

    template <typename T>
    cvector<T>::~cvector()
    {
        for(int i = 0; i<_length; i++)
            (_arr+i)->~T();
        delete [] reinterpret_cast<int8_t*>(_arr);
    }

    template <typename T>
    T& cvector<T>::operator[](int ind)
    {
        return _arr[ind];
    }
    template <typename T>
    size_t cvector<T>::size()
    {
        return this->_length;
    }
    template <typename T>
    size_t cvector<T>::capacity()
    {
        return this->_cpct;
    }
    template <typename T>
    void cvector<T>::resize(size_t n, T val)
    {
        if(n == _length) return;
        else if(n<_length)
        {
            // int i = n-1;
            int j = _length-1;
            for(; j>n ;j--) (_arr+j)->~T();
            // for(;i<_length;i++) (_arr+i)->~T();
            (_arr+n)->~T();
            _length = n;
        }
        else if(n>_length) 
        {
            reserve(n);
            int i = _length;
            try
            {
                for(;i<n; i++) new (_arr+i) T(val);
            }
            catch(const std::exception& e)
            {
                for(;i>=0; i--) (_arr+i)->~T();
                delete [] reinterpret_cast<int8_t*>(_arr);
                throw e;
            }
            _length = n;
        }
    }
    template <typename T>
    void cvector<T>::push_back(T& val)
    {
        if(_cpct == 0) reserve(2);
        if(_cpct==_length)
            reserve(2*_length);
        try
        {
            new (_arr + _length) T(val);
        }
        catch(const std::exception& e)
        {
            this->~cvector();
            throw e;
        }
        _length++;
    }
    template <typename T>
    void cvector<T>::push_back(T&& val)
    {
        if(_cpct == 0) reserve(2);
        if(_cpct==_length)
            reserve(2*_length);
        try
        {
            new (_arr + _length) T(val);
        }
        catch(const std::exception& e)
        {
            this->~cvector();
            throw e;
        }
        _length++;
    }
    template <typename T>
    void cvector<T>::pop_back()
    {
        (_arr+_length-1)->~T();
        _length--;
    }
    template <typename T>
    bool cvector<T>::empty()
    {
        return !_length;
    }
    template <typename T>
    _cvector_iterator<T> cvector<T>::end()
    {
        return _cvector_iterator<T>(_arr+_length);
    }
    template <typename T>
    _cvector_iterator<T> cvector<T>::begin()
    {
        return _cvector_iterator<T>(_arr);
    }
    template <typename T>
    _cvector_iterator<const T> cvector<T>::cbegin()
    {
        return _cvector_iterator<const T>(_arr);
    }
    template <typename T>
    _cvector_iterator<const T> cvector<T>::cend()
    {
        return _cvector_iterator<const T>(_arr+_length);
    }
    template <typename T>
    _cvector_rev_iterator<T> cvector<T>::rbegin()
    {
        return _cvector_rev_iterator<T> (_arr+_length-1);
    }
    template <typename T>
    _cvector_rev_iterator<T> cvector<T>::rend()
    {
        return _cvector_rev_iterator<T> (_arr-1);
    }
    template <typename T>
    void cvector<T>::assign(size_t n, T val)
    {
        resize(0);
        resize(n, val);
    }
    template <typename T>
    void cvector<T>::assign(_cvector_iterator<const T> b, _cvector_iterator<const T> e)
    {
        resize(0);
        reserve(e-b);
        for(auto it = b; it!=e; ++it, _length++) new (_arr+_length) T(*(it));
    }
    template <typename T>
    void cvector<T>::assign(_cvector_iterator<T> b, _cvector_iterator<T> e)
    {
        resize(0);
        reserve(e-b);
        for(auto it = b; it!=e; ++it, _length++) new (_arr+_length) T(*(it));
    }
    template <typename T>
    T& cvector<T>::at(int ind)
    {
        if(ind<0 || ind>=_length)
        {
            throw std::out_of_range();   
        }
        return _arr[ind];
    }

    template <typename T>
    T& cvector<T>::back()
    {
        return _arr[_length-1];
    }
    template <typename T>
    void cvector<T>::clear()
    {
        resize(0);
    }
    template <typename T>
    T* cvector<T>::data()
    {
        return _arr;
    } 
    template <typename T>
    void cvector<T>::swap(cvector<T> &sec)
    {
        std::swap(_arr, sec._arr);
        std::swap(_length, sec._length);
        std::swap(_cpct, sec._cpct);
    }
    template <typename T>
    T& cvector<T>::front()
    {
        return (*_arr);
    }
    template <typename T>
    size_t cvector<T>::max_size()
    {   
        return INT64_MAX/sizeof(T);
    }

    template <typename T>
    _cvector_iterator<T> cvector<T>::erase(_cvector_iterator<T> f, _cvector_iterator<T> e)
    {
        auto it = f;
        for(;(it - end())>0; ++it)
        {
            (it).cbase()->~T();
        }
        it = f;
        auto it2 = e;
        for(;(it2 - end()) <0; ++it2, ++it)
        {
            (*it) = (*it2); 
        }
        _length = _length - (e-f);
        return e;
    }
    
    template <typename T>
    _cvector_iterator<T> cvector<T>::erase(_cvector_iterator<T> f)
    {
        return erase(f, f+1);
    }
    template <typename T>
    void cvector<T>::insert(_cvector_iterator<T> pos, T& val)
    {
        long long i = pos - begin();
        reserve(_length+1);
        pos = begin() + i;
        _cvector_iterator it = end();
        for(; (it-pos)>0; --it)
        {
            new (it.cbase()) T(*(it-1));
            (*(it-1)).~T();
        }
        new (pos.cbase()) T(val);        
        _length++;
    }
    template <typename T>
    void cvector<T>::insert(_cvector_iterator<T> pos, T&& val)
    {
        long long i = pos - begin();
        reserve(_length+1);
        pos = begin() + i;
        _cvector_iterator it = end();
        for(; (it-pos)>0; --it)
        {
            new (it.cbase()) T(*(it-1));
            (*(it-1)).~T();
        }
        new (pos.cbase()) T(val);
        _length++;
    }

    template <typename T>
    cvector<T>::cvector(cvector<T> &_old)
    {
        reserve(_old._cpct);
        _length = 0;
        try
        {
            for(;_length<_old.size(); _length++)
            {
                new (_arr+_length) T(_old[_length]);
            }
        }
        catch(const std::exception& e)
        {
            this->~cvector();
            throw e; 
        }
    }

    template <typename T>
    cvector<T>::cvector(std::initializer_list<T> list)
    {
        reserve(list.size());
        _length = 0;
        for(auto it = list.begin(); it!=list.end(); ++it, _length++)
            new (_arr+_length) T(*it);
    }
    template <typename T>
    cvector<T>& cvector<T>::operator=(ctl::cvector<T>& _old)
    {
        if(this!= &(_old)) //TODO adressoff
        {
            
            clear();
            reserve(_old.capacity());
            for(; _length<_old._length; _length++)
                new (_arr+_length) T(_old[_length]);
        }
        return *this;
    }
    template <typename T>
    cvector<T>& cvector<T>::operator=(ctl::cvector<T>&& _old)
    {
        if(this!= &(_old)) //TODO adressoff
        {
            
            clear();
            reserve(_old.capacity());
            for(; _length<_old._length; _length++)
                new (_arr+_length) T(_old[_length]);
        }
        return *this;
    }
    template <typename T>
    template <typename ... Args>
    void cvector<T>::emplace_back(Args&&... args)
    {
        // T tmp(args...);
        // push_back(tmp);
        if(_cpct == 0) reserve(2);
        if(_cpct==_length)
            reserve(2*_length);
        try
        {
            new (_arr + _length) T(args...);
        }
        catch(const std::exception& e)
        {
            this->~cvector();
            throw e;
        }
        _length++;
    }
    template <typename T>
    template <typename ... Args>
    void cvector<T>::emplace(_cvector_iterator<T> pos, Args&&... args)
    {
        // T temp(args...);
        // insert(pos, temp);
        long long i = pos - begin();
        reserve(_length+1);
        pos = begin() + i;
        _cvector_iterator it = end();
        for(; (it-pos)>0; --it)
        {
            new (it.cbase()) T(*(it-1));
            (*(it-1)).~T();
        }
        new (pos.cbase()) T(args...);        
        _length++;
    }
    
}

#endif
