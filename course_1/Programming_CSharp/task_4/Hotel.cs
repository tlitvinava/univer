using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace task_4
{
        public sealed class Hotel
        {
            private static Hotel _instance = null; // Статическая переменная для хранения единственного экземпляра класса Hotel
            private static readonly object padlock = new object(); // Объект для синхронизации потоков при создании экземпляра класса

            public string Name { get; set; } // Свойство для хранения названия гостиницы
            public int OccupiedPlaces { get; set; } // Свойство для хранения числа заселенных мест
            public int TotalPlaces { get; set; } // Свойство для хранения общего числа мест
            public Rate Rate { get; set; } // Свойство для хранения тарифа

            Hotel() // Приватный конструктор, чтобы предотвратить создание экземпляра класса напрямую
            {
            }

            public static Hotel Instance // Свойство для получения единственного экземпляра класса
            {
                get
                {
                    lock (padlock) // Блокировка для синхронизации потоков
                    {
                        if (_instance == null) // Если экземпляр класса еще не создан
                        {
                            _instance = new Hotel(); // Создаем новый экземпляр класса
                        }
                        return _instance; // Возвращаем единственный экземпляр класса
                    }
                }
            }

            public double CalculateRevenue() // Метод для подсчета общей выручки гостиницы
            {
                return OccupiedPlaces * Rate.CostPerDay; // Вычисляем выручку как произведение числа заселенных мест на стоимость проживания за день
            }
        }

    //}
}
