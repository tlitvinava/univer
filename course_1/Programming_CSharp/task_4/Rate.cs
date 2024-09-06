using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace task_4
{
    public class Rate
    {
            public double CostPerDay { get; set; } // Свойство для хранения стоимости проживания за день

            public Rate(double costPerDay)
            {
                CostPerDay = costPerDay; //стоимость проживания за один день
            }

            public void IncreaseRate(double increment)
            {
                CostPerDay += increment; // Увеличиваем стоимость проживания за день на указанное значение
            }

            public void DecreaseRate(double decrement) // Метод для уменьшения тарифа
            {
                CostPerDay -= decrement; // Уменьшаем стоимость проживания за день на указанное значение
            }
    }

}
