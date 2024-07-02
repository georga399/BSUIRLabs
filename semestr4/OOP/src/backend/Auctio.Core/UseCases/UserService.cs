using Auctio.Core.Domain.Abstractions;
using Auctio.Core.Domain.Entities;

namespace Auctio.Core.UseCases;

public class UserService : IUserService
{
    private readonly IUnitOfWork _unitOfWork;

    public UserService(IUnitOfWork unitOfWork)
    {
        _unitOfWork = unitOfWork;
    }

    public async Task<User> GetUser(string username)
    {
        return await _unitOfWork.UserRepository.FirstOrDefaultAsync(user => user.Name == username);
    }

    public async Task<User> GetUserById(Guid id)
    {
        return await _unitOfWork.UserRepository.FirstOrDefaultAsync(u => u.Id == id);
    }

    public async Task<string> GetUserName(Guid id)
    {
        var user = await GetUserById(id);
        return user.Name;
    }
}
