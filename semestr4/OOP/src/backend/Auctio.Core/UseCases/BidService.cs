using System.Runtime.InteropServices;
using Auctio.Core.Domain.Abstractions;
using Auctio.Core.Domain.Entities;

namespace Auctio.Core.UseCases;

public class BidService : IBidService
{
    private readonly IUnitOfWork _unitOfWork;

    public BidService(IUnitOfWork unitOfWork)
    {
        _unitOfWork = unitOfWork;
    }

    public async Task<IEnumerable<Bid>> GetBidsByItemAsync(Guid itemId)
    {
        return await _unitOfWork.BidRepository.ListAsync(b => b.ItemId == itemId);
    }

    public async Task<IEnumerable<Bid>> GetBidsByUserAsync(string username)
    {
        var user = await _unitOfWork.UserRepository.FirstOrDefaultAsync(u => u.Name == username);
        if (user == null)
            return Enumerable.Empty<Bid>();

        return await _unitOfWork.BidRepository.ListAsync(b => b.UserId == user.Id);
    }

    public async Task<(bool, Bid)> CreateBidAsync(decimal amount, string username, Guid itemId)
    {
        var user = await _unitOfWork.UserRepository.FirstOrDefaultAsync(u => u.Name == username);
        var item = await _unitOfWork.ItemRepository.FirstOrDefaultAsync(i => i.Id == itemId);

        if (user == null || item == null || amount <= 0 || item.StartingPrice > amount)
            return (false, null);
        
        if(item.StartTime > DateTime.UtcNow || item.EndTime < DateTime.UtcNow)
            return (false, null);
        
        if(item.ItemStatus != ItemStatus.Active)
            return (false, null);
        
        var lastBid = await _unitOfWork.BidRepository
            .ListAsync(b => b.ItemId == itemId)
            .ContinueWith(task => task.Result.OrderByDescending(b => b.DateTime).FirstOrDefault());   
        
        if(lastBid != null && 
            (lastBid.Amount >= amount 
                || lastBid.Amount + item.MinIncrease > amount))
        {
            return (false, null);
        }

        var bid = new Bid
        {
            Amount = amount,
            UserId = user.Id,
            ItemId = item.Id,
            DateTime = DateTime.UtcNow
        };

        var bidId = await _unitOfWork.BidRepository.AddAsync(bid);
        await _unitOfWork.SaveAllAsync();

        if(bidId != Guid.Empty)
        {
            return (true, bid);
        }
        return (false, null);
    }

    public async Task<Bid> GetLastBidAsync(Guid itemId)
    {
        var lastBid = await _unitOfWork.BidRepository
            .ListAsync(b => b.ItemId == itemId)
            .ContinueWith(task => task.Result.OrderByDescending(b => b.DateTime).FirstOrDefault());   
        return lastBid;
    }

    public async Task<(bool, Bid)> DeleteBidAsync(Guid id, string username)
    {
        var bid = await _unitOfWork.BidRepository.FirstOrDefaultAsync(b => b.Id == id);
        if(bid == null)
            return (false, null);   
        var user = await _unitOfWork.UserRepository.FirstOrDefaultAsync(u => u.Name == username);
        if(user == null)
            return (false, null);
        if(user.Id != bid.UserId && user.Role != UserRole.Admin && user.Role != UserRole.Staff)
            return (false, null);
        
        var itemid = bid.ItemId;

        await _unitOfWork.BidRepository.DeleteAsync(bid);
        await _unitOfWork.SaveAllAsync();
        var lastBid = await GetLastBidAsync(itemid);
        return (true, lastBid);
    }
}
