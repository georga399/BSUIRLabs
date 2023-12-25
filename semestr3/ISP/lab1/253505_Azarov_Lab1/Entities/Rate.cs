namespace Entities;

public class Rate
{
    public string Direction{get; set; } = "";
    public Cost Cost {get; set;}
    public DateTime Date {get; set;}
    public Rate(string direction, Cost cost, DateTime date)
    {
        Direction = direction;
        Cost = cost;
        Date = date;
    }
}