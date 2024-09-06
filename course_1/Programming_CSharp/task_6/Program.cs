using _1;
using System.Numerics;
internal class Program
{
    public static List<Planet> Planets;
    public static List<Star> Stars;
    private static void Info()
    {

        Console.WriteLine("===Планеты===");
        foreach (Planet planet in Planets)
        {
            Console.WriteLine(planet.MainInfo());
        }
        Console.WriteLine("\n***Звезды***");
        foreach (Star star in Stars)
        {
            Console.WriteLine(star.MainInfo());
        }
        Console.WriteLine("----------------------------------\n\n");
    }
    private static int GetStarID()
    {
        int i = 0;
        foreach (Star Star in Stars)
        {
            Console.WriteLine($"[{i}] {Star.MainInfo()}");
        }

        Console.WriteLine("\nНапишите id планеты");
        if (!int.TryParse(Console.ReadLine(), out i) || i < 0 || i >= Stars.Count())
            return GetStarID();
        return i;

    }
    private static void Relative()
    {
        if (Stars.Count() == 0)
        {
            Console.WriteLine("Сначала добавьте звезду");
            return;
        }
        int i = GetStarID();
       Console.WriteLine(Stars[i].GoToEarth() + "\n");
    }
    private static void Visible()
    {
        if (Stars.Count() == 0)
        {
            Console.WriteLine("Сначала добавьте звезду");
            return;
        }
        int i = GetStarID();
        Console.WriteLine(Stars[i].Visible()+"\n");
    }
    private static int GetPlanetID()
    {
        int i = 0;
        foreach (Planet planet in Planets)
        {
            Console.WriteLine($"[{i}] {planet.MainInfo()}");
        }

        Console.WriteLine("\nНапишите id планеты");
        if (!int.TryParse(Console.ReadLine(), out i)||i<0||i>=Planets.Count())
            return GetPlanetID();
        return i;

    }
    private static void Move_Planet()
    {
        if (Planets.Count() == 0)
        {
            Console.WriteLine("Сначала добавьте планету");
            return;
        }
        Console.WriteLine("Выберите id планеты");
        int id = GetPlanetID();
        double time = 0;
        Console.WriteLine("Введите сколько секунд(>0) должна двигаться выбранная планета ");
        while (!double.TryParse(Console.ReadLine(), out time))
        {
            Console.WriteLine("Неверный ввод");
        }
        Planets[id].move(time);

    }
    private static Star ReadStar()
    {
        Console.WriteLine("Вводите корректные данные: размер>=0, расстояние(км)>=0, скорость(км/с)>=0, направление в диапазоне [0;359], яркость >= 0");
        string name;
        double size, dist, dir, speed, br;
        Console.WriteLine("Введите название звезды:");
        name=Console.ReadLine();
        if (name == "")
            return ReadStar();
        Console.WriteLine("Введите размер звезды:");

        if (!double.TryParse(Console.ReadLine(), out size)||size<0)
            return ReadStar();

        Console.WriteLine("Введите расстояние:");

        if (!double.TryParse(Console.ReadLine(), out dist)||dist<0)
            return ReadStar();
        Console.WriteLine("Введите направление:");

        if (!double.TryParse(Console.ReadLine(), out dir) || dir < 0||dir>359)
            return ReadStar();
        Console.WriteLine("Введите скорость:");

        if (!double.TryParse(Console.ReadLine(), out speed) || speed < 0)
            return ReadStar();
        Console.WriteLine("Введите яркость:");

        if (!double.TryParse(Console.ReadLine(), out br) || br < 0)
            return ReadStar();
        return new Star(name, size, dist, dir, speed, br);
    }
    private static Planet ReadPlanet()
    {
        //double R, double s, double size, double distance, string name
        Console.WriteLine("Введите корректные данные: размер>=0, расстояние(км)>=0,скорость(км/с)>=0, радиус >= 0");
        string name;
        double size, dist, R, speed;
        Console.WriteLine("Введите название планеты:");
        name = Console.ReadLine();
        if (name == "")
            return ReadPlanet();
        Console.WriteLine("Введите размер:");

        if (!double.TryParse(Console.ReadLine(), out size) || size < 0)
            return ReadPlanet();

        Console.WriteLine("Введите расстояние:");

        if (!double.TryParse(Console.ReadLine(), out dist) || dist < 0)
            return ReadPlanet();
        Console.WriteLine("Введите скорость изменения скорости вдоль одной оси планеты:");

        if (!double.TryParse(Console.ReadLine(), out speed) || speed < 0)
            return ReadPlanet();
        Console.WriteLine("Введите радиус:");

        if (!double.TryParse(Console.ReadLine(), out R) || R < 0)
            return ReadPlanet();
        return new Planet(R, speed, size, dist, name);
    }
    private static void Menu()
    {
        Info();
        int p;
        Console.WriteLine("Выберите опцию:\n1. Добавить звезду\n2. Добавить планету\n3. Передвинуть планету\n4. Проверьте направление относительно Земли\n5. Проверить видимость");
        if (!int.TryParse(Console.ReadLine(), out p) || p > 5 || p < 1)
            Menu();
        switch (p)
        {
            case 1:
                Stars.Add(ReadStar());
                break;
            case 2:
                Planets.Add(ReadPlanet());
                break;
            case 3:
                Move_Planet();
                break;
            case 4:
                Relative();
                break;
            default:
                Visible();
                break;
        }
    }
    private static void Main(string[] args)
    {
        Planets =new List<Planet>();
        Stars=new List<Star>();
        while (true) Menu();
    }
}