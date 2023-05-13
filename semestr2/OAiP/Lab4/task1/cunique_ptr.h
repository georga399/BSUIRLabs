#ifndef _CUNIQUE_PTR
#define _CUNIQUE_PTR
#include <cstdio>
namespace ctl // custom template library
{
    template<class T>
    class cunique_ptr
    {
        T* m_ptr;

    public:
        operator bool() const
        {
            return m_ptr != nullptr;
        }
        cunique_ptr(T* ptr = nullptr)
            :m_ptr(ptr)
        {
        }
        ~cunique_ptr()
        {
            delete m_ptr;
        }
        cunique_ptr(cunique_ptr&& x)
            : m_ptr(x.m_ptr)
        {
            x.m_ptr = nullptr;
        }

        cunique_ptr(const cunique_ptr& x) = delete;

        cunique_ptr& operator=(cunique_ptr& a) = delete;

        cunique_ptr& operator=(cunique_ptr&& x)
        {
            if(&x == this)
                return *this;
            delete m_ptr;
            m_ptr = x.m_ptr;
            x.m_ptr = nullptr;
            return *this;
        }
        T& operator*() const { return *m_ptr; }
        T* operator->() const { return m_ptr; }
        bool isNull() const { return m_ptr == nullptr; }
    };
    template<class T>
    class cunique_ptr<T[]>
    {
        T* m_ptr;

    public:
        operator bool() const
        {
            return m_ptr != nullptr;
        }
        cunique_ptr(T* ptr = nullptr)
            :m_ptr(ptr)
        {
        }
        ~cunique_ptr()
        {
            delete[] m_ptr;
        }
        cunique_ptr(cunique_ptr&& x)
            : m_ptr(x.m_ptr)
        {
            x.m_ptr = nullptr;
        }

        cunique_ptr(const cunique_ptr& x) = delete;

        cunique_ptr& operator=(cunique_ptr& a) = delete;

        cunique_ptr& operator=(cunique_ptr&& x)
        {
            if(&x == this)
                return *this;
            delete[] m_ptr;
            m_ptr = x.m_ptr;
            x.m_ptr = nullptr;
            return *this;
        }
        T& operator[](size_t ind)
        {
            return m_ptr[ind];
        }
        T& operator*() const { return *m_ptr; }
        T* operator->() const { return m_ptr; }
        bool isNull() const { return m_ptr == nullptr; }
    };
    template <class T>
    cunique_ptr<T[]> make_unique(size_t n)
    {
        return cunique_ptr<T[]>(new T[n]);
    }
    
}
#endif