using System.Linq.Expressions;
using Microsoft.EntityFrameworkCore;
using Auctio.Persistense;
using Auctio.Persistense.Data;

namespace Auctio.Persistense.Repository;

public class EfRepository<T> : IRepository<T> where T:BaseEntity
{
    protected readonly AppDbContext _context;
    protected readonly DbSet<T> _entities;
    public EfRepository(AppDbContext context)
    {
        _context = context;
        _entities = context.Set<T>();
    }
    public async Task<T> GetByIdAsync(Guid id,
        CancellationToken cancellationToken = default,
        params Expression<Func<T, object>>[]? includesProperties
    )
    {
        IQueryable<T>? query = _entities.AsQueryable();
        if (includesProperties is not null && includesProperties.Any())
        {
            foreach (Expression<Func<T, object>> included in includesProperties)
            {
                query = query.Include(included);
            }
        }

        query.Where((e) => e.Id == id);
        return await query.FirstOrDefaultAsync(cancellationToken);
    }

    public async Task<IReadOnlyList<T>> ListAllAsync(CancellationToken cancellationToken = default)
    {
        return await _entities.ToListAsync(cancellationToken);
    }
    public async Task<IReadOnlyList<T>> ListAsync(Expression<Func<T, bool>> filter,
        CancellationToken cancellationToken = default,
        params Expression<Func<T, object>>[]? includesProperties)
    {
        IQueryable<T>? query = _entities.AsQueryable();
        if(includesProperties is null)
        {
            return await query.ToListAsync();
        }
        if (includesProperties.Any())
        {
            foreach (Expression<Func<T, object>>? included in includesProperties)
            {
                query = query.Include(included);
            }
        }
        if (filter != null)
        {
            query = query.Where(filter);
        }
        return await query.ToListAsync();
    }
    public async Task<Guid> AddAsync(T entity, CancellationToken cancellationToken = default)
    {
        _entities.Add(entity);
        return entity.Id;
    }
    public Task DeleteAsync(T entity, CancellationToken cancellationToken = default)
    {
        _entities.Remove(entity);
        return Task.CompletedTask;
    }
    public async Task<T> FirstOrDefaultAsync(Expression<Func<T, bool>> filter, 
        CancellationToken cancellationToken = default)
    {
        return await _entities.FirstOrDefaultAsync(filter, cancellationToken);
    }
    public Task UpdateAsync(T entity, CancellationToken cancellationToken = default)
    {
        _context.Entry(entity).State = EntityState.Modified;
        return Task.CompletedTask;
    }  
}