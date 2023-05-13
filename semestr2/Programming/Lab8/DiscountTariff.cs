using ITariffNameSpace;
namespace DiscountTariffNameSpace;
class DiscountTariff : ITariff
{
    private decimal Price;
    private decimal Discount;
    public DiscountTariff(decimal price = 0, decimal discount = 0)
    {
        Price = price;
        Discount = discount;
    }
    public decimal GetPrice()
    {
        return Price - Discount;
    }

}