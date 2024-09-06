using System;

class Program
{

    static void Main()
    {

        double x = GetDoubleFromUser("Введите координату x: ");
        double y = GetDoubleFromUser("Введите координату y: ");

        double circle = Math.Sqrt(Math.Pow(x, 2) + Math.Pow(y, 2));
        double line = -Math.Abs(x);

        if (circle < 25 && y < line)
        {
            Console.WriteLine("Да");
        }
        else if (((circle == 25 || y == line) && y < 0&& circle<=25) || (x==0 && y==0))
        {
            Console.WriteLine("На границе");
        }
        else
        {
            Console.WriteLine("Нет");
        }


        static double GetDoubleFromUser(string prompt)
        {
            double number;
            Console.Write(prompt);
            while (!double.TryParse(Console.ReadLine(), out number))
            {
                Console.Write("Неверный ввод. Введите число еще раз: ");
            }
            return number;
        }
    }
}
