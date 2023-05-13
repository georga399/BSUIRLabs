#include <iostream>
#include <string>

int main()
{
    std::string str;
    while(std::getline(std::cin, str))
    {
        if (str == "\0") break;
        for(int i = 0; i<str.length(); )
        {   
            if((tolower(str[i]) == 'b' || tolower(str[i]) == 'c' || tolower(str[i]) == 'd' || tolower(str[i]) == 'f' ||  tolower(str[i]) == 'g' || tolower(str[i]) == 'h' || tolower(str[i]) == 'j' || tolower(str[i]) == 'k' || tolower(str[i]) == 'l' || tolower(str[i]) == 'm' || tolower(str[i]) == 'n' || tolower(str[i]) == 'p' || tolower(str[i]) == 'q' || tolower(str[i]) == 'r' || tolower(str[i]) == 's' || tolower(str[i]) == 't' || tolower(str[i]) == 'v' || tolower(str[i]) == 'w' || tolower(str[i]) == 'x' || tolower(str[i]) == 'z') && tolower(str[i]) == tolower(str[i]))
            while(tolower(str[i]) == tolower(str[i+1]))
            {
                str.erase(i+1,1);
            }
            if(str[i] == 'c')
            {
                if(str[i+1] == 'e' || str[i+1] == 'E' || str[i+1] == 'i' || str[i+1] == 'I' || str[i+1] == 'y' || str[i+1] == 'Y')
                str[i] = 's';
                else
                str[i] = 'k';
            
            }
            else if(str[i] == 'C')
            {
                if(str[i+1] == 'e' || str[i+1] == 'E' || str[i+1] == 'i' || str[i+1] == 'I' || str[i+1] == 'y' || str[i+1] == 'Y')
                str[i] = 'S';
                else
                str[i] = 'K';
            
            }
            
            if(str[i] == 'q')
            {
                str[i] = 'k';
                if(str[i+1] == 'u')
                {
                    str[i+1] = 'v';
                }
                else if(str[i+1] == 'U')
                {
                    str[i+1] = 'V';
                } 
                
            }
            else if(str[i] == 'Q')
            {
                str[i] = 'K';
                if(str[i+1] == 'u')
                {
                    str[i+1] = 'v';
                }
                else if(str[i+1] == 'U')
                {
                    str[i+1] = 'V';
                } 
                
            }
            if(str[i] == 'x')
            {
                str[i] = 'k';
                str.insert(i+1, 1, 's');
                
            }
            else if(str[i] == 'X')
            {
                str[i] = 'K';
                str.insert(i+1, 1, 's');
            }
            if(str[i] == 'w')
            {
                str[i]='v';
            }
            else if(str[i]=='W')
            {
                str[i] = 'V';
            }
            if(str[i] == 'p' && str[i+1] == 'h')
            {
                str[i]='f';
                str.erase(i+1,1);
            }
            else if (str[i] == 'P' && (str[i] == 'h' || str[i] == 'H'))
            {
                str[i] = 'F';
                str.erase(i+1,1);
            }
            if(str[i] == 't' && str[i+1] == 'h')
            {
                str[i]='z';
                str.erase(i+1,1);
            }
            else if (str[i] == 'T' && (str[i] == 'h' || str[i] == 'H'))
            {
                str[i] = 'Z';
                str.erase(i+1,1);
            }
            if(str[i] == 'y' && str[i+1] == 'o' && str[i+2] == 'u')
            {
                str[i] = 'u';
                str.erase(i+1,2);
                //str.erase(i+2,1);
            }//////
            else if(str[i] == 'Y' && ((str[i+1] == 'o' && str[i+2] == 'u') || (str[i+1] == 'O' && str[i+2] == 'U')))
            {
                str[i] = 'U';
                str.erase(i+1,2);
                //str.erase(i+1,1);
            }
            if(str[i] == 'o' && str[i+1] == 'o')
            {
                str[i] = 'u';
                str.erase(i+1,1);
            }
            else if(str[i] == 'O' && (str[i+1]=='O' || str[i+1]=='o'))
            {
                str[i] == 'U';
                str.erase(i+1,1);
            }
            if(str[i] == 'e' && str[i+1] == 'e')
            {
                str[i] = 'i';
                str.erase(i+1,1);
            }
            else if(str[i] == 'E' && (str[i+1]=='E' || str[i+1]=='e'))
            {
                str[i] == 'I';
                str.erase(i+1,1);
            }
            if(str[i] == 't' && str[i+1] == 'h')
            {
                str[i] = 'z';
                str.erase(i+1,1);
            }
            else if(str[i]=='T' && (str[i+1]=='h' || str[i+1]=='H'))
            {
                str[i] = 'Z';
                str.erase(i+1,1);
            }

            ///
            if((tolower(str[i]) == 'b' || tolower(str[i]) == 'c' || tolower(str[i]) == 'd' || tolower(str[i]) == 'f' ||  tolower(str[i]) == 'g' || tolower(str[i]) == 'h' || tolower(str[i]) == 'j' || tolower(str[i]) == 'k' || tolower(str[i]) == 'l' || tolower(str[i]) == 'm' || tolower(str[i]) == 'n' || tolower(str[i]) == 'p' || tolower(str[i]) == 'q' || tolower(str[i]) == 'r' || tolower(str[i]) == 's' || tolower(str[i]) == 't' || tolower(str[i]) == 'v' || tolower(str[i]) == 'w' || tolower(str[i]) == 'x' || tolower(str[i]) == 'z') && tolower(str[i]) == tolower(str[i]))
            {   
                while(tolower(str[i]) == tolower(str[i+1]))
                {
                    str.erase(i+1,1);
                }
                if (tolower(str[i]) == tolower(str[i-1]))
                {
                    str.erase(i, 1);
                    continue;
                }

            }
            i++;
        }
        std::cout<< str<<'\n';
    }
    
}