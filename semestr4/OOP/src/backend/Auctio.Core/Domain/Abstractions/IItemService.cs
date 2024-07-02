using System.Runtime.InteropServices;
using Auctio.Core.Domain.Entities;

namespace Auctio.Core.Domain.Abstractions;
public interface IItemService
{
    Task<Item> GetItemAsync(Guid id);
    Task<IEnumerable<Item>> GetItemsByCategoryAsync(string categoryName);
    Task<IEnumerable<Item>> GetItemsByUserIdAsync(Guid userId);
    Task<IEnumerable<Item>> GetItemsByUserAsync(string username);
    Task<(bool, Item)> CreateItemAsync(string name, string username, 
        string description, string categoryName, 
        decimal startingPrice, decimal minIncrease,
        DateTime startTime, DateTime endTime);
    Task<(bool, Item)> ChangeItemStatusAsync(Guid itemId, ItemStatus status);
    Task<(bool, Item)> ChangeItemDetailsAsync(Guid itemId, Item item, string username);
    Task<(bool, Item)> CloseItemAsync(Guid itemId, string username);
    Task<bool> DeleteItemAsync(Guid itemId, string username);
}