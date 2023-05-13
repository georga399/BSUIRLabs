using System;
class DateService
{
    public static string GetDay(string strdate)
    {
       DateTime date = Convert.ToDateTime(strdate);
        return date.DayOfWeek.ToString();
    }   
    public static int GetDaysSpan(int year, int month, int day)
    {
        DateTime date = new DateTime(year, month, day);
        return (date - DateTime.Now).Days;
    }
}