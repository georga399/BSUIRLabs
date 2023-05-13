using ITariffNameSpace;
namespace NoDiscountNameSpace;
class NoDiscount: ITariff
{
    private decimal Price;

    public NoDiscount(decimal price = 0)
    {
        Price = price;
    }
    public decimal GetPrice()
    {
        return Price;
    }
}