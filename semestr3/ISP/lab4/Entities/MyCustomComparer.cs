using Interfaces;
namespace Entities;
public class MyCustomComparer: IComparer<Worker>
{
    public int Compare(Worker? f, Worker? s)
    {
        if(f is null || s is null)
            return 0;
        return f.Name.CompareTo(s.Name);
    }
}