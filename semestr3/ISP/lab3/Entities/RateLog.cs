using System.Dynamic;
using System;
namespace Entities;
public class RateLog
{
    public Rate Rate {get; private set;}
    public DateTime Date{get;}
    public RateLog(Rate rate, DateTime date) 
    {
        Rate = rate;
        Date = date;
    }
    public override string ToString()
    {
        return Rate.Direction + " Update:" + Date.ToString();
    }
}