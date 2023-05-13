#pragma once
#include "cstack.h"
#include "../../Lab3/cvector/cvector.h"
#include "../../Lab3/cpair/cpair.h"
template <typename T>
class HashTable
{
private:
    ctl::cvector<cstack<ctl::cpair<int, T>>> table;
    size_t table_size;
public:
    HashTable(size_t size): table_size(size) 
    {
        table.resize(size);
    }
    cstack<ctl::cpair<int, T>> GetStack(int key)
    {
        return table[key%table_size];
    }
    void insert(int key, T val)
    {
        table[((key%table_size < 0) ? -(key%table_size) : (key%table_size))].push(ctl::cpair(key, val));
    }
    T find(int key)
    {
        auto stck = GetStack(key);
        while (!stck.empty())
        {
            if(stck.top().first == key) return stck.top().second;
            stck.pop();
        }
        return T();
    }
    size_t GetTableSize()
    {
        return table_size;
    }
};
