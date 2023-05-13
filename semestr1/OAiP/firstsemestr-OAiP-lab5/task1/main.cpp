#include <iostream>
#include <string>
#include <windows.h>

//long double InputLD();
//int InputInt(int,int);
void InputElofArray(long double [], int size, long double(*InputLD)());
void Solve(long double[], long double[], long double[], int);
void contextmenu()
{
    printf("\e[1;1H\e[2J");
    std::cout <<"Egor Azarov (253501)\n";
    std::cout << "Task 1(1):\n";
    std::cout << "Program solve equation a*x + b = 0, where a and b - elements of array A and B.\n";
    std::cout <<"To start program enter any string: ";
    std::string str;
    std::getline(std::cin, str);
    std::cout << "-----------------------------------------------------------\n";
}
int main()
{
    contextmenu();
    //HINSTANCE load = LoadLibrary("../../inputslib/build/libinputs.dll");
    // typedef int (*inputint)(int, int);
    // inputint InputInt = (inputint)GetProcAddress(load, "InputInt");
    
    // int (*InputInt) (int, int);
    int (*InputInt)(int,int) = (int(*)(int, int))GetProcAddress(LoadLibrary("../../inputslib/build/libinputs.dll"), "InputInt");
    long double (*InputLD)() = (long double(*)())GetProcAddress(LoadLibrary("../../inputslib/build/libinputs.dll"), "InputLD");

    // typedef long double (*inputld)();
    // inputld InputLD = (inputld)GetProcAddress(load, "InputLD");   
    std::cout << "Input size of arrays: ";
    int size = InputInt(1, 10000);
    long double * A = new long double[size];
    long double * B = new long double[size];
    long double * X = new long double[size];
    std::cout << "Input elements of array A:\n";
    InputElofArray(A, size, InputLD);
    std::cout << "Input elements of array B:\n";
    InputElofArray(B, size, InputLD);
    Solve(X, A, B, size);
    std::cout << "-----------------------------------------------------------\n";
    std::cout << "Result: \n";
    for(int i =0; i<size; i++)
    {
        std::cout <<  X[i] << ' ';
    }
    delete []A;
    delete []B;
    delete []X;
    //FreeLibrary(LoadLibrary("../../inputslib/build/libinputs.dll"));
}
void InputElofArray(long double T[], int size, long double(*InputLD)())
{
    for(int i = 0; i<size; i++)
    {
        std::cout << "input element number " << i << " :"; 
        T[i] = InputLD();
    }
}
