namespace Works.Domain.Entities;

public class Factory:IEquatable<Factory>
{
    public Storage? Storage{get; set;}
    public string Address {get; set;} = "";
    public int PostCode {get; set;}
    public bool Equals(Factory? factory)
    {
        return (Storage!.Equals(factory?.Storage) && Address == factory?.Address && PostCode == factory.PostCode);
    }
}