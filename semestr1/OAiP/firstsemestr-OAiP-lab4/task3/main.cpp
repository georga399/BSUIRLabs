#include <iostream>
void contextmenu()
{
     printf("\e[1;1H\e[2J");
    std::cout << "Задача №3 Вариант №1\n";
    std::cout << "Выполнил Азаров Егор (253501)\n" <<
                "Суть задания:\n" <<
                "Пользователь вводит размерность матрицы, далее поочередно каждый её элемент. Программа меняет местами между собой строки матрицы, где находятся минимальный и максимальный элемент. Если они находятся на одной строке, то программма просто сообщает об этом пользователю. Далее выводится полученная матрица. \n";
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
    int N;
    std::cout << "Введите размерность матрицы (число N): ";
    //std::cin >> N; //простая проверка
    while (!(std::cin >> N) || (std::cin.peek()) != '\n' || N<1)
    {
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << "Ошибка!\nВведите заново: ";
    }
    std::cin.clear();
    std::cin.ignore(1024, '\n');
    long double ** matr = new long double* [N];
    long double min, max;
    int countofMax = 1;
    int countofMin = 1;
    int rowswithMax[100]{};
    int rowswithMin[100]{};
    int iMin = 0;
    int iMax = 0;
    bool isfirstelem = 1;
    for (int i =0; i<N; i++)
    {
        matr[i] = new long double [N];
        for(int j =0; j<N; j++)
        {
            std::cout << "Введите элемент a["<<i<<"]["<<j<<"]: ";
            //std::cin >> matr[i][j];
            matr[i][j] = InputLD();
            if(isfirstelem)
            {
                isfirstelem = 0;
                min = max = matr[i][j];
            } 
            if(max<matr[i][j])
            {
                max = matr[i][j];
                countofMax =1;
                rowswithMax[0] = i;
            }else if(min>matr[i][j])
            {
                min = matr[i][j];
                countofMin = 1;
                rowswithMin[0] = i;  
            }
            else if(max == matr[i][j])
            {
                countofMax++;
                rowswithMax[countofMax-1] = i;
            }
            else if(min == matr[i][j])
            {
                countofMin++;
                rowswithMin[countofMin-1] = i;
            }

        }
    }
    std::cout << "Исходные данные: \n";
    
    bool istruematr=0;
    for (int i = 0; i < countofMax && !istruematr; i++)
    {
        for(int j = 0; j < countofMin; j++)
        {
            if(rowswithMax[i]==rowswithMin[j])
            {
                istruematr =1;
                break;
            }
        }
    }
    for(int i = 0; i<N; i++)
    {
        std::cout << "| ";
        for(int j=0; j<N; j++)
        {
            std::cout << matr[i][j] << ' ';
        }
        std::cout <<"|" <<std::endl;
    }
    std::cout << "\n-------------------------------------------------------------------\n";
    if(istruematr)
    {
        std::cout << "Ничего менять не надо. Максимальный и минимальный элемент находятся в одной строке.\n";
    }
    else
    {
        std::swap(matr[rowswithMax[0]], matr[rowswithMin[0]]);
        std::cout << "Полученная матрица: \n";
        
    }
    
        for(int i =0; i<N; i++)
        {
            std::cout << "| ";
            for(int j =0; j<N; j++)
            {
                std::cout << matr[i][j]<< ' ';
            }
            std::cout << "|\n";
        }   


    for(int i =0; i< N; i++)
    {
        delete [] matr[i];
    }
    delete [] matr;
}