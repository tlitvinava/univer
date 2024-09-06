using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab
{
    internal class Client
    {
        private string? name;
        public string Name//получение имени клиента
        {
            get
            {
                return name;
            }
            set { name = value; }
        }

        private List<Shlak> shlakList = new List<Shlak>();//список с грузом
        public List<Shlak> Shlaks//возвращение списка груза
        {
            get
            {
                return shlakList;
            }
        }
        public Client(string name)
        {
            this.name = name;
        }
        public double get_total()//общая стоимость обьектов для клиента
        {
            double sum = 0;
            for (int i = 0; i<shlakList.Count; i++)
            {
                sum += shlakList[i].wei * shlakList[i].tariff.Cost;
            }
            return sum;
        }

    }
}