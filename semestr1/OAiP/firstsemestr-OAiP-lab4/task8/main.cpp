#include <iostream>
int main()
{
    setlocale(LC_ALL, "Russian");
    printf("\e[1;1H\e[2J");
    int N, M;
    // int A [100][100];
    // int B [100][100];
    // int C [100][100];
    std::cout << "Введите размер матриц: ";
    //std::cin >> N;
    while (!(std::cin >> N) || (std::cin.peek()) != '\n')
    {
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << "Упс...Что-то пошло не так...\nВведите заново: ";
    }
    int ** A = new int*[N];
    int ** B = new int*[N];
    for (int i = 0; i<N; i++)
    {
        A[i] = new int[N];
        B[i] = new int[N];
        for (int j =0; j<N; j++)
        {

            std::cout << "Введите элемент a["<<i<<"]["<<j<<"] первой матрицы: ";
            //std::cin >> A[i][j];
            while (!(std::cin >> A[i][j]) || (std::cin.peek()) != '\n')
            {
                std::cin.clear();
                while (std::cin.get() != '\n');
                std::cout << "Упс...Что-то пошло не так...\nВведите заново: ";
            }
        }
    }
    //std::cin >> M;
    for (int i = 0; i<N; i++)
    {

        for (int j =0; j<N; j++)
        {
            std::cout << "Введите элемент b["<<i<<"]["<<j<<"] второй матрицы: ";
            //std::cin >> B[i][j];
            while (!(std::cin >> B[i][j]) || (std::cin.peek()) != '\n')
            {
                std::cin.clear();
                while (std::cin.get() != '\n');
                std::cout << "Упс...Что-то пошло не так...\nВведите заново: ";
            }
        }
    }
    std::cout << "\n-------------------------------------------------------------------\n";
    std::cout << "Исходные данные: \n";
    std::cout << "Матрица A: \n";
    for(int i = 0; i<N; i++)
    {
        std::cout << "| ";
        for(int j = 0; j<N; j++)
        {
            std::cout<<A[i][j]<<' ';
        }
        std::cout << "|\n";
    }
    std::cout << "Матрица B: \n";
    for(int i = 0; i<N; i++)
    {
        std::cout << "| ";
        for(int j = 0; j<N; j++)
        {
            std::cout<<B[i][j]<<' ';
        }
        std::cout << "|\n";
    }
    std::cout << "Полученная матрица: \n";
    for (int i = 0; i<N; i++)
    {
        std::cout << "| ";
        for (int j =0; j<N; j++)
        {
            int c =0;
            for (int k =0; k<N; k++)
            {
                c+= A[i][k] * B[k][j];
            }
            std::cout << c ;//<< ' ';
            std::cout << ' ';
        }
        std::cout << "|\n";
    }
    for (int i=0;i<N;i++)
    {
        delete [] A[i];
        delete [] B[i];
    }
    delete [] A;
    delete [] B;
}