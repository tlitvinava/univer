using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace _1
{
    internal class Planet : Object
    {
        public double LightSignalTime(double delta)
        {
            return (Distance + delta) / (299792.458);
        }

        private double orbit_radius;
        public double Orbit_radius
        {
            get { return orbit_radius; }
            set { orbit_radius = value; }
        }
        private double speed;
        public double Speed
        {
            get { return speed; }
            set { speed = value; }
        }
        private double way = 0;
        public double Way { 
            get { return way; } 
            set { way = value; } 
        }
        public Planet(double R, double s, double size, double distance, string name) : base(size, distance, name)
        {
            orbit_radius= R;
            speed = s;
            way = 0;
        }
        public void move(double time)
        {
            way += speed * time;
            way %= 4 * orbit_radius;
            if (way>2*orbit_radius)
            {
                way=2*orbit_radius - way %(2 * orbit_radius);
            }
        }

        public new string MainInfo()
        {
            return $"Имя: {Name} \tРазмер: {Size} \tРасстояние : {Distance} км \tРадиус орбиты: {orbit_radius} км \tСкорость на оси: {speed} км/с \tПозиция на одной из осей: {way} \tСветовой сигнал идет в {LightSignalTime(way)} секунд";
        }
    }
}
