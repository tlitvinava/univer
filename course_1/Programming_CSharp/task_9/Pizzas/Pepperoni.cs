using System;
namespace lab9
{
    internal class Pepperoni : PizzaBase, IMeatTopping, IDelivery
    {
        public Pepperoni(string name, Size size, IPizza pizza)
        : base(name, size, pizza)
        {
        }
        public override void GetInfo()
        {
            Comment(" Типа: Pepperoni, " + "имеет размер: " + size);
        }
        public override string ToString()
        {
            GetInfo();
            AddMeatTopping();
            DeliveryMethod();
            return base.ToString();
        }
        public void AddMeatTopping()
        {
            Comment(" с добавлением дополнительной порции пепперони.");
        }
        public void DeliveryMethod()
        {
            Console.WriteLine("Способ доставки: курьером ресторана.");
        }
    }
}
