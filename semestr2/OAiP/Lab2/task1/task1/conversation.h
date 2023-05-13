#ifndef CONVERSATION_H
#define CONVERSATION_H
#include <QDate>
#include <QString>
struct Conversation
{
    QDate date;
    QString city;
    unsigned int seconds;
    int tariff;
    QString numberOfCallerFrom;
    QString numberOfCallerTo;
};

#endif // CONVERSATION_H
