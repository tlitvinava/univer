using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab
{
    internal class Shlak
    {
        private int w_type;
        public int wei//возвращение веса соответственно типу
        {
            get
            {
                switch (w_type)
                {
                    case 0: return (int)weight.First; break;
                    case 1: return (int)weight.Second; break;
                    case 2: return (int)weight.Third; break;
                    default: return (int)weight.Fourth; break;
                }
            }

        }
        public Shlak(int w, Tariff t)//устанавливает тип веса и тариф
        {
            this.w_type = w;
            this.t = t;
        }

        private Tariff t;
        public Tariff tariff//установление тарифа
        {
            get { return t; }
            set { t = value; }
        }
    }
}
