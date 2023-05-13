#include "struct.h"
#include <string>
void CreateCustomers(Customer** customers, int &n)
{
    std::string names[] = {"Crazy", "Frog", "Zin", "Yun"};
    std::string surnames[] = {"Cholera", "Chi", "Da"};
    std::string addr[] = {"Malinauka", "Piatroushina", "Mihalowa"};
    printf("Enter size: ");
    n = InputInt(1, 100000);
    if(n == -1)
    {
        n = 0;
        return;
    }
    *customers = (Customer*)malloc(n*sizeof(Customer));
    bool tocontinueinput = 1;
    for(int i = 0; i<n; i++)
    {
        if(tocontinueinput)
        {
            printf("#%d\n", i);
            printf("Input name: ");
            (*customers)[i].name = NULL;
            InputStr(&(*customers)[i].name);
            printf("Input surname: ");
            (*customers)[i].surname = NULL;
            InputStr(&(*customers)[i].surname);
            printf("Input patronymic: ");
            (*customers)[i].patronymic = NULL;
            InputStr(&(*customers)[i].patronymic);
            printf("Input address: ");
            (*customers)[i].address = NULL;
            InputStr(&(*customers)[i].address);
            printf("Input discount: ");
            (*customers)[i].discount = InputLD();
            if(i!=n-1)
            {

                printf("Continue input?(Y): ");
                char *str = NULL;
                InputStr(&str);
                char cmp[] = "Y";
                if(strcmp(str, cmp)) 
                        tocontinueinput = 0;
            }
        }
        else
        {
            int n = rand()%4;
            (*customers)[i].name = (char*)malloc(strlen(names[n].c_str()) +1);
            strcpy((*customers)[i].name, names[n].c_str());
            n = rand()%3;
            (*customers)[i].surname = (char*)malloc(strlen(surnames[n].c_str()) +1);
            strcpy((*customers)[i].surname, surnames[n].c_str());
            n = rand()%3;
            (*customers)[i].patronymic = (char*)malloc(strlen(names[n].c_str()) +1);
            strcpy((*customers)[i].patronymic, names[n].c_str());
            n = rand()%4;
            (*customers)[i].address = (char*)malloc(strlen(addr[n].c_str()) +1);
            strcpy((*customers)[i].address, addr[n].c_str());
            n = rand()%100;
            (*customers)[i].discount = n;
        }
    }  

}