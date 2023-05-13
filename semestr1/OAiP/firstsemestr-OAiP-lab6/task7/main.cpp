#include <iostream>
#include <string.h>
bool checkforonel(std::string &str)
{
    for(int i = 0; i<str.length(); i++)
    {
        if(str[i]!=str[0]) return 0;
    }
    return 1;
}
bool checkpol(std::string &str)
{
    for (int i = 0; i<str.length(); i++)
    {
        if (str[i] != str[str.length()-1-i])
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    std::string str; 
    std::cin >> str;
   if(checkforonel(str))
    {
        std::cout << -1;
    }
    else if(checkpol(str))
    {
        std::cout << str.length()-1;
    }
    else
    {
        std::cout << str.length();
    }
}