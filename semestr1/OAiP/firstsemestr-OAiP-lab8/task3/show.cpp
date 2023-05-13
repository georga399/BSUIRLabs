#include "functions.h"

void ShowAllAirways(FILE *fd)
{
    fseek(fd, 0, SEEK_END);
    if(ftell(fd) == 0)
    {
        std::cout << "Empty..." <<std::endl;
        getch();
        return;
    }
    int size;
    fseek(fd, 0L, SEEK_SET);
    fread(&size, sizeof(int), 1, fd);
    if(size == 0)
    {
        std::cout <<"Empty..." << std::endl;
        getch();
        return;
    }
    for(int i = 0; i<size; i++)
    {
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
        a.coutAirway();
    }
    getch();
}

void ShowAirwaysforDestin(FILE *fd)
{
    std::cout << "Enter destination: ";
    std::string dest;
    InputStr(dest);
    if(dest == "EXIT") return;
    while (dest.size()<20)
    {
        dest.push_back(' ');
    }
    
    fseek(fd, 0, SEEK_END);
    if(ftell(fd) == 0)
    {
        std::cout << "Empty..." <<std::endl;
        getch();
        return;
    }
    int size;
    fseek(fd, 0L, SEEK_SET);
    fread(&size, sizeof(int), 1, fd);
    if(size == 0)
    {
        std::cout <<"Empty..." << std::endl;
        getch();
        return;
    }
    int countofsearchedairways = 0;
    for(int i = 0; i<size; i++)
    {
        fseek(fd, (sizeof(int) + 53*i + sizeof(unsigned long long) + 5 + 20) , SEEK_SET);
        char buf[21];
        fread(buf, sizeof(char), 20, fd);
        buf[20] = '\0';
        if(strcmp(buf, dest.c_str()) == 0) countofsearchedairways++;
    }
    if(countofsearchedairways == 0)
    {
        std::cout << "Not found..." << std::endl;
        getch();
        return;
    }
    airway * airways = new airway[countofsearchedairways];
    int tcounter = 0;
    for(int i = 0; i<size; i++)
    {
        fseek(fd, (sizeof(int) + 53*i + sizeof(unsigned long long) + 5 + 20) , SEEK_SET);
        char buf[21];
        fread(buf, sizeof(char), 20, fd);
        buf[20] = '\0';
        if(strcmp(buf, dest.c_str()) == 0)
        {
            unsigned long long num;
            fseek(fd, (sizeof(int) + 53*i) , SEEK_SET);
            fread(&num, sizeof(unsigned long long), 1, fd);
            airways[tcounter].setNumber(num);
            char tbuf[21];
            fread(tbuf, sizeof(char), 5, fd);
            tbuf[5] = '\0';
            airways[tcounter].setTimedep(tbuf);
            fread(tbuf, sizeof(char), 20, fd);
            tbuf[20] = '\0';
            airways[tcounter].setTypeofplane(tbuf);
            airways[tcounter].setDestination(buf);
            tcounter++;
        }
    }
    if(countofsearchedairways > 1)
        _sortairways(airways, 0, countofsearchedairways -1);
    for(int i = 0; i<countofsearchedairways; i++)
    {
        std::cout << "Minutes: " << airways[i].GetMinutes() << std::endl;
        airways[i].coutAirway();
    }
    delete [] airways;
}

void _sortairways(airway * arr, int b, int e)
{
 
  int l = b, r = e;
  int piv = arr[(l + r) / 2].GetMinutes(); 
  while (l <= r)
  {
    while (arr[l].GetMinutes() < piv)
      l++;
    while (arr[r].GetMinutes() > piv)
      r--;
    if (l <= r)
      std::swap(arr[l++], arr[r--]);
  }
  if (b < r)
    _sortairways(arr, b, r);
  if (e > l)
    _sortairways(arr, l, e);
}
// void _sortairways(airway * arr, int b, int e)
// {
//     for (int i = 0; i < e+1; i++) {
//     for (int j = 0; j < e; j++) {
//       if (arr[j].GetMinutes() > arr[j + 1].GetMinutes()) {
//         std::swap(arr[i], arr[j]);
//       }
//     }
//   }
// }