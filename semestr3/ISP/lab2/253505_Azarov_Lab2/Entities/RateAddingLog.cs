namespace Entities;
public class RateAddingLog: AirportLog
{
    public Rate Rate{get; private set;}
    public RateAddingLog(Rate rate, DateTime date, string msg = "")
        :base(date, msg)
    {
        Rate = rate;   
    }
    public override string ToString()
    {
        return Rate.Name + " " + date.ToString();
    }
}