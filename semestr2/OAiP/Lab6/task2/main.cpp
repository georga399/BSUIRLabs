#include <iostream>
#include "HashTable.h"
#include "../../Lab3/cvector/cvector.h"

int main()
{
    std::cout << "Start" << std::endl;
    HashTable<int> table(128);    
    for(int i = 0; i<10; i++)
    {
        if(!table.insert(2 + 128*i, 2 + 128*i))
            std::cout << "key:" << 2 + 128*i << " wasn't inserted" << std::endl;
    }
    for(int i = 0; i<10; i++)
    {
        std::cout << table.find(2 + 128*i) << std::endl;
    }
    
}