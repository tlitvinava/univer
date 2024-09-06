using task_4;

class Program
{
    static void Main(string[] args) 
    {
        Hotel hotel = Hotel.Instance; // Получаем единственный экземпляр класса Hotel
        Console.Write("Введите название гостиницы: ");
        string name = Console.ReadLine();
        hotel.Name = name;

        Console.Write("Введите общее количество мест: ");
        int totalPlaces = Convert.ToInt32(Console.ReadLine());
        hotel.TotalPlaces = totalPlaces;

        Console.Write("Введите количество занятых мест: ");
        int occupiedPlaces = Convert.ToInt32(Console.ReadLine());
        hotel.OccupiedPlaces = occupiedPlaces;

        Console.Write("Введите тариф: ");
        double rateValue = Convert.ToDouble(Console.ReadLine());
        hotel.Rate = new Rate(rateValue);


        double revenue = hotel.CalculateRevenue(); // Вычисляем выручку
        System.Console.WriteLine($"Выручка: {revenue}"); // Выводим выручку на экран

        hotel.Rate.IncreaseRate(20.0); // Увеличиваем тариф
        revenue = hotel.CalculateRevenue(); // Вычисляем новую выручку
        System.Console.WriteLine($"Новая выручка: {revenue}"); // Выводим новую выручку на экран
    }
}
