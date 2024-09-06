using System; 

public class Vector 
{
    private int a, b, c; 

    public Vector(int a, int b, int c) 
    {
        this.a = a;
        this.b = b;
        this.c = c;
    }

    public int A 
    {
        get { return a; }
        set { a = value; }
    }

    public int B 
    {
        get { return b; }
        set { b = value; }
    }

    public int C 
    {
        get { return c; }
        set { c = value; }
    }

    public override string ToString() // Переопределение метода ToString()
    {
        return $"Vector: ({a}, {b}, {c})";
    }

    public int this[int i] // Индексатор
    {
        get
        {
            switch (i)
            {
                case 0: return a;
                case 1: return b;
                case 2: return c;
                default: throw new IndexOutOfRangeException("Index is out of range!");
            }
        }
        set
        {
            switch (i)
            {
                case 0: a = value; break;
                case 1: b = value; break;
                case 2: c = value; break;
                default: throw new IndexOutOfRangeException("Index is out of range!");
            }
        }
    }

    public static Vector operator +(Vector v1, Vector v2) // Перегрузка оператора +
    {
        return new Vector(v1.a + v2.a, v1.b + v2.b, v1.c + v2.c);
    }

    public static Vector operator -(Vector v1, Vector v2) // Перегрузка оператора -
    {
        return new Vector(v1.a - v2.a, v1.b - v2.b, v1.c - v2.c);
    }

    public static Vector operator ++(Vector v) // Перегрузка оператора ++
    {
        return new Vector(++v.a, ++v.b, ++v.c);
    }

    public static Vector operator --(Vector v) // Перегрузка оператора --
    {
        return new Vector(--v.a, --v.b, --v.c);
    }

    public static Vector operator *(Vector v, int scalar) // Перегрузка оператора *
    {
        return new Vector(v.a * scalar, v.b * scalar, v.c * scalar);
    }

    public static Vector operator /(Vector v, int scalar) // Перегрузка оператора /
    {
        return new Vector(v.a / scalar, v.b / scalar, v.c / scalar);
    }

    public static bool operator ==(Vector v1, Vector v2) // Перегрузка оператора ==
    {
        return v1.a == v2.a && v1.b == v2.b && v1.c == v2.c;
    }

    public static bool operator !=(Vector v1, Vector v2) // Перегрузка оператора !=
    {
        return !(v1 == v2);
    }

    public static bool operator true(Vector v) // Перегрузка оператора true
    {
        return v.a != 0 || v.b != 0 || v.c != 0;
    }

    public static bool operator false(Vector v) // Перегрузка оператора false
    {
        return v.a == 0 && v.b == 0 && v.c == 0;
    }

    public static explicit operator double(Vector v) // Перегрузка оператора преобразования типа
    {
        return Math.Sqrt(v.a * v.a + v.b * v.b + v.c * v.c);
    }

    public static explicit operator Vector(double magnitude) // Перегрузка оператора преобразования типа
    {
        int component = (int)Math.Round(magnitude / Math.Sqrt(3));
        return new Vector(component, component, component);
    }
}