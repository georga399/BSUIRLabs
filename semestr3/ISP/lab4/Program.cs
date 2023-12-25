using System.IO;
using Entities;
Console.WriteLine("Hello, World!");

var directoryInfo = new DirectoryInfo(".");
directoryInfo.CreateSubdirectory("Azarov_Lab4");

var exts = new List<string>{".txt", ".rtf", ".dat", ".inf"};
for(int i = 0; i < 10; i++)
{
    var filename = "Azarov_Lab4/" + Path.GetRandomFileName() + exts[i%exts.Count];
    File.Create(filename);
}
Console.WriteLine("All files:");
foreach(var f in directoryInfo.GetFiles("./Azarov_Lab4/"))
{
    Console.WriteLine($"Имя файла: {f.Name} , расширение: {f.Extension}");
}

var workers = new List<Worker>{
    new Worker{Name="Bob", Age=20, BodyPositive=false},
    new Worker{Name="Egor", Age=30, BodyPositive=false},
    new Worker{Name="David", Age=35, BodyPositive=false},
    new Worker{Name="John", Age=40, BodyPositive=true},
    new Worker{Name="Dank", Age=20, BodyPositive=true},
    new Worker{Name="Alex", Age=20, BodyPositive=false},
};

var fileService = new FileService<Worker>();

File.Create("Azarov_Lab4/workers.txt").Dispose();
fileService.SaveData(workers, "Azarov_Lab4/workers.txt");

File.Move("Azarov_Lab4/workers.txt", "Azarov_Lab4/new_workers.txt");
File.Delete("Azarov_Lab4/workers.txt");

var new_workers = fileService.ReadFile("Azarov_Lab4/new_workers.txt");

foreach(var w in new_workers)
{
    Console.WriteLine($"Worker: {w.Name}, age: {w.Age}, bodypositive: {w.BodyPositive}");
}

var orderedByName = new_workers.OrderBy(w => w, new MyCustomComparer());

Console.WriteLine("After sorting by Name:");
foreach(var w in orderedByName)
{
    Console.WriteLine($"Worker: {w.Name}, age: {w.Age}, bodypositive: {w.BodyPositive}");
}

var orderedByAge = new_workers.OrderBy(w1 => w1.Age);
Console.WriteLine("After sorting by age:");
foreach(var w in orderedByAge)
{
    Console.WriteLine($"Worker: {w.Name}, age: {w.Age}, bodypositive: {w.BodyPositive}");
}