using Auctio.Core.Domain.Abstractions;
using Auctio.Core.Domain.Entities;

namespace Auctio.Core.UseCases;

public class CategoryService : ICategoryService
{
    private readonly IUnitOfWork _unitOfWork;

    public CategoryService(IUnitOfWork unitOfWork)
    {
        _unitOfWork = unitOfWork;
    }

    public async Task<IEnumerable<Category>> GetAllAsync()
    {
        return await _unitOfWork.CategoryRepository.ListAllAsync();
    }

    public async Task<Category> GetCategoryAsync(Guid id)
    {
        return await _unitOfWork.CategoryRepository.FirstOrDefaultAsync(c => c.Id == id);
    }

    public async Task<(bool, Category)> CreateCategoryAsync(string name)
    {
        var category = new Category { Name = name };
        var categoryId = await _unitOfWork.CategoryRepository.AddAsync(category);
        await _unitOfWork.SaveAllAsync();
        return (categoryId != Guid.Empty, category);
    }

    public async Task<bool> DeleteCategoryAsync(Guid id)
    {
        var category = await _unitOfWork.CategoryRepository.FirstOrDefaultAsync(c => c.Id == id);
        if (category != null)
        {
            await _unitOfWork.CategoryRepository.DeleteAsync(category);
            await _unitOfWork.SaveAllAsync();
            return true;
        }
        return false;
    }

    public async Task<Category> GetCategoryAsync(string name)
    {
        string lowername = name.ToLower();
        return await _unitOfWork.CategoryRepository.FirstOrDefaultAsync(c => c.Name.ToLower() == lowername);
    }

    public async Task<string> GetCategoryName(Guid id)
    {
        var cat = await GetCategoryAsync(id);
        return cat.Name;
    }

    public async Task<(bool, Category)> ChangeCategoryAsync(Guid id, Category category)
    {
        var foundcategory = await _unitOfWork.CategoryRepository.FirstOrDefaultAsync(c => c.Id == id);
        if (foundcategory != null)
        {
            foundcategory.Name = category.Name;

            await _unitOfWork.CategoryRepository.UpdateAsync(foundcategory);
            await _unitOfWork.SaveAllAsync();
            return (true, foundcategory);
        }
        return (false, null)!;

    }
}
