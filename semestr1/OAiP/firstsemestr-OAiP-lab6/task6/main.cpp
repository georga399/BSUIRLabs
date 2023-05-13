#include <iostream>
#include <string>
#include <map>
unsigned long long fact(unsigned long long n)
{
    if(n==1) return 1;
    return n*fact(n-1);
}
int main()
{
    std::string str;
    std::cin >> str;
    std::map<char, int> mp;
    unsigned long long dim = 1;
    for(auto a: str)
    {
        mp[a]++;
    }
    for(auto a: mp)
    {
        dim*=fact(a.second);
    }
    unsigned long long res = fact(str.length())/dim;
    std::cout << res;
}