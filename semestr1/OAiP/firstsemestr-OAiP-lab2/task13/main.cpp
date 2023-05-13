#include <iostream>
int main(){
    int n;
    int d10;
    int d;
    std::cin>>n;
    d10 = n/10;
    std::cout<<"Мы нашли "<<n;
    if(d10%10==1){
        std::cout<<" грибов в лесу.";
        return 0;
    }
    d = n%10;
    if (d == 1){
        std::cout<<" гриб в лесу.";
    }
    else if (d >=2 && d <=4){
        std::cout<<" гриба в лесу.";
    }
    else {
        std::cout<<" грибов в слесу";
    }
    return 0;
}
