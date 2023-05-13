#include "struct.h"
int InputInt(int min, int max)
{
    bool isvalidinput = 0;
    int res = 0;
    char buf[6];
    char ex[] = "EXIT";
    do 
    {
        int counter = 0;
        char c;
        while((c = getchar())!='\n')
        {
            counter++;
            if(counter>5)
            {
                printf("Error input...Try again: ");
                fflush(stdin);
                counter = 0;
                break;
            } 
            buf[counter-1] = c;
        }
        if(counter != 0)
        {
            
            buf[counter] = '\0';
            if(strcmp(buf, ex) == 0) return -1;
            int i =0;
            
            for(; i<counter; i++)
            {
                if(!(buf[i]>='0' && buf[i]<='9')) 
                break;
            }
            if(i != counter) 
            {
                printf("Error input... Try again: ");
                continue;
            }
            res = atoi(buf);
            if(res>=min && res<=max) isvalidinput = 1;
            else printf("Error input... Try again: ");
        }
    } while (!isvalidinput);
    return res;
}
void InputStr(char** str)
{
    bool isvalidinput = 0;
    char buf[128];
    do
    {
        int counter = 0;
        char c;
        while((c = getchar())!='\n')
        {
            counter++;
            if(counter>126)
            {
                printf("Error input...Try again: ");
                fflush(stdin);
                counter = 0;
                break;
            } 
            buf[counter-1] = c;
        }
        if(counter != 0)
        {
            buf[counter] = '\0';
            isvalidinput = 1;
        }
    } while (!isvalidinput);
    free(*str);
    (*str) = (char*)malloc(strlen(buf)+1);
    strcpy(*str, buf);
}
long double InputLD()
{
    bool isvalidinput = 0;
    long double res = 0;
    char buf[6];
    char ex[] = "EXIT";
    do 
    {
        int counter = 0;
        char c;
        while((c = getchar())!='\n')
        {
            counter++;
            if(counter>5)
            {
                printf("Error input...Try again: ");
                fflush(stdin);
                counter = 0;
                break;
            } 
            buf[counter-1] = c;
        }
        if(counter != 0)
        {
            
            buf[counter] = '\0';
            if(buf[0] == '.') 
            {
                printf("Error input... Try again: ");
                continue;
            }
            if(strcmp(buf, ex) == 0) return -1;
            int i =0;
            int countofdots = 0;
            for(; i<counter; i++)
            {
                if((buf[i]>='0' && buf[i]<='9') || (buf[i]=='.' && countofdots++ == 0)) continue;
                else 
                {
                    break;
                }
            }
            if(i != counter) 
            {
                printf("Error input... Try again: ");
                continue;
            }
            if(counter == i){
                res = atof(buf);
                if(res>=0 && res<=100) isvalidinput = 1;
                else printf("Error input... Try again: ");
            }
        }
    } while (!isvalidinput);
    return res;
    
}