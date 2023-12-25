using Collections;
namespace Entities;
public class Airport
{
    public delegate void AddUserHandler(User user);
    public delegate void AddRateHandler(Rate rate);
    public delegate void AddPurchaseHandler(Purchase purchase);
    public event AddUserHandler? AddingUserEvent;
    public event AddRateHandler? AddingRateEvent;
    public event AddPurchaseHandler? AddingPurchaseEvent;
    private MyCustomCollection<User> users{get; set;}
    public MyCustomCollection<Rate> rates{get; private set;}
    private MyCustomCollection<Purchase> purchases{get; set;}
    public Airport()
    {
        users = new MyCustomCollection<User>();
        rates = new MyCustomCollection<Rate>();
        purchases = new MyCustomCollection<Purchase>();
    }
    public void AddUser(User user)
    {
        users.Add(user);
        AddingUserEvent?.Invoke(user);
    }
    public void AddRate(Rate rate)
    {
        rates.Add(rate);
        AddingRateEvent?.Invoke(rate);
    }
    public User? FindUserByPass(string passData)
    {
        foreach(var usr in users)
        {
            if(passData == usr.PassData)
            {
                return usr;
            }
        }
        return null;
    }
    public Rate? FindRateByName(string name)
    {
        foreach(var rate in rates)
        {
            if(rate.Name == name)
            {
                return rate;
            }
        }
        return null;
    }
    public void AddPurchase(User user, Rate rate)
    {
        var purchase = new Purchase(user, rate);
        purchases.Add(purchase);
        AddingPurchaseEvent?.Invoke(purchase);

    }
    public void RemoveUser(User user)
    {
        users.Remove(user);
    }
    public void RemoveRate(Rate rate)
    {
        rates.Remove(rate);
    }
}