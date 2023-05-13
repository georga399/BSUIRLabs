#include <cstdio>
int InputArr(char *);
int GetCountGroups(char* arr, int size);
int main()
{
    printf("%s", "Input array of 0 and 1: \n");
    char arr[80]{};
    int size = InputArr(arr);
    int count = GetCountGroups(arr, size);
    printf("%s", "Count of groups with 5 digits: ");
    printf("%d", count);
}
int InputArr(char *arr)
{
    int size = 0;
    char c;
    bool isvalidinput = 0;
    int k = 0;
    while (!isvalidinput)
    {   
        size = 0;
        k = 0;
        while ((c = getchar())!='\n')
        {
            k++;
            if(size>=80)
            {
                printf("%s", "Error, try again: \n");
                while((c=getchar())!='\n');
                break;
            }
            if(!(c == '0' || c=='1' || c==' '))
            {
                
                printf("%s", "Error, try again: \n");
                while((c=getchar())!='\n');
                break;
            }
            arr[size] = c;
            size++;
            
        }
        if(c=='\n' && size!=0 && k==size) isvalidinput = 1; 
    }
    return size;
}

int GetCountGroups(char* arr, int size)
{
    int counter = 0;
    int helpcounter = 0;
    for(int i=0; i<size; i++)
    {
        if(arr[i] == ' ')
        {
            helpcounter = 0;
            continue;
        }
        helpcounter++;
        if(helpcounter==5 && (arr[i+1] == ' ' || i==size-1))
        {
            counter++;
        }
    }
    return counter;
}