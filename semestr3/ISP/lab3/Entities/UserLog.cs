using System.Dynamic;
using System;
namespace Entities;
public class UserLog
{
    public string User {get; private set;}
    public DateTime Date{get;}
    public UserLog(string user, DateTime date) 
    {
        User = user;
        Date = date;
    }
    public override string ToString()
    {
        return User + " Update:" + Date.ToString();
    }
}