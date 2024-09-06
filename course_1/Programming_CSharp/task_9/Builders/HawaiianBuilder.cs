namespace lab9
{
    internal class HawaiianBuilder : AbstractBuilder
    {
        public override PizzaBase Build()
        {
            var hawaiian = new Hawaiian(name, size, pizza);
            if (pizza != null)
                hawaiian.SetPizza(pizza);
            return hawaiian;
        }
    }
}
