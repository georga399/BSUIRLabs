using System.Numerics;
namespace Entities;
public class Cost: IAdditionOperators<Cost, Cost, Cost>
{
    public Cost(decimal value, string currency = "$")
    {
        val = value;
        cur = currency;
    }
    public decimal val{get; set;}
    public string cur{get;}
    public static Cost operator+(Cost l, Cost r)
    {
        return new Cost(l.val + r.val);
    }
    public override string ToString()
    {
        return val.ToString() + cur;
    }

}