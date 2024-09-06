/*using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace task_3.Services
{
    internal class Pelmen
    {
        public static void CalculateValue(double a, double b, double z)
        {
            double y;
            int branchNumber;

            if (z < a * b)
            {
                y = (a * z + b * Math.Cos(Math.Sqrt(z))) / (z + a * b);
                branchNumber = 1;
            }
            else
            {
                y = (Math.Sqrt(a * a + b * b - z)) / (Math.Sin(z * z) + a * b - z);
                branchNumber = 2;
            }

            Console.WriteLine($"Result: {y}, Branch Number: {branchNumber}");
        }

        public static void Main()
        {
            // Пример использования с вашими конкретными значениями для a, b и z.
            CalculateValue(1, 2, 0.5);
        }
    }

}*/

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace task_3.Services
{
    internal class Pelmen
    {
        public static void CalculateValue(double a, double b, double z)
        {
            double y;
            int branchNumber;

            if (z < a * b)
            {
                y = (a * z + b * Math.Cos(Math.Sqrt(z))) / (z + a * b);
                branchNumber = 1;
            }
            else
            {
                y = (Math.Sqrt(a * a + b * b - z)) / (Math.Sin(z * z) + a * b - z);
                branchNumber = 2;
            }

            Console.WriteLine($"Result: {y}, Branch Number: {branchNumber}");
        }
    }

    public class Program
    {
        public static void Main()
        {
            // Пример использования с вашими конкретными значениями для a, b и z.
            Pelmen.CalculateValue(1, 2, 0.5);
        }
    }
}


