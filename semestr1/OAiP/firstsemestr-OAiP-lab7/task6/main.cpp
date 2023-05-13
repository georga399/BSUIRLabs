#include <iostream>
#include <string>
#include <exception>
void checkdivby3(int val); // O(log3(lgn))
void checkdivby37(int val); //O(n)
void checkdivby89(int val); //O(n)
unsigned int InputVal();
int subtract(unsigned int a, unsigned int b);
int multiply(unsigned int a, unsigned int b);
int divide(unsigned int a, unsigned int b);
int divide2(unsigned int a, unsigned int b);
int mod(unsigned int a, unsigned int m);
void contextmenu();
int main()
{
    contextmenu();
    unsigned int d;
    std::cout << "Input value: ";
    d = InputVal();
    checkdivby3(d);
    checkdivby37(d);
    checkdivby89(d);
    
}
void checkdivby3(int val)
{
    std::string val1 = std::to_string(val);
    int sum = 0;
    do
    {
        sum = 0;
        for(auto a: val1)
        {
            sum += atoi(&a);
        }
        val1 = std::to_string(sum);
    } while (sum>9);
    
    if(sum == 3 || sum == 6 || sum == 9 || sum == 0)
    {
        std::cout <<"The value is divisible by 3." << std::endl;
    }
    else
    {
        std::cout << "The number is not divisible by 3." << std::endl;
    }
}
int subtract(unsigned int a, unsigned int b) //O(1)
{
    return a + ~b + 1;
}
int multiply(unsigned int a, unsigned int b) // O(logb)
{
    int res = 0;
    while(b)
    {
        if(b & 1) res +=a;
        a+=a;
        b>>=1;
    }
    return res;
}
int divide(unsigned int a, unsigned int b) //O(a/b)
{
    int res = 0;
    int t = 0;
    while (t<a)
    {
        t+=b;
        if(t>a) break;
        res++;
    }
    return res;
}
int mod(unsigned int a, unsigned int m)
{
    int r = divide(a, m);
    //int r = a/m;
    return subtract(a, multiply(r, m));
}
void checkdivby37(int val) //O(n/37 + log37)
{
    if(mod(val, 37))
    {
        std::cout << "This value is not divisible by 37." << std::endl;
    }
    else
    {
        std::cout << "This value is divisible by 37." << std::endl;
    }
}
void checkdivby89(int val) //O(n/89 + log89)
{
   if(mod(val, 89))
    {
        std::cout << "This value is not divisible by 89." << std::endl;
    }
    else
    {
        std::cout << "This value is divisible by 89." << std::endl;
    } 
}
unsigned int InputVal()
{
    unsigned int val;
    bool isvalid = 0;
    while (!isvalid)
    {
        std::string str;
        std::getline(std::cin, str);
        int i;
        for (i = 0; i<str.length(); i++)
        {
            if(!(str[i]>='0' && str[i]<='9')) break;
        }
        if(i != str.length())
        {
            std::cout << "Error input. Try again: ";
            continue;
        }
        try
        {
            val = stoi(str);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            continue;
        }
        isvalid = 1;
    }
    return val;
}
void contextmenu()
{
    std::cout << "Made by Egor Azarov" << std::endl;
    std::cout << "Task 6:"<<std::endl;
    std::cout << "Program count that its the number divisible by 3, 37, 89." <<std::endl;
    std::cout <<"_________________________________\n";
}