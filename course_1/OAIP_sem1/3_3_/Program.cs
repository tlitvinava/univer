using Microsoft.VisualBasic;
using System;
using System.Globalization;
using System.Reflection.Metadata.Ecma335;

namespace _3_3_.DateServiceNamespace
{
    public class Program
    {
        public static void Main()
        {
            DateService dateService = new DateService();
            string choice = "";
            bool isChoiceValid = false;

            while (!isChoiceValid)
            {
                Console.WriteLine("Выбор");
                Console.WriteLine("1) Определить день недели");
                Console.WriteLine("2) Определить количество дней между датами");
                choice = Console.ReadLine();

                switch (choice)
                {
                    case "1":
                        Console.WriteLine("Введите дату:");
                        string Date = Console.ReadLine();

                        try
                        {
                            string week = dateService.GetDay(Date);
                            Console.WriteLine(week);
                        }
                        catch
                        {
                            Console.WriteLine("Неверный формат даты");

                        }
                        finally
                        {
                            isChoiceValid = true;

                        }
                

                        /* string week = dateService.GetDay(Date);
                         Console.WriteLine(week);
                         isChoiceValid = true;*/
                        break;

                    case "2":
                        string a = "";
                        bool isNumberInRange = false;
                        while (!isNumberInRange)
                        {
                            Console.Write("Введите число: ");
                            a = Console.ReadLine();
                            if (int.TryParse(a, out int number))
                            {
                                if (number > 0 && number < 32)
                                {
                                    isNumberInRange = true;
                                }
                                else
                                {
                                    Console.WriteLine("Введено неверное значение. Пожалуйста, введите число.");
                                }
                            }
                            else
                            {
                                Console.WriteLine("Введено неверное значение. Пожалуйста, введите число.");
                            }
                        }

                        string b = "";
                        bool isMonthInRange = false;
                        while (!isMonthInRange)
                        {
                            Console.Write("Введите месяц: ");
                            b = Console.ReadLine();
                            if (int.TryParse(b, out int number))
                            {
                                if (number > 0 && number < 13)
                                {
                                    isMonthInRange = true;
                                }
                                else
                                {
                                    Console.WriteLine("Введено неверное значение. Пожалуйста, введите число.");
                                }
                            }
                            else
                            {
                                Console.WriteLine("Введено неверное значение. Пожалуйста, введите число.");
                            }
                        }
                        Console.Write("Введите год: ");
                        int c = Convert.ToInt32(Console.ReadLine());
                        int quantity = dateService.GetDaysSpan(int.Parse(a), int.Parse(b), c);
                        Console.WriteLine(quantity);
                        isChoiceValid = true;
                        break;

                    default:
                        Console.WriteLine("Неверный выбор. Пожалуйста, выберите 1 или 2.");
                        break;
                }
            }
        }
    }
}


