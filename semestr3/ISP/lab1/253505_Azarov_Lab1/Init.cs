using Collections;
using Entities;

public static class Initialiser{
    public static void Initialise(Airport airport)
    {
        var user1 = new User("Egor", new MyCustomCollection<Rate>());
        var user2 = new User("Alex", new MyCustomCollection<Rate>());
        var user3 = new User("Igor", new MyCustomCollection<Rate>());
        var user4 = new User("Oleg", new MyCustomCollection<Rate>());
        var user5 = new User("Max", new MyCustomCollection<Rate>());
        var user6 = new User("Danik", new MyCustomCollection<Rate>());
        var user7 = new User("Leo", new MyCustomCollection<Rate>());

        airport.AddUser(user1);
        airport.AddUser(user2);
        airport.AddUser(user3);
        airport.AddUser(user4);
        airport.AddUser(user5);
        airport.AddUser(user6);
        airport.AddUser(user7);

        var rate1 = new Rate("Minsk", new Cost(49), new DateTime(2023, 7, 20));
        var rate2 = new Rate("Moscow", new Cost(89), new DateTime(2023, 7, 22));
        var rate3 = new Rate("London", new Cost(149), new DateTime(2023, 7, 20));
        var rate4 = new Rate("Berlin", new Cost(134), new DateTime(2023, 7, 22));
        var rate5 = new Rate("Pekin", new Cost(490), new DateTime(2023, 7, 22));
        var rate6 = new Rate("Canberra", new Cost(480), new DateTime(2023, 7, 20));
        var rate7 = new Rate("Hamburg", new Cost(129), new DateTime(2023, 7, 20));

        airport.AddRate(rate1);
        airport.AddRate(rate2);
        airport.AddRate(rate3);
        airport.AddRate(rate4);
        airport.AddRate(rate5);
        airport.AddRate(rate6);
        airport.AddRate(rate7);

    }
}