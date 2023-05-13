#include "string.h"
// using namespace ctl;
#include <utility>
ctl::string::string()
{}

ctl::string::string(size_t n, char val)
{
    _arr = ctl::make_unique<char>(n+1);
    for(int i = 0; i<n; i++)
    {
        _arr[i] = val;
    }
    _length = n;
    _cpct = n;
    _arr[n] = '\0';
}

ctl::string::string(ctl::string& str)
{
    _arr = ctl::make_unique<char>(str._cpct+1);
    for(int i = 0; i<str._length; i++)
    {
        _arr[i] = str[i];
    }
    _length = str._length;  
    _cpct = str._cpct; 
    _arr[_length] = '\0';
}

ctl::string::string(ctl::string&& str)
{
    _arr = std::move(str._arr);
    _cpct = str._cpct;
    _length = str._length;
}

void ctl::string::reserve(size_t n)
{
    if(_cpct>=n) return;
    auto tmp = ctl::make_unique<char>(n+1);
    for(int i = 0; i<_length; i++)
    {
        tmp[i] = _arr[i];
    }
    tmp[_length] = '\0';
    _arr = std::move(tmp);
    _cpct = n;
}

void ctl::string::resize(size_t n, char val)
{
    reserve(n);
    for(int i = _length; i<n; i++)
    {
        _arr[i] = val;
    }
    _length = n;
    _arr[_length] = '\0';
}

char& ctl::string::operator[](size_t ind)
{
    return _arr[ind];
}

ctl::char_iterator ctl::string::begin()
{
    return ctl::char_iterator(&(*_arr));
}

ctl::char_iterator ctl::string::end()
{
    return ctl::char_iterator(&(*_arr) + _length);
}

size_t ctl::string::capacity()
{
    return _cpct;
}

size_t ctl::string::size()
{
    return _length;
}

const char* ctl::string::c_str()
{
    return &(*_arr);
}

void ctl::string::push_back(char val)
{
    if(_cpct == _length) reserve(2*_length+1);
    _arr[_length] = val;
    _arr[_length+1] = '\0';
    _length++;
}

void ctl::string::pop_back()
{
    _length--;
    _arr[_length] = '\0';
}

void ctl::string::insert(ctl::char_iterator where, char val)
{
    int i = where - begin();
    reserve(_length+1);
     _length++;
    for(; i<_length; i++)
    {
        std::swap(val, _arr[i]);
    }
    _arr[_length] = '\0';
}

void ctl::string::erase(ctl::char_iterator where)
{
    int i = where - begin();
    for(; i<_length-1; i++)
    {
        _arr[i] = _arr[i+1];
    }
    _length--;
    _arr[_length] = '\0';
}

ctl::string& ctl::string::operator=(ctl::string& str)
{
    _arr = make_unique<char>(str._cpct+1);
    for(int i = 0; i<str._length; i++)
    {
        _arr[i] = str[i];
    }
    _length = str._length;
    _cpct = str._cpct;
    _arr[_length] = '\0';
    return *this;
}

ctl::string& ctl::string::operator=(ctl::string&& str)
{
    _arr = std::move(str._arr);
    _length = str._length;
    _cpct = str._cpct;
    return *this;
}

ctl::string& ctl::string::operator+=(ctl::string& str)
{
    reserve(_length+str._length);
    for(int i = 0; i<str._length; i++)
    {
        _arr[_length+i] = str[i];
    }
    _length+=str._length;
    _arr[_length] = '\0';
    return *this;
}

ctl::string& ctl::string::operator+=(ctl::string&& str)
{
    reserve(_length+str._length);
    for(int i = 0; i<str._length; i++)
    {
        _arr[_length+i] = str[i];
    }
    _arr[_length] = '\0';
    return *this;
}

ctl::string ctl::string::operator+(ctl::string& str)
{
    string res(*this);
    res+=str;
    return res;
}

ctl::string ctl::string::operator+(ctl::string&& str)
{
    string res(*this);
    res+=str;
    return res;
}

ctl::string::string(const char* cstr)
{
    reserve(ctl::strlen(cstr));
    for(int i = 0; i<ctl::strlen(cstr); i++)
    {
        _arr[i] = cstr[i];
    }
    _length = ctl::strlen(cstr);
    _arr[_length] = '\0';
}

ctl::string::~string()
{}