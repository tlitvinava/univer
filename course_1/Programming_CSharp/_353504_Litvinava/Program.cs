using System;

namespace _353504_Litvinava
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string a, b;
            double x, y, c;
            Console.WriteLine("Введите делимое и делитель: ");
            a = Console.ReadLine();
            x = Convert.ToInt64(a);
            b = Console.ReadLine();
            y = Convert.ToInt64(b);

            c = Convert.ToDouble(x/y);

            Console.WriteLine("Частное: " + c);

        }
    }
}
