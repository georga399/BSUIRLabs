using TicketNameSpace;
namespace AirportNameSpace
{
    class Airport
    {
        public override string ToString()
        {
            return  $"Airport name: {this.Name}";
        }
        public string Name{get; private set;}
        public uint CountOfSeats{get; set;}
        public uint CountOfSoldTickets{get; set;}

        public decimal GetTotalPriceOfSoldTicks()
        {
            return CountOfSoldTickets*ticket.Cost;
        }
        public decimal GetCostOfTicket()
        {
            return this.ticket.Cost;
        }
        public void IncreaseCostOfTicket(decimal val)
        {
            this.ticket.Cost+=val;
        }
        public void DecreaseCostOfTicket(decimal val)
        {
            this.ticket.Cost-=val;
        }
        private Ticket ticket;
        private static Airport? _instance = null;
        private Airport(string name = "", uint CountOfSeats = 0, uint CountOfSoldTickets = 0, decimal Cost = 0)
        {
            this.Name = name;
            this.CountOfSeats = CountOfSeats;
            this.CountOfSoldTickets = CountOfSoldTickets;
            ticket = new Ticket(Cost);
        }
        public static Airport GetAirport(string name = "", uint CountOfSeats = 0, uint CountOfSoldTickets = 0, decimal Cost = 0)
        {
            if(_instance == null) _instance = new Airport(name, CountOfSeats, CountOfSoldTickets, Cost);
            return _instance;
        }
    }
}