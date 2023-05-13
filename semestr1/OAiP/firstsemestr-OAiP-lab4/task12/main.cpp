#include <iostream>
int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Введите запрашиваемое число: ";
    long long x;
    //std::cin>>x;

    while (!(std::cin >> x) || (std::cin.peek()) != '\n' || x<1)
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
	    std::cout << "Ошибка!\nВведите заново\n";
    }
    long long counter = 1;
    long long h=1;
    long long i = 0, j = 0;
    long long addition = 0;
    while (h<x)
    {
        i++;
        j++;
        addition +=2;
        h += addition;
    }
    long long rem = h-x;
    if(rem!=0){
        if (rem <= j)
        {
            j -=rem; 
        }
        else
        {
            
            i = rem -1 -i;
            j--;
        }
    }
    std::cout << "Число находится в позиции: ";
    std::cout<<j<<' '<<i;
}