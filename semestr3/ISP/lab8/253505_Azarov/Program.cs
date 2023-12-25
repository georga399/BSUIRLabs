using Manufacture;
using StreamService;
using LoremNET;
using System.Security.Cryptography;
using Microsoft.VisualBasic;
using _253505_Azarov.Utils;
using System.Formats.Asn1;
namespace _253505_Azarov;
class Program
{
    static async Task Main(string[] args)
    {
        var workers = new List<Worker>();
        for(int i = 0; i < 1000; i++)
        {
            workers.Add(new Worker
            {
                Id = i,
                Name = Lorem.Email().Split('@')[0],
                Age = (i%2 == 0) ? (int)Lorem.Number(18, 35) : (int)Lorem.Number(36, 65)
            });
        }
        Console.WriteLine($"Thread {Thread.CurrentThread.ManagedThreadId}: Main was started.");
        var task1 = new Task(async () => 
        {
            Console.WriteLine("started");
            await Task.Delay(2000);
            Console.WriteLine("ended");
        }
        );
        task1.Start();
        task1.Wait();
        // var service = new StreamService<Worker>();
        // var memStream = new MemoryStream();
        // var progress = new SynchronousProgress<string>(str => Console.WriteLine(str));
        // var task1 = service.WriteToStreamAsync(memStream, workers, progress);
        // task1.Start();
        // task1.Wait();
        // Task task1 = Task.Run(async () => await service.WriteToStreamAsync(memStream, workers, progress));
        // await Task.Delay(200);
        // Task task2 = Task.Run(async () => await service.CopyFromStreamAsync(memStream, "data/workers.json", progress));
        // task1.Wait();
        // await service.WriteToStreamAsync(memStream, workers, progress);
        // task2.Wait();
        // int stats = await service.GetStatisticsAsync("data/workers.json", w => w.Age > 35);
        // Console.WriteLine($"Stats (workers with age more than 35): {stats}");
        Console.WriteLine("OK");  
         
    }
}