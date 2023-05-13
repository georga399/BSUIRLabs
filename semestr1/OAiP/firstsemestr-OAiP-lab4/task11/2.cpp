#include <iostream>
#include <string.h>
void contextmenu()
{
    printf("\e[1;1H\e[2J");
    std::cout << "Задача №11\n";
    std::cout << "Выполнил Азаров Егор (253501)\n" <<
                "Суть задания:\n" <<
                "Пользователь вводит размер поля. Далее построчно вводит само поле, где '*' означает мину, а '.' пустое место. Программа дополняет поле числами и выводит его.\n";
    std::cout << "\n-------------------------------------------------------------------\n";

}
int main()
{
    setlocale(LC_ALL, "Russian");
    int n, m;
    contextmenu();
    std::cout << "Input rows: ";
    //std::cin >> n; // простая проверка
    while (!(std::cin >> n) || (std::cin.peek()) != '\n' || n<0 || n >10000)
    {
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << "Ошибка!\nВведите заново: ";
    }
    std::cout << "Input columns: ";
    //std::cin >> m; // простая провекра
    while (!(std::cin >> m) || (std::cin.peek()) != '\n'|| m<0 || m>10000)
    {
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << "Ошибка!\nВведите заново: ";
    }
    char** warzone = (char**)malloc(n*sizeof(char*));
    std::cin.clear();
    std::cin.ignore (1024, '\n');
    for(int i=0; i<n; )
    {
        std::string line;
        warzone[i] = (char*)malloc(m*sizeof(char));
        std::cout << "Input line "<<i << ": ";
        std::getline(std::cin, line);
        //std::cin.clear();
        //std::cin.ignore (1024, '\n');
        if(line.length()!=m)
        {
            std::cout << "Wrong size of line!\n";
            continue;
        }
        
        bool itswrong = 0;
        for(int j=0; j < m; j++ )
        {
            if(line[j] != '*' && line[j] !='.')
            {
                itswrong =1;
                break;
            } 
            warzone[i][j] = line[j];
        }
        if(itswrong)
        {
            std::cout << "It's wrong line!\n";
            continue;
        }
        
        i++;
    }    

    for(int i=0; i<n; i++) for (int j=0; j<m; j++)
    {
        if(warzone[i][j] == '*')
        {
            continue;
        }
        char counter = '0';
        if(i-1>=0 && warzone[i-1][j] == '*')
        {
            counter++;
        }
        if(i+1<n && warzone[i+1][j] == '*')
        {
            counter++;
        }
        if(j-1>=0 && warzone[i][j-1]=='*')
        {
            counter++;
        }
        if(j+1<n && warzone[i][j+1] == '*')
        {
            counter++;
        }
        if(i-1>=0 && j-1>=0 && warzone[i-1][j-1] == '*')
        {
            counter++;
        }
        if(i-1>=0 && j+1<n && warzone[i-1][j+1]=='*')
        {
            counter++;
        }
        if(j+1<n && i+1<n && warzone[i+1][j+1] == '*')
        {
            counter++;
        }
        if(i+1<n && j-1>=0 && warzone[i+1][j-1]=='*')
        {
            counter++;
        }
        warzone[i][j] = counter;
    }
    std::cout << "Result:\n";
    for (int i = 0; i<n; i++)
    {
        //std::cout << warzone[i];
        for (int j =0; j<m; j++)
        {
            std::cout << warzone[i][j] <<' '; 
        }
        std::cout << std::endl;
        free(warzone[i]);
    }   
    free(warzone);

    

}