using System.Runtime.ConstrainedExecution;
using System.Text.RegularExpressions;
using Entities;
class Program
{    
    static void Main(string [] Args)
    {    Console.WriteLine("Hello, World!");
        var airport = new Airport();
        var journal = new Journal();
        airport.OnAddingRate += journal.RateHandler;
        airport.OnAddingUser += journal.UserHandler;
        airport.OnBuying += (string user, Rate rate) =>
        {
            Console.WriteLine($"{user} bought rate: {rate.Direction}.");
        };
        Initilizer.Initialize(airport);

        Console.WriteLine("All rates:");
        var allRates = airport.GetAllRates();
        foreach(var s in allRates)
        {
            Console.WriteLine(s);
        }

        Console.Write("General revenue:");
        var revenue = airport.GetRevenue();
        Console.WriteLine(revenue);

        Console.Write("Danik's spendings:");
        var daniksRevenue = airport.GetUserRevenue("Danik");
        Console.WriteLine(daniksRevenue);

        Console.Write("User with max spendings:");
        var maxUser = airport.BiggestSpender();
        Console.WriteLine(maxUser);

        Console.Write("Users with spendings more than 1000$:");
        var usersMoreThan = airport.MoreThanAmount(new Cost(1000));
        Console.WriteLine(usersMoreThan);

        Console.WriteLine("Egor rates:");
        var egorsRates = airport.GetUserRates("Egor");
        if(egorsRates is not null) foreach(var r in egorsRates)
        {
            Console.WriteLine($"{r.Item1} : {r.Item2}");
        }
        else Console.WriteLine("Null");
    }
}