using static System.Runtime.InteropServices.JavaScript.JSType;

namespace task_3.GooseberryFile
{

    class Program
    {
        static void Main(string[] args)
        {
            Number help = new Number();

            int number;

            Console.Write("Введите число: ");

            while (!int.TryParse(Console.ReadLine(), out number))
            {
                Console.WriteLine("Ошибка! Введите число:");
            }


            int result = help.ProcessNumber(number);

            Console.WriteLine($"Результат: {result}");
        }
    }
}
