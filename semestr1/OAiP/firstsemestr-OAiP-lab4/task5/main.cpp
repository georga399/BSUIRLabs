#include <iostream>
#include <float.h>
int main()
{
    setlocale(LC_ALL, "Russian");
    printf("\e[1;1H\e[2J");
    //int A[10][10];
    //int B[10][10];
    int N, M; //Простая проверка
    std::cout << "Введите количество строк матрицы: ";
    std::cin >> N;
    std::cout << "Введите количество столбцов матрицы: ";
    std::cin >> M;
    long double ** A = new long double*[N];
    long double ** B = new long double*[N];
    for(int i = 0; i<N; i++)
    {   
        A[i] = new long double[M];
        B[i] = new long double[M];
        for(int j=0; j<M; j++)
        {   
            std::cout << "Введите элемент матрицы a["<<i<<"]["<<j<<"]: ";
            std::cin >> A[i][j];
        }
    }
    std::cout << "\n-------------------------------------------------------------------\n";
    std::cout << "Исходные данные:\n";
    for(int i = 0; i<N; i++)
    {
        std::cout << "| ";
        for(int j=0; j<M; j++)
        {
            std::cout << A[i][j] << ' ';
        }
        std::cout << "|\n";
    }
    std::cout << "Результат:\n";

    for(int i = 0; i<N; i++)
    {
        std::cout << "| ";
        for(int j = 0; j<M; j++)
        {
            long double max = A[i][j];
            long double a, b, c;
            
            if(i==0)
            {
                //b = -1e8;
                c = -LDBL_MAX;
                b = -LDBL_MAX;
            }
            else 
            {
                c=B[i-1][j];
            }
            if(j == 0)
            {
                a = -LDBL_MAX;
                b = -LDBL_MAX;
                //b = -1e8;
            }
            else
            {
                a=B[i][j-1];
            }
            if(a!= -LDBL_MAX && c!= -LDBL_MAX)
            {
                b=B[i-1][j-1];
            }
            max = (max < a)? a:max;
            max = (max < b)? b:max;
            max = (max < c)? c:max;
            B[i][j] = max;
            std::cout << B[i][j] << ' ';
        }
        std::cout << "|"<<std::endl;
    }
    for (int i =0; i<N; i++)
    {
        delete [] A[i];
        delete [] B[i];
    }   
    delete [] A;
    delete [] B;
}