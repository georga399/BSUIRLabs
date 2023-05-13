#pragma once 
#include <QString>
#include <regex>
QString GetAllVars(QString input);
QString GetAllClassesStructs(QString input);
QString GetAllArrays(QString input);
QString GetAllFunProto(QString input);
QString GetAllChanges(QString input);
QString GetAllLocalVars(QString input);
QString GetOverrideFuncs(QString input);
QString GetDeepBranches(QString input);
QString GetLogicalWarns(QString input);
int GetNestingsIn(int pos, int sizeStr, QString allText);
