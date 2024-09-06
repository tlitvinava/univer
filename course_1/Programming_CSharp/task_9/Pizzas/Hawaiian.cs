using System;
namespace lab9
{
    internal class Hawaiian : PizzaBase, INotMeatTopping, IMeatTopping, IDelivery
    {
        public Hawaiian(string name, Size size, IPizza pizza)
        : base(name, size, pizza)
        {
        }

        public override void GetInfo()
        {
            Comment(" Типа: Hawaiian, " + "имеет размер: " + size);
        }
        public override string ToString()
        {
            GetInfo();
            AddNotMeatTopping();
            AddMeatTopping();
            DeliveryMethod();
            return base.ToString();
        }
        public void AddNotMeatTopping()
        {
            Comment(" с добавлением морепродуктов.");
        }
        public void AddMeatTopping()
        {
            Comment(" с добавлением ветчины.");
        }
        public void DeliveryMethod()
        {
            Console.WriteLine("Способ доставки: курьером.");
        }
    }
}
