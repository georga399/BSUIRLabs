using Collections;
using Entities;
public class Program
{
    static void Main(string [] args)
    {
        Console.WriteLine("Helllo =)");
        var airport = new Airport();        Console.WriteLine("Helllo =)");

        var journal = new Journal();
        airport.AddingRateEvent += journal.AddRateEvent;
        airport.AddingUserEvent += delegate(User user){journal.AddUserEvent(user);};
        airport.AddingPurchaseEvent += (Purchase purchase) =>
        {
            var purchaseEvent = new PurchaseLog(purchase, DateTime.Now);
            Console.WriteLine(purchaseEvent);
        };

        Initializer.Initialize(airport);
        var rates = airport.rates;
        try
        {
            var rate = rates[20];
        }
        catch (IndexOutOfRangeException ex)
        {
            Console.WriteLine($"Exception!!! {ex.Data}");
        }
        try
        {
            rates.Remove(new Rate("Mars", 1111));
        }
        catch(MyCustomRemoveException ex)
        {
            Console.WriteLine($"Exception!!! {ex.Data}");
        }
    }
}