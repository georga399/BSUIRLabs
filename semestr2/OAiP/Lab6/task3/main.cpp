#include <iostream>
#include "cstack.h"
#include "HashTable.h"
int main()
{
    std::cout <<"Start" << std::endl;
    HashTable<int> table(90);
    for(int i = 0; i<10; i++)
    {
        table.insert(1-i*90, 1-i*90);
    }
    for(int i = 0; i<10; i++)
    {
        std::cout << table.find(1-i*90) << std::endl;
    }
    // std::cout << -10%3 << std::endl;
}