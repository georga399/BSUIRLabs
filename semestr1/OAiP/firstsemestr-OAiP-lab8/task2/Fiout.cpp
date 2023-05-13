#include "Struct.h"
void ReadFromFile(conversation ** convers, int &size)
{
    std::fstream in("../task2/input.txt", std::ios::in);
    std::string s;
    std::getline(in, s);
    if (s==""|| s=="0") 
    {
        size = 0;
        return;
    }
    if(size != 0) delete [] (*convers);
    size = std::stoi(s);
    (*convers) = new conversation[size];
    for(int i = 0; i<size; i++)
    {
        std::getline(in, (*convers)[i].numberofcaller);
        std::getline(in, (*convers)[i].numberofcalling);
        std::getline(in, (*convers)[i].date);
        std::getline(in, (*convers)[i].city);
        std::getline(in, s);
        (*convers)[i].duration = std::stod(s);
        std::getline(in, s);
        (*convers)[i].tariff = std::stod(s);
    }
}
void WriteToFile(conversation ** convers, int &size)
{
    std::fstream out("../task2/output.txt", std::ios::out);
    for(int i = 0; i<size; ++i)
    {
        out<< "#" << i  << std::endl;
        out<< "City: " << (*convers)[i].city << std::endl;
        out<< "Date: " << (*convers)[i].date << std::endl;
        out<<"Tarriff: " << (*convers)[i].tariff << std::endl;
        out<< "Duration: " << (*convers)[i].duration << std::endl;
        out<< "Number of caller: " << (*convers)[i].numberofcaller << std::endl; 
        out<< "Number of calling: " << (*convers)[i].numberofcalling << std::endl;
        out << "_______________________" << std::endl;
    }
}