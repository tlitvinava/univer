namespace lab9
{
    internal abstract class AbstractBuilder
    {
        protected string name;
        protected Size size;
        protected IPizza pizza;

        public AbstractBuilder SetName(string name)
        {
            this.name = name;
            return this;
        }
        public string GetName()
        {
            return name;
        }
        public AbstractBuilder SetSize(Size size)
        {
            this.size = size;
            return this;
        }
        public AbstractBuilder SetPizza(IPizza pizza)
        {
            this.pizza = pizza;
            return this;
        }
        public abstract PizzaBase Build();
    }
}
