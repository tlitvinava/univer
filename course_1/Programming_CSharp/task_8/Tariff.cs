  using System;

public class Tariff
{
    private ISalary ip;
    public string Name { get; set; }
    public decimal Price => ip.GetPrice();

    public Tariff(string name, decimal price, decimal discount = 0)
    {
        if (discount == 0)
        {
            ip = new NoDiscount(price);
        }
        else
        {
            ip = new Discount(price, discount);
        }

        Name = name;
    }
}
