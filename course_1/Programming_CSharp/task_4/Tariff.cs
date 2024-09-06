using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace main
{
    public class Tariff
    {
        private double cost;
        public double Cost { get { return cost; } set { this.cost = value; } }
        public void change_cost(double delta)
        {
            cost += delta;
            if (cost<0) cost = 0;
        }
        public Tariff()
        {
            cost = 0;
        }
    }
}
