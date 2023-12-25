namespace Entities;
public class PurchaseLog:AirportLog
{
    public Purchase Purchase{get; set;}
    public PurchaseLog(Purchase purchase, DateTime date, string msg = "")
        :base(date, msg)
    {
        Purchase = purchase;
    }
    public override string ToString()
    {
        return $"Purchase: {Purchase.User} - {Purchase.Rate} - {date}";
    }
}