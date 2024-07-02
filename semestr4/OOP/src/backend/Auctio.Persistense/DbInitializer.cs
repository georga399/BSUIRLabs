using Microsoft.Extensions.Configuration;
using Microsoft.Extensions.DependencyInjection;

namespace Auctio.Persistense;

public static class DbInitializer
{
    public static async Task Initialize(IServiceCollection services)
    {
        var serviceProvider  = services.BuildServiceProvider();
        var unitOfWork = serviceProvider.GetRequiredService<IUnitOfWork>();
        var authService = serviceProvider.GetRequiredService<IAuthService>();
        // Create database again
        await unitOfWork.DeleteDataBaseAsync();
        await unitOfWork.CreateDataBaseAsync();

        // // Seed data for Users
        await authService.Register("admin", "admin");
        var admin = await unitOfWork.UserRepository.FirstOrDefaultAsync(x => x.Name == "admin");
        admin.Role = UserRole.Admin;
        await unitOfWork.SaveAllAsync();

        await authService.Register("user1", "user1");
        await authService.Register("user2", "user2");
        await authService.Register("user3", "user3");
        await authService.Register("user4", "user4");
        var users = await unitOfWork.UserRepository.ListAllAsync();


        // Seed data for Categories
        var categories = new List<Category>
        {
            new Category { Name = "Electronics" },
            new Category { Name = "Clothing" }
        };
        foreach (var category in categories)
        {
            await unitOfWork.CategoryRepository.AddAsync(category);
        }

        // Seed data for Items
        var items = new List<Item>
        {
            new Item { 
                Title = "Smartphone", 
                Description = "Latest model", 
                StartingPrice = 500, 
                MinIncrease = 50, 
                StartTime = DateTime.UtcNow, 
                EndTime = DateTime.UtcNow.AddDays(7), 
                UserId = users[2].Id, 
                CategoryId = categories[0].Id, 
                ItemStatus = ItemStatus.Active 
            },

            new Item
            {
                Title = "Laptop",
                Description = "High-performance gaming laptop",
                StartingPrice = 1000,
                MinIncrease = 100,
                StartTime = DateTime.UtcNow,
                EndTime = DateTime.UtcNow.AddDays(10),
                UserId = users[2].Id,
                CategoryId = categories[0].Id,
                ItemStatus = ItemStatus.Active
            },
            new Item
            {
                Title = "Dining Table",
                Description = "Solid oak dining table with 6 chairs",
                StartingPrice = 800,
                MinIncrease = 100,
                StartTime = DateTime.UtcNow,
                EndTime = DateTime.UtcNow.AddDays(21),
                UserId = users[2].Id,
                CategoryId = categories[1].Id,
                ItemStatus = ItemStatus.Active
            },
            new Item { 
                Title = "T-shirt", 
                Description = "Cotton material", 
                StartingPrice = 20, 
                MinIncrease = 5, 
                StartTime = DateTime.UtcNow, 
                EndTime = DateTime.UtcNow.AddDays(3), 
                UserId = users[1].Id, 
                CategoryId = categories[1].Id, 
                ItemStatus = ItemStatus.Active 
            }
        };
        foreach (var item in items)
        {
            await unitOfWork.ItemRepository.AddAsync(item);
        }

        // Seed data for bids
        var bids = new List<Bid>
        {
            // Bid for Smartphone
            new Bid
            {
                Amount = 550,
                UserId = users[3].Id,
                ItemId = items[0].Id,
                DateTime = DateTime.UtcNow
            },
            new Bid
            {
                Amount = 600,
                UserId = users[4].Id,
                ItemId = items[0].Id,
                DateTime = DateTime.UtcNow
            },
            new Bid
            {
                Amount = 650,
                UserId = users[3].Id,
                ItemId = items[0].Id,
                DateTime = DateTime.UtcNow
            },
            // Bid for Laptop
            new Bid
            {
                Amount = 1100,
                UserId = users[4].Id,
                ItemId = items[1].Id,
                DateTime = DateTime.UtcNow
            },
            new Bid
            {
                Amount = 1200,
                UserId = users[3].Id,
                ItemId = items[1].Id,
                DateTime = DateTime.UtcNow
            },
            // Bid for Dining Table
            new Bid
            {
                Amount = 900,
                UserId = users[4].Id,
                ItemId = items[2].Id,
                DateTime = DateTime.UtcNow
            },
            // Bid for T-shirt
            new Bid
            {
                Amount = 25,
                UserId = users[3].Id,
                ItemId = items[3].Id,
                DateTime = DateTime.UtcNow
            }
        };
        foreach(var bid in bids)
        {
            await unitOfWork.BidRepository.AddAsync(bid);
        }

        await unitOfWork.SaveAllAsync();
    }
}