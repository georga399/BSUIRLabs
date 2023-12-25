using Collections;
using Entities;
using Microsoft.VisualBasic;
public static class Initializer
{
    public static void Initialize(Airport airport)
    {
        InitUsers(airport);
        InitRates(airport);
        InitPurchases(airport);
    }
    public static void InitUsers(Airport airport)
    {
        airport.AddUser(new User("Egor"));
        airport.AddUser(new User("Alex"));
        airport.AddUser(new User("German"));
        airport.AddUser(new User("Danik"));
        airport.AddUser(new User("Brah"));
        airport.AddUser(new User("Anton"));
        airport.AddUser(new User("Lex"));
        airport.AddUser(new User("David"));
        airport.AddUser(new User("Tony"));
        airport.AddUser(new User("James"));
        airport.AddUser(new User("Oleg"));
        airport.AddUser(new User("Igor"));
        airport.AddUser(new User("Roman"));
    }
    public static void InitRates(Airport airport)
    {
        airport.AddRate(new Rate("Minsk", 43));
        airport.AddRate(new Rate("Moscow", 24));
        airport.AddRate(new Rate("Stambul", 78));
        airport.AddRate(new Rate("Pekin", 333));
        airport.AddRate(new Rate("Berlin", 90));
        airport.AddRate(new Rate("Paris", 123));
        airport.AddRate(new Rate("NY", 689));
        airport.AddRate(new Rate("LA", 789));
        airport.AddRate(new Rate("Minsk", 78));
        airport.AddRate(new Rate("Minsk", 67));
    }
    public static void InitPurchases(Airport airport)
    {
        
        var user1 = airport.FindUserByPass("Egor");
        var user2 = airport.FindUserByPass("Danik");
        var user3 = airport.FindUserByPass("Alex");
        var user4 = airport.FindUserByPass("Lex");
        var user5 = airport.FindUserByPass("Igor");
        var user6 = airport.FindUserByPass("David");
        var user7 = airport.FindUserByPass("Oleg");
        var user8 = airport.FindUserByPass("Roman");

        var rate1 = airport.FindRateByName("Minsk");
        var rate2 = airport.FindRateByName("Moscow");
        var rate3 = airport.FindRateByName("Stambul");
        var rate4 = airport.FindRateByName("Pekin");
        var rate5 = airport.FindRateByName("Berlin");
        var rate6 = airport.FindRateByName("Paris");
        var rate7 = airport.FindRateByName("NY");
        var rate8 = airport.FindRateByName("LA");

        if(user1 is not null && rate1 is not null)
            airport.AddPurchase(user1, rate1);
        if(user2 is not null && rate2 is not null)
            airport.AddPurchase(user2, rate2);
        if(user3 is not null && rate3 is not null)
            airport.AddPurchase(user3, rate3);
        if(user4 is not null && rate4 is not null)
            airport.AddPurchase(user4, rate4);
        if(user5 is not null && rate5 is not null)
            airport.AddPurchase(user5, rate5);
        if(user6 is not null && rate6 is not null)
            airport.AddPurchase(user6, rate6);
        if(user7 is not null && rate7 is not null)
            airport.AddPurchase(user7, rate7);
        if(user8 is not null && rate8 is not null)
            airport.AddPurchase(user8, rate8);
        
    }
}