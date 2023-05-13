#include <iostream>
#include <string.h>
#include <Windows.h>
// int InputInt(int, int);
// long double InputLD();
//void InputelofArray(long double[]);
//bool algo(long double[], int, int);
void contextmenu()
{
    printf("\e[1;1H\e[2J");
    std::cout <<"Egor Azarov (253501)\n";
    std::cout << "Task 2(1):\n";
    std::cout << "Program check if exists element A[i] in array, that sin(a)>0.\n";
    std::cout <<"To start program enter any string: ";
    std::string str;
    std::getline(std::cin, str);
    std::cout << "-----------------------------------------------------------\n";
}
int main()
{   
    contextmenu();
    // HINSTANCE load1 = LoadLibrary("../../inputslib/build/libinputs.dll");
    // typedef int (*inputint)(int, int);
    // inputint InputInt = (inputint)GetProcAddress(load1, "InputInt");
    // typedef long double (*inputld)();
    // inputld InputLD = (inputld)GetProcAddress(load1, "InputLD");
    int (*InputInt)(int,int) = (int(*)(int, int))GetProcAddress(LoadLibrary("../../inputslib/build/libinputs.dll"), "InputInt");
    long double (*InputLD)() = (long double(*)())GetProcAddress(LoadLibrary("../../inputslib/build/libinputs.dll"), "InputLD");
   
    // HINSTANCE load2 = LoadLibrary("libalgo.dll");
    // typedef bool (*fun)(long double[], int, int);
    // fun algo = (fun)GetProcAddress(load2, "algo");
    bool (*algo)(long double[], int, int) = (bool(*)(long double[], int, int))GetProcAddress(LoadLibrary("libalgo.dll"), "algo"); 
    std::cout<<"Input size of array: ";
    int size = InputInt(1, 10000);
    long double * A = new long double[size];
    for(int i = 0; i<size; i++)
    {
        std::cout << "Input A["<<i<<"]: ";
        A[i] = InputLD();
    }
    std::cout << "-----------------------------------------------------------\n";
    if(algo(A, 0, size-1))
    {
        std::cout << "There is element A[i], that sin(A[i])>0";
    }
    else
    {
        std::cout << "Element A[i], that sin(A[i])>0, not found";   
    }
    //FreeLibrary(LoadLibrary("../../inputslib/build/libinputs.dll"));
    //FreeLibrary(LoadLibrary("libalgo.dll"));
}
