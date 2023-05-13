#pragma once
#include <utility>
#include "../../Lab3/cvector/cvector.h"
#define _C1_FOR_CALCULATING_HASH 53
#define _C2_FOR_CALCULATING_HASH 13
template <typename T>
class HashTable
{
private:
    size_t hashTableSize;
    ctl::cvector<std::pair<int, T>> table;
public:
    HashTable(size_t size);
    int CalculateHash(int key);
    bool insert(int key, T item);
    T  find(int key);
    T& operator[](int key);
};
template <typename T>
HashTable<T>::HashTable(size_t size)
{
    hashTableSize = size;
    table.resize(size, {-1, T()});
}
template <typename T>
int HashTable<T>::CalculateHash(int key)
{
    return key % hashTableSize;
}
template <typename T>
bool HashTable<T>::insert(int key, T item)
{
    int index = CalculateHash(key);
    if(table[index].first == -1)
    {
        table[index].first = key;
        table[index].second = item;
        return true;
    }
    int h2 = (index + _C1_FOR_CALCULATING_HASH + _C2_FOR_CALCULATING_HASH)%hashTableSize;
    for(int i = 1; index!=h2; i++)
    {
        if(table[h2].first == -1)
        {
           table[h2].first = key;
           table[h2].second = item;
           return true;
        }
        h2 = (index + _C1_FOR_CALCULATING_HASH*i + _C2_FOR_CALCULATING_HASH*i*i)%hashTableSize;
    }
    return false;
}
template <typename T>
T& HashTable<T>::operator[](int key)
{
    int index = CalculateHash(key);
    if(table[index].first == key) 
        return table[index].second;
    int h2 = (index + _C1_FOR_CALCULATING_HASH + _C2_FOR_CALCULATING_HASH)%hashTableSize;
    for(int i = 1; index!=h2; i++)
    {
        
        if(table[h2].first == key) 
            return table[h2].second;
        h2 = (index + _C1_FOR_CALCULATING_HASH*i + _C2_FOR_CALCULATING_HASH*i*i)%hashTableSize;
    }
    return table[h2].second;
}
template <typename T>
T HashTable<T>::find(int key)
{
    int index = CalculateHash(key);
    if(table[index].first == key) 
        return table[index].second;
    int h2 = (index + _C1_FOR_CALCULATING_HASH + _C2_FOR_CALCULATING_HASH)%hashTableSize;
    for(int i = 1; index!=h2; i++)
    {
        if(table[h2].first == key) 
            return table[h2].second;
        h2 = (index + _C1_FOR_CALCULATING_HASH*i + _C2_FOR_CALCULATING_HASH*i*i)%hashTableSize;

    }
    return T();
}