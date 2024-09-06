using System;
using System.Collections.Generic;
namespace lab9
{
    internal class Program
    {
        static void Main(string[] args)
        {
            var pizzas = new List<PizzaBase>();
            var hawaiianBuilder = new HawaiianBuilder();
            var pepperoniBuilder = new PepperoniBuilder();
            var margaritaBuilder = new MargaritaBuilder();

            pizzas.AddRange(new PizzaBase[] {
                Director.GetSmallPizza("Pizza №1",hawaiianBuilder),
                Director.GetMediumPizza("Pizza №2",pepperoniBuilder),
                Director.GetLargeThickPizza("Pizza №3",margaritaBuilder),
                Director.GetExtraLargeClosedPizza("Pizza №4",hawaiianBuilder),
                Director.GetSmallThinPizza("Pizza №5",pepperoniBuilder)
            });
            foreach (var pizza in pizzas)
            {
                Console.WriteLine(pizza.ToString());
            }
        }
    }
}
