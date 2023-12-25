public class Rate
{
    public decimal Cost{get; set;}
    public string Name{get;}
    public Rate(string name, decimal cost)
    {
       Name = name;
       Cost = cost; 
    }
}