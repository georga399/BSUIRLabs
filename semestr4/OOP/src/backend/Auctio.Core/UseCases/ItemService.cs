using Auctio.Core.Domain.Abstractions;
using Auctio.Core.Domain.Entities;

namespace Auctio.Core.UseCases;

public class ItemService : IItemService
{
    private readonly IUnitOfWork _unitOfWork;

    public ItemService(IUnitOfWork unitOfWork)
    {
        _unitOfWork = unitOfWork;
    }

    public async Task<Item> GetItemAsync(Guid id)
    {
        return await _unitOfWork.ItemRepository.FirstOrDefaultAsync(i => i.Id == id);
    }

    public async Task<IEnumerable<Item>> GetItemsByCategoryAsync(string categoryName)
    {
        var lowcatname = categoryName.ToLower();
        var category = await _unitOfWork.CategoryRepository.FirstOrDefaultAsync(c => c.Name.ToLower() == lowcatname);
        if (category == null)
            return null;

        return await _unitOfWork.ItemRepository.ListAsync(i => i.CategoryId == category.Id);
    }

    public async Task<IEnumerable<Item>> GetItemsByUserIdAsync(Guid userId)
    {
        return await _unitOfWork.ItemRepository.ListAsync(i => i.UserId == userId);
    }

    public async Task<IEnumerable<Item>> GetItemsByUserAsync(string username)
    {
        var user = await _unitOfWork.UserRepository.FirstOrDefaultAsync(u => u.Name == username);
        if (user == null)
            return null;

        return await GetItemsByUserIdAsync(user.Id);
    }

    public async Task<(bool, Item)> CreateItemAsync(string name, string username, string description, string categoryName, decimal startingPrice, decimal minIncrease, DateTime startTime, DateTime endTime)
    {
        var user = await _unitOfWork.UserRepository.FirstOrDefaultAsync(u => u.Name == username);
        var category = await _unitOfWork.CategoryRepository.FirstOrDefaultAsync(c => c.Name == categoryName);

        if (user == null || category == null)
            return (false, null);
        
        if (startTime <= DateTime.UtcNow || endTime <= DateTime.UtcNow)
            return (false, null);

        if (endTime <= startTime)
            return (false, null);
        
        if (startingPrice < 0 || minIncrease < 0)
            return (false, null);

        var item = new Item
        {
            Title = name,
            Description = description,
            StartingPrice = startingPrice,
            MinIncrease = minIncrease,
            StartTime = startTime,
            EndTime = endTime,
            UserId = user.Id,
            CategoryId = category.Id,
            ItemStatus = ItemStatus.WaitingApprove
        };

        var itemId = await _unitOfWork.ItemRepository.AddAsync(item);

        await _unitOfWork.SaveAllAsync();
        return (itemId != Guid.Empty, item);
    }

    public async Task<(bool, Item)> ChangeItemStatusAsync(Guid itemId, ItemStatus status)
    {
        if(status > ItemStatus.Finished || status < ItemStatus.WaitingApprove)
            return (false, null);

        var item = await GetItemAsync(itemId);
        if (item == null)
            return (false, null);

        item.ItemStatus = status;
        await _unitOfWork.ItemRepository.UpdateAsync(item);
        await _unitOfWork.SaveAllAsync();
        return (true, item);
    }

    public async Task<(bool, Item)> ChangeItemDetailsAsync(Guid itemId, Item updatedItem, string username)
    {
        var item = await GetItemAsync(itemId);
        if (item == null)
            return (false, null);
        
        var user = await _unitOfWork.UserRepository.FirstOrDefaultAsync(u => u.Name == username);
        
        if(user == null)
            return (false, null);

        if(item.UserId != user.Id && user.Role != UserRole.Admin && user.Role != UserRole.Staff)
            return (false, null);
        
        if (updatedItem.StartTime <= DateTime.UtcNow || updatedItem.EndTime <= DateTime.UtcNow)
            return (false, item);

        if (updatedItem.EndTime <= updatedItem.StartTime)
            return (false, item);

        if (updatedItem.StartingPrice < 0 || updatedItem.MinIncrease < 0)
            return (false, item);
        

        item.Title = updatedItem.Title;
        item.Description = updatedItem.Description;
        item.StartingPrice = updatedItem.StartingPrice;
        item.MinIncrease = updatedItem.MinIncrease;
        item.StartTime = updatedItem.StartTime;
        item.EndTime = updatedItem.EndTime;

        item.ItemStatus = ItemStatus.Updated;

        await _unitOfWork.ItemRepository.UpdateAsync(item);
        await _unitOfWork.SaveAllAsync();
        return (true, item);
    }
    public async Task DeleteItemAsync(Guid itemId)
    {
        var item = await GetItemAsync(itemId);
        if (item != null)
        {
            await _unitOfWork.ItemRepository.DeleteAsync(item);
            await _unitOfWork.SaveAllAsync();
        }
    }
    public async Task<(bool, Item)> CloseItemAsync(Guid itemId, string username)
    {
        var item = await GetItemAsync(itemId);
        var user = await _unitOfWork.UserRepository.FirstOrDefaultAsync(u => u.Name == username);
        if (item == null)
            return (false, null);
        
        if(user.Id != item.UserId && user.Role != UserRole.Admin && user.Role != UserRole.Staff)
            return (false, null);

        item.ItemStatus = ItemStatus.Finished;
        await _unitOfWork.ItemRepository.UpdateAsync(item);
        await _unitOfWork.SaveAllAsync();
        return (true, item);
    }
    public async Task<bool> DeleteItemAsync(Guid itemId, string username)
    {
        var item = await GetItemAsync(itemId);
        var user = await _unitOfWork.UserRepository.FirstOrDefaultAsync(u => u.Name == username);
        if (item == null)
            return false;
        
        if(user.Id != item.UserId && user.Role != UserRole.Admin && user.Role != UserRole.Staff)
            return false;

        await _unitOfWork.ItemRepository.DeleteAsync(item);
        await _unitOfWork.SaveAllAsync();
        return true;
    }
}
