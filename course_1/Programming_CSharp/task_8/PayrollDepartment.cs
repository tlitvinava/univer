// PayrollDepartment.cs
using System;
using System.Collections.Generic;

public class PayrollDepartment
{
    private List<Tariff> tariffList;

    public PayrollDepartment()
    {
        tariffList = new List<Tariff>();
    }

    public void AddTariff(Tariff tariff)
    {
        tariffList.Add(tariff);
    }

    public decimal CalculateAveragePayment()
    {
        if (tariffList.Count == 0)
        {
            return 0; // Обработка случая, когда не добавлено ни одного тарифа
        }

        decimal totalPayment = 0;
        foreach (var tariff in tariffList)
        {
            totalPayment += tariff.Price;
        }

        return totalPayment / tariffList.Count;
    }
}
