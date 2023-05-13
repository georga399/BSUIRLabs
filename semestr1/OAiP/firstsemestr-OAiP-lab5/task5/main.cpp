#include <iostream>
#include <string>
#include <cassert>
int InputInt(int, int);
int ArithMean(int arr[], int size)
{
    int res = 0;
    for(int i =0; i<size; i++)
    {
        res+=arr[i];
    }
    if(size !=0)res/=size;
    return res;
}
void PrintMatrix(int ** matr, int cols, int rows)
{
    for(int i =0; i<cols; i++)
    {
        for(int j =0; j<rows; j++)
        {
            std::cout << matr[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}
void contextmenu()
{
    printf("\e[1;1H\e[2J");
    std::cout <<"Egor Azarov (253501)\n";
    std::cout << "Task 5:\n";
    std::cout << "User enters elements of matrix. Program creates array with not even elements from even columns. Then program calculate arithmethic mean.\n";
    std::cout <<"To start program enter any string: ";
    std::string str;
    std::getline(std::cin, str);
    std::cout << "-----------------------------------------------------------\n";
}
void Testing ()
{
    {
        int ** matrix = new int* [3];
        int * arroftrueval = new int[3];
        int countoftrueval = 0;
        int armean = 0;
        for (int i = 0; i<3; i++)
        {
            matrix[i] = new int[3];
            for(int j = 0; j<3; j++)
            {
                matrix[i][j] = j;
                if(j%2 == 0 && matrix[i][j] %2==1) //?
                {
                    arroftrueval[countoftrueval] = matrix[i][j];
                    countoftrueval++;
                }
            }
        }
        
        int arithmean = ArithMean(arroftrueval, countoftrueval);
        assert(arithmean==0);
    }
    {
        int ** matrix = new int* [3];
        int * arroftrueval = new int[3];
        int countoftrueval = 0;
        int armean = 0;
        for (int i = 0; i<3; i++)
        {
            matrix[i] = new int[3];
            for(int j = 0; j<3; j++)
            {
                matrix[i][j] = i+j;
                if(j%2 == 0 && matrix[i][j] %2==1) //?
                {
                    arroftrueval[countoftrueval] = matrix[i][j];
                    countoftrueval++;
                }
            }
        }
        
        int arithmean = ArithMean(arroftrueval, countoftrueval);
        assert(arithmean==2);
    }
    {
        int ** matrix = new int* [3];
        int * arroftrueval = new int[3];
        int countoftrueval = 0;
        int armean = 0;
        for (int i = 0; i<3; i++)
        {
            matrix[i] = new int[3];
            for(int j = 0; j<3; j++)
            {
                matrix[i][j] = 0;
                if(j%2 == 0 && matrix[i][j] %2==1) //?
                {
                    arroftrueval[countoftrueval] = matrix[i][j];
                    countoftrueval++;
                }
            }
        }
        
        int arithmean = ArithMean(arroftrueval, countoftrueval);
        assert(arithmean==0);
    }
}
int main()
{

    /// 
    /// Ограничение по вводу больших чисел 
    Testing();
    contextmenu();
    std::cout << "Input count of columns: ";
    int cols = InputInt(1, 100);
    std::cout << "Input count of rows: ";
    int rows = InputInt(1, 100);
    int ** matrix = new int* [cols];
    int * arroftrueval = new int[cols*rows];
    int countoftrueval = 0;
    int armean = 0;    
    for (int i = 0; i<cols; i++)
    {
        matrix[i] = new int [rows];
        for(int j = 0; j < rows; j++)
        {
            std::cout << "Input element["<<i<<"]["<<j<<"]: ";
            matrix[i][j] = InputInt(INT_MIN, INT_MAX);
            if(j%2 == 0 && matrix[i][j] %2==1) //?
            {
                arroftrueval[countoftrueval] = matrix[i][j];
                countoftrueval++;
            }
        }
    }
    std::cout << "Initial data: \n";
    PrintMatrix(matrix, cols, rows);
    std::cout << "Array of true values: \n";
    for(int i = 0; i<countoftrueval; i++)
    {
        std::cout <<arroftrueval[i] << ' ';
    }
    int arithmean = ArithMean(arroftrueval, countoftrueval);
    std::cout << "\n Arithmetical mean of true values: " << arithmean;
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