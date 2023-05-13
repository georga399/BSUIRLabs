#include <iostream>
#include <string>
#include <conio.h>
#include "Struct.h"
typedef void (*action)(conversation **, int&);
action actions[7] = {AddConverstion, DeleteConverstion, ChangeConversation, ShowAllConversations, ShowDataforCity, ReadFromFile, WriteToFile};
int main()
{
    conversation* arr;
    int sizeofarr = 0;
    std::string menu[7] = {"0.Add conversation ", "1.Delete Conversation ", "2.Change conversation ", "3.Show all conversations ", "4.Show data for city ", "5.Read from .txt file", "6.Write to .txt file"};
    do
    {
        std::cout << "\x1B[2J\x1B[H";
        for(int i = 0; i<7; i++)
        {
            std::cout << menu[i] << std::endl;
        }
        std::cout << "___________________________________" <<std::endl;
        std::cout << "(To exit enter 'EXIT')" << std::endl;
        std::cout << "Enter digit (0-6): ";
        int activemenu = InputInt(0, 6); 
        if(activemenu == -1)
        {
            if(sizeofarr > 0) DestructConversations(&arr, sizeofarr);
            exit(0);
        }
        actions[activemenu](&arr, sizeofarr);
    } while (1);
}
