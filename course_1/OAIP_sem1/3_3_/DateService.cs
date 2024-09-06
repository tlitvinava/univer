using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


    public class DateService
    {
        public string GetDay(string date)
            {
                DateTime parsedDate;
                if (DateTime.TryParse(date, out parsedDate))
                {
                    return parsedDate.DayOfWeek.ToString();
                }
                else
                {
                    throw new FormatException("Неверный формат даты");
                }
        }

            public int GetDaysSpan(int day, int month, int year)
            {
                DateTime futureDate = new DateTime(year, month, day);
                TimeSpan timeSpan = futureDate - DateTime.Now;
                return Math.Abs(timeSpan.Days);
            }

    }
