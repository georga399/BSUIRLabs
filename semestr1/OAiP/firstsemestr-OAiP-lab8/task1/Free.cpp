#include "struct.h"
void FreeCustomers(Customer** customers, int &size)
{
    for(int i = 0; i < size; i++)
    {
        free((*customers)[i].name);
        free((*customers)[i].surname);
        free((*customers)[i].patronymic);
        free((*customers)[i].address);
    }
    free(*customers);
}