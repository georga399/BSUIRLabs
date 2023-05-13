#include <iostream>
#include <string>
#include <exception>
#include <limits>
extern "C" __declspec(dllexport) int InputInt(int inf = INT_MIN, int sup = INT_MAX)
{
    bool isvalidinput = 0;
    std::string str;
    int out;
    while (!isvalidinput)
    {    
        std::getline(std::cin, str);
        int i = 0;
        int b = 1;
        if(str[i] == '-')
        {
            b=-1;
            i++;
        }
        for(;i<str.length(); i++)
        {
            if(str[i]<='9' && str[i]>='0')
            {
                continue;
            }
            else
            {
                break;
            }
        }
        if(i == str.length())
        {
            try
            {
                out = stoi(str);
            }
            catch(std::exception &e)
            {
                std::cout << "Error input. Please, try again: ";
                continue;
            }
            if(out<inf || out >sup)
            {
                std::cout << "Error input. Please, try again: ";
                continue;
            }
            isvalidinput=1;
        }   
        else
        {
            std::cout << "Error input. Please, try again: ";
        }
    }
    return out;
}
extern "C" __declspec(dllexport) long double InputLD()
{
    std::string str;
    bool validinput = 0;
    long double ld;
    while(!validinput)
    {
        std::getline(std::cin, str);
        int howmanydots = 0;
        int howmanye = 0;
        int posofe = -1;
        if(!((*str.begin() >= '0' && *str.begin() <='9') || *str.begin() == '-'))
        {
            
            std::cout << "Error input. Try again: ";
            continue;
        }
        int i = 0;
        for(; i<str.length(); i++)
        {
            char el = str[i];
            if((str[i]>= '0' && str[i]<='9') || (str[i] == '.' && howmanydots == 0 && i!=str.length()-1) || (str[i] == 'e' && howmanye==0) || (str[i] == '-' &&(posofe + 1 ==i || i==0) ))
            {
                if(str[i]=='.')
                {
                    howmanydots++;
                }
                if(str[i]=='e')
                {
                    posofe = i;
                    howmanye++;
                }
                continue;
            }
            
            else
            {
                break;
            }
        }
        if(i==str.length())
        {
            validinput = 1;
            try{
                ld = std::stold(str);
            }
            catch(std::exception &e)
            {
                std::cout << "Error input. Try again: ";
                validinput = 0;
            }
            
        }
        else 
        {
            std::cout << "Error input. Try again: ";
        }
    }
    return ld;
}