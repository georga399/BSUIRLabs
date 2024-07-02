namespace Auctio.Core.Domain.Entities;
public class Item: BaseEntity
{
    public string Title { get; set; } = null!;
    public string Description { get; set; } = null!;
    public decimal StartingPrice { get; set; }
    public decimal MinIncrease { get; set; }
    public DateTime StartTime { get; set; }
    public DateTime EndTime { get; set; }
    public Guid UserId { get; set; }
    public Guid CategoryId { get; set; }
    public ItemStatus ItemStatus {get;set;}
}