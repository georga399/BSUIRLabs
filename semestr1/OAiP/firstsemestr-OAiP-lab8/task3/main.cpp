#include "airwayclass.h"
#include "functions.h"
int main()
{
    airway * airways;
    int size = 0;
    FILE *fd;
    fd = fopen("../task3/base.bin", "r+b");
    while (1)
    {
        std::cout << "0. Add airway" << std::endl;
        std::cout << "1. Show all airways" << std::endl;
        std::cout << "2. Show airway for destination" << std::endl;
        std::cout << "3. Change airway" << std::endl;
        std::cout << "4. Delete airway" << std::endl;
        int activemenu = InputInt(0, 4);
        switch (activemenu)
        {
        case -1:
            fclose(fd);
            exit(0);
        case 0:
            AddAirway(fd);
            break;
        case 1:
            ShowAllAirways(fd);
            break;
        case 2:
            ShowAirwaysforDestin(fd);
            break;
        case 3:
            ChangeAirway(fd);
            break;
        case 4:
            DeleteAirway(fd);
            break;
        default:
            break;
        }
    }
    
}