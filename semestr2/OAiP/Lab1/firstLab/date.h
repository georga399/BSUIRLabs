#ifndef DATE_H
#define DATE_H
#include <QDate>

class Date: public QDate
{
public:
    Date();
    Date NextDay();
    Date PreviousDay();
    bool IsLeap();
    short WeekNumber();
    int DaysTillYourBirthday(Date birthdate);
    int Duration(Date date);
};

#endif // DATE_H
