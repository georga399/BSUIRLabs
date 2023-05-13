using PassengerNameSpace;
using TicketNameSpace;
namespace AirportNameSpace
{
    class Airport
    {
        public string Name{get; private set;}
        private LinkedList<Passenger> LstOfPassengers = new LinkedList<Passenger>();
        private LinkedList<Ticket> LstOfTarrifs = new LinkedList<Ticket>();
        private Passenger curPasenger;
        public bool LogIn(string Name, string Surname, string PasCode)
        {
            foreach(var usr in LstOfPassengers)
            {
                if(usr.Name == Name && usr.Surname == Surname && usr.id == PasCode)
                {
                    curPasenger = usr;
                    return true;
                }
            }
            return false;
        }
        public void LogOut()
        {
            if(curPasenger != null)
                curPasenger = null!;
        }
        public Airport(string Name = "")
        {
            this.Name = Name;
            curPasenger = null!;
        }
        public void AddTarrif(string Direction, string CodeOfTariff, TicketType tp, decimal cost)
        {
            LstOfTarrifs.AddLast(new Ticket(Direction, CodeOfTariff, tp, cost));
        }
        public decimal GetCostOfBoughtTicket()
        {
            if(curPasenger == null)
            {
                throw new Exception("Current user isn't found");
            }
            return curPasenger.GetTotalCost();            
           
        }
        public bool BuyTicket(string CodeOfTariff)
        {
            if(curPasenger == null) return false;
            foreach(var tkt in LstOfTarrifs) 
            {
                if(tkt.CodeOfTariff == CodeOfTariff)
                {
                    curPasenger.BuyTicket(tkt);        
                }
            }
            return false;
        }
        public void AddPassenger(string Name, string Sur, string Patr, string PasportId)
        {
            LstOfPassengers.AddLast(new Passenger(Name, Sur, Patr, PasportId));
        }
        public decimal GetTotalCost()
        {
            decimal sum = 0;
            foreach(var usr in LstOfPassengers)
            {
                sum += usr.GetTotalCost();
            }
            return sum;
        }
    }
}