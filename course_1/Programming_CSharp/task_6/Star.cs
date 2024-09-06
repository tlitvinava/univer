using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace _1
{
    sealed class Star : Object
    {
        public Star(string name, double size, double distance, double direction, double speed, double Brightness) : base(size, distance, name)
        {

            Direction = direction;
            Speed = speed;
            Brightness = brightness;
        }
        private double direction, speed, brightness;
        public double Direction { 
            get { return direction; } 
            set { direction = value; } 
        }
        public double Speed { 
            get { return speed; } 
            set { speed = value; } 
        }

        public double Brightness {
            get { return brightness; } 
            set { brightness = value; } 
        }

        public string GoToEarth()
        {
            if (direction == 0) return $"Полетит на Землю через {Distance / speed} секунд";
            if (direction <180||direction>270) return "Приблизится к Земле";
            return $"Звезда удаляется от Земли со скоростью: {speed} км/с";
        }
        public string Visible()
        {
            double time = 0;
            if (direction == 0)
            {
                time = Distance / speed;
            }
            if (direction < 180 || direction > 270)
            {
                time += Distance / speed +  Math.Sqrt(brightness * 1e18)/speed;
            }

            if (direction >= 180 && direction <= 270)
            {
                time +=  (Math.Sqrt(brightness * 1e18) - Distance) / speed;
            }
            if (brightness * 1e18 / (Distance*Distance) >= 1)
            {
                return $"Звезда будет видна с Земли через {time} секунд";
            }
            else return "Звезда невидима :(";
        }
        public override string MainInfo()
        {
            return $"Имя: {Name} \tРазмер: {Size} \tЯркость: {brightness} \tНаправление: {direction} азимут \tРасстояние: {Distance} км \tСкорость: {speed} км/с \tСветовой сигнал идет {LightSignalTime()} секунд";
        }
    }
}
