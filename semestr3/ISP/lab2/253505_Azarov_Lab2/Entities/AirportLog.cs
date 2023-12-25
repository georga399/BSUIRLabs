namespace Entities;
public class AirportLog
{
    public AirportLog(DateTime date, string msg = "")
    {
        this.date = date;
        info = msg;   
    }
    public DateTime date{get; protected set;}
    public string info{get; protected set;}
}