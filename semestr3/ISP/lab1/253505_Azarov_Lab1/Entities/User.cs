using Interfaces;
namespace Entities;
public class User
{
    public User(string data, ICustomCollection<Rate> rates)
    {
        PassData = data;
        Rates = rates;
    }
    public string PassData {get; set;}
    public ICustomCollection<Rate> Rates {get; set;}
}