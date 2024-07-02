using Auctio.Core.Domain.Entities;

namespace Auctio.Core.Domain.Abstractions;
public interface IUnitOfWork
{
    IRepository<User> UserRepository{get;}
    IRepository<Category> CategoryRepository{get;}
    IRepository<Item> ItemRepository{get;}
    IRepository<Bid> BidRepository{get;}
    public Task SaveAllAsync();
    public Task DeleteDataBaseAsync();
    public Task CreateDataBaseAsync();
}