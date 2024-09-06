using _3_2_.Services;
     
namespace _3_2_ {

    public class Program//сделать проверку на ввод и добавить вещественные числа
    {
        public static void Main()
        {
            ProcessNum pelmen = new ProcessNum();
            double a, b, c;

            a = GetDoubleFromUser("Введите a: ");
            b = GetDoubleFromUser("Введите b: ");
            c = GetDoubleFromUser("Введите c: ");


            pelmen.CalculateFunction(a, b, c);
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
