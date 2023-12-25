using System.Collections.Generic;
using System.Net.Http.Headers;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
namespace Entities;
public class Airport
{
    private Dictionary<string, Rate> rates{get; set;}
    private List<User> users{get; set;}
    public event Action<Rate>? OnAddingRate;
    public event Action<string>? OnAddingUser;
    public event Action<string, Rate>? OnBuying;
    public Airport()
    {
        rates = new();
        users = new();
    }
    public void AddUser(string PassData)
    {
        users.Add(new User(PassData));
        OnAddingUser?.Invoke(PassData);
    }
    public void AddRate(string id, Rate rate)
    {
        if(rates.TryAdd(id, rate))
            OnAddingRate?.Invoke(rate);
    }
    public void BuyRate(string UserPass, string id)
    {
        Rate? rate;
        rates.TryGetValue(id, out rate);
        User? user = users.FirstOrDefault(u => u.PassData == UserPass);
        if(rate is not null) 
        {
            user?.Rates.Add(rate);
            OnBuying?.Invoke(UserPass, rate);
        }
    }
    public IEnumerable<string> GetAllRates()
    {
        var idsOfRates = from r in rates
                            orderby r.Value.Cost
                            select r.Key;
        return idsOfRates;
    }
    public Cost GetRevenue()
    {
        var cost = users.SelectMany(u => u.Rates)
                    .Select(r => r.Cost)
                    .Aggregate((x, y) => x + y);
        return cost;
    }
    public Cost GetUserRevenue(string UserPass)
    {
        User? user = users.FirstOrDefault(u => u.PassData == UserPass);
        if(user is not null)
        {
            Cost cost = user.Rates
                    .Select(r => r.Cost)
                    .Aggregate((x, y) => x + y);
            return cost;
        }
        return new Cost();
    }
    public string? BiggestSpender()
    {
        var user = users.MaxBy( u => u.Rates.Sum(r => r.Cost.val));
        return user?.PassData;
    }
    public int MoreThanAmount(Cost cost)
    {

        var count = users
                    .Aggregate(0, (total, next) => 
                        next.Rates.Select(r => r.Cost.val).Sum() < cost.val ?
                         total + 1 : 
                         total);
        return count;
    }
    public IEnumerable<(string, decimal)>? GetUserRates(string UserPass) //TODO: return <string, Cost>
    {
        var user = users.FirstOrDefault(u => u.PassData == UserPass);
        if(user is null) return null;
        var costs = from r in user.Rates 
                    group r by r.Direction into g
                    select (g.Key, g.Sum(r=>r.Cost.val));
        return costs;
    }
}