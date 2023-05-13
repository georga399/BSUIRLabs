#include <iostream>
#include <string>
#include <Windows.h>
#include <exception>
#include <conio.h>
void printnumbers(int id, int arr[]);
int InputVal();
int main()
{
    
    setlocale(LC_ALL, "Russian");
    int id;
    std::cout << "Введите номер отравленной бочки: ";
    id = InputVal();
    std::cout << "Пронумеруем каждую бочку в троичной системе счисления (Нажмите любую клавишу):\n";
    getch();
    int result[5];
    printnumbers(id, result);
    std::cout << "Номер разряда бочки соответствует id раба(значение 0 в этом разряде означает что раб с id разряда бочки не пил с этой бочки\nЗначение 1 - раб пьёт с этой бочки в первый день,\nЗначение 2 - раб пьёт с этой бочки во второй день)";
    std::cout << "_______________________________________";
    std::cout <<"\nЖертвы:\n";
    for (int i = 4; i>=0; i--)
    {
        if(result[i] != 0)
        {
            std::cout << "Раб id = " << i+1 << " умер на день номер " << result[i] <<std::endl; 
        }
    }
    std::cout << "Получаем номер бочки в троичной системе: ";
    int numofpoison = 0;
    int expofthree = 81;
    for(int i = 4; i>=0; i--)
    {
        numofpoison += result[i]*expofthree;
        std::cout << result[i];
        expofthree/=3;
    }
    std::cout<<"\nИли же в десятичной системе: "<<numofpoison;
}
void printnumbers(int id, int arr[])
{
    HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
    int d5 = 0, d4 = 0, d3 = 0, d2 = 0, d1 = 0;
    for(int i = 1; i<=240; i++)
    {
        
        bool itspoison = 0;
        if(i == id)
        {
            itspoison = 1;
            SetConsoleTextAttribute(hOUTPUT,FOREGROUND_RED   | FOREGROUND_INTENSITY);
        }
        d1++;
        if(d1 == 3) d2++;
        d1%=3;
        if(d2 == 3) d3++;
        d2%=3;
        if(d3==3) d4++;
        d3%=3;
        if(d4==3) d5++;
        d4%=3;
        std::cout << d5<< ' ' <<d4<<' '<< d3 <<' ' << d2 << ' '<< d1;
        
        std::cout << "   - " << i << std::endl;
        if(itspoison)
        {
            SetConsoleTextAttribute(hOUTPUT, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
            arr[0] = d1;
            arr[1] = d2;
            arr[2] = d3;
            arr[3] = d4;
            arr[4] = d5;
        }
        
    }
}
int InputVal()
{
    int res;
    bool isvalid = 0;
    while(!isvalid)
    {
        std::string str;
        std::getline(std::cin, str);
        int i = 0;
        for(; i<str.length(); i++)
        {
            if(!(str[i]>='0' && str[i]<='9')) break;
        }
        if(i==str.length()) 
        {
            try
            {
                res = stoi(str);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
                continue;
            }
            
        }
        else
        {
            std::cout << "Error. Try again: ";
            continue;
        }
        if(res>0 && res<=240)
        {
            isvalid =1;
        }
        else{
            std::cout << "Error value. Try again: ";
        }
    }
    return res;
}
