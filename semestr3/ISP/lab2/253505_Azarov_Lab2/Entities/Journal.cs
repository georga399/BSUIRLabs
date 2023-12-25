using System.ComponentModel;
using Collections;
using Entities;
public class Journal
{
    public delegate void AddUserDelegate(User user);
    public AddUserDelegate? UserHandler;
    private MyCustomCollection<UserAddingLog> userAddingEvents{get; set;}
    private MyCustomCollection<RateAddingLog> rateAddingEvents{get; set;}
    public Journal()
    {
        userAddingEvents = new MyCustomCollection<UserAddingLog>();
        rateAddingEvents = new MyCustomCollection<RateAddingLog>();
        UserHandler += AddUserEvent;
    }
    public void AddUserEvent(User user)
    {
        var userEvent = new UserAddingLog(user, DateTime.Now);
        userAddingEvents.Add(userEvent);
        Console.WriteLine($"Adding user to journal {userEvent}");
    }
    public void AddRateEvent(Rate rate)
    {
        var rateEvent = new RateAddingLog(rate, DateTime.Now);
        rateAddingEvents.Add(rateEvent);
        Console.WriteLine($"Adding rate to journal {rateEvent}");
    }
}