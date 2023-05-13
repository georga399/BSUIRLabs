#ifndef _CDEQUE
#define _CDEQUE
// #include "../task1/cshared_ptr.h"
#include <stdexcept>
namespace ctl
{
    #ifndef _CTL_CDEQUE_BUF_SIZE
    #define _CTL_CDEQUE_BUF_SIZE 128
    #endif
    using size_t = unsigned long long;

    template <typename T, size_t buff_size = ((sizeof(T) < _CTL_CDEQUE_BUF_SIZE) ? (_CTL_CDEQUE_BUF_SIZE/ sizeof(T)) : size_t(1))>
    class _cdeque_iterator
    {
    private:
        T* _ptr_to_elem;
        size_t _ind_of_chunk;
        T*** _ptr_to_map;
        size_t* _map_size;
    public:
        _cdeque_iterator(): _ptr_to_elem(nullptr), _ptr_to_map(nullptr), _map_size(nullptr) {}
        _cdeque_iterator(T* ptr_to_elem, size_t ind_of_chunk, T*** ptr_to_map, size_t* map_size)
        {
            _ptr_to_elem = ptr_to_elem;
            _ind_of_chunk = ind_of_chunk;
            _ptr_to_map = ptr_to_map;
            _map_size = map_size;
        }
        _cdeque_iterator operator++()
        {
            if(_ind_of_chunk + 1 >= *_map_size && _ptr_to_elem - (*_ptr_to_map)[_ind_of_chunk] + 1 == buff_size)
            {
                ++_ptr_to_elem;
            }
            else if(_ptr_to_elem - (*_ptr_to_map)[_ind_of_chunk] + 1 == buff_size)
            {
                _ind_of_chunk++;
                _ptr_to_elem = ((*_ptr_to_map)[_ind_of_chunk]);
            }
            else 
            {
                ++_ptr_to_elem;
            }
            return *this;
        }
        _cdeque_iterator operator--()
        {
            if(_ind_of_chunk == 0 && _ptr_to_elem == (*_ptr_to_map)[_ind_of_chunk])
            {
                throw std::out_of_range("bad using of operator--");
            }
            else if(_ptr_to_elem == (*_ptr_to_map)[_ind_of_chunk])
            {
                _ind_of_chunk--;
                _ptr_to_elem = ((*_ptr_to_map)[_ind_of_chunk]) + buff_size - 1;
            }
            else 
            {
                --_ptr_to_elem;
            }
            return *this;
        }
        _cdeque_iterator operator+(size_t shift)
        {
            if(_ind_of_chunk*buff_size + (_ptr_to_elem - (*_ptr_to_map)[_ind_of_chunk]) + shift >= (*_map_size)*buff_size)
            {
                throw std::out_of_range("bad using of operator of operator+");
            }
            int t = int(shift) - int (buff_size - int((_ptr_to_elem - (*_ptr_to_map)[_ind_of_chunk])));
            if(t>=0)
            {
                auto indOfBlock = _ind_of_chunk + 1 + t/buff_size;

                return _cdeque_iterator((*_ptr_to_map)[indOfBlock]  + (t%buff_size), indOfBlock,_ptr_to_map, _map_size);
            }
            else 
            {
                return _cdeque_iterator(_ptr_to_elem + shift, _ind_of_chunk, _ptr_to_map, _map_size);
            }
        }
        _cdeque_iterator operator-(size_t shift)
        {
            if(_ind_of_chunk*buff_size + (_ptr_to_elem - (*_ptr_to_map)[_ind_of_chunk]) < shift)
            {
                throw std::out_of_range("bad using of operator of operator-");
            }
            if(shift <= (_ptr_to_elem - (*_ptr_to_map)[_ind_of_chunk]))
            {
                return _cdeque_iterator(_ptr_to_elem - shift, _ind_of_chunk, _ptr_to_map, _map_size);
            }            
            else 
            {
                int t = shift - (_ptr_to_elem - (*_ptr_to_map)[_ind_of_chunk]);
                return _cdeque_iterator((*_ptr_to_map)[_ind_of_chunk - 1 - t/buff_size] + (buff_size - t%buff_size), _ind_of_chunk - 1 - t/buff_size, _ptr_to_map, _map_size);
            }
        }
        T& operator*()
        {
            return *_ptr_to_elem;
        }
        T* operator->()
        {
            return _ptr_to_elem;
        }
        T* data()
        {
            return _ptr_to_elem;
        }
        ~_cdeque_iterator() {}
        bool operator !=(_cdeque_iterator it)
        {
            return (_ptr_to_elem != it._ptr_to_elem);
        }
        bool operator ==(_cdeque_iterator it)
        {
            return (_ptr_to_elem == it._ptr_to_elem);
        }
    };
    
    template <typename T>
    class cdeque
    {
    private:
        size_t _length = 0;
        size_t __deque_buf_size = ((sizeof(T) < _CTL_CDEQUE_BUF_SIZE) ? \
                (_CTL_CDEQUE_BUF_SIZE/ sizeof(T)) : size_t(1));
        T* _beg = nullptr;
        T* _end = nullptr;
        T** _map = nullptr;
        size_t _map_size = 0;
        T** _chunk_with_beg = nullptr;
        T** _chunk_with_end = nullptr;
        T*** _ptr_to_map = nullptr;
        size_t* _ptr_to_size_map = nullptr;
    public:
        using iterator = _cdeque_iterator<T>;
        //TODO: MAKE NORMAL COPY
        cdeque(cdeque<T>& s); 
        cdeque(cdeque<T>&& s);
        cdeque<T>& operator=(cdeque<T>& s);
        cdeque<T>& operator=(cdeque<T>&& s);

        cdeque(size_t count = 0, T val = T());
        ~cdeque();
        void push_back(T val);
        void push_front(T val);
        void pop_back();
        void pop_front();
        void clear();
        size_t size();
        bool empty();
        T& operator[](size_t ind);
        iterator begin();
        iterator end();
    };
    template <typename T>
    cdeque<T>::cdeque(size_t count, T val)
    {
        if(count == 0) return;
        _map_size = count/__deque_buf_size + 1;
        _map = new T*[_map_size];
        _ptr_to_size_map = new size_t(_map_size);
        _ptr_to_map = new T**(_map);
        _chunk_with_beg = _map;
        size_t counter = 0;
        for(int i = 0; i<_map_size; i++)
        {
            _map[i] = reinterpret_cast<T*>(new char[__deque_buf_size*sizeof(T)]);
            for(int j = 0; (j < __deque_buf_size) && (counter <count); counter++, j++)
            {
                new (_map[i] + j) T(val);
            }
        }
        _beg = *_chunk_with_beg;
        _chunk_with_end = _map + _map_size - 1;
        _end = *_chunk_with_end + count%__deque_buf_size;
        _length = count;
    }
    template <typename T>
    cdeque<T>::~cdeque()
    {
        size_t counter = 0;
        auto ptr_to_el = _beg;
        auto ptr_to_chunk = _chunk_with_beg;
        while (counter != _length)
        {
            ptr_to_el->~T();
            ++ptr_to_el;
            if(ptr_to_el - (*_chunk_with_beg) == __deque_buf_size)
            {
                ++ptr_to_chunk;
                if(ptr_to_chunk - _map != _map_size) ptr_to_el = *ptr_to_chunk;
            }
            ++counter;
        }
        for(int i = 0; i<_map_size; i++)
        {
            delete [] _map[i];
        }
        delete [] _map;
        delete _ptr_to_map;
        delete _ptr_to_size_map;
        _beg = nullptr;
        _end = nullptr;
        _map = nullptr;
        _map_size = 0;
        _chunk_with_beg = nullptr;
        _chunk_with_end = nullptr;
        _ptr_to_map = nullptr;
        _ptr_to_size_map = nullptr;
        _length = 0;
    }
    template <typename T>
    void cdeque<T>::push_back(T val)
    {
        if(_beg == nullptr)
        {
            _map_size = 1;
            _map = new T*[_map_size];
            _ptr_to_map = new T**(_map);
            _ptr_to_size_map = new size_t(_map_size);
            _chunk_with_beg = _map;
            _map[0] = reinterpret_cast<T*>(new char[__deque_buf_size*sizeof(T)]);
            _chunk_with_end = _chunk_with_beg;
            _beg = *_chunk_with_beg;
            _end = _beg;
        }
        else if(_beg != _end && _chunk_with_end + 1 - _map == _map_size && _end - *_chunk_with_end == __deque_buf_size)
        {
            // std::cout << "Realocating";
            T** newmap = new T*[_map_size+1];
            for(int i = 0; i< _map_size; i++)
            {
                newmap[i] = _map[i];
            }
            newmap[_map_size] = reinterpret_cast<T*>(new char[__deque_buf_size*sizeof(T)]);
            int ind_of_beg_chunk = _chunk_with_beg - _map;
            _chunk_with_beg = newmap + ind_of_beg_chunk;
            _chunk_with_end = newmap + _map_size;
            _end = *_chunk_with_end;
            ++_map_size;
            delete [] _map;
            _map = newmap;
            *_ptr_to_map = _map;
            *_ptr_to_size_map = _map_size;
        } 
        new (_end) T(val);
        ++_end;
        if(_end - *_chunk_with_end == __deque_buf_size && _chunk_with_end - _map + 1 != _map_size) 
        {
            ++_chunk_with_end;
            _end = *_chunk_with_end;
        }
        ++_length;
        // std::cout << "beg:" << _beg << ' ' << "chunk with beg:" << *_chunk_with_beg << std::endl;
    }
    template <typename T>
    void cdeque<T>::push_front(T val)
    {
        if(_beg == nullptr)
        {
            _map_size = 1;
            _map = new T*[_map_size];
            _ptr_to_map = new T**(_map);
            _ptr_to_size_map = new size_t(_map_size);
            _chunk_with_beg = _map;
            _map[0] = reinterpret_cast<T*>(new char[__deque_buf_size*sizeof(T)]);
            _chunk_with_end = _chunk_with_beg;
            _beg = *_chunk_with_beg;
            _end = _beg;
        }
        if(_beg == *_chunk_with_beg && _chunk_with_beg == _map)
        {
            T** newmap = new T*[_map_size+1];
            for(int i = 1; i< _map_size+1; i++)
            {
                newmap[i] = _map[i-1];
            }
            newmap[0] = reinterpret_cast<T*>(new char[__deque_buf_size*sizeof(T)]);
            int ind_of_beg_chunk = _chunk_with_beg - _map;
            int ind_of_end_chunk = _chunk_with_end - _map;
            delete [] _map;
            _map = newmap;
            *_ptr_to_map = _map;
            _chunk_with_beg = _map + 1 + ind_of_beg_chunk;
            _chunk_with_end = _map + 1 + ind_of_end_chunk;
            ++_map_size;
            *_ptr_to_size_map = _map_size;
        }
        if(_beg == *_chunk_with_beg)
        {
            _beg = *(--_chunk_with_beg) + __deque_buf_size - 1; 
        }
        else
        {
            --_beg;
        }
        new (_beg) T(val);
        
        _length++;
    }
    template <typename T>
    void cdeque<T>::pop_back()
    {
        if(_length == 0) throw std::out_of_range("Cdeque is already cleared.");
        if(_end == *_chunk_with_end)
        {
            --_chunk_with_end;
            _end = *_chunk_with_end + __deque_buf_size - 1;
            _end->~T();
        }
        else
        {
            --_end;
            _end->~T();
        }
        _length--;
    }
    template <typename T>
    void cdeque<T>::pop_front()
    {
        if(_length == 0) throw std::out_of_range("Cdeque is already cleared.");
        _beg->~T();
        if(_beg - *_chunk_with_beg + 1 == __deque_buf_size)
        {
            ++_chunk_with_beg;
            if(_chunk_with_beg <= _chunk_with_end) _beg = *_chunk_with_beg;
        }
        else
        {
            ++_beg;
        }
        --_length;
    }
    template <typename T>
    size_t cdeque<T>::size()
    {
        return _length;
    }
    template <typename T>
    bool cdeque<T>::empty()
    {
        return _length == 0;
    }
    template <typename T>
    T& cdeque<T>::operator[](size_t ind)
    {
        if(ind >= _length) throw std::out_of_range("Bad index");
        // std::cout << _beg << ':' << *_chunk_with_beg << std::endl;
        int t = int(ind) - int (__deque_buf_size - int((_beg - *_chunk_with_beg)));
        if(t>=0)
        {
            auto block = _chunk_with_beg + 1 + t/__deque_buf_size;
            return (*block)[t%__deque_buf_size];
        }
        else 
        {
            return *(_beg+ind);
        }
    }
    template <typename T>
    void cdeque<T>::clear()
    {
        size_t counter = 0;
        auto ptr_to_el = _beg;
        auto ptr_to_chunk = _chunk_with_beg;
        while (counter != _length)
        {
            ptr_to_el->~T();
            ++ptr_to_el;
            if(ptr_to_el - (*_chunk_with_beg) == __deque_buf_size)
            {
                ++ptr_to_chunk;
                if(ptr_to_chunk - _map != _map_size) ptr_to_el = *ptr_to_chunk;
            }
            ++counter;
        }
        _length = 0;
        _end = _beg;
        _chunk_with_end = _chunk_with_beg;
    }
    template <typename T>
    _cdeque_iterator<T> cdeque<T>::begin()
    {
        return iterator(_beg, _chunk_with_beg - (_map), _ptr_to_map, _ptr_to_size_map);
    }
    template <typename T>
    _cdeque_iterator<T> cdeque<T>::end()
    {
        return iterator(_end, _chunk_with_end - (_map), _ptr_to_map, _ptr_to_size_map);
    }
    template <typename T>
    cdeque<T>::cdeque(cdeque<T>& s)
    {
        this->~cdeque();
        for(int i = 0; i<s.size(); i++) this->push_back(s[i]);
    }
    template <typename T>
    cdeque<T>::cdeque(cdeque<T>&& s)
    {
        this->~cdeque();
        for(int i = 0; i<s.size(); i++) this->push_back(s[i]);
    }
    template <typename T>
    cdeque<T>& cdeque<T>::operator=(cdeque<T>& s)
    {
        if(this == &(s)) return *this;
        this->~cdeque();
        for(int i = 0; i<s.size(); i++) 
            this->push_back(s[i]);
        return *this;
    }
    template <typename T>
    cdeque<T>& cdeque<T>::operator=(cdeque<T>&& s)
    {
        if(this == &(s)) return *this;
        this->~cdeque();
        for(int i = 0; i<s.size(); i++) this->push_back(s[i]);
        return *this;
    }
}
#endif