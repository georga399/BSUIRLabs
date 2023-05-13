#include <iostream>
#include <string>
#include <exception>
#include <limits>
long double InputLD()
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

int InputInt(int inf = INT_MIN, int sup = INT_MAX)
{
    int val;
    while (!(std::cin >> val) || (std::cin.peek()) != '\n' || val>sup || val<inf)
	{
		// std::cin.clear();
        // std::cin.ignore(1024, '\n');
		while (std::cin.get() != '\n');
		
        std::cout << "Error input. Try again: ";
	}
    std::cin.clear();
    std::cin.ignore(1024, '\n');
    return val;
}