namespace lab9
{
    internal class MargaritaBuilder : AbstractBuilder
    {
        public override PizzaBase Build()
        {
            var margarita = new Margarita(name, size, pizza);
            if (pizza != null)
                margarita.SetPizza(pizza);
            return margarita;
        }
    }
}
