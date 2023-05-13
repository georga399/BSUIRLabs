namespace TicketNameSpace
{
    class Ticket
    {
        public string Direction{get; set;}
        public string CodeOfTariff{get; set;}
        public TicketType Type{get; set;}
        public decimal Cost{get; set;}
        public Ticket(string Direction = "", string CodeOfTariff = "", TicketType tp = TicketType.Economy, decimal cost = 0)
        {
            this.Direction = Direction;
            this.CodeOfTariff = CodeOfTariff;
            this.Type = tp;
            this.Cost = cost;
        }
    }
    enum TicketType
    {
        Economy,
        Middle,
        Bussiness
    }
}
