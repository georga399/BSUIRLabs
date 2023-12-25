namespace Entities;
public class User
{
    public User(string data)
    {
        PassData = data;
        Rates = new();
    }
    public string PassData {get; set;}
    public List<Rate> Rates{get; set;}
}