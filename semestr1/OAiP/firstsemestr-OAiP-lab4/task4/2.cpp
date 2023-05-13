#include <iostream>
#include <float.h>
#include <exception>
int main()
{
    
    int k, j;
    std::cin >> k >> j;
    //int matrix[1000][1000];
    long double **matrix = new long double*[k];
    int counter = 0;
    for(int i = 0; i<k; i++ )
    {
        matrix[i] = new long double [j];
        for(int l = 0; l<j; l++)
        {
            std::cin >> matrix[i][l];
        }
    }
    for(int i = 0; i<k; i++ )
    {
        for(int l = 0; l<j; l++)
        {
            long double el = matrix[i][l];
            long double a, b,c,d,q,f,g,h;
            try
            {
                a = matrix[i-1][l-1];
            }
            catch(std::exception &e)
            {
                a = LDBL_MAX;
            }
            try
            {
                b = matrix[i-1][l];
            }
            catch(std::exception &e)
            {
                b = LDBL_MAX;
            }
            try
            {
                c = matrix[i-1][l+1];
            }
            catch(std::exception &e)
            {
                c = LDBL_MAX;
            }
            try
            {
                d = matrix[i][l+1];
            }
            catch(std::exception &e)
            {
                d = LDBL_MAX;
            }
            try
            {
                q = matrix[i+1][l+1];
            }
            catch(std::exception &e)
            {
                q = LDBL_MAX;
            }
            try
            {
                f = matrix[i+1][l];
            }
            catch(std::exception &e)
            {
                f = LDBL_MAX;
            }
            try
            {
                g = matrix[i+1][l-1];
            }
            catch(std::exception &e)
            {
                g = LDBL_MAX;
            }
            try
            {
                h = matrix[i][l-1];
            }
            catch(std::exception &e)
            {
                h = LDBL_MAX;
            }
            if(el<a && el<b && el<c && el<d && el<q && el<f && el<g && el<h)
            {
                counter++;
            }
        }
        
    }
    std::cout << counter;
    for(int i =0; i<k; i++)
    {
        delete [] matrix[i];
    }
    delete [] matrix;
}