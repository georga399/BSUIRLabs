using System.Linq.Expressions;
using Auctio.Core.Domain.Entities;
namespace Auctio.Core.Domain.Abstractions;
public interface IRepository<T> where T : BaseEntity
{
    Task<T> GetByIdAsync(Guid id, CancellationToken cancellationToken = default, params Expression<Func<T, object>>[]? includesProperties);
    Task<IReadOnlyList<T>> ListAllAsync(CancellationToken cancellationToken = default);
    Task<IReadOnlyList<T>> ListAsync(Expression<Func<T, bool>> filter, CancellationToken cancellationToken = default, params Expression<Func<T, object>>[]? includesProperties);
    Task<Guid> AddAsync(T entity, CancellationToken cancellationToken = default);
    Task UpdateAsync(T entity, CancellationToken cancellationToken = default);
    Task DeleteAsync(T entity, CancellationToken cancellationToken = default);
    Task<T> FirstOrDefaultAsync(Expression<Func<T, bool>> filter, CancellationToken cancellationToken = default);
}