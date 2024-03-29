﻿namespace Manufacture;
using Manufacture.Interfaces;
public class Worker: IWorker
{
    public int Id{get; set;}
    public string Name{get; set;} = "";
    public int Age{get; set; }
    public override string ToString()
    {
        return $"Name={Name} Age={Age} Id={Id}";
    }
}
