// NoDiscount.cs
using System;

public class NoDiscount : ISalary
{
    private decimal price;

    public decimal Price
    {
        get { return price; }
        set { price = value; }
    }

    public decimal GetPrice() => price;

    public NoDiscount(decimal price)
    {
        Price = price;
    }
}
