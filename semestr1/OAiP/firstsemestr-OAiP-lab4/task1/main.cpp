#include <iostream>
#include <string.h>
void contextmenu()
{
    printf("\e[1;1H\e[2J");
    std::cout << "Задача №1\n";
    std::cout << "Выполнил Азаров Егор (253501)\nВариант 1 \n" <<
                "Суть задания:\n" <<
                "Пользователь вводит размер массива, далее вводит каждый его элемент. Программа переносит отрицательные числа в начало массива и выводит на экран результат.\n";
    // std::cout << "Для запуска программы введите любой символ: ";
    // while(!getchar());
    std::cout << "\n-------------------------------------------------------------------\n";

}
long double InputLD()
{
    std::string str;
    //std::cout << text;
    bool flag = 1;
    long double ld;
    // std::cin.clear();
    // std::cin.ignore(1024, '\n');
    while(flag)
    {
        std::getline(std::cin, str);
        int howmanydots = 0;
        int howmanye = 0;
        int posofe = -1;
        if(!((*str.begin() >= '0' && *str.begin() <='9') || *str.begin() == '-'))
        {
            
            std::cout << "Error input. Try again: ";
            continue;
        }
        int i = 0;// str.length()-1;
        for(; i<str.length(); i++)
        {
            char el = str[i];
            if((str[i]>= '0' && str[i]<='9') || (str[i] == '.' && howmanydots == 0 && i!=str.length()-1) || (str[i] == 'e' && howmanye==0 && i!=str.length()-1) || (str[i] == '-' &&(posofe + 1 ==i || i==0 && i!=str.length()-1) ))
            {
                if(str[i]=='.')
                {
                    howmanydots++;
                }
                if(str[i]=='e')
                {
                    posofe = i;
                    howmanye++;
                }
                continue;
            }
            
            else
            {
                //std::cout << "It's wrong.";
                break;
            }
        }
        if(i==str.length())
        {
            flag = 0;
            ld = std::stold(str);
            
        }
        else 
        {
            std::cout << "Error input. Try again: ";
        }
    }
    return ld;

}

int main()
{
    setlocale(LC_ALL, "Russian");
    contextmenu();
    int k;
    
    std::cout << "Введите размер массива: ";
    while (!(std::cin >> k) || (std::cin.peek()) != '\n' || k>10000 || k<=0)
	{
		// std::cin.clear();
        // std::cin.ignore(1024, '\n');
		while (std::cin.get() != '\n');
		
        if(k>10000)
        {
            std::cout << "Пожалуйста, введите меньшее число: ";
        }
        else{
            std::cout << "Ошибка!\nВведите заново\n";
        }
	}
    std::cin.clear();
    std::cin.ignore(1024, '\n');
    //std::cin >> k;

    long double arr[10000];
    long double b[10000];
    int j =0;
    for(int i =0; i<k; i++)
    {
        std::cout << "Введите arr[" << i <<"]: ";
        //std::cin >> arr[i];
        // 
        
        arr[i] = InputLD();
        if(arr[i]<0)
        {
            b[j]=arr[i];
            j++;
        }
    }
    std::cout << "\n-------------------------------------------------------------------\n";
    std::cout << "Исходный массив: \n{";
    for(int i = 0; i<k; i++)
    {
        std::cout << arr[i];
        if (i!=k-1)
        {
            std::cout << ", ";
        }
        if(arr[i]>=0)
        {
            b[j] = arr[i];
            j++;
        }
    }
    std::cout << "}\n";
    std::cout << "Полученный массив: \n{";
    for (int i = 0; i<j; i++)
    {
        std::cout << b[i];
        if (i!=k-1)
        {
            std::cout << ", ";
        }
    }
    std::cout << "}\n";

}