namespace Works.Domain.Entities;

public class Storage:IEquatable<Storage>
{
    public int CountOfDetails{get; set;}
    public string Name{get; set;} = "";
    public string Director{get; set;} = "";
    public bool Equals(Storage? storage)
    {
        return (CountOfDetails == storage?.CountOfDetails && Name == storage?.Name && Director == storage?.Director);
    }
}