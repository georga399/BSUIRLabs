#include <iostream>
void contextmenu()
{
    printf("\e[1;1H\e[2J");
    std::cout << "Задача №2 Вариант №1\n";
    std::cout << "Выполнил Азаров Егор (253501)\n" <<
                "Суть задания:\n" <<
                "Пользователь вводит разиерность матрицы, далее поочередно сами элементы. Программа находит количество положительных чисел, расположенных ниже побочной диагонали.\n";
    std::cout << "\n-------------------------------------------------------------------\n";
}
int main()
{
    setlocale(LC_ALL, "Russian");
    contextmenu();
    int N, M;
    std::cout << "Введите количество строк матрицы: ";
    while (!(std::cin >> N) || (std::cin.peek()) != '\n' || N>100)
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		
        if(N>100)
        {
            std::cout << "Ну навряд ли вы сможете ввести так много элементов. Введите меньшее число: ";
        }
        else{
            std::cout << "Ошибка!\nВведите заново: ";
        }
	}
    //std::cin >> N;
    // std::cout << "Введите количество столбцов матрицы: ";
    // std::cin >> M;
    long long matr[100][100];
    int counter = 0;
    for (int i=0; i<N; i++) {
        for(int j =0; j < N; j++)
        {
            std::cout << "Введите элемент матрицы a["<<i<<"]["<<j<<"]: ";
            while (!(std::cin >> matr[i][j]) || (std::cin.peek()) != '\n')
            {
                std::cin.clear();
                while (std::cin.get() != '\n');
                std::cout << "Ошибка!\nВведите заново: ";
            }
            //std::cin >> matr[i][j];
            if(i+j>N-1 && matr[i][j]>0)
            {
                counter++;
            }
        }
    // std::cin >> mpog[i];
    //  if (!(isdigit(mpog[i]))) {
    //       std::cout << "Not a number!";
    //       continue;
    //  }
    }
    std::cout << "\n-------------------------------------------------------------------\n";

    std::cout << "Исходные данные: \n";
    std::cout << "Матрица: \n";
    for(int i = 0; i<N; i++)
    {
        for(int j =0; j<N; j++)
        {
            std::cout << matr[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << "\n-------------------------------------------------------------------\n";

    std::cout << "Количество положительных элементов, расположенных ниже побочной диагонали: " << counter;
    return 0;

}
