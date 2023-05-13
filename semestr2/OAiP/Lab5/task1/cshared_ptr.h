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
        cshared_ptr(){}
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
            if(_count != nullptr && *_count>1) --*_count;
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
            if(_count != nullptr && *_count>1) --*_count;
            _ptr = x._ptr;
            _count = x._count;
            if(_count != nullptr)
            ++*_count;
            return *this;
        }
        bool operator==(cshared_ptr& x)
        {
            return x._ptr == _ptr;
        }
        bool operator!=(cshared_ptr& x)
        {
            return x._ptr != _ptr;
        }
        T& operator*() const { return *_ptr; }
        T* operator->() const { return _ptr; }
        size_t use_count(){ return *_count;}
        bool isNull() const { return _ptr == nullptr; }
        ~cshared_ptr()
        {
            if(_count == nullptr) return;
            if( *_count == 1) 
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
        T* data()
        {
            return _ptr;
        } 
    };
    template <typename T, typename ...Args>
    cshared_ptr<T> make_cshared(Args&&... args)
    {
        return cshared_ptr(new T(args...));
    }
}
#endif