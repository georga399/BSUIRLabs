namespace CarNameSpace;
abstract class Car
{
    protected int MaxSpeed;
    public string Name {get; private set;}
    protected bool EngineOn{get; set;} = false;
    public Car(string name = "")
    {
        Console.WriteLine("Constructing car");
        Name = name;
    }
    public abstract void Move();
    public void CheckEngine()
    {
        if(EngineOn) Console.WriteLine("Engine on");
        else Console.WriteLine("Engine off");
    }
    public virtual void StartEngine()
    {
        if(EngineOn) Console.WriteLine("Engine is already on");
        else Console.WriteLine("Start engine");
        EngineOn = true;
    }
    public virtual void OffEngine()
    {
        if(!EngineOn) Console.WriteLine("Engine is already off");
        else Console.WriteLine("Engine off");
        EngineOn = false;
    }

}