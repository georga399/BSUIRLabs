#include <iostream>
#include <string>
int main()
{
    setlocale(LC_ALL, "Russian");
    printf("\e[1;1H\e[2J");
    std::string str; //Вводимое число
    int D; //Цифра, которую необходимо найти
    int countsOfDifDig[10]{};//массив, где указано сколько раз встречалась каждая цифра
    int* posOfD = new int[35000]; //Разряды, где стоит цифра D
    int countOfD = 0; //Количество цифр D в числе
    int K =0; //Количество различных цифр в числе
    std::cout << "Введите число: ";
    std::cin >> str;
    std::cout << "Введите индекс цифры, которую хотите отыскать: ";
   // std::cin >> D; // Простая проверка
    while (!(std::cin >> D) || (std::cin.peek()) != '\n' || D<1)
    {
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << "Ошибка!\nВведите заново: ";
    }
    D-=1;
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == str[D])
        {
            posOfD[countOfD] = str.length()-1-i;
            
            countOfD++;
        }
        countsOfDifDig[int(str[i]-'0')]++;
    }    
    for (auto a: countsOfDifDig)
    {
        if(a!=0)
        {
            K++;
        }
    }
    std::cout << "Количество различных цифр в числе: ";
    std::cout << K << std::endl;
    std::cout <<"Разряды найденной цифры: "; 
    //int t = int(str[D]- '0');
    for(int i  = countsOfDifDig[int(str[D]- '0')]-1; i>=0; i--)
    {   
        std::cout <<posOfD[i] << ' ';

    }
    delete [] posOfD;
}