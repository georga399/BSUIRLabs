#include <iostream>
#include <float.h>
int main()
{
    setlocale(LC_ALL, "Russian");
    printf("\e[1;1H\e[2J");
    int k, j; // простая проверка
    std::cout << "Введите количество строк матрицы: ";
    std::cin >> k ;
    std::cout << "Введите количество столбцов матрицы: ";
    std::cin>> j;
    //int matrix[1000][1000];
    long double **matrix = new long double*[k];
    int counter = 0;
    for(int i = 0; i<k; i++ )
    {
        matrix[i] = new long double [j];
        for(int l = 0; l<j; l++)
        {
            std::cout << "Введите элемент a["<<i<<"]["<<k<<"]: ";
            std::cin >> matrix[i][l];
        }
    }
    std::cout << "\n-------------------------------------------------------------------\n";
    std::cout << "Исходные данные:\n";
    for(int i = 0; i<k; i++ )
    {
        std::cout << "| ";
        for(int l = 0; l<j; l++)
        {
            long double el = matrix[i][l];
            long double a; //a b  c
            long double b; //h el d
            long double c; //g f  e
            long double d;
            long double e;
            long double f;
            long double g;
            long double h;
            if(i==0)
            {
                //a = LDBL_MAX;
                b = LDBL_MAX;
                //c = LDBL_MAX;
            }
            else
            {
                //a = matrix[i-1][l-1];
                b = matrix[i-1][l];
                //c = matrix[i-1][l+1];
            }
            if (i == k-1)
            {
                //g = LDBL_MAX;
                f = LDBL_MAX;
                //e = LDBL_MAX;
            }
            else 
            {
                //e = matrix[i+1][l+1];
                f = matrix[i+1][l];
                //g = matrix[i+1][l-1];
            }
            if(l == 0)
            {
                //a = LDBL_MAX;
                h = LDBL_MAX;
                //g = LDBL_MAX;
            }
            else
            {
                //a = matrix[i-1][l-1];
                h = matrix[i][l-1];
                //h = matrix[i][l-1];
            }
            if (l == j-1)
            {
                //c = LDBL_MAX;
                d = LDBL_MAX;
                //e = LDBL_MAX;
                
            }
            else
            {
                //c = matrix[i-1][l+1];
                d = matrix[i][l+1];
                //e = matrix[i+1][l+1];
            }
            if(b != LDBL_MAX && h != LDBL_MAX)
            {
                a = matrix[i-1][l-1];
            }
            else
            {
                a = LDBL_MAX;
            }
            if(b != LDBL_MAX && d != LDBL_MAX)
            {
                c = matrix[i-1][l+1];
            }
            else
            {
                c = LDBL_MAX;
            }
            if(f != LDBL_MAX && h != LDBL_MAX)
            {
                g = matrix[i+1][l-1];
            }
            else
            {
                g = LDBL_MAX;
            }
            if(f != LDBL_MAX && d != LDBL_MAX)
            {
                e = matrix[i+1][l+1];
            }
            else
            {
                e = LDBL_MAX;
            }
            if(el<a && el<b && el<c && el<d && el<e && el<f && el<g && el<h)
            {
                counter++;
            }
            std::cout<<el<<' ';

        }
        std::cout << "|\n";
        
    }
    std::cout << "Количество локальных минимумов в матрице: "<<counter;
    for(int i =0; i<k; i++)
    {
        delete [] matrix[i];
    }
    delete [] matrix;
}