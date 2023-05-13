#include <ctype.h>
#include <cstdio>
#include <stdlib.h>
int InputTxt(char**, int);
double ValidInputD();
long double ToCountCost(char*,int, double costperword);
int main()
{
    int size = 100;
    char *txt = (char*)malloc(sizeof(char)*size);
    printf("Input text(in the end click ENTER twice): \n");
    size = InputTxt(&txt, size);
    printf("Input cost of one word: ");
    double costperword = ValidInputD();
    printf("Your telegram: \n");
    long double cost = ToCountCost(txt,size, costperword);
    printf("Cost of pubclication this text: %Lf", cost);
    free(txt);
}
int InputTxt(char **txt, int size)
{
    int counter = 0;
    char c;
    while(!( (c = getchar()) == '\n' && (*txt)[counter-1] == '\n'))
    {
        if(counter>size-1)
        {
            size+=20;
            *txt = (char*)realloc(*txt, (size)*sizeof(char));
        }
        (*txt)[counter] = c;
        counter++;
    }
    return counter + 1;
}
double ValidInputD()
{
    bool isvalidinput = 0;
    double res;
    while(!isvalidinput)
    {
        char c;
        //char str[100];
        char str[100]{};
        int counter = 0;
        int howmanydots = 0;
        int k =0 ;
        while((c=getchar()) != '\n')
        {   
            k++;
            if(!(isdigit(c) || (c=='.' && howmanydots == 0 && counter != 0)) || counter>20 )
            {
                printf("Wrong input. Try again: ");
                while(c=getchar() !='\n');
                break;
            }
            if(c=='.')
            {
                howmanydots++;
            }
            str[counter] = c;
            counter++;

        }
        if(counter==k && !(str[counter-1]!='\n' && (res = atof(str))==0))
        {
            //printf("%s", str);
            isvalidinput = 1;
        }
        if(res == 0)
        {
            printf("Wrong input. Try again: ");
        }
    }
    return res;
}
long double ToCountCost(char* str, int size, double costperword)
{
    int res = 0;
    for(int i = 0; i<size; i++)
    {
        if(isalpha(str[i]) && (str[i+1] == ' ' || str[i+1] == '\n' || str[i+1] == '.' || str[i+1] == ',' || str[i+1] == 0))
        {
            res++;
        }
        printf("%c", str[i]);
    }
    res *=costperword;
    return res;
}