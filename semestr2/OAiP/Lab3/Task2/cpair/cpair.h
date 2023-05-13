#ifndef _CPAIR
#define _CPAIR
//#include "../cvector/cvector.h"
namespace ctl // Custom template library
{
    template <class _T1, class _T2>
    struct cpair
    {
        typedef _T1 first_type;
        typedef _T2 second_type;
        _T1 first;
        _T2 second;
        void swap(cpair<_T1, _T2> &sec)
        {
            std::swap(sec.first, first);
            std::swap(sec.second, second);
        }
        void operator=(cpair<_T1, _T2> &sec)
        {
            first = _T1(sec.first);
            second = _T2(sec.second);
        }
        void operator=(cpair<_T1, _T2> &&sec)
        {
            first = _T1(sec.first);
            second = _T2(sec.second);
        }
        cpair(cpair<_T1, _T2>& p)
        {
            first = p.first;
            second = p.second;
        }
        cpair(_T1& f , _T2& s )
        {
            first = f;
            second = s;
        }
        cpair(_T1&& f , _T2&& s )
        {
            first = f;
            second = s;
        }
        cpair()
        {
            first = _T1();
            second = _T2();
        }
    };
}
#endif
