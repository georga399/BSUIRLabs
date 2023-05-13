#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <algorithm>
int main()
{
    
    std::string str;
    std::getline(std::cin, str);
    std::string s;
    std::stringstream ss(str);
    std::vector<int> out;
    char delim = ' ';
    while (std::getline(ss, s, delim)) {
        out.push_back(std::stoi(s));
    }
    int d1 = std::distance(out.begin(), std::max_element(out.begin(), out.end()));
    int d2 =std::distance(out.begin(), std::min_element(out.begin(), out.end()));
    if(d2<d1){
        int t=d2;
        d2 = d1;
        d1 = d2;
    }
    for (int i = d1+1; i<d2; i++)
    {
        out[i]=0;
    }
    int countzero = std::count(out.begin(), out.end(), 0);
    if(countzero>out.size()/2)
    {
        for(int i=0; i<out.size();)
        {
            if(out[i]==0)
            {
                out.erase(out.begin()+i);
                continue;
            }
            i++;
        }
    }
    for (auto a: out)
    {
        std::cout << a << ' ';
    }
}


