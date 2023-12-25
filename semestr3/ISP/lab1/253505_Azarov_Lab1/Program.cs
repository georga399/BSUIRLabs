using Entities;
using Collections;
using Interfaces;
var airport = new Airport(new MyCustomCollection<User>(), 
            new MyCustomCollection<Rate>());
       

       Initialiser.Initialise(airport);

airport.RegisterPurchase(user1, rate1);
airport.RegisterPurchase(user1, rate1);
airport.RegisterPurchase(user2, rate1);
airport.RegisterPurchase(user3, rate3);
airport.RegisterPurchase(user4, rate4);
airport.RegisterPurchase(user4, rate5);
airport.RegisterPurchase(user6, rate7);
airport.RegisterPurchase(user3, rate3);
airport.RegisterPurchase(user3, rate1);
airport.RegisterPurchase(user7, rate2);
airport.RegisterPurchase(user5, rate1);

var amount1 = airport.GetPurchaseAmount(user1);
var amount2 = airport.GetPurchaseAmount(user2);
var amount3 = airport.GetPurchaseAmount(user3);
var amount4 = airport.GetPurchaseAmount(user4);
var amount5 = airport.GetPurchaseAmount(user5);
var amount6 = airport.GetPurchaseAmount(user6);
var amount7 = airport.GetPurchaseAmount(user7);

Console.WriteLine($"{user1.PassData}'s amount: {amount1}");
Console.WriteLine($"{user2.PassData}'s amount: {amount2}");
Console.WriteLine($"{user3.PassData}'s amount: {amount3}");
Console.WriteLine($"{user4.PassData}'s amount: {amount4}");
Console.WriteLine($"{user5.PassData}'s amount: {amount5}");
Console.WriteLine($"{user6.PassData}'s amount: {amount6}");
Console.WriteLine($"{user7.PassData}'s amount: {amount7}");

ICustomCollection<User> usersOnDate1 = new MyCustomCollection<User>();
airport.GetUsersOnDate(new DateTime(2023, 7, 20), ref usersOnDate1);
Console.WriteLine("Users on date 20.07.2023:");
for(int i = 0; i<usersOnDate1.Count; i++)
{
    usersOnDate1.Next();
    Console.WriteLine(usersOnDate1.Current()!.PassData);
}

Console.WriteLine("After deleting first user:");

airport.Users.Remove(user1);
airport.Users.Reset();
for(int i=0; i<airport.Users.Count; i++)
{
    airport.Users.Next();
    Console.WriteLine(airport.Users.Current()?.PassData);
}

Console.WriteLine("After deleting every second users:");
airport.Users.Reset();
var initialUsersCount = airport.Users.Count;
for(int i = 0; i<initialUsersCount; i++)
{
    airport.Users.Next();
    if(i%2 == 1)
    {
        airport.Users.RemoveCurrent();
    }
}
airport.Users.Reset();
for(int i = 0; i<airport.Users.Count; i++)
{
    airport.Users.Next();
    Console.WriteLine(airport.Users.Current()!.PassData);
}