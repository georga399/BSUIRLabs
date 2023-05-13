#include "functions.h"
int InputInt(int min, int max)
{
    bool isvalid = 0;
    std::string str;
    int res;
    while(!isvalid)
    {
        std::getline(std::cin, str);
        if(str == "EXIT") return -1;
        if(str.size() > 6 || str.size() == 0)
        {
            std::cout << "Error input integer... Try again: ";
            continue;
        }
        int i = 0;
        for(i; i<str.size(); i++)
        {
            if(!(str[i]>='0' && str[i]<='9'))
            {
                std::cout << "Error input integer... Try again: ";
                break;
            }
        }
        if(i == str.size())
        {
            res = std::stoi(str);
            if(res>=min && res<=max) isvalid = 1;
            else std::cout << "Error... Try again: ";
        }
        
    }   
    return res;

}

unsigned long long InputNumber()
{
    bool isvalid = 0;
    std::string str;
    unsigned long long res;
    while(!isvalid)
    {
        std::getline(std::cin, str);
        if(str == "EXIT") return -1;
        if(str.size() > 17 || str.size() == 0)
        {
            std::cout << "Error input integer... Try again: ";
            continue;
        }
        int i = 0;
        for(i; i<str.size(); i++)
        {
            if(!(str[i]>='0' && str[i]<='9'))
            {
                std::cout << "Error input integer... Try again: ";
                break;
            }
        }
        if(i == str.size())
        {
            res = std::stoull(str);
            isvalid = 1;
            
        }
        
    }
    return res;
}

void InputStr(std::string &str)
{

    do
    {
        if(str.size()>20)
        {
            std::cout << "Error... Try again: ";
        }
        std::getline(std::cin, str);
        if(str == "EXIT") return;
    } while (str.size() > 20 || str.size() == 0);
    
    
}
void InputTime(std::string &tm)
{
    std::string buf;
    bool isvalid = 0;
    while(!isvalid)
    {
        std::getline(std::cin, buf);
        if(buf == "EXIT")
        {
            tm = "EXIT";
            return;
        } 
        if(buf.size() != 5 || buf[2] != ':') 
        {
            std::cout << "Error input... Should be (XX:XX): ";
            continue;
        }
        int hour, min;
        std::string strhour, strmin;
        strhour.append(buf, 0, 2);
        strmin.append(buf, 3, 2);
        int i = 0;
        for(; i<2; i++)
        {
            if(!isdigit(strhour[i]) || !isdigit(strmin[i]))
            {
                std::cout << "Error input... Should be (XX:XX): ";
                break;
            }
        }
        if(i==2)
        {
            hour = stoi(strhour);
            min = stoi(strmin);
        }
        if(hour>=0 && hour<24 && min>=0 && min <60)
        {
            isvalid = 1;
        }
        else 
        {
            std::cout << "Error input... Should be (XX:XX): ";
        }
    }
    tm = buf;
    
}