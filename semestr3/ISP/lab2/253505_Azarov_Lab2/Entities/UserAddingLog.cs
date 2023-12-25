using System.Dynamic;
using System;
namespace Entities;
public class UserAddingLog: AirportLog
{
    public User User {get; private set;}
    public UserAddingLog(User user, DateTime date, string msg = "") 
        :base(date, msg)
    {
        User = user;
    }
    public override string ToString()
    {
        return User.PassData + " " + date.ToString();
    }
}