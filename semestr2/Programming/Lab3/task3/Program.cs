class Program
{
    static void Main(string [] args)
    {
        while(true)
        {
            Console.WriteLine("Input date: ");
            int day, month, year;
            Console.WriteLine("Day: ");
            try
            {
                day = Convert.ToInt32(Console.ReadLine());
            }
            catch
            {
                Console.WriteLine("Error input.");
                continue;
            }
            Console.WriteLine("Month: ");
            try
            {
                month = Convert.ToInt32(Console.ReadLine());
            }
            catch
            {
                Console.WriteLine("Error input.");
                continue;
            }
            Console.WriteLine("Year: ");
            try
            {
                year = Convert.ToInt32(Console.ReadLine());
            }
            catch
            {
                Console.WriteLine("Error input.");
                continue;
            }
            string dt = day.ToString() + (String)"/" + month.ToString() + (String)"/" + year.ToString();
            try
            {
                Console.WriteLine($"Day of week: {DateService.GetDay(dt)}");
                Console.WriteLine($"Duration between this date and current date: {DateService.GetDaysSpan(year, month, day)}");   
            }
            catch
            {
                Console.WriteLine("Error date.");
                continue;
            }
            Console.WriteLine("Continue(yes):");
            string req = new String(Console.ReadLine());
            if(req == "yes")
            {
                continue;
            }
            else
            {
                break;
            }
        } 
    }
    
}