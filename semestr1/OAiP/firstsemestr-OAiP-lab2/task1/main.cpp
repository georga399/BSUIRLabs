#include <iostream>
int main (){
    int x;
    int y;
    std::cin>>x;
    std::cin>>y;
    if (x==0 && y==0){
        std::cout<<"ERROR";
        return 0;
    }
    
    if (x == 0 || y == 0) {
        std::cout << "YES";
        return 0;
    }
  
    if ((y%x)==0 || (x%y)==0){
        std::cout<<"YES";
    }else {
        std::cout<<"NO";

    }
    return 0;
}