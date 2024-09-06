using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _3_2_.Services
{
    public class ProcessNum
    {
        public void CalculateFunction(double a, double b, double z)
        {
            double x;
            if (z < a * b)
            {
                x = Math.Sqrt(a*a + b*b - z);
                Console.WriteLine($"Результат: {x}, Bетка: 1");
            }
            else
            {
                x = (Math.Pow(Math.Sin(z) + a*b - z, 2)) / (a * z);
                Console.WriteLine($"Результат: {x}, Bетка: 2");
            }
        }
    }
    
}


