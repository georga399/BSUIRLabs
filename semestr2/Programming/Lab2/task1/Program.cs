class Program
{
    static void Main(string[] args)
    {
        Console.WriteLine("Variant 4. Program indicate that number ends with 7. ");
        bool continueProgram = true;
        while(continueProgram)
        {
            int val;
            Console.WriteLine("Enter integer value: ");
            try
            {
                val = Convert.ToInt32(Console.ReadLine());
            }
            catch
            {
                Console.WriteLine("Error type input.");
                continue;
            }
            Console.WriteLine($"Result. The value ends with 7: {val%10==7}");
            Console.WriteLine("Continue program? (yes/no): ");
            string req = new String(Console.ReadLine());
            switch(req)
            {
            case "no":
                continueProgram = false;
                break;
            case "yes":
                continueProgram = true;
                break;
            default:
                Console.WriteLine("Error request (yes or no only)");
                continueProgram = false;
                break;
            }
        }
    }
}

