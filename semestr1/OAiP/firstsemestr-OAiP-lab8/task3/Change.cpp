#include "functions.h"
void AddAirway(FILE *fd)
{
    int size;
    fseek(fd, 0, SEEK_END);
    if(ftell(fd) == 0)
    {
        size = 0;
        fwrite(&size, sizeof(int), 1, fd);
    }
    else
    {
        fseek(fd, 0, SEEK_SET);
        fread(&size, sizeof(int), 1, fd);
        // size++;
        // fseek(fd, 0, SEEK_SET);
        // fwrite(&size, sizeof(int), 1, fd);
    }    
    airway buf;
    std::cout << "Input number: ";
    unsigned long long number = InputNumber();
    if(number == -1) return;
    for(int i = 0; i<size; i++)
    {
        fseek(fd, (sizeof(int) + 53*i) , SEEK_SET);
        int numforcomp;
        fread(&numforcomp, sizeof(unsigned long long), 1, fd);
        if(numforcomp == number)
        {
            std::cout << "Error.... This number already exists..." << std::endl;
            getch();
            return;
        }
    }
    size++;
    // fseek(fd, 0, SEEK_SET);
    // fwrite(&size, sizeof(int), 1, fd);
    
    std::cout << "Input time departure: ";
    std::string td;
    InputTime(td);
    if(td == "EXIT") return;
    
    std::cout << "Input type of plane: ";
    std::string type;
    InputStr(type);
    if(type == "EXIT") return;
    while(type.size()<20)
    {
        type.push_back(' ');
    }
    
    std::cout << "Input destination: ";
    std::string dest;
    InputStr(dest);
    if (dest == "EXIT") return;
    while(dest.size()<20)
    {
        dest.push_back(' ');
    }
    
    
    fseek(fd, 0, SEEK_SET);
    fwrite(&size, sizeof(int), 1, fd);

    fseek(fd, 0, SEEK_END);
    fwrite(&number, sizeof(unsigned long long), 1, fd);
    fwrite(td.c_str(), sizeof(char), strlen(td.c_str()), fd);
    fwrite(type.c_str(), sizeof(char), strlen(type.c_str()), fd);
    fwrite(dest.c_str(), sizeof(char), strlen(dest.c_str()), fd);

    getch();
}

void ChangeAirway(FILE *fd)
{
    unsigned long long usreq;
    std::cout << "Enter number: ";
    usreq = InputNumber();
    if(usreq == -1) return;
    int tsize;
    fseek(fd, 0, SEEK_END);
    if(ftell(fd) == 0)
    {
        std::cout << "Error to change...";
        return;
    }
    else
    {
        fseek(fd, 0L, SEEK_SET);
        fread(&tsize, sizeof(int), 1, fd);   
        if(tsize == 0)
        {
            std::cout <<"Empty..." << std::endl;
            getch();
            return;
        }
        
        for(int i =0; i<tsize; i++)
        {
            unsigned long long num;
            fseek(fd, (sizeof(int) + 53*i) , SEEK_SET);
            // std::cout << "pos: " << ftell(fd);
            fread(&num, sizeof(unsigned long long), 1, fd);
            // std::cout << "Num: " << num <<std::endl;
            if(num == usreq)
            {
                airway a;
                // a.setNumber(num);
                std::cout << "0. Number: " << num << std::endl;
                char buf[21];
                fread(buf, sizeof(char), 5, fd);
                buf[5] = '\0';
                std::cout << "1. Time departure: " << buf << std::endl;
                // a.setTimedep(buf);
                fread(buf, sizeof(char), 20, fd);
                buf[20] = '\0';
                std::cout << "2. Type of plane: " << buf << std::endl;
                // a.setTypeofplane(buf);
                fread(buf, sizeof(char), 20, fd);
                buf[20] = '\0';
                std::cout << "3. Destination: " << buf << std::endl;
                std::cout << "Choose area(0-3): ";
                int activearea = InputInt(0, 3);
                std::cout << "______________________" << std::endl;
                std::string str;
                if(activearea == -1)
                {
                    return;
                }
                else if(activearea == 0)
                {
                    std::cout << "Enter new number: ";
                    unsigned long long newnum = InputNumber();
                    if(newnum == -1) return;
                    fseek(fd, (sizeof(int) + i*53), SEEK_SET);
                    fwrite(&newnum, sizeof(unsigned long long), 1, fd);
                }
                else if(activearea == 1)
                {   
                    std::cout << "Enter new time: ";
                    // std::string tm;
                    InputTime(str);
                    if(str == "EXIT") return;
                    fseek(fd, (sizeof(int) + i*53 + sizeof(unsigned long long)), SEEK_SET);
                    fwrite(str.c_str(), sizeof(char), strlen(str.c_str()), fd);
                }
                else if(activearea == 2)
                {
                    std::cout << "Enter new type: ";
                    // std::string str;
                    InputStr(str);
                    if(str == "EXIT") return;
                    while(str.size()<20) str.push_back(' ');
                    fseek(fd, (sizeof(int) + i*53 + sizeof(unsigned long long) + 5), SEEK_SET);
                    fwrite(str.c_str(), sizeof(char), strlen(str.c_str()), fd);
                }
                else if(activearea == 3)
                {
                    std::cout << "Enter new destination: ";
                    // std::string str;
                    InputStr(str);
                    if(str == "EXIT") return;
                    while(str.size()<20) str.push_back(' ');
                    fseek(fd, (sizeof(int) + i*53 + sizeof(unsigned long long) + 5 + strlen(str.c_str())), SEEK_SET);
                    fwrite(str.c_str(), sizeof(char), strlen(str.c_str()), fd);
                }
            }
        }
        getch();
    }

}

void DeleteAirway(FILE *fd)
{
    int tsize;
    fseek(fd, 0, SEEK_END);
    if(ftell(fd) == 0)
    {
        std::cout << "Error to delete...";
        return;
    }
    fseek(fd, 0L, SEEK_SET);
    fread(&tsize, sizeof(int), 1, fd);   
    if(tsize == 0)
    {
        std::cout <<"Empty..." << std::endl;
        getch();
        return;
    }
    unsigned long long usreq;
    std::cout << "Enter number: ";
    usreq = InputNumber();
    if(usreq == -1) return;
    int counter = 0;
    for(; counter<tsize; counter++)
    {
        unsigned long long num;
        fseek(fd, (sizeof(int) + 53*counter) , SEEK_SET);
        fread(&num, sizeof(unsigned long long), 1, fd);
        if(num == usreq)
        {
            break;
        }
    }
    if(counter == tsize)
    {
        std::cout << "Not found....";
        getch();
        return;
    }
    else
    {
        for(int i = counter + 1; i<tsize; i++)
        {
            fseek(fd, sizeof(int) + i*53,SEEK_SET);
            airway a;
            unsigned long long num;
            fread(&num, sizeof(unsigned long long), 1, fd);
            a.setNumber(num);
            char buf[21];
            fread(buf, sizeof(char), 5, fd);
            buf[5] = '\0';
            a.setTimedep(buf);
            fread(buf, sizeof(char), 20, fd);
            buf[20] = '\0';
            a.setTypeofplane(buf);
            fread(buf, sizeof(char), 20, fd);
            buf[20] = '\0';
            a.setDestination(buf);
            // std::string buf;
            // fread(&buf, 53, 1, fd);
            fseek(fd, sizeof(int) + (i-1)*53, SEEK_SET);
            unsigned long long mmm = a.GetNumber();
            fwrite(&mmm, sizeof(unsigned long long), 1, fd);
            strcpy(buf, a.GetTimedep().c_str());
            fwrite(buf, sizeof(char), 5, fd);
            strcpy(buf, a.GetTypeofPlane().c_str());
            fwrite(buf, sizeof(char), 20, fd);
            strcpy(buf, a.GetDestination().c_str());
            fwrite(buf, sizeof(char), 20, fd);
            // fwrite(&buf, sizeof(std::string), 1, fd);
        }
        fseek(fd, 0L, SEEK_SET);
        tsize--;
        fwrite(&tsize, sizeof(int), 1, fd);
        _chsize(fileno(fd), sizeof(int) + tsize*53);
    }
}

void __makecorrect(FILE * fd)
{
    int size;
    fseek(fd, 0, SEEK_SET);
    fread(&size, sizeof(int), 1, fd);
    size--;
    fseek(fd, 0, SEEK_SET);
    fwrite(&size, sizeof(int), 1, fd);   
}