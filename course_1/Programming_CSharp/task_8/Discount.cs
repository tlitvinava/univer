// Discount.cs
using System;

public class Discount : ISalary
{
    private decimal price;
    private decimal discount;

    public decimal Price
    {
        get { return price; }
        set { price = value; }
    }

    public decimal DiscountCalculation
    {
        get { return discount; }
        set { discount = value; }
    }

    public decimal GetPrice()
    {
        return price * (100 - discount) / 100;
    }

    public Discount(decimal price, decimal discount)
    {
        this.price = price;
        this.discount = discount;
    }
}
