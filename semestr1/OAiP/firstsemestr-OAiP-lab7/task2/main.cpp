#include <iostream>
#include <string>
#include <exception>
#define LENGTHOFDIG 100
// void InputStr(std::string &str);
long long InputLL();
void ConvertToAdt(std::string &str);// O(n) - worst; O(1) - good
void Sum(std::string &s1, std::string &s2, std::string &res); //O(n)
void ConvertToTrue(std::string &str); // O(n)
void contextmenu();
void FromNattyToTrue(std::string &str, int val); //O(n)
int main()
{
    contextmenu();
    while(true)
    {
        std::string s1(LENGTHOFDIG, '0'), s2(LENGTHOFDIG, '0'), res(LENGTHOFDIG, '0');
        long long val1, val2;
        std::cout << "Input first value: \n";
        val1 = InputLL();
        FromNattyToTrue(s1, val1);
        std::cout << "Input second value: \n";
        val2 = InputLL();
        FromNattyToTrue(s2, val2);
        ConvertToAdt(s2);
        ConvertToAdt(s1);
        Sum(s1, s2, res);
        ConvertToTrue(res);
        std::cout << "Result:\n";
        std::cout << res << std::endl;
        std::cout << "____________________\n";

    }
}
// void InputStr(std::string &str)
// {
//     bool validinput = 0;
//     while(!validinput)
//     {
//         int i = 0;
//         int countofdots = 0;
//         std::getline(std::cin, str);
//         for (i; i<str.length(); i++)
//         {
//             if(str[i] == '.')
//             {
//                 if(!countofdots && i>0)
//                 {
//                     countofdots++;
//                     continue;
//                 }
//                 else 
//                 {
//                     break;
//                 }
//             }
//             if(!(str[i] == '1' || str[i] == '0'))
//             {
//                 break;
//             }
//         }
//         if(i == str.length())
//         {
//             validinput = 1;
//             if(countofdots == 0)
//             {
//                 str.push_back('.');
//             }
//         }
//         else 
//         {
//             std::cout << "Error input. Try again:\n";
//         }
//     }
// }
void ConvertToAdt(std::string &str)
{
   if(str[0] == '1')
    {
        char prev = '1';
        for(int i=str.length()-1; i>0; i--)
        {
            str[i] = (str[i]=='0') ? '1' : '0';
            char t = str[i];
            str[i] = char((prev^(str[i])) + 48);
            prev = t & prev; 
            
        }
        
    }
}
void Sum(std::string &s1, std::string &s2, std::string &res)
{
    
    char prev = '0';
    for(int i = LENGTHOFDIG-1; i>=0; i--)
    {
        if(res[i] == '.') continue;
        char t = (s1[i] & s2[i]) | (s1[i] & prev) | (s2[i] & prev); 
        res[i] = (char)(((char((s1[i] ^ s2[i]) + 48))^prev) + 48);
        prev = t;
    } 
}
void ConvertToTrue(std::string &str)
{
    if(str[0] != '0')
    {
        int prev = 1;
        for(int i = str.length()-1; i>0; i--)
        {
            if (str[i] == '.') continue;
            char t = str[i];
            str[i] = char(bool(((str[i] - 48) - prev)) + 48);
            prev = (t - 48 - prev <0) ? 1 : 0;
            str[i] = (str[i]=='0') ? '1' : '0';
        }
    }
    while(str[1] == '0')
    {
        str.erase(1, 1);
    }
}
void FromNattyToTrue(std::string &str, int val)
{
    char sign = (val > 0)? '0' : '1';
    (val > 0)? val : val*=-1;
    int i = LENGTHOFDIG-1;
    for (i; val; i--)
    {
        str[i] += val%2;
        val/=2;
    }
    str[0] = sign;
    //str.push_back('.');
}       
long long InputLL()
{
    long long res;
    std::string str;
    bool isvalid = 0;
    while(!isvalid)
    {
        std::getline(std::cin, str);
        if(str == "EXIT") exit(0);
        int i=0;
        for(; i<str.length(); i++)
        {
            if(str[i] == '-' && i==0)
            {
                continue;
            }
            if(!(str[i]<='9' && str[i]>='0'))
            break;
        }
        if(i==str.length())
        {
            try
            {
                res = stoll(str);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
                std::cout << "Try again: \n";
                continue;
            }
            isvalid = 1;
        }
        else
        {
            std::cout<<"Error input. Try again:\n";
        }
    }
    return res;
}
void contextmenu()
{
    std::cout << "Made by Egor Azarov(253501)" << std::endl;
    std::cout << "Task 2:\n";
    std::cout << "User enter natty values. Then program count sum of two's complement number. Then reparesent result in true form.\n";
    std::cout << "(To exit enter \"EXIT\")" << std::endl;
    std::cout <<"----------------------------------------\n";
}