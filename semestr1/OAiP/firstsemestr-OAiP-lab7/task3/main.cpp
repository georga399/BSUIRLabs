#include <iostream>
#include <string>
#define SIZESTR 200
int InputInt();
void InputStr(std::string &str, int d); 
void sumofpos(std::string a, std::string b, std::string &res, int d); //O(n)
void sumnegot(std::string a, std::string b, std::string &res, int d); //O(n)
void contextmenu();
int main() 
{   
    contextmenu();
    std::cout << "Input Base: ";
    int d = InputInt();
    std::string a, b, res_sum, res_dif;
    std::cout << "Input first value: ";
    InputStr(a, d);
    std::cout << "Input second value: ";
    InputStr(b, d);
    std::cout << "__________________________________" << std::endl;
    std::cout <<"Base: "<< d << std::endl;
    std::cout <<"First value: "<< a << std::endl;
    std::cout <<"Second value: "<<b << std::endl;
    if(*a.begin() != '-' && *b.begin() != '-')
    {
        sumofpos(a, b, res_sum, d);
        b.insert(b.begin(), '-');
        sumnegot(a, b, res_dif, d);        
    }
    else if(*a.begin() == '-' && *b.begin() != '-')
    {
        sumnegot(a, b, res_sum, d);
        b.insert(b.begin(), '-');
        sumnegot(a, b, res_dif, d);
    }
    else if(*a.begin() != '-' && *b.begin() == '-')
    {
        sumnegot(a, b, res_sum, d);
        b.erase(0,1);
        sumofpos(a, b, res_dif, d);
    }
    else
    {
        sumnegot(a, b, res_sum, d);
        b.erase(0,1);
        sumnegot(a, b, res_dif, d);
    }
    //sumofpos(a, b, res_sum, d);
    std::cout <<"Sum: "<< res_sum <<std::endl;
    std::cout <<"Difference: "<< res_dif << std::endl;
    std::cout << "__________________________________" << std::endl;
}
void InputStr(std::string &str,int d)
{
    bool isvalid = 0;
    int length =0;
    do
    {
        std::getline(std::cin, str);
        if(str.length() > SIZESTR)
        {
            std::cout << "Error. Big value. Try again: ";
            str.erase(0);
            continue;
        }
        int i =0;
        length = str.length();
        for(; i<length; ++i)
        {
            char c = str[i];
            if(c == '-' && i!=0)
            {
                std::cout << "Error type. Try again: ";
                str.erase(0);
                break;
            }
            else if(c == '-' && str.length()==1)
            {
                std::cout << "Error type. Try again: ";
                str.erase(0);
                break;
            }
            else if(c=='-') continue;
            int cc = -1;

            if(isdigit(c)) cc = c -48;
            else if(isalpha(c)) cc = c-97+10;
            if(cc==-1 || cc >=d )
            {
                std::cout << "Error type. Try again: ";
                str.erase(0);
                break;
            }
        }
        if(i == length)
        {
            isvalid = 1;
        }
    } while (!isvalid);
    while (*str.begin() == '0' && str.length() > 1)
    {
        str.erase(0,1);
    }
    
}
int InputInt()
{
    int res;
    while(1)
    {
        std::string str;
        std::getline(std::cin, str);
        int i;
        for( i = 0; i<str.length(); i++)
        {
            if(!(str[i] >='0' && str[i] <='9' ))
            {
                break;
            }
        }
        if(i != str.length())
        {
            std::cout << "Error. Try again: ";
        }
        else
        {
            res = stoi(str);
            if(res>1 && res < 37)
                return res;
            else
                std::cout << "Error value. Try again: ";
        }
    }
}
void sumofpos(std::string a, std::string b, std::string &res, int d)
{
    int prev = 0;
    //int length = std::max(a.length(), b.length()) + 1;
    for(int i = 0; i<SIZESTR; i++)
    {
        int aa = 0, bb = 0;
        char aaa = (a != "\0" && a!="-") ? *a.rbegin() : '0';
        char bbb = (b != "\0" && b!="-") ? *b.rbegin() : '0';
        if(isdigit(aaa))
            aa = aaa - 48;
        else
            aa = aaa - 97 + 10;
        if(isdigit(bbb))
            bb = bbb - 48;
        else
            bb = bbb - 97 + 10;
        int r = (aa + bb + prev)%d;
        if(r < 10)
            //res[i] = (char)r + 48;
            res.insert(res.begin(), char(r+48));
        else 
            //res[i] = char(r+97-10);
            res.insert(res.begin(), char(r+97-10));
        if(a!= "\0")
            a.pop_back();
        if(b!="\0")
            b.pop_back();
        prev = (aa + bb + prev)/d;
    }
    while (*res.begin() == '0' && res.length() > 1)
    {
        res.erase(0,1);
    }
}
void sumnegot(std::string a, std::string b, std::string &res, int d)
{
    if(*a.begin() == '-' && *b.begin() == '-')
    {
        a.erase(0,1);
        b.erase(0,1);
        sumofpos(a, b, res, d);
        res.insert(res.begin(), '-');
    }
    else
    {
        char signa = (*a.begin() == '-') ? '-' : '+';
        char signb = (*b.begin() == '-') ? '-' : '+';
        if(*a.begin()=='-')
        {
            a.erase(0,1);
        }
        else
        {
            b.erase(0,1);
        }
        char signres = 0;
        // if(a>b && signa == '-')
        // {
        //     signres = '-';
        // }
        // else if(b>a && signb == '-')
        // {
        //     signres = '-';
        // }
       
        if(b.length()>a.length())
        {
            b.swap(a);
            if(signb == '-') signres = '-';
        }
        else if(b.length() == a.length() && b > a)
        {
            b.swap(a);  //a>b
            if(signb == '-') signres = '-';
        }
        else if(signa == '-') signres = '-';
        //algo
        int prev = 0;
        int r;
        int length = a.length();
        for(int i = 0; i<length; i++)
        {
            char aaa = (a != "\0" ) ? *a.rbegin() : '0';
            char bbb = (b != "\0" ) ? *b.rbegin() : '0';
            int aa, bb;
            if(isdigit(aaa))
                aa = aaa - 48;
            else
                aa = aaa - 97 + 10;
            if(isdigit(bbb))
                bb = bbb - 48;
            else
                bb = bbb - 97 + 10;
            r = (d + aa - bb + prev)%d;
            prev = (bb - prev>aa) ? -1 : 0;
            if(r < 10)  
                res.insert(res.begin(), char(r+48));
            else 
                res.insert(res.begin(), char(r+97-10)); 
            if(a!= "\0")
                a.pop_back();
            if(b!="\0")
                b.pop_back();
        } 
        while (*res.begin()=='0' && res.length()>1)
        {
            res.erase(0,1);
        }       
        res.insert(res.begin(), signres);
        
        
    }
}
void contextmenu()
{
    std::cout << "Made by Egor Azarov" << std::endl;
    std::cout << "Task 3:\n";
    std::cout << "Program count sum and difference of values in a specific number system.\n";
    std::cout <<"----------------------------------------\n";
}