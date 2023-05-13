#include <iostream>
#include <string>
#include <cassert>
void convert(int n, std::string &str); //O(lgn)
void Testing();
int main()
{
    Testing();
    int n;
    std::cin >> n;
    std::string str;
    convert(n, str);
    std::cout << str;
}
void convert(int n, std::string &str)
{
    int num_M = n/1000;
    str.append(num_M, 'M');
    n%=1000;
    if(n/100 == 9)
    {
        str.append("CM");
        n%=100;
    }
    else
    {
        int num_D = n/500;
        str.append(num_D, 'D');
        n%=500;  
    }
    if(n/100 == 4)
    {
        str.append("CD");
        n%=100;
    }
    else
    {
        int num_C = n/100;
        str.append(num_C, 'C');
        n%=100;
    }
    if(n/10 == 9)
    {
        str.append("XC");
        n%=10;
    }
    else
    {
        int num_L = n/50;
        n%=50;
        str.append(num_L, 'L');
    }
    int num_X = n/10;
    if(num_X == 4)
    {
        str.append("XL");
    }
    else
    {
        str.append(num_X, 'X');
    }
    n%=10;
    if(n == 9)
        str.append("IX");
    else if(n==8)
        str.append("VIII");
    else if(n==7)
        str.append("VII");
    else if(n==6)
        str.append("VI");
    else if(n==5)
        str.append("V");
    else if(n==4)
        str.append("IV");
    else if(n==3)
        str.append("III");
    else if(n==2)
        str.append("II");
    else if(n==1)
        str.append("I");    
}
void Testing()
{
    {
        int n = 123;
        std::string str;
        convert(n, str);
        assert(str=="CXXIII");
    }
    {
        int n = 1;
        std::string str;
        convert(n, str);
        assert(str=="I");
    }
    {
        int n = 3999;
        std::string str;
        convert(n, str);
        assert(str=="MMMCMXCIX");
    }
}