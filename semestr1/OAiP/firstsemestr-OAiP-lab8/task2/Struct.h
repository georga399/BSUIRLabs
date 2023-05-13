#ifndef STRUCTCONV
#define STRUCTCONV
#include <iostream>
#include <string>
#include <ctime>
#include <conio.h>
#include <float.h>
#include <fstream>
struct conversation
{
    double tariff;
    double duration;
    std::string date; 
    std::string city;
    std::string numberofcaller;
    std::string numberofcalling;
};
void ReadFromFile(conversation ** convers, int &size);
void InitConversations(conversation ** convers, int &size);
void AddConverstion(conversation ** convers, int &size);
void DeleteConverstion(conversation ** convers, int &size);
void ChangeConversation(conversation ** convers, int &size);
void ShowAllConversations(conversation ** convers, int &size);
void ShowDataforCity(conversation ** convers, int &size);
void DestructConversations(conversation ** convers, int &size);
void WriteToFile(conversation ** convers, int &size);
/////
int InputInt(int min, int max);
void InputStr(std::string &str);
void InputDate(std::string &str);
void InputNumber(std::string &str);
double InputD();
void GenerateRandConv(conversation &convers);
#endif