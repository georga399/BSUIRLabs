using Auctio.Core.Domain.Entities;

namespace Auctio.Core.Domain.Abstractions;
public interface IAuthService
{
    Task<(bool, Guid)> Register(string username, string password);
    Task<(bool, string)> SignIn(string username, string password);
}