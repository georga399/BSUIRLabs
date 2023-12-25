using Entities;
using Interfaces;
namespace Contracts;
public interface IAirport
{
    void AddRate(Rate rate);
    void AddUser(User user);
    void RegisterPurchase(User user, Rate rate);
    Cost GetPurchaseAmount(User user);
    void GetUsersOnDate(DateTime dateTime, ref ICustomCollection<User> users);
}