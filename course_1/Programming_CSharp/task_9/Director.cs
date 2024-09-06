namespace lab9
{
    internal static class Director
    {
        public static PizzaBase GetSmallPizza(string name, AbstractBuilder builder)
        {
            return builder.SetName(name).SetSize(Size.Small).Build();
        }
        public static PizzaBase GetMediumPizza(string name, AbstractBuilder builder)
        {
            return builder.SetName(name).SetSize(Size.Medium).Build();
        }
        public static PizzaBase GetLargeThickPizza(string name, AbstractBuilder builder)
        {
            return builder.SetName(name).SetSize(Size.Large).SetPizza(new Thick()).Build();
        }
        public static PizzaBase GetExtraLargeClosedPizza(string name, AbstractBuilder builder)
        {
            return builder.SetName(name).SetSize(Size.ExtraLarge).SetPizza(new Closed()).Build();
        }
        public static PizzaBase GetSmallThinPizza(string name, AbstractBuilder builder)
        {
            return builder.SetName(name).SetSize(Size.Small).SetPizza(new Thin()).Build();
        }
    }
}
