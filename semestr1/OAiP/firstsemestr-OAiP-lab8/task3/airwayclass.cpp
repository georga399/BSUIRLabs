#include "airwayclass.h"

void airway::setNumber(unsigned long long number)
{
    this->number = number;
}

void airway::setTypeofplane(std::string str)
{
    this->typeofplane = str;
}

void airway::setTimedep(std::string str)
{
    this->timedep = str;
    std::string strhours, strmins;
    int mins;
    strmins.append(str, 3, 2);
    mins = std::stoi(strmins);
    strhours.append(str, 0 ,2);
    mins += std::stoi(strhours)*60;
    this->countofmins = mins;
}

void airway::setDestination(std::string dest)
{
    this->destination = dest;
}

void airway::coutAirway()
{
    std::cout << "Number: " << this->number << std::endl;
    std::cout << "Time departure: " << this->timedep << std::endl;
    std::cout << "Destination: " << this->destination <<std::endl;
    std::cout << "Type of plane: " << this->typeofplane << std::endl;
    std::cout << "_______________________" << std::endl;
}

unsigned long long airway::GetNumber()
{
    return this->number;
}

std::string airway::GetDestination()
{
    return this->destination;
}

std::string airway::GetTimedep()
{
    return this->timedep;
}

std::string airway::GetTypeofPlane()
{
    return this->typeofplane;
}

int airway::GetMinutes()
{
    return this->countofmins;
}