#ifndef AIRWAYFUNC
#define AIRWAYFUNC
#include "airwayclass.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <io.h>
void ShowAllAirways(FILE *);
void ShowAirwaysforDestin(FILE *);
void ChangeAirway(FILE *);
void DeleteAirway(FILE *);
void AddAirway(FILE *); 
void _sortairways(airway *, int b, int e);
void __makecorrect(FILE * fd);
int InputInt(int min, int max);
unsigned long long InputNumber();
void InputStr(std::string &str);
void InputTime(std::string &str);
#endif