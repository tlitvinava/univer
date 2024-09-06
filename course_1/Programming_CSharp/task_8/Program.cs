// Program.cs
using System;

internal class Program
{
    private static void Main(string[] args)
    {
        PayrollDepartment payrollDepartment = new PayrollDepartment();

        // Добавление тарифов (вы можете настроить их)
        Tariff regularWork = new Tariff("Обычная работа", 5000);
        Tariff overtimeWork = new Tariff("Сверхурочная работа", 7000, 20);

        payrollDepartment.AddTariff(regularWork);
        payrollDepartment.AddTariff(overtimeWork);

        // Вычисление и вывод средней величины оплаты
        decimal averagePayment = payrollDepartment.CalculateAveragePayment();
        Console.WriteLine($"Средняя оплата: {averagePayment:C}");
    }
}
