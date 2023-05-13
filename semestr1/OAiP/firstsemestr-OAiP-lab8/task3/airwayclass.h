#ifndef AIRWAYCLASS
#define AIRWAYCLASS
#include <string>
#include <iostream>
#include <stdio.h>


class airway
{   
private:
    union
    {
        unsigned long long number;
    };
    std::string typeofplane;
    std::string destination;
    std::string timedep;
    int countofmins;
    
public:
    void setNumber(unsigned long long);
    void setTypeofplane(std::string);
    void setDestination(std::string);
    void setTimedep(std::string);
    unsigned long long GetNumber();
    std::string GetDestination();
    std::string GetTimedep();
    std::string GetTypeofPlane();
    void coutAirway();
    int GetMinutes();
};

#endif