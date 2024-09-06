class Program
{
    static void Main(string[] args)
    {
        Vector v1 = new Vector(1, 2, 3); 
        Vector v2 = new Vector(4, 5, 6);

        Console.WriteLine(v1.ToString());  
        Console.WriteLine(v2.ToString()); 

        Vector v3 = v1 + v2; 
        Console.WriteLine(v3.ToString()); 

        Vector v4 = v1 - v2; 
        Console.WriteLine(v4.ToString());

        Vector v5 = v1 * 2; 
        Console.WriteLine(v5.ToString()); 

        Vector v6 = v1 / 2; 
        Console.WriteLine(v6.ToString()); 

        Console.WriteLine((v1 == v2).ToString()); 
        Console.WriteLine((v1 != v2).ToString()); 

        Vector v7 = ++v1; 
        Console.WriteLine(v7.ToString()); 

        Vector v8 = --v1; 
        Console.WriteLine(v8.ToString());

        double magnitude = (double)v1; 
        Console.WriteLine(magnitude.ToString()); 

        Vector v9 = (Vector)magnitude; 
        Console.WriteLine(v9.ToString()); 
    }
}