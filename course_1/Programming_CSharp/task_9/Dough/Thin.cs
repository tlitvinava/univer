using System;
namespace lab9
{
    internal class Thin : IPizza
    {
        public void Bake()
        {
            Console.WriteLine("Пицца на тонкой основе.");
        }
    }
}
