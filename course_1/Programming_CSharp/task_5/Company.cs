using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab
{
    internal class Company
    {
        private List<Client> ClientList = new List<Client>();
        private List<Tariff> TariffList = new List<Tariff>();
        public List<Client> Clients//получение списка клиентов
        {
            get { return ClientList; }
        }


        public double profit()//получение общей прибыли компании
        {
            double sum = 0;
            foreach (Client client in ClientList)
            {
                sum += client.get_total();
            }
            return sum;
        }

        public void reg_user(string username)//регистрация клиента
        {
            Client client = new Client(username);
            ClientList.Add(client);
        }


        public void add_shlak(int index, int w_type, int tariff_id)//добавление груза к клиенту
        {
            Shlak shlak = new Shlak(w_type, TariffList[tariff_id]);
            ClientList[index].Shlaks.Add(shlak);
        }

        public void add_tarrif(double t)//добавление тарифа
        {
            TariffList.Add(new Tariff(t));
        }
    }
}