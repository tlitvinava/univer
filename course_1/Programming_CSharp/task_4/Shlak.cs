using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace main
{
    public class Shlak
    {
        private static Shlak? _instance;
        public static Shlak GetInstance()
        {
            if (_instance == null)
                _instance = new Shlak();
            return _instance;
        }
        private double w;
        public double weight
        {
            set { this.w = value; }
            get { return this.w; }
        }
        private string name;
        public string Name
        {
            set { this.name = value; }
            get { return this.name; }
        }
        private Tariff tariff;
        public Tariff Tariff
        {
            get
            {
                return this.tariff;
            }
        }
        public Shlak()
        {
            tariff = new Tariff();
            w = 0;
            name = "";
        }
        public void change_tariff(double delta)
        {
            tariff.change_cost(delta);
        }

        public void total()
        {
            Console.WriteLine(w * tariff.Cost);
        }
    }
}
