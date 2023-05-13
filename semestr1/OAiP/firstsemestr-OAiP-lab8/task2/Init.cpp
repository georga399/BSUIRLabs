#include "Struct.h"
// void InitConversations(conversation ** convers, int &size)
// {
//     std::cout << "Initialisation... Enter size of array: ";
//     size = InputInt(1, 100000);
//     if (size==-1) 
//     {
//         size = 0;
//         return;
//     }
//     (*convers) = new conversation[size];
//     int counter = 0;
//     bool tocontinueinp = 1;
//     do
//     {
//         if(tocontinueinp)
//         {
//             std::cout << "#"<<counter << std::endl;
//             std::cout << "Enter number of caller: ";
//             InputNumber((*convers)[counter].numberofcaller);
//             if((*convers)[counter].numberofcaller == "EXIT")
//             {
//                 delete [] (*convers);
//                 size = 0;
//                 return;
//             } 
//             std::cout << "Enter number of calling: ";
//             InputNumber((*convers)[counter].numberofcalling);
//             if((*convers)[counter].numberofcalling == "EXIT")
//             {
//                 delete [] (*convers);
//                 size = 0;
//                 return;
//             } 
//             std::cout << "Enter date of conversation: ";
//             InputDate((*convers)[counter].date);
//             if((*convers)[counter].date == "EXIT")
//             {
//                 delete [] (*convers);
//                 size = 0;
//                 return;
//             }
//             std::cout << "Enter city: ";
//             InputStr((*convers)[counter].city);
//             if((*convers)[counter].city == "EXIT")
//             {
//                 delete [] (*convers);
//                 size = 0;
//                 return;
//             }
//             std::cout << "Enter duration of conversation: ";
//             (*convers)[counter].duration = InputD();
//             if((*convers)[counter].duration == -DBL_MAX)
//             {
//                 delete [] (*convers);
//                 size = 0;
//                 return;
//             }
//             std::cout << "Enter tarriff: ";
//             (*convers)[counter].tariff = InputD();
//             if((*convers)[counter].tariff == -DBL_MAX)
//             {
//                 delete [] (*convers);
//                 size = 0;
//                 return;
//             }
//             if(counter != size-1) 
//             {
//                 std::cout << "Continue to input(y/n): ";
//                 std::string s;
//                 while(s!="y" && s!="n" && counter < size-1)
//                 {
//                     if(s.size() != 0 )
//                     {
//                         std::cout << "Error...(only 'y' or'n'). Try again: ";
//                     }
//                     std::getline(std::cin, s);
//                 }
//                 if(s=="n") tocontinueinp = 0;
//             }
//         }
//         else
//         {
//             GenerateRandConv((*convers)[counter]);
//         }
//         counter++;
//     } while (counter < size);
// }
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
void InputStr(std::string &str)
{
    // std::cin >> str;
    std::getline(std::cin, str);
}
void InputDate(std::string &str)
{   
    bool isvalid = 0;
    std::string temp;
    while (!isvalid)
    {
        std::getline(std::cin, temp);
        if(temp == "EXIT") 
        {
            str = "EXIT";
            return;
        }
        if(temp.size() != 10 || temp[2] != '.' || temp[5] != '.')
        {
            std::cout<<"Error input date value... (should be XX.XX.XXXX).Try again: ";
            continue;
        }
        int day, month, year;
        std::string strday, strmonth, stryear;
        strday.append(temp, 0, 2);
        strmonth.append(temp, 3, 2);
        stryear.append(temp, 6, 4);
        for(int i = 0; i<2; i++)
        {
            if(!isdigit(strday[i]) || !(isdigit(strmonth[i])))
            {
                std::cout<<"Error input date value... (should be XX.XX.XXXX).Try again: ";
                break;
            }
        }
        for(auto a: stryear)
        {
            if(!isdigit(a))
            {
                std::cout<<"Error input date value... (should be XX.XX.XXXX).Try again: ";
                break;
            }
        }
        day = std::stoi(strday);
        month = std::stoi(strmonth);
        if(day>31 || month>12) 
        {
            std::cout<<"Error input date value... (should be XX.XX.XXXX).Try again: ";
            continue;
        }
        isvalid = 1;
    }   
    str = temp;
}
void InputNumber(std::string &str) // 10 digits
{
    bool isvalid = 0;
    while (!isvalid)
    {
        std::getline(std::cin, str);
        if(str == "EXIT") 
        {
            str = "EXIT";
            return;
        }
        if(str.size() != 10)
        {
            std::cout << "Error number... Input 10 digits without space (0000000000): ";
            continue;
        }
        int i = 0;
        for(i; i<10; i++)
        if(!isdigit(str[i])) 
        {
            std::cout << "Error number... Input 10 digits without space (0000000000): ";
            break;
        }

        if(i==10) isvalid = 1;
    }
    
    
}
double InputD()
{
    bool isvalid = 0;
    std::string str;
    double res;
    while(!isvalid)
    {
        std::getline(std::cin, str);
        if(str == "EXIT") return -DBL_MAX;
        if(str.size() > 6 && str.size() == 0)
        {
            std::cout << "Error input double value... Try again: ";
            continue;
        }
        int i =0;
        int countofdots = 0;
        for(i; i<str.size(); i++)
        {
            if(!(str[i]>='0' && str[i]<='9'  || (str[i] = '.' && countofdots++ == 0))) // Скользкий момент
            {
                std::cout << "Error input float value... Try again: ";
                break;
            }
        }
        if(i == str.size() && (res = std::stod(str))) isvalid = 1;
    }   
    return res;
}
// void GenerateRandNumber(std::string &s)
// {
//     for(int i = 0; i<10; i++)
//     {
//         s.push_back(char(rand()%10 + 48));
//     }
// }
// void GenerateDate(std::string &d)
// {
//     // time_t t1 = time(NULL);
//     // tm t = *localtime(&t1);
//     // d.push_back(t.tm_mday);
//     // d.push_back('.');
//     // d.push_back(t.tm_mon);
//     // d.push_back('.');
//     // d.push_back(t.tm_year);
//     d = "12.12.1212";
// }
// void GenerateRandConv(conversation& conver)
// {
//     std::string cities[9] = {"LA", "NY", "Minsk", "Gomel", "Mahilyow", "Moscow", "Brest", "Grodno", "Vitebsk"};
//     GenerateRandNumber(conver.numberofcaller);
//     GenerateRandNumber(conver.numberofcalling);
//     GenerateDate(conver.date);
//     srand(time(0));
//     conver.duration = double(rand())/RAND_MAX*100;
//     conver.tariff = double(rand())/RAND_MAX*100;
//     conver.city = cities[rand()%9];
// }