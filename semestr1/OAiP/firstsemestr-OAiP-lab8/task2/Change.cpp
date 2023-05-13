#include "Struct.h"

void AddConverstion(conversation ** convers, int &size)
{
    std::cout << "\x1B[2J\x1B[H";
    conversation * temp = new conversation[size+1];
    for(int i = 0; i < size; i++)
    {
        temp[i] = (*convers)[i];
    }
    std::cout << "#"<<size << std::endl;
    std::cout << "Enter number of caller: ";
    InputNumber((temp)[size].numberofcaller);
    if((temp)[size].numberofcaller == "EXIT")
    {
        delete [] (temp);
        return;
    } 
    std::cout << "Enter number of calling: ";
    InputNumber((temp)[size].numberofcalling);
    if((temp)[size].numberofcalling == "EXIT")
    {
        delete [] (temp);
        return;
    }
    std::cout << "Enter date of conversation: ";
    InputDate((temp)[size].date);
    if((temp)[size].date == "EXIT")
    {
        delete [] (temp);
        return;
    }
    std::cout << "Enter city: ";
    InputStr((temp)[size].city);
    if((temp)[size].city == "EXIT")
    {
        delete [] (temp);
        return;
    }
    std::cout << "Enter duration of conversation: ";
    (temp)[size].duration = InputD();
    if((temp)[size].duration == -DBL_MAX)
    {
        delete [] (temp);
        return;
    }
    std::cout << "Enter tarriff: ";
    (temp)[size].tariff = InputD();
    if((temp)[size].tariff == -DBL_MAX)
    {
        delete [] (temp);
        return;
    }
    size++;
    delete [] (*convers);
    (*convers) = temp;
    std::cout << "\x1B[2J\x1B[H";
}
void DeleteConverstion(conversation ** convers, int &size)
{
    std::cout << "\x1B[2J\x1B[H";
    std::cout << "Enter id of conversation you want to delete: ";
    int id = InputInt(0, size-1);
    if(id == -1) return;
    std::cout << "Are you sure? ('y' or 'n'): ";
    conversation * temp = new conversation[size-1];
    int counter = 0;
    for(int i = 0; i<size; i++)
    {
        if(id!=i)
        {
            temp[counter] = (*convers)[i];
            counter++;
        }
    }
    size--;
    delete [](*convers);
    (*convers) = temp;
    std::cout << "\x1B[2J\x1B[H";
}
void ChangeConversation(conversation ** convers, int &size)
{
    std::cout << "\x1B[2J\x1B[H";
    std::cout << "Choose id to edit: ";
    int id = InputInt(0, size-1);
    if(id==-1) return;
    std::cout << "#" << id << std::endl;
    std::cout<< "0.City: " << (*convers)[id].city << std::endl;
    std::cout<< "1.Date: " << (*convers)[id].date << std::endl;
    std::cout<< "2.Tarriff: " << (*convers)[id].tariff << std::endl;
    std::cout<< "3.Duration: " << (*convers)[id].duration << std::endl;
    std::cout<< "4.Number of caller: " << (*convers)[id].numberofcaller << std::endl; 
    std::cout<< "5.Number of calling: " << (*convers)[id].numberofcalling << std::endl;
    std::cout << "_______________________" << std::endl;   
    std::cout << "Enter digit (0-5): ";
    int activemenu = InputInt(0, 5);
    if (activemenu == -1) return; 
    std::cout << "New value: ";
    std::string buf;
    double temp;
    switch (activemenu)
    {
    case 0:
        InputStr(buf);
        if(buf == "EXIT") return;
        (*convers)[id].city = buf;
        // InputStr((*convers)[id].city);
        break;
    case 1:
        InputDate(buf);
        if(buf == "EXIT") return;
        (*convers)[id].date = buf;
        // InputDate((*convers)[id].date);
        break;
    case 2:
        temp = InputD();
        if(temp == -DBL_MAX) return;
        (*convers)[id].tariff = temp;
        break;
    case 3: 
        temp = InputD();
        if(temp == -DBL_MAX) return;
        (*convers)[id].duration = temp;
        break;
    case 4:
        InputNumber(buf);
        if(buf == "EXIT") return;
        (*convers)[id].numberofcaller = buf;
        // InputNumber((*convers)[id].numberofcaller);
        break;
    case 5:
        InputNumber(buf);
        if(buf == "EXIT") return;
        (*convers)[id].numberofcalling = buf;
        // InputNumber((*convers)[id].numberofcalling);
        break;
    default:
        break;
    }
    std::cout << "To continue press button..." << std::endl;
    char ch = _getch();
    std::cout << "\x1B[2J\x1B[H";
}