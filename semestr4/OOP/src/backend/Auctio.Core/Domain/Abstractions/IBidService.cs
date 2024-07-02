using Auctio.Core.Domain.Entities;

namespace Auctio.Core.Domain.Abstractions;
public interface IBidService
{
    Task<IEnumerable<Bid>> GetBidsByItemAsync(Guid itemId);
    Task<IEnumerable<Bid>> GetBidsByUserAsync(string username);
    Task<(bool, Bid)> CreateBidAsync(decimal amount, string username, Guid item);
    Task<(bool, Bid)> DeleteBidAsync(Guid id, string username);
    Task<Bid> GetLastBidAsync(Guid itemId);
}