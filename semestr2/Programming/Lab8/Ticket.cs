using ITariffNameSpace;
namespace TicketNameSpace;
public class Ticket
{
    private ITariff Tariff{get; set;}
    public string Direction{get; private set;}= "";
    public Ticket(ITariff tariff, string direction = "")
    {
        Direction = direction;
        Tariff = tariff;
    }
    public decimal GetPrice()
    {
        return Tariff.GetPrice();
    }
}