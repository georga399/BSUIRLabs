using EquatNameSpace;
using System;
class Program
{
    static void Main(string [] args)
    {
        Console.WriteLine("Variant 4. y = cos^3(x^2) + sin^2(x^3).");
        while(true)
        {
            Console.WriteLine("Enter x: ");
            double x;
            try
            {
                x = Convert.ToDouble(Console.ReadLine());
            }
            catch
            {
                Console.WriteLine("Error input");
                continue;
            }
            double ans = Equation.CountFunct(x);
            Console.WriteLine($"Result: {ans}");
            Console.WriteLine("Continue(yes):");
            string req = new String(Console.ReadLine());
            if(req == "yes") continue;
            else break;
        }
    }    
}
