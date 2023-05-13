#include "struct.h"

int main()
{
    Customer * arr;
    int size = 0;
    CreateCustomers(&arr, size);
    while (1)
    {
        int activemenu;
        printf("\033[2J\033[1;1H");
        printf("0.Show all customers\n");
        printf("1.New customer\n");
        printf("2.Show customer with 5 percents discount\n");
        printf("3.Delete customer\n"); 
        printf("4.Edit customer\n");
        printf("5.Sort customers\n");
        printf("__________________\n");
        printf("Choose option (0-5): ");
        activemenu = InputInt(0,5);
        if(activemenu == 0) PrintCustomers(&arr, size);
        switch (activemenu)
        {
        case -1:

            exit(0);
            break;
        case 0:
            PrintCustomers(&arr, size);
            break;
        case 1:
            NewCustomer(&arr, size);
            break;
        case 2:
            PrintAwesomeCustomers(&arr, size);
            break;
        case 3:
            DeleteCustomer(&arr, size);
            break;
        case 4:
            ChangeCustomer(&arr, size);
            break;
        case 5:
            SortCustomers(&arr, size);
            break;
        default:
            break;
        }
    }
    
}