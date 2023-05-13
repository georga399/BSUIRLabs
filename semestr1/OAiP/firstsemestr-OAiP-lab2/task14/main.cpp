#include <iostream>
#include <cmath>
int main(){
    long double W, H;
    long double x1, y1, x2, y2;
    long double w, h;
    long double l = 9999999;
    std::cin>>W>>H;
    std::cin>>x1>>y1>>x2>>y2;
    std::cin>>w>>h;
    if(h + y2 - y1 > H && w + x2 - x1 > W)
    {
        std::cout<<-1;
        return 0;
    }

    if(h + y2 - y1 <= H)
    {   if (h - y1>=0){
            l = (l>(h-y1)) ? h-y1 : l;
        }
        else{
            l = 0;
        }
        if(y2 -(H-h) >=0){
        l = (l>(y2-(H-h))) ? y2-(H-h) : l;
        }
         else{
             l = 0;
         }
    }
    if(w + x2 - x1 <= W)
    {   if (w - x1 >= 0){
        l = (l>(w-x1)) ? w-x1 : l;
        }
        else{
            l = 0;
        }
        if (x2 - (W -w) >=0){
        l = (l>(x2-(W-w))) ? x2-(W-w) : l;
        }
        else{
            l =0;
        }
    }
   
    std::cout<<l;
    return 0;
}