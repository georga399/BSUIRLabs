#include <iostream>
#include <cstdio>
int InputInt();
void GetMatr(char *** matr, int cols, int rows, int **sizeofstrns);
void PrintMatr(char ***matr, int cols, int rows, int **sizeofstrns);
//void contextmenu();
int main()
{
  //  contextmenu();
    printf("Input count of columns of matrix: ");
    int cols = InputInt();
    printf("Input count of rows of matrix: ");
    int rows = InputInt();
    char ***matr = (char***)malloc(cols*sizeof(char**));
    //int **sizeofstrns = new int*[cols];
    int **sizeofstrns = (int**)malloc(cols*sizeof(int*));
    printf("Input strings of matrix %dx%d:\n", cols, rows);
    GetMatr(matr, cols, rows, sizeofstrns);
    printf("\n---------------------------------------\n");
    printf("Result: \n");
    
    PrintMatr(matr, cols, rows, sizeofstrns);
    for (int i=0; i<cols; i++)
    {
        for(int j=0;j<rows; j++)
        {
            free(matr[i][j]);
        }
        free(matr[i]);
        //delete [] sizeofstrns[i];
        free(sizeofstrns[i]);
    }
    free(matr);
    //delete [] sizeofstrns;
    free(sizeofstrns);
}

void PrintMatr(char ***matr, int cols, int rows, int **sizeofstrns)
{
    for(int i =0; i<cols; i++)
    {
        for(int j = 0; j<rows; j++)
        {
            for(int k = 0; k<sizeofstrns[i][j]; k++)
            {
                printf("%c", matr[i][j][k]);
            }
            printf(" ");
        }
        printf("\n");
    }
}
int InputInt()
{
    bool isvalidinput = 0;
    int res;
    while(!isvalidinput)
    {
        char c;
        char str[100]{};
        int counter = 0;
        int howmanydots = 0;
        int k =0 ;
        while((c=getchar()) != '\n')
        {   
            k++;
            if(!(isdigit(c)) || counter>4)
            {
                //printf("Wrong input. Try again: ");
                while(c=getchar() !='\n');
                break;
            }
            str[counter] = c;
            counter++;

        }
        if(counter==k && !(str[counter-1]!='\n' && (res = atoi(str))==0))
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
void GetMatr(char *** matr, int cols, int rows, int **sizeofstrns)
{
     for (int i=0; i<cols; i++)
    {
        matr[i] = (char**)malloc(rows*sizeof(char*));
        //sizeofstrns[i] = new int[rows];
        sizeofstrns[i] = (int*)malloc(rows*sizeof(int));
        for(int j=0; j<rows; j++)
        {
            printf("Input element[%d][%d](in the end press ENTER): ", i, j);
            char c;
            int size = 0;
            int tsize = 80;
            int tcounter = 0;

            matr[i][j] = (char*)malloc(tsize*sizeof(char));
            while ((c=getchar())!='\n')
            {
                if(size == tsize)
                {
                    tsize+=20;
                    matr[i][j] = (char*)realloc(matr[i][j], tsize*sizeof(char));
                } 

                matr[i][j][size] = c;
                size++;
                tcounter += c%2;
            }
            sizeofstrns[i][j] = size;
            if(tcounter%2 == 0)
            {
                int t = size;
                while(t != size/2)
                {
                    std::swap(matr[i][j][t-1], matr[i][j][size - t]);
                    t--;
                }
            }
        }
    }
} 