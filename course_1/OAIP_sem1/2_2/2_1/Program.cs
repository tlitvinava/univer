using System;

class Program
{

    static bool IsIsosceles(double a, double b, double c)
    {
        return a == b || a == c || b == c;
    }

    static void Menu(bool isIsosceles)
    {

        double side1 = GetDoubleFromUser("Введите длину первой стороны треугольника: ");
        double side2 = GetDoubleFromUser("Введите длину второй стороны треугольника: ");
        double side3 = GetDoubleFromUser("Введите длину третьей стороны треугольника: ");




        if (side1 + side2 > side3 && side1 + side3 > side2 && side2 + side3 > side1)
        {
            if (IsIsosceles(side1, side2, side3))
            {
                Console.WriteLine("Треугольник является равнобедренным.");
            }
            else
            {
                Console.WriteLine("Треугольник не является равнобедренным.");
            }
        }
        else
        {
            Console.WriteLine("Треугольник не существует.");
        }
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

    static void Main()
    {
        bool flag = true;

        Menu(true);

        while (flag)
        {

            Console.WriteLine("Хотите продолжить или закончить?");
            Console.WriteLine("1) Закончить");
            Console.WriteLine("2) Продолжить");
            string choice = Console.ReadLine();

            switch (choice)
            {
                case "1":
                    Console.WriteLine("Завершение программы");
                    flag = false;
                    break;

                case "2":
                    Menu(true);
                    break;
                default:
                    Console.WriteLine("Неверный выбор. Пожалуйста, выберите 1 или 2.");
                    break;
            }
        }

    }
}
