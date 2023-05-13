#ifndef _CTL_STRING
#define _CTL_STRING
#include "../task1/cunique_ptr.h"
// #include <utility>
// #include <cstdio>
// #include <cstring>
#include "custcstring.h"
namespace ctl
{
    class char_iterator
    {
        char* _ptr;
    public:
        char_iterator(char* ptr = nullptr): _ptr(ptr)
        {}
        char& operator*() {return *_ptr;}
        char_iterator operator++()
        {
            return char_iterator(++(this->_ptr));
        }
        char_iterator operator--()
        {
            return char_iterator(--(this->_ptr));
        }
        char_iterator operator+(int shift)
        {
            return char_iterator((this->_ptr + shift));
        }
        char_iterator operator-(int shift)
        {
            return char_iterator((this->_ptr - shift));
        }
        int operator-(char_iterator b)
        {
            return ((this->_ptr - b._ptr));
        }
        friend bool operator==( char_iterator& a,  char_iterator& b) { return a._ptr == b._ptr;};
        friend bool operator!=( char_iterator& a,  char_iterator& b) { return a._ptr != b._ptr;};
        friend bool operator> ( char_iterator& a,  char_iterator& b) { return a._ptr > b._ptr; };
        friend bool operator< ( char_iterator& a,  char_iterator& b) { return a._ptr < b._ptr; };
    };
    class string
    {
    private:
        size_t _length = 0;
        size_t _cpct = 0;
        cunique_ptr<char[]> _arr;
    public:
        using iterator = char_iterator;
        string();
        string(size_t n, char val);
        string(string& str);
        string(string&& str);
        string(const char * cstr);
        void reserve(size_t n);
        void resize(size_t n, char val);
        char& operator[](size_t ind);
        char_iterator begin();
        char_iterator end();
        void insert(char_iterator where, char val);
        void erase(char_iterator where);
        void push_back(char val);
        void pop_back();
        const char* c_str();
        size_t size();
        size_t capacity();
        string& operator=(string& str);
        string& operator=(string&& str);
        string operator+(string& str);
        string operator+(string&& str);
        string& operator+=(string& str);
        string& operator+=(string&& str);
        ~string();
    };
}
#endif