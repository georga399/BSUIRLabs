using Auctio.Persistense.Data;
using Auctio.Persistense.Repository;

namespace Auctio.Persistense.UnitOfWork;
public class EfUnitOfWork : IUnitOfWork
{
    private readonly AppDbContext _context;
    private readonly Lazy<IRepository<User>> _userRepository;
    private readonly Lazy<IRepository<Category>> _categoryRepository;
    private readonly Lazy<IRepository<Item>> _itemRepository;
    private readonly Lazy<IRepository<Bid>> _bidRepository;

    public EfUnitOfWork(AppDbContext context)
    {
        _context = context;
        _userRepository = new Lazy<IRepository<User>>(() => 
            new EfRepository<User>(context)); 
        _categoryRepository = new Lazy<IRepository<Category>>(() => 
            new EfRepository<Category>(context));
        _itemRepository = new Lazy<IRepository<Item>>(() => 
            new EfRepository<Item>(context));
        _bidRepository = new Lazy<IRepository<Bid>>(() => 
            new EfRepository<Bid>(context));
    }

    public IRepository<User> UserRepository => 
        _userRepository.Value;
    public IRepository<Category> CategoryRepository => 
        _categoryRepository.Value;
    public IRepository<Item> ItemRepository => 
        _itemRepository.Value;
    public IRepository<Bid> BidRepository => 
        _bidRepository.Value;

    public async Task CreateDataBaseAsync() => 
        await _context.Database.EnsureCreatedAsync();

    public async Task DeleteDataBaseAsync() => 
        await _context.Database.EnsureDeletedAsync();

    public async Task SaveAllAsync() => 
        await _context.SaveChangesAsync();
}