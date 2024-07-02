namespace Auctio.Core.Domain.Entities;
public class User: BaseEntity
{
    public string Name {get;set;} = null!;
    public string PassHash {get;set;} = null!;
    public UserRole Role{get;set;}
}