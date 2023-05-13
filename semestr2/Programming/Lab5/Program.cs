using AirportNameSpace;
internal class Program
{
    private static void Main(string[] args)
    {
        Airport airport1 = new Airport("Minsk");
        airport1.AddTarrif("Hong-Kong", "#01", TicketNameSpace.TicketType.Bussiness, 1000);
        airport1.AddTarrif("Moscow", "#02", TicketNameSpace.TicketType.Economy, 200);
        airport1.AddTarrif("LA", "#03", TicketNameSpace.TicketType.Middle, 1000);
        airport1.AddPassenger("Mihail", "Petrov", "Petrovich", "#000001");
        airport1.AddPassenger("Ivan", "Ivanov", "Ivanovich", "#000002");
        Console.WriteLine($"Total cost of all sold tickets on the aritport BEFORE: {airport1.GetTotalCost()}");
        airport1.LogIn("Ivan", "Ivanov", "#000002");
        airport1.BuyTicket("#01");
        airport1.BuyTicket("#03");
        Console.WriteLine($"Cost of Ivan's tickets: {airport1.GetCostOfBoughtTicket()}");
        airport1.LogOut();
        airport1.LogIn("Mihail", "Petrov",  "#000001");
        airport1.BuyTicket("#01");
        Console.WriteLine($"Total cost of all sold tickets on the aritport AFTER: {airport1.GetTotalCost()}");
        airport1.LogOut();
        airport1.LogIn("Ivan", "Ivanov", "#000002");
        Console.WriteLine($"Cost of Ivan's tickets: {airport1.GetCostOfBoughtTicket()}");

    }
}