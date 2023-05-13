#include "Struct.h"
void ShowAllConversations(conversation ** convers, int &size)
{
    if(size == 0)
    {
        std::cout<< "Is empty...";
    }
    else
    {
        for(int i = 0; i<size; i++)
        {
            std::cout<< "#" << i  << std::endl;
            std::cout<< "City: " << (*convers)[i].city << std::endl;
            std::cout<< "Date: " << (*convers)[i].date << std::endl;
            std::cout<<"Tarriff: " << (*convers)[i].tariff << std::endl;
            std::cout<< "Duration: " << (*convers)[i].duration << std::endl;
            std::cout<< "Number of caller: " << (*convers)[i].numberofcaller << std::endl; 
            std::cout<< "Number of calling: " << (*convers)[i].numberofcalling << std::endl;
            std::cout << "_______________________" << std::endl;
        }
        
    }
    char ch = _getch();
    std::cout << "\x1B[2J\x1B[H";
}
void ShowDataforCity(conversation ** convers, int &size)
{
    std::cout << "\x1B[2J\x1B[H";
    std::cout << "Enter city: ";
    std::string city;
    InputStr(city);
    bool isempty = 0;
    for(int i = 0; i<size; i++)
    {
        if((*convers)[i].city == city)
        {
            std::cout << "#" << i << std::endl;
            std::cout<< "City: " << (*convers)[i].city << std::endl;
            std::cout<< "Date: " << (*convers)[i].date << std::endl;
            std::cout<<"Tarriff: " << (*convers)[i].tariff << std::endl;
            std::cout<< "Duration: " << (*convers)[i].duration << std::endl;
            std::cout<< "Number of caller: " << (*convers)[i].numberofcaller << std::endl; 
            std::cout<< "Number of calling: " << (*convers)[i].numberofcalling << std::endl;
            std::cout << "_______________________" << std::endl;
            isempty = 1;
        }
    }
    if(!isempty)
    {
        std::cout << "Not found..." << std::endl;
    }
    std::cout << "To continue press button..." << std::endl;
    char ch = _getch();
    std::cout << "\x1B[2J\x1B[H";
}