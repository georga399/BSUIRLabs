using CarNameSpace;
namespace CoupeNameSpace;
sealed class Coupe : Car
{
    public override void Move()
    {
        Console.WriteLine($"Coupe is moving very fast. Max speed: {MaxSpeed}");

    }
    public Coupe()
    {
        MaxSpeed = 180;
        Console.WriteLine("Construct coupe");
    }
    public override void StartEngine()
    {
        if(EngineOn) Console.WriteLine("Coupe's engine is already on");
        else Console.WriteLine("Coupe's engine was started");
        EngineOn = true;
    }
    public override void OffEngine()
    {
        if(!EngineOn) Console.WriteLine("Engine is already off");
        else Console.WriteLine("Engine off");
        EngineOn = false;
    }
}