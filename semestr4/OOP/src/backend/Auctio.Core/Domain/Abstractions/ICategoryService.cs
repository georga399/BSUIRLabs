using Auctio.Core.Domain.Entities;

namespace Auctio.Core.Domain.Abstractions;
public interface ICategoryService
{
    Task<IEnumerable<Category>> GetAllAsync();
    Task<Category> GetCategoryAsync(Guid id);

    Task<Category> GetCategoryAsync(string name);
    Task<(bool, Category)> CreateCategoryAsync(string name);
    Task<(bool, Category)> ChangeCategoryAsync(Guid id, Category category);
    Task<bool> DeleteCategoryAsync(Guid id);
    Task<string> GetCategoryName(Guid id);
}
