namespace lab9
{
    internal class PepperoniBuilder : AbstractBuilder
    {
        public override PizzaBase Build()
        {
            var pepperoni = new Pepperoni(name, size, pizza);
            if (pizza != null)
                pepperoni.SetPizza(pizza);
            return pepperoni;
        }
    }
}
