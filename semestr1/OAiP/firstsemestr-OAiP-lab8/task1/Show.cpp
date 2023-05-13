#include "struct.h"
void PrintCustomers(Customer** customers, int &n)
{
    printf("\033[2J\033[1;1H");
    for(int i = 0; i<n; i++)
    {
        printf("#%d\n", i);
        printf("%s %s %s\nAddress: %s\nDiscount: %.2Lf\%\n", (*customers)[i].name, (*customers)[i].surname, (*customers)[i].patronymic, (*customers)[i].address, (*customers)[i].discount);
        printf("____________________\n");
    }
    getch();
}
void PrintAwesomeCustomers(Customer** customers, int &n)
{
    printf("\033[2J\033[1;1H");   
    
    for(int i = 0; i < n; i++)
    {
        if(is_five((*customers)[i].discount))
        {
            printf("#%d\n", i);
            printf("%s %s %s\nAddress: %s\nDiscount: %2Lf\%\n", (*customers)[i].name, (*customers)[i].surname, (*customers)[i].patronymic, (*customers)[i].address, (*customers)[i].discount);
            printf("____________________\n");
        }
    }
    getch();
       
}

bool is_five(long double a)
{
    return fabsl(a-5) < std::numeric_limits<long double>::epsilon();
}