namespace Auctio.API.DTOs;

public class Item
{
    public Guid Id {get;set;} 
    public string Title{get;set;}="";
    public string Description{get;set;}="";
    public string CategoryName {get;set;}="";
    public Guid CategoryId {get;set;}
    public Guid UserId {get;set;}
    public string Username {get;set;}="";
    public decimal StartingPrice {get;set;}
    public decimal MinIncreasePrice {get;set;}
    public DateTime StartTime   {get;set;}
    public DateTime EndTime {get;set;}
    public ItemStatus ItemStatus {get;set;}
    public Bid? LastBid {get;set;}
}