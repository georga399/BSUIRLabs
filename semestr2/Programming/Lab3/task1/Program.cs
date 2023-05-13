class Program
{
    
    static void Main(string [] args)
    {
        Console.WriteLine("Variant 4. Method f(x) return x-sin(x). Count max of function in a and b.");
        while(true)
        {    
            Console.WriteLine("Enter a: ");
            double a, b;
            try
            {
                a = Convert.ToDouble(Console.ReadLine());
            }
            catch
            {
                Console.WriteLine("Error input");
                continue;
            }
            Console.WriteLine("Enter b: ");
            try
            {
                b = Convert.ToDouble(Console.ReadLine());
            }
            catch
            {
                Console.WriteLine("Error input");
                continue;
            }
            double fa = func(a), fb = func(b);
            Console.WriteLine($"f(a) = {fa}, f(b) = {fb}");
            if(fa.CompareTo(fb) == 0)
            {
                Console.WriteLine("f(a)=f(b)");
            }
            else if(fa.CompareTo(fb) < 0)
            {
                Console.WriteLine("f(a) is min");
            }
            else 
            {
                Console.WriteLine("f(b) is min");
            }
            Console.WriteLine("Continue(yes): ");
            string? req = Console.ReadLine();
            if(req == "yes") continue;
            else break;        
            double func(double x)
            {
                return x - Math.Sin(x);
            }
        }
    }
    
}
