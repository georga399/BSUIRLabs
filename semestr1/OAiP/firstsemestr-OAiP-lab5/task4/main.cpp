#include <iostream>
#include <string>
#include <exception>
#include <limits>
#include <cassert>
int InputInt(int, int);
long double InputLD();
void Reverse(long double **arr, int n, int k)
{
    for(int i = 0; i<n/2; i++)
    {
        std::swap(arr[i], arr[n-i-1]);
        for(int j = 0; j<k/2; j++)
        {
            std::swap(arr[i][j], arr[i][k-j-1]);
            std::swap(arr[n-1-i][j], arr[n-i-1][k-j-1]);
        }
    }
    if(n%2 != 0)
    {
        for (int j = 0; j<k/2; j++)
        {
            std::swap(arr[n/2][j], arr[n/2][k-j-1]);
        }
    }
}

void PrintMatrix(long double **matr, int columns, int rows)
{
    for (int i = 0; i<columns; i++)
    {
        for(int j =0 ; j<rows; j++)
        {
            std::cout << matr[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}
void contexmenu()
{
    printf("\e[1;1H\e[2J");
    std::cout <<"Egor Azarov (253501)\n";
    std::cout << "Task 4:\n";
    std::cout << "Program find positions of zero in array. Also program reverse positons of elements in this array. \n";
    std::cout <<"To start program enter any string: ";
    std::string str;
    std::getline(std::cin, str);
    std::cout << "-----------------------------------------------------------\n";

}
void Testing ()
{
    {
        
        long double ** array = new long double*[2];
        int * posiofzero = new int [2];
        int * posjofzero = new int [2]; 
        int counterzero = 0;
        for (int i =0; i<2; i++)
        {
            array[i] = new long double[2];
            for(int j = 0; j<2; j++)
            {
                array[i][j] = j;   
                if (array[i][j]==0)
                {
                    posiofzero[counterzero] = i;
                    posjofzero[counterzero] = j;
                    counterzero++;
                }
            }
        }
        assert(counterzero==2);
        for(int i = 0; i<2; i++)
        {
            delete [] array[i];
        }
        delete [] array;
    }
    {
        long double firstmatr[3][3] = {{1,2,3},
                                        {3,79,9},
                                        {4,6,7}};
        long double seconfmatrix[3][3] = {{7,6,4},
                                          {9,79,3},
                                          {3,2,1}};
        long double ** array = new long double*[3];
        int * posiofzero = new int [3];
        int * posjofzero = new int [3]; 
        int counterzero = 0;
        for (int i =0; i<3; i++)
        {
            array[i] = new long double[3];
            for(int j = 0; j<3; j++)
            {
                array[i][j] = firstmatr[i][j];   
                if (array[i][j]==0)
                {
                    posiofzero[counterzero] = i;
                    posjofzero[counterzero] = j;
                    counterzero++;
                }
            }
        }
        Reverse(array, 3,3);
        for (int i = 0; i<3; i++)
        {
            for(int j =0; j<3;j++)
            {
                assert(array[i][j]==seconfmatrix[i][j]);
            }
        }
        assert(counterzero==0);
        for(int i = 0; i<3; i++)
        {
            delete [] array[i];
        }
        delete [] array;   
    }
    {
        
        long double ** array = new long double*[3];
        int * posiofzero = new int [3];
        int * posjofzero = new int [3]; 
        int counterzero = 0;
        for (int i =0; i<3; i++)
        {
            array[i] = new long double[3];
            for(int j = 0; j<3; j++)
            {
                array[i][j] = 0;   
                if (array[i][j]==0)
                {
                    posiofzero[counterzero] = i;
                    posjofzero[counterzero] = j;
                    counterzero++;
                }
            }
        }
        Reverse(array, 3,3);
        for (int i = 0; i<3; i++)
        {
            for(int j =0; j<3;j++)
            {
                assert(array[i][j]==0);
            }
        }
        assert(counterzero==9);
        for(int i = 0; i<3; i++)
        {
            delete [] array[i];
        }
        delete [] array;  
    }
}
int main()
{
    Testing();
    contexmenu();
    std::cout << "Input count of columns array: ";
    int n = InputInt(1, INT_MAX);
    std::cout << "Input count of rows array: ";
    int k = InputInt(1, INT_MAX);
    long double ** array = new long double*[n];
    int * posiofzero = new int [n];
    int * posjofzero = new int [n]; 
    int counterzero = 0;
    for (int i =0; i<n; i++)
    {
        array[i] = new long double[k];
        for(int j = 0; j<k; j++)
        {
            std::cout << "Input element[" << i << "][" << j<<"]: ";
            array[i][j] = InputLD();
            if (array[i][j]==0)
            {
                posiofzero[counterzero] = i;
                posjofzero[counterzero] = j;
                counterzero++;
            }
        }
    }
    std::cout << "Initial data: \n";
    PrintMatrix(array, n, k);
    Reverse(array, n, k);
    std::cout << "\nReversed matrix: \n";
    PrintMatrix(array, n, k);
    std::cout << "\nCount of position zero: " << counterzero;
    std::cout << "\nPositions: \n"; 
    for(int i = 0; i<counterzero; i++)
    {
        std::cout << posiofzero[i] << " " <<posjofzero[i] << std::endl;
    }    


    for(int i = 0; i<n; i++)
    {
        delete [] array[i];
    }
    delete [] array;
}
  
long double InputLD()
{
    std::string str;
    bool validinput = 0;
    long double ld;
    while(!validinput)
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
        int i = 0;
        for(; i<str.length(); i++)
        {
            char el = str[i];
            if((str[i]>= '0' && str[i]<='9') || (str[i] == '.' && howmanydots == 0 && i!=str.length()-1) || (str[i] == 'e' && howmanye==0) || (str[i] == '-' &&(posofe + 1 ==i || i==0) ))
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
                break;
            }
        }
        if(i==str.length())
        {
            validinput = 1;
            try{
                ld = std::stold(str);
            }
            catch(std::exception &e)
            {
                std::cout << "Error input. Try again: ";
                validinput = 0;
            }
            
        }
        else 
        {
            std::cout << "Error input. Try again: ";
        }
    }
    return ld;
}

int InputInt(int inf = INT_MIN, int sup = INT_MAX)
{
    bool isvalidinput = 0;
    std::string str;
    int out;
    while (!isvalidinput)
    {    
        std::getline(std::cin, str);
        int i = 0;
        int b = 1;
        if(str[i] == '-')
        {
            b=-1;
            i++;
        }
        for(;i<str.length(); i++)
        {
            if(str[i]<='9' && str[i]>='0')
            {
                continue;
            }
            else
            {
                break;
            }
        }
        if(i == str.length())
        {
            try
            {
                out = stoi(str);
            }
            catch(std::exception &e)
            {
                std::cout << "Error input. Please, try again: ";
                continue;
            }
            if(out<inf || out >sup)
            {
                std::cout << "Error input. Please, try again: ";
                continue;
            }
            isvalidinput=1;
        }   
        else
        {
            std::cout << "Error input. Please, try again: ";
        }
    }
    return out;
}