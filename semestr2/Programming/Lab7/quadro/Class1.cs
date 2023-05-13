namespace QuadroNameSpace;
public class Quadro
{
    public int a{get; set;}
    public int b{get; set;}
    public int c{get; set;}
    public Quadro(int a = 0, int b = 0, int c = 0)
    {
        this.a = a;
        this.b = b;
        this.c = c;
    }
    public void CountX(out double x1, out double x2)
    {
        if(a == 0 && b == 0)
        {
            System.Console.WriteLine("Infinity of solves.");
            x1 = 0;
            x2 = 0;
            Console.WriteLine("a = 0 b = 0");
        }
        else if(b == 0)
        {
            Console.WriteLine("b = 0");
            double x = System.MathF.Sqrt(-c/a);
            x1 = x;
            x2 = -x;
        }
        else if( a == 0)
        {
            Console.WriteLine("a = 0");
            x1 = -c/a;
            x2 = x1;
        }
        else 
        {
            Console.WriteLine("Counting...");
            // double sqrtD = System.Math.Sqrt(b*b - 4*a*c);
            double D = b*b - 4*a*c;
            Console.WriteLine(D);
            if(D<0)
            {
                throw new System.Exception("Discriminant lower than 0.");
            }
            else
            {
                double sqrtD = Math.Sqrt(D);
                x1 = ( -b + sqrtD )/( 2 * a );
                x2 = ( -b - sqrtD )/( 2 * a );
                Console.WriteLine($"{x1}, {x2}");
            }
        }
    }
    public override string ToString()
    {
        return new String($"{a}*x^2 + {b}*x + {c} = 0");
    }
    public int this[int index]
    {
        get
        {
            if(index > 2 || index  < 0) throw new IndexOutOfRangeException();
            if(index  == 0) return a;
            else if(index == 1) return b;
            else return c;
        }
        set
        {
            if(index > 2 || index  < 0) throw new IndexOutOfRangeException();
            if(index  == 0) a = value;
            else if(index == 1) b = value;
            else c = value;
        }
    }
    public static bool operator false(Quadro q)
    {
        double D = q.b*q.b - 4*q.a*q.c;
        return D<0;
    }
    public static bool operator true(Quadro q)
    {
        double D = q.b*q.b - 4*q.a*q.c;
        return D>=0;
    }
    public static Quadro operator ++(Quadro q)
    {
        return new Quadro{a = q.a+1, b = q.b+1, c = q.c+1};
    }
    public static Quadro operator --(Quadro q)
    {
        return new Quadro{a = q.a-1, b = q.b-1, c = q.c-1};
    }
    
    public static bool operator == (Quadro q1, Quadro q2)
    {
        return (q1.a == q2.a && q1.b == q2.b && q1.c == q2.c);
    }
    public static bool operator != (Quadro q1, Quadro q2)
    {
        return (q1.a != q2.a || q1.b != q2.b || q1.c != q2.c);
    }
    public static bool operator > (Quadro q1, Quadro q2)
    {
        return (q1.a > q2.a || q1.b > q2.b || q1.c > q2.c);
    }
    public static bool operator < (Quadro q1, Quadro q2)
    {
        return (q1.a < q2.a || q1.b < q2.b || q1.c < q2.c);
    }
    public static Quadro operator + (Quadro q1, Quadro q2)
    {
        return new Quadro(q1.a + q2.a, q1.b + q2.b, q1.c + q2.c);
    }
    public static Quadro operator - (Quadro q1, Quadro q2)
    {
        return new Quadro(q1.a - q2.a, q1.b - q2.b, q1.c - q2.c);
    }
    public static Quadro operator * (Quadro q1, int q2)
    {
        return new Quadro(q1.a * q2, q1.b * q2, q1.c * q2);
    }
    public static Quadro operator / (Quadro q1, int q2)
    {
        return new Quadro(q1.a / q2, q1.b / q2, q1.c / q2);
    }

    public static explicit operator int(Quadro q)
    {
        return q.a;
    }
    public static explicit operator Quadro(int q)
    {
        return new Quadro(q);
    }
    public override bool Equals(object? obj)
    {
        if(obj is Quadro q) 
        return this == q;
        return false;
    }
    public override int GetHashCode()
    {
        return Tuple.Create(a, b, c).GetHashCode();
    }
}
