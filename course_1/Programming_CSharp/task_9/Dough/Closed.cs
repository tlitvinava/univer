using System;
namespace lab9
{
    internal class Closed : IPizza
    {
        public void Bake()
        {
            Console.WriteLine("Закрытая пицца.");
        }
    }
}
