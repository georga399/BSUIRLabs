using Collections;
using Interfaces;
using Contracts;
using System.Numerics;
namespace Entities;

public class Airport: IAirport
{
    public ICustomCollection<User> Users {get; }
    public ICustomCollection<Rate> Rates {get; }
    public Airport(ICustomCollection<User> users, ICustomCollection<Rate> rates)
    {
        Users = users;
        Rates = rates;
    }
    public void AddRate(Rate rate)
    {
        Rates.Add(rate);
    }
    public void AddUser(User user)
    {
        Users.Add(user);
    }
    public void RegisterPurchase(User user, Rate rate)
    {
        user.Rates.Add(rate);
    }
    public Cost GetPurchaseAmount(User user)
    {
        Cost amount  = new(0);
        user.Rates.Reset();
        for(int i = 0; i<user.Rates.Count; i++)
        {
            user.Rates.Next();
            amount = amount + user.Rates.Current()!.Cost;
        }
        return amount;
    }
    public void GetUsersOnDate(DateTime date, ref ICustomCollection<User> users)
    {
        Users.Reset();
        for(int i = 0; i<Users?.Count; ++i)
        {
            Users.Next();
            var tempUser = Users.Current();
            tempUser?.Rates.Reset();
            for(int j = 0; j < tempUser?.Rates.Count; ++j)
            {
                tempUser.Rates.Next();
                if(tempUser.Rates.Current()?.Date == date)
                {
                    users.Add(tempUser);
                    break;
                }
            }
        }
    }
}