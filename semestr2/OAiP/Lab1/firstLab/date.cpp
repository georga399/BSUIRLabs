#include "date.h"

Date::Date()
{

}

Date Date::NextDay()
{
    QDate tempqdt = this->addDays(1);
    Date tempdt;
    tempdt.setDate(tempqdt.year(), tempqdt.month(), tempqdt.day());
    return tempdt;
}

Date Date::PreviousDay()
{
    QDate tempqdt = this->addDays(-1);
    Date tempdt;
    tempdt.setDate(tempqdt.year(), tempqdt.month(), tempqdt.day());
    return tempdt;
}

bool Date::IsLeap()
{
    return this->isLeapYear(this->year());
}

short Date::WeekNumber()
{
    return (short)this->weekNumber();
}

int Date::DaysTillYourBirthday(Date birthdate)
{
    birthdate.setDate(this->year(), birthdate.month(), birthdate.day());
    if(birthdate<(*this))
        birthdate.setDate(this->year()+1, birthdate.month(), birthdate.day());
    return (int)this->daysTo(birthdate);
}

int Date::Duration(Date date)
{
    if(date>*this)
        return this->daysTo(date);
    else
        return date.daysTo((*this));
}
