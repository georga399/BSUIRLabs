using System.Dynamic;
using Interfaces;
namespace Entities;
public class Worker: IWorker
{
    public string Name{get; set;} ="";
    public int Age{get; set;} = 0;
    public bool BodyPositive{get; set;} = false;
}