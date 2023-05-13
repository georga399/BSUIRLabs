#include <iostream>
#include <string>
#include <cassert>
void toconvert(int n, std::string& str);
void Testing();
int main()
{
    Testing();
    int n;
    std::cin >> n;
    std::string res;
    toconvert(n, res);
    std::cout << res;
}
void toconvert(int n, std::string& str) //O(log3n)
{
    while(n)
    {
        str.insert(str.begin(),(char(n%3 + 48)));
        n/=3;
    }
    int pos = str.find("10");
    while (pos!= -1)
    {
        str.replace(pos, 2, "03");
        pos = str.find("10");
    }
    pos = str.find("20");
    while (pos!= -1)
    {
        str.replace(pos, 2, "13");
        pos = str.find("20");
    }
    pos = str.find("30");
    while (pos!=-1)
    {
        str.replace(pos, 2, "23");
        pos = str.find("30");
    }
    while(*str.begin() == '0' && str.length()>1)
    {
        str.erase(0,1);
    }
    
}
void Testing()
{
    {
        std::string str;
        int n = 22;
        toconvert(n, str);
        assert(str == "211");
    }
    {
        std::string str;
        int n = 81;
        toconvert(n, str);
        assert(str == "2223");
    }
    {
        std::string str;
        int n = 9;
        toconvert(n, str);
        assert(str == "23");
    }
        {
        std::string str;
        int n = 1;
        toconvert(n, str);
        assert(str == "1");
    }
}