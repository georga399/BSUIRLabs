#include <iostream>
#include <string>
void InputStr(std::string &str);
void FromTrueToCompl(std::string &str); // O(n)
void contextmenu();
int main()
{
    contextmenu();
    std::string str;
    std::cout << "Input integers in true code:\n";
    InputStr(str);
    std::cout << "Result:\n";
    FromTrueToCompl(str);
    std::cout << str << std::endl;

}
void InputStr(std::string &str)
{
    bool validinput = 0;
    while (!validinput)
    {
        std::getline(std::cin, str);
        int i = 0;
        for (i; i<str.length(); i++)
        {
            if (!(str[i] == '1' || str[i]=='0'))
            {
                break;
            }
        }
        if(i==str.length()) validinput = 1;
        else std::cout << "Error input. Try again:\n";
    }
    
    

}
void FromTrueToCompl(std::string &str) // O(n)
{
    if(str[0] == '1')
    {
        for(int i = 1; i<str.length(); i++)
        {
            str[i] = (str[i] == '0') ? '1' : '0';
        }
    }
}
void contextmenu()
{
    std::cout << "Made by Egor Azarov(253501)" << std::endl;
    std::cout << "Task 1:\n";
    std::cout << "User enter integer in true code. Then program print this digit in complement on-one.\n";
    std::cout <<"----------------------------------------\n";
}