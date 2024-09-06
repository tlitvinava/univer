using System;
namespace lab9
{
    internal class Margarita : PizzaBase, INotMeatTopping, IDelivery
    {
        public Margarita(string name, Size size, IPizza pizza)
        : base(name, size, pizza)
        {
        }
        public override void GetInfo()
        {
            Comment(" Типа: Margarita, " + "имеет размер: " + size);
        }
        public override string ToString()
        {
            GetInfo();
            AddNotMeatTopping();
            DeliveryMethod();
            return base.ToString();
        }
        public void AddNotMeatTopping()
        {
            Comment(" с добавлением голубого сыра.");
        }
        public void DeliveryMethod()
        {
            Console.WriteLine("Способ доставки: самовывоз.");
        }
    }
}
