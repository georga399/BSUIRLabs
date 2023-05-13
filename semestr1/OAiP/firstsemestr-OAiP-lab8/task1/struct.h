#ifndef CUSTOMERS
#define CUSTOMERS
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <cmath>
#include <limits>
struct Customer
{
    int id;
    long double discount;
    char* name;
    char* surname;
    char* patronymic;
    char* address;
};
void CreateCustomers(Customer**,int &n);
void PrintCustomers(Customer**, int &n);
void PrintAwesomeCustomers(Customer**, int &n);
void DeleteCustomer(Customer**, int &);
void ChangeCustomer(Customer**, int&);
void NewCustomer(Customer**, int &n);
void FreeCustomers(Customer** customers, int &size);
void SortCustomers(Customer**, int &size);
////
bool is_five(long double a);
long double InputLD();
int InputInt(int min, int max);
void InputStr(char** str);
#endif