using Entities;
public static class Initilizer
{
    public static void Initialize(Airport airport)
    {
        InitUsers(airport);
        InitRates(airport);
        InitPurchases(airport);
    }
    public static void InitUsers(Airport airport)
    {
        airport.AddUser("Egor");
        airport.AddUser("Dima");
        airport.AddUser("Danik");
        airport.AddUser("Alex");
        airport.AddUser("Lex");
        airport.AddUser("David");
        airport.AddUser("Gena");
        airport.AddUser("Oleg");
    }
    public static void InitRates(Airport airport)
    {
        airport.AddRate("Business-31", new Rate("Pekin", new Cost(123), new DateTime(2023, 12, 12)));
        airport.AddRate("Business-33", new Rate("Pekin", new Cost(300), new DateTime(2023, 12, 20)));
        airport.AddRate("Business-35", new Rate("Pekin", new Cost(233), new DateTime(2023, 12, 30)));
        airport.AddRate("Belavia-90", new Rate("Minsk", new Cost(132), new DateTime(2030, 11, 11)));
        airport.AddRate("Light-0340", new Rate("NY", new Cost(400), new DateTime(2023, 10, 10)));
        airport.AddRate("Light-0789", new Rate("LA", new Cost(123), new DateTime(2023, 9, 9)));
        airport.AddRate("Light-0898", new Rate("WA", new Cost(123), new DateTime(2023, 12, 11)));
    }
    public static void InitPurchases(Airport airport)
    {
        airport.BuyRate("Egor", "Business-33");
        airport.BuyRate("Egor", "Business-35");
        airport.BuyRate("Egor", "Business-31");
        airport.BuyRate("Dima", "Business-31");
        airport.BuyRate("Danik", "Belavia-90");
        airport.BuyRate("Alex", "Belavia-90");
        airport.BuyRate("David", "fas-31");
        airport.BuyRate("Gena", "Light-0789");
        airport.BuyRate("Gena", "Light-0789");
        airport.BuyRate("Egor", "Light-0340");
        airport.BuyRate("David", "Business-31");
        airport.BuyRate("Alex", "Business-31");
        airport.BuyRate("Egor", "Business-31");
        airport.BuyRate("Egor", "Business-31");
        airport.BuyRate("Egor", "Business-31");
        airport.BuyRate("David", "Business-31");
        airport.BuyRate("Lex", "Business-31");
        airport.BuyRate("Egor", "Business-31");
        airport.BuyRate("Lex", "Business-31");
    }
}