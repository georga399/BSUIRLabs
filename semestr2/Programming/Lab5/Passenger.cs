using TicketNameSpace;
namespace PassengerNameSpace
{
    class Passenger
    {
        private LinkedList<Ticket> lst = new LinkedList<Ticket>();
        public string Name{get; set;}
        public string Surname{get; set;}
        public string Patronymic{get; set;}
        public string id{get; set;}
        public Passenger(string Name = "", string Surname = "", string Patronymic = "", string id = "")
        {
            this.Name = Name;
            this.Surname = Surname;
            this.Patronymic = Patronymic;
            this.id = id;
        }
        public decimal GetTotalCost()
        {
            decimal sum = 0;
            foreach(var tkt in lst)
            {
                sum += tkt.Cost;
            }
            return sum;
        }
        public void BuyTicket(Ticket tkt)
        {
            lst.AddLast(tkt);
        }
    }
}