#ifndef _CITERATOR
#define _CITERATOR

namespace ctl //custom template library
{
    template <typename T>
    class base_citerator
    {
    protected:
        T* _obj;
    public:
        T& operator*();
        base_citerator(T* = nullptr);
        ~base_citerator();
        T* cbase();
    };

    template <typename T>
    base_citerator<T>::base_citerator(T* obj)
    {
        _obj = obj;
    }

    template <typename T>
    base_citerator<T>::~base_citerator()
    {}

    template <typename T>
    T& base_citerator<T>::operator*()
    {
        return *_obj;
    }
    template <typename T>
    T* base_citerator<T>::cbase()
    {
        return _obj;
    }
}

#endif
