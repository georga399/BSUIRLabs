#include <iostream>
#include <algorithm>
void contextmenu()
{
    printf("\e[1;1H\e[2J");
    std::cout << "Задача №9 Вариант №1\n";
    std::cout << "Выполнил Азаров Егор (253501)\n" <<
                "Суть задания:\n" <<
                "Пользователь вводит размер одной грани куба, далее попеременно каждый его элемент. Программа считает и выводит в консоль максимальную сумму элементов, находящихся на диагонали.\n";
    std::cout << "\n-------------------------------------------------------------------\n";
}
int main()
{
    contextmenu();
    setlocale(LC_ALL, "Russian");
    unsigned int n;
    unsigned d1 =0;
    unsigned d2 =0;
    unsigned d3 =0;
    unsigned d4 =0;
    std::cout << "Введите размер одной грани куба: ";
    //std::cin >> n;
    while (!(std::cin >> n) || (std::cin.peek()) != '\n' || n<1)
    {
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << "Ошибка!\nВведите заново: ";
    }
    unsigned *** cube = NULL;
    cube = (unsigned***) malloc(n*sizeof(unsigned**));
    for (int i = 0; i < n; i++)
    {
        cube[i] = NULL;
        cube[i] = (unsigned**)malloc(n*sizeof(unsigned*));
        for (int j = 0; j < n; j++)
        {
            cube[i][j] = (unsigned*)malloc(n*sizeof(unsigned));
            for(int k = 0; k<n; k++)
            {
                std::cout << "Введите элемент a["<<i<<"]["<<j<<"]["<<k<<"]: ";
                //std::cin >> cube[i][j][k];
                while (!(std::cin >> cube[i][j][k]) || (std::cin.peek()) != '\n')
                {
                    std::cin.clear();
                    while (std::cin.get() != '\n');
                    std::cout << "Ошибка!\nВведите заново: ";
                }
            }
        } 
    }
    std::cout << "Исходные данные: \n";
    for (int i = 0; i < n; i++)
    {   
        std::cout << i<<":\n";
        for (int j = 0; j < n; j++)
        {
            for(int k = 0; k<n; k++)
            {
                std::cout << cube[i][j][k] << ' ';
                
            }
            std::cout << "\n";
        } 
        std::cout << "-----------------------\n";
    }
    std::cout << "Наибольшая диагональ куба равна: ";
    int d1i = 0;
    int d1j = 0;
    int d1k = 0;

    int d2i = 0;
    int d2j = 0;
    int d2k = n-1;

    int d3i = 0;
    int d3j = n-1;
    int d3k = 0;

    int d4i = 0;
    int d4j =n-1;
    int d4k = n-1;
    for (int i = 0; i<n; i++)
    {
        d1+= cube[d1i++][d1j++][d1k++];
        //d1i++; d1j++; d1k++;

        d2+=cube[d2i++][d2j++][d2k--];
        //d2i++; d2j++; d2k--;

        d3+=cube[d3i++][d3j--][d3k++];
    
        d4+=cube[d4i++][d4j--][d4k--];
    }
    unsigned res = std::max(d1, d2);
    res = std::max(res, d3);
    res = std::max(res, d4);
    std::cout << res;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            free(cube[i][j]);
        }
        free(cube[i]); 
    }
    free(cube);

}