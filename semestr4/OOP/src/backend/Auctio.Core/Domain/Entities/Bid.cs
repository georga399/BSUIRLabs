namespace Auctio.Core.Domain.Entities;
public class Bid: BaseEntity
{
    public decimal Amount { get; set; }
    public Guid UserId { get; set; }
    public Guid ItemId { get; set; }
    public DateTime DateTime {get;set;}
}