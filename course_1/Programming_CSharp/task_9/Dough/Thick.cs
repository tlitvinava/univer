using System;
namespace lab9
{
    internal class Thick : IPizza
    {
        public void Bake()
        {
            Console.WriteLine("Пицца на толстой основе.");
        }
    }
}
