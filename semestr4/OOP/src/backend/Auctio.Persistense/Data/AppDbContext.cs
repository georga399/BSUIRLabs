using Microsoft.EntityFrameworkCore;
namespace Auctio.Persistense.Data;
public class AppDbContext: DbContext
{
    public DbSet<User> Users { get; set; }
    public DbSet<Category> Categories{ get; set; }
    public DbSet<Item> Items { get; set; }
    public DbSet<Bid> Bids{ get; set; }
    public AppDbContext()
    {
    }
    protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
    {
        optionsBuilder.UseSqlite("Data Source=../auctio.db");
    }
    #region Required
    protected override void OnModelCreating(ModelBuilder modelBuilder)
    {
        modelBuilder.Entity<Category>(c =>
        {
            c.HasKey(c => c.Id);
            c.ToTable("Category");
        });

        modelBuilder.Entity<User>(u =>
        {
            u.HasKey(u => u.Id);
            u.ToTable("User");
        });

        modelBuilder.Entity<Item>(i =>
        {
            i.HasKey(i => i.Id);
            i.ToTable("Item");
            i.Property(b => b.UserId).IsRequired();
            
            i.HasOne<Category>()
                .WithMany()
                .HasForeignKey(i => i.CategoryId);

            i.HasOne<User>()
                .WithMany()
                .HasForeignKey(i => i.UserId);
            
            i.ToTable("Item");
        });

        modelBuilder.Entity<Bid>( b =>
        {
            b.HasKey( b => b.Id);

            b.Property(b => b.ItemId).IsRequired();
            b.HasOne<Item>()
                .WithMany()
                .HasForeignKey(b => b.ItemId);


            b.Property(b => b.UserId).IsRequired();
            b.HasOne<User>()
                .WithMany()
                .HasForeignKey(b => b.UserId);

            b.ToTable("Bid");
        }
        );


    }
    #endregion

}