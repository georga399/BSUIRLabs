#include <iostream>
#include <string>
std::string sum(std::string &a, std::string &b)
{
    std::string d,c;
    std::string res;
    if (a.length() < b.length())
    {
        d = b;
        c = a;
    }
    else 
    {
        d = a;
        c = b;
    }
    int prev = 0;
    int j = c.length()-1;
    for (int i = d.length()-1; i>=0; i--)
    {
        int d1 = int(d[i] - '0');
        int d2;
        if(j<0)
        {
            d2 = 0;
        }
        else 
        {
            d2 = int(c[j] - '0');
        }
        j--;
        int s = (d1+d2 +prev)%10;
        prev = (d1+d2+prev)/10;
        res.insert(res.begin(), char(s)+'0');
    }
    if(prev!=0)
    {
        res.insert(res.begin(), prev);
    }
    return res;

}
void inputNumber(std::string a, std::string & str)
{
    std::cout << "Input "<< a <<": ";
    while(true)
    {
        std::getline(std::cin, str);
        int i =0;
        bool istruedigit = 1;
        for (; i< str.length(); i++)
        {
            if(!(str[i]<='9' && str[i]>='0') )
            {
                istruedigit = 0;
                break;
            }
        }
        if(istruedigit && str.length() )
        {
            break;
        }
        else
        {
            std::cout << "Sorry... It's incorrect. Please, try again: ";
        }
    }
    while(*str.begin() == '0' && str.length()>1)
    {
        str.erase(str.begin());
    }
    //return res;
}
void divide2(std::string &a)
{
    int rem = 0;
    int num = 0; //int(a[0]-'0');
    for(int i = 0; i<a.length(); i++)
    {
        num = rem*10 + int(a[i]-'0');
        rem = num%2;
        a[i] = char(num/2) + '0';
    }
} 
std::string mult(std::string &a, std::string &b)
{
    std::string * arr = new std::string[a.length()]{};
    std::string j = "";
    std::string c, d;
    if (a.length()<b.length())
    {
        c = a;
        d = b;
    }
    else 
    {
        c = b;
        d = a;
    }
   

    for(int i = c.length()-1; i>=0; i-- )
    {
        int el1 = int(c[i]-'0');
        int prev = 0;
        for (int k = d.length()-1; k>=0; k--)
        {
            int el2 = int(d[k]-'0');
            char dis = char((el1*el2 + prev)%10)+'0';
            prev =(el1*el2 + prev)/10;
            arr[i].insert(arr[i].begin(), dis);
        }
        if(prev!=0)
        {
            arr[i].insert(arr[i].begin(), char(prev)+'0');
        }
            arr[i] +=j;
            j+='0';
    }

    
    std::string res = "0";
    for (int i = 0; i<c.length(); i++)
    {
        //std::cout << arr[i]<<std::endl;
        res = sum(res, arr[i]);
    }

    delete [] arr; 
    return res;   
}
void decrement(std::string &str)
{
    int prev = 1;
    for(int i = str.length()-1; i>=0; i--)
    {
        int el = (int(str[i] - '0')+10 - prev)%10;
        if(str[i] == '0')
        prev = 1;
        else 
        {
            prev =0;
        }
        str[i] = char(el) + '0';
    }
}
int main()
{
    std::string str1, str2;
    inputNumber("number",str1);
    str2 =str1;
    if(*str1.rbegin() == '0' || *str1.rbegin() == '2' || *str1.rbegin() == '4' || *str1.rbegin() == '6' || *str1.rbegin() == '8')
    {
        divide2(str1);
        decrement(str2);
    }
    else 
    {
        decrement(str2);
        divide2(str2);
    }
    std::string res = "1";
    std::string m1 = mult(str1, str2);
    res = sum(res, m1);
    std::cout << res << std::endl;
    while(*res.begin() == '0' && res.length()>1)
    {
        res.erase(res.begin());
    }      
    std::cout << "Result: "<< res;
}