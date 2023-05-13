using NoDiscountNameSpace;
using DiscountTariffNameSpace;
using TicketNameSpace;
namespace AirporNameSpace;
class Airport
{
    List<Ticket> lst = new List<Ticket>();
    public void AddTariffWithDiscount(string direction, decimal price, decimal discount)
    {
        lst.Add(new Ticket(new DiscountTariff(price, discount), direction));
    }
    public void AddTariff(string direction, decimal price)
    {
        lst.Add(new Ticket(new NoDiscount(price), direction));
    }
    public decimal GetMaxPrice()
    {
        decimal max = 0;
        foreach(var t in lst)
        {
            if(t.GetPrice() > max) max = t.GetPrice();
        }
        return max;
    }
    
}