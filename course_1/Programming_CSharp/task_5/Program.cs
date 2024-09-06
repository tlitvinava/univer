using Lab;
using System.Net;
internal class Program
{
    private static void write_shlak(List<Client> c)
    {
        foreach (Client client in c)
        {
            Console.WriteLine("Имя: "+client.Name);
            foreach (Shlak shlak in client.Shlaks)
            {
                Console.WriteLine($"  Вес: {shlak.wei} Тариф: {shlak.tariff.Cost}");
            }
            Console.WriteLine($" = {client.get_total()}");
        }
    }

    private static void write_total(double total)
    {
        Console.WriteLine("======================");
        Console.WriteLine($"Итоговая стоимость: {total}");
    }
    private static void Main(string[] args)
    {
        Company cmp = new Company();

        cmp.add_tarrif(1.1);
        cmp.add_tarrif(3.0);
        cmp.add_tarrif(10.1);
        cmp.add_tarrif(100);

        cmp.reg_user("Каваски");
        cmp.reg_user("Карго");
        cmp.reg_user("Криго");
        cmp.reg_user("Эстрипер");
        cmp.reg_user("Морт");

        cmp.add_shlak(0, 0, 1);
        cmp.add_shlak(0, 3, 2);
        cmp.add_shlak(0, 1, 3);

        cmp.add_shlak(1, 0, 3);
        cmp.add_shlak(1, 3, 0);

        cmp.add_shlak(2, 2, 3);
        cmp.add_shlak(2, 3, 3);
        cmp.add_shlak(2, 1, 3);

        cmp.add_shlak(3, 0, 1);
        cmp.add_shlak(3, 1, 2);
        cmp.add_shlak(3, 2, 3);

        cmp.add_shlak(4, 2, 1);
        cmp.add_shlak(4, 3, 0);
        cmp.add_shlak(4, 1, 0);

        write_shlak(cmp.Clients);
        write_total(cmp.profit());
    }
}