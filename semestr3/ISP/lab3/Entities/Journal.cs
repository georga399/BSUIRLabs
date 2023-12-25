using System.ComponentModel;
using Entities;
public class Journal
{
    public delegate void AddUserDelegate(User user);
    public Action<string> UserHandler;
    public Action<Rate> RateHandler;
    private List<UserLog> userAddingEvents{get; set;}
    private List<RateLog> rateAddingEvents{get; set;}
    public Journal()
    {
        userAddingEvents = new List<UserLog>();
        rateAddingEvents = new List<RateLog>();
        UserHandler += AddUserEvent;
        RateHandler += AddRateEvent;
    }
    public void AddUserEvent(string user)
    {
        var userLog = new UserLog(user, DateTime.Now);
        userAddingEvents.Add(userLog);
        Console.WriteLine($"Adding user to journal {userLog}");
    }
    public void AddRateEvent(Rate rate)
    {
        var rateEvent = new RateLog(rate, DateTime.Now);
        rateAddingEvents.Add(rateEvent);
        Console.WriteLine($"Adding rate to journal {rateEvent}");
    }
}