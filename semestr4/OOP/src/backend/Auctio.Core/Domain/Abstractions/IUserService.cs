using Auctio.Core.Domain.Entities;

namespace Auctio.Core.Domain.Abstractions;
public interface IUserService
{
    Task<User> GetUser(string username);
    Task<User> GetUserById(Guid id);
    Task<string> GetUserName(Guid id);

}