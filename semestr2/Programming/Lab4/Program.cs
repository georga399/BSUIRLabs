using AirportNameSpace;
class Program
{
    static void Main(string[] args)
    {
        Airport airport1 = Airport.GetAirport("Minsk Airport", 12000, 20, 120);
        airport1.IncreaseCostOfTicket(10);
        airport1.DecreaseCostOfTicket(20);
        Console.WriteLine(airport1);
        Console.WriteLine($"Total count of seats: {airport1.CountOfSeats}");
        Console.WriteLine($"Count of sold tickets: {airport1.CountOfSoldTickets}");
        Console.WriteLine($"Cost of one ticket: {airport1.GetCostOfTicket()}");
        Console.WriteLine($"Total price of sold tickets: {airport1.GetTotalPriceOfSoldTicks()}");
    }
}

