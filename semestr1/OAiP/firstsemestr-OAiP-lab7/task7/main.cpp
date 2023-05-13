#include <iostream>
#include <string>
#include <ctime>
#include <cassert>
void tobinary(std::string a, std::string &bin, int k);
void divide2(std::string &a);
std::string sum(std::string &a, int expoften);
void algo(int n, std::string &res);
void Testing();
int main() // ~O(n^2)
{
    Testing();
    int n;
    std::cin >> n;
    std::string res;
    clock_t tStart = clock();
    algo(n, res);
    std::cout << res << std::endl;
    std::cout << "\nTime: " << (double)(clock() - tStart)/CLOCKS_PER_SEC << "s" <<std::endl;    
}
void tobinary(std::string a, std::string &bin, int k) //O(k) O(logn)
{
    if(a=="0")
    { 
        bin = "0";
        return;
    }
    while (a!="0" && bin.size()!=k)
    {
        int t = (*a.begin() - 48)%2;
        bin.push_back(char(t+48));
        divide2(a);
    }
}
void divide2(std::string &a)
{
    int carry = 0;
    for (int i=a.length()-1; i>=0; --i) {
        long long cur = a[i] - 48 +  carry* 10;
        a[i] = char (cur / 2) + 48;
        carry = int (cur % 2);
    }
    while (a.size() > 1 && *a.rbegin() == '0')
        a.pop_back();

}
std::string sum(std::string &a, int expoften)
{
    std::string b = a;
    while (b.length() <= expoften-1 )
    {
        b.push_back('0');
    }
    b.push_back('1');
    return b;
}
void algo(int number, std::string &res)
{
    std::string Ak[1000], Bk[1000], Ck[1000];
    int ABki = 0, Cki = 8, k = 4, answer = 7, m = 0;
    Ck[0] = "0"; 
    Ck[1] = "1";
    Ck[2] = "01";//"10"; 
    Ck[3] = "11";
    Ck[4] = "001";//"100"; 
    Ck[5] = "101";
    Ck[6] = "011";//"110"; 
    Ck[7] = "111";
    int i;
    //std::cin >> number;
    clock_t tStart = clock();
    for(k = 4; answer<number; k++)  
    {
        for(i = 0; i<Cki; i++)
        {
            std::string bin;
            tobinary(Ck[i], bin, k); //O(k)
            if(bin.size() >= k)
            {
                
                char c = bin[k-1];//bin[bin.length()-k];
                //std::cout << c << ' '<<Ck[i]<< ' '<< bin << std::endl;
                if(c == '0')
                {
                    Ak[ABki] = Ck[i];
                    Bk[ABki] = sum(Ak[ABki], k-1);
                    answer++;
                    ABki++;
                }
            }
            else
            {
                Ak[ABki] = Ck[i];
                Bk[ABki] = sum(Ak[ABki], k-1);
                answer++;
                ABki++;
            }
        }
        for(i = 0; i<ABki;i++)
        {
            Ck[i] = Ak[i];
            Ck[i+ABki] = Bk[i];
        }
        m=ABki;
        Cki = 2 * ABki;
        ABki=0;
    } 
    if(number<8)
    {
        //std::reverse(Ck[number].begin(), Ck[number].end());
        for(int li = Ck[number].length()-1; li>=0; --li)
        //std::cout << Ck[number][li];
        res.push_back(Ck[number][li]);
    } 
    else
    {
        //std::reverse(Bk[m - 1 - (answer - number)].begin(), Bk[m - 1 - (answer - number)].end());
        for(int li = Bk[m - 1 - (answer - number)].length()-1; li>=0; --li)
        // std::cout << Bk[m - 1 - (answer - number)][li];
        res.push_back(Bk[m - 1 - (answer - number)][li]);
    }
    //std::cout << "\nTime: " << (double)(clock() - tStart)/CLOCKS_PER_SEC << "s" <<std::endl;
}
void Testing()
{
    {
        std::string str;
        int d = 1;
        algo(d, str);
        assert(str=="1");
    }
    {
        std::string str;
        int d = 10;
        algo(d, str);
        assert(str=="1100");
    }
    {
        std::string str;
        int d = 2;
        algo(d, str);
        assert(str=="10");
    }
}
