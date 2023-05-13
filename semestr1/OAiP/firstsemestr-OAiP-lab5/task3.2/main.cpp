#include <iostream>
#include <string>
#include <cassert>
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
int FillArrayofEvens(int res[], int * arr[], int n)
{
    int countofevens = 0;
    for(int i=0; i<n; i++)
    {
        if(arr[i][i]%2==0)
        {
            res[countofevens] = arr[i][i];
            countofevens++;
        }
    }
    return countofevens;
}
int MultiplyElofArray(int arr[], int size)
{
    int ans =1;
    
    for(int i = 0; i<size; i++)
    {
        ans*=arr[i];
    }
    return ans;
}
void contextmenu()
{
    printf("\e[1;1H\e[2J");
    std::cout <<"Egor Azarov (253501)\n";
    std::cout << "Task 3:\n";
    std::cout << "Program create array from elements that locate main diagonal of the matrix and have умут value. Also program calculate product of this elements. \n";
    std::cout <<"To start program enter any string: ";
    std::string str;
    std::getline(std::cin, str);
    std::cout << "-----------------------------------------------------------\n";
}
void Testing()
{   {
    
        int counter = 0;
        int **arr = new int *[5];
        for (int i = 0; i<5; i++)
        {
            arr[i] = new int[5];
           for(int j  = 0; j < 5; j++)
            {
                arr[i][j] = counter;
                counter++;
            }
        }
        
        int *res = new int[5];
        int count = FillArrayofEvens(res, arr, 5);
        
        int mult = MultiplyElofArray(res, count);        
        for(int i=0 ; i<5; i++)
        {
            delete [] arr[i];
        }
        delete [] arr;
        assert(MultiplyElofArray(res, 5) == 0 );
    }
    {
    
        int counter = 1;
        int **arr = new int *[5];
        for (int i = 0; i<5; i++)
        {
            arr[i] = new int[5];
           for(int j  = 0; j < 5; j++)
            {
                arr[i][j] = counter;
                counter+=j;
            }
        }
        
        int *res = new int[5];
        int count = FillArrayofEvens(res, arr, 5);
        
        int mult = MultiplyElofArray(res, count);        
        for(int i=0 ; i<5; i++)
        {
            delete [] arr[i];
        }
        delete [] arr;
        assert(MultiplyElofArray(res, count) ==  748);
    }
    {
    
        int counter = 2;
        int **arr = new int *[5];
        for (int i = 0; i<5; i++)
        {
            arr[i] = new int[5];
           for(int j  = 0; j < 5; j++)
            {
                arr[i][j] = counter;
                counter--;
            }
        }
        
        int *res = new int[5];
        int count = FillArrayofEvens(res, arr, 5);
        
        int mult = MultiplyElofArray(res, count);        
        for(int i=0 ; i<5; i++)
        {
            delete [] arr[i];
        }
        delete [] arr;
        assert(MultiplyElofArray(res, 5) == 28160 );
    }  
    
}
int main()
{
    Testing();
    contextmenu();
    std::cout << "Input size of matrix: ";
    int n = InputInt(1, INT_MAX);
    int ** arr = new int* [n];
    for (int i = 0;i<n; i++)
    {
        arr[i] = new int[n];
        for(int j =0; j<n; j++)
        {
            std::cout << "Input element["<<i<<"]["<<j<<"]: ";
            arr[i][j] = InputInt(INT_MIN, INT_MAX);
        }
    }
    
    std::cout << "Initial data: \n";
    for (int i = 0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            std::cout << arr[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    int * res = new int[n];
    int countofevens = FillArrayofEvens(res, arr, n);
    int ans = MultiplyElofArray(res, countofevens);
    std::cout << "Result: \n";
    std::cout << "Array: \n";
    int i = 0;
    for(; i<countofevens; i++)
    {
        std::cout << res[i]<<' ';
    }
    if(i == 0)
    {
        std::cout << "array is empty\n";
    }
    else
    {
        std::cout<< "Product of mult.: " <<ans;
    }
    for(int i=0; i<n; i++)
    {

        delete [] arr[i];
    }
    
    delete [] arr;
    delete [] res;
}