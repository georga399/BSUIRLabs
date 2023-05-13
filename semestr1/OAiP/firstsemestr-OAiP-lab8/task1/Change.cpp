#include "struct.h"
void NewCustomer(Customer** customers, int &n)
{
    printf("\033[2J\033[1;1H");   
    n++;
    (*customers) = (Customer*)realloc(*customers, n*sizeof(Customer));
    char buffer[128];
    printf("#%d\n", n-1);
    printf("Input name: ");
    (*customers)[n-1].name = NULL;
    InputStr(&(*customers)[n-1].name);
    printf("Input surname: ");
    (*customers)[n-1].surname = NULL;
    InputStr(&(*customers)[n-1].surname);
    printf("Input patronymic: ");
    (*customers)[n-1].patronymic = NULL;
    InputStr(&(*customers)[n-1].patronymic);
    printf("Input address: ");
    (*customers)[n-1].address = NULL;
    InputStr(&(*customers)[n-1].address);
    printf("Input discount: ");
    (*customers)[n-1].discount = InputLD();
}

void DeleteCustomer(Customer** customers, int &size)
{
    printf("\033[2J\033[1;1H");   
    printf("Choose id of customer to delete: ");
    int id = InputInt(0, size-1);
    printf("\nAre you sure(yes): ");
    char cc[4];
    scanf("%4s", cc);
    if(!stricmp(cc, "yes"))
    {

        Customer* temp = (Customer*)malloc(size*sizeof(Customer));
        for(int i = 0; i<size; i++)
        {
            temp[i] = (*customers)[i];
        }
        free(*customers);
        *customers = (Customer*)malloc((--size)*sizeof(Customer));
        int counter = 0;
        for(int i = 0; i<size+1; i++)
        {
            if(id!=i)
            {
                (*customers)[counter] = temp[i];
                (*customers)[counter].id = counter;
                counter++;
            }
        }
    }
}

void ChangeCustomer(Customer** customers, int &n)
{
    printf("\033[2J\033[1;1H");   
    printf("Enter id of customer you want edit: ");
    int id = InputInt(0, n-1);
    printf("0.Name: %s\n", (*customers)[id].name);
    printf("1.Surame: %s\n", (*customers)[id].surname);
    printf("2.Patronymic: %s\n", (*customers)[id].patronymic);
    printf("3.Address: %s\n", (*customers)[id].address);
    printf("4.Discount: %2Lf\n", (*customers)[id].discount);
    printf("_________________\n");
    printf("Choose area you want to edit(0-4): ");
    int active_area = InputInt(0, 4);
    printf("New value: ");
    switch (active_area)
    {
    case 0:
        InputStr(&(*customers)[id].name);
        break;
    case 1:
        InputStr(&(*customers)[id].surname);
        break;
    case 2:
        InputStr(&(*customers)[id].patronymic);
        break;
    case 3:
        InputStr(&(*customers)[id].address);
        break;
    case 4:
        long double val = InputLD();
        (*customers)[id].discount = val;
        break;
    }

    
}