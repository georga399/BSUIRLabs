#include "struct.h"
void SortCustomers(Customer** customers, int &size)
{
    printf("\033[2J\033[1;1H");
    printf("Please wait...");
    for(int i = 0; i<size; i++)
    {
        int j = i-1;
        int x = (*customers)[i].discount;
        while (j>=0 && x<(*customers)[j].discount)
        {
            std::swap((*customers)[j], (*customers)[j+1]);
            j--;
        }
    }
}