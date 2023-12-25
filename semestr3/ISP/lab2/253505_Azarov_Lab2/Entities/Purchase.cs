namespace Entities;
public class Purchase
{
    public Purchase(User user, Rate rate)
    {
        User = user;
        Rate = rate;
    }
    public User User{get; set;}
    public Rate Rate{get; set;}
}