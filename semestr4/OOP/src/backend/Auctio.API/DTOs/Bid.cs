namespace Auctio.API.DTOs;

public class Bid
{
    public Guid Id{get;set;}
    public string Username {get;set;} = "";
    public Guid UserId {get;set;} 
    public Guid ItemId { get; set; }
    public DateTime DateTime {get;set;}
    public decimal Amount {get;set;}
}