#ifndef _CSHARED_PTR
#define _CSHARED_PTR

namespace ctl //custom template library
{
    template <typename T>
    class cshared_ptr
    {
    private:
        T* _ptr = nullptr;
        size_t* _count = nullptr;
    public:
        operator bool() const
        {
            return _ptr != nullptr;
        }
        cshared_ptr(T* ptr): _ptr(ptr)
        {
            _count = new size_t(1);
        }
        cshared_ptr(cshared_ptr&& x)
            : _ptr(x._ptr)
        {
            x._ptr = nullptr;
        }
        cshared_ptr(cshared_ptr& x)
            : _ptr(x._ptr), _count(x._count)
        {
            ++*_count;
        }
        cshared_ptr& operator=(cshared_ptr&& x)
        {
            if(&x == this)
                return *this;
            if(*_count>1) --*_count;
            else 
            {
                delete _count;
                delete _ptr;
            }
            _ptr = x._ptr;
            _count = x._count;
            x._ptr = nullptr;
            x._count = nullptr;
            return *this;
        }
        cshared_ptr& operator=(cshared_ptr& x)
        {
            if(&x == this)
                return *this;
            if(*_count>1) --*_count;
            else 
            {
                delete _count;
                delete _ptr;
            }
            _ptr = x._ptr;
            _count = x._count;
            ++*_count;
            return *this;
        }
        T& operator*() const { return *_ptr; }
        T* operator->() const { return _ptr; }
        size_t use_count(){ return *_count;}
        bool isNull() const { return _ptr == nullptr; }
        ~cshared_ptr()
        {
            if(*_count == 1) 
            {
                delete _count;
                delete _ptr;
                _count = nullptr;
                _ptr = nullptr;
            } 
            else{
                --*_count;
            }
        }    
    };
    template <typename T>
    class cshared_ptr<T[]>
    {
    private:
        T* _ptr = nullptr;
        size_t* _count = nullptr;
    public:
        operator bool() const
        {
            return _ptr != nullptr;
        }
        cshared_ptr(T* ptr): _ptr(ptr)
        {
            _count = new size_t(1);
        }
        cshared_ptr(cshared_ptr&& x)
            : _ptr(x._ptr)
        {
            x._ptr = nullptr;
        }
        cshared_ptr(cshared_ptr& x)
            : _ptr(x._ptr), _count(x._count)
        {
            ++*_count;
        }
        cshared_ptr& operator=(cshared_ptr&& x)
        {
            if(&x == this)
                return *this;
            if(*_count>1) --*_count;
            else 
            {
                delete _count;
                delete[] _ptr;
            }
            _ptr = x._ptr;
            _count = x._count;
            x._ptr = nullptr;
            x._count = nullptr;
            return *this;
        }
        cshared_ptr& operator=(cshared_ptr& x)
        {
            if(&x == this)
                return *this;
            if(*_count>1) --*_count;
            else 
            {
                delete _count;
                delete []_ptr;
            }
            _ptr = x._ptr;
            _count = x._count;
            ++*_count;
            return *this;
        }
        T& operator*() const { return *_ptr; }
        T* operator->() const { return _ptr; }
        size_t use_count(){ return *_count;}
        bool isNull() const { return _ptr == nullptr; }
        ~cshared_ptr()
        {
            if(*_count == 1) 
            {
                delete _count;
                delete[] _ptr;
                _count = nullptr;
                _ptr = nullptr;
            } 
            else{
                --*_count;
            }
        }    
    };
}
#endif