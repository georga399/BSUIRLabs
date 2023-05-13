class Program
{
    static void Main(string[] args)
    {
        Console.WriteLine("Variant 4.");
        while(true)
        {
            double x, y;
            Console.WriteLine("Enter coordinates: ");
            Console.WriteLine("x: ");
            try
            {
                x = Convert.ToDouble(Console.ReadLine());
            }
            catch
            {
                Console.WriteLine("Error type input.");
                continue;
            }
            Console.WriteLine("y: ");
            try
            {
                y = Convert.ToDouble(Console.ReadLine());
            }
            catch
            {
                Console.WriteLine("Error type input.");
                continue;
            }
            if(((x*x + y*y).CompareTo(100) == 0 
                || (x*x + y*y).CompareTo(25) == 0) && y>=0 )
            {
                Console.WriteLine("On the border.");
            }
            else if((x*x + y*y) >25 
                && (x*x + y*y) <100 && y>=0)
            {
                Console.WriteLine("Yes. In the shaded area.");
            }
            else
            {
                Console.WriteLine("No. Outside the area.");
            }
            Console.WriteLine("To continue enter 'yes': ");
            var req = Console.ReadLine();
            if(req == "yes" ) continue;
            else break;
        }
    }
}

