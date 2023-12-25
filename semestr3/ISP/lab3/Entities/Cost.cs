using System.Numerics;
namespace Entities;
public class Cost: IAdditionOperators<Cost, Cost, Cost>, IComparable<Cost>, IComparisonOperators<Cost, Cost, bool>
{
    public Cost(decimal value = 0)
    {
        val = value;
    }
    public string cur{get;} = "$";
    public decimal val{get; set;}

    public static Cost operator+(Cost l, Cost r)
    {
        return new Cost(l.val + r.val);
    }
    public override string ToString()
    {
        return val.ToString() + cur;
    }
    public int CompareTo(Cost? other)
    {
        return val.CompareTo(other?.val);
    }
    public static bool operator<(Cost left, Cost right)
    {
        return left.val < right.val;
    }
    public static bool operator>(Cost left, Cost right)
    {
        return left.val > right.val;
    }
    public static bool operator<=(Cost left, Cost right)
    {
        return left.val <= right.val;
    }
    public static bool operator>=(Cost left, Cost right)
    {
        return left.val >= right.val;
    }
    public static bool operator==(Cost? left, Cost? right)
    {
        return left?.val == right?.val;
    }
    public static bool operator!=(Cost ?left, Cost ?right)
    {
        return left?.val != right?.val;
    }
}