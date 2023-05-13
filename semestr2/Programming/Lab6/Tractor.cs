using CarNameSpace;
namespace TractorNameSpace;
class Tractor : Car
{
    public string Manufacturer{get; private set;}
    public Tractor(string manufacturer = "", string name = "") : base(name)
    {
        MaxSpeed = 40;
        Console.WriteLine($"Construct tractor: {name}, manufacturer: {manufacturer}");
        Manufacturer = manufacturer;
    }
    public override void Move()
    {
        Console.WriteLine($"Tractor is moving. Max speed: {MaxSpeed}");
    }
}