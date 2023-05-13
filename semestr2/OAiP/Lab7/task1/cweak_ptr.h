#ifndef _CWEAK_PTR
#define _CWEAK_PTR
#include "cshared_ptr.h"
namespace ctl
{
    template <typename T>
    class cweak_ptr
    {
    private:
        /* data */
    public:
        cweak_ptr(/* args */);
        ~cweak_ptr();
        cshared_ptr<T> lock();
        size_t use_count();
        bool expired();
    };
    template <typename T>
    cweak_ptr<T>::cweak_ptr(/* args */)
    {
    }
    template <typename T>
    cweak_ptr<T>::~cweak_ptr()
    {
    }
}

#endif