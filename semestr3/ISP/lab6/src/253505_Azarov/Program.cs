using System.Reflection;

// See https://aka.ms/new-console-template for more information
using _253505_Azarov.Entities;
using _253505_Azarov.Interfaces;

// Console.WriteLine("Hello, World!");
var employees = new List<Employee>()
{
    new Employee(){Name = "Egor", Age = 18, BodyPositive =false},
    new Employee(){Name = "Danil", Age = 18, BodyPositive =false},
    new Employee(){Name = "Sanya", Age = 19, BodyPositive =true},
    new Employee(){Name = "Alex", Age = 20, BodyPositive =true},
    new Employee(){Name = "David", Age = 35, BodyPositive =true},
    new Employee(){Name = "Georg", Age = 40, BodyPositive =false}
};

Assembly asm = Assembly.LoadFrom("../FileSaver/bin/Release/net7.0/FileSaver.dll");
Type? fileServiceType = asm.GetType("FileSaver.FileService");
var fileService = Activator.CreateInstance(fileServiceType!) as IFileService<Employee>;
fileService?.SaveData(employees, "data/employees.json");

var readedEmployees = fileService?.ReadFile("data/employees.json");
Console.WriteLine("Employees from data/employees.json...");
foreach(var e in readedEmployees!)
{
    Console.WriteLine($"Employee: Name: {e.Name}, Age: {e.Age}, BodyPositive: {e.BodyPositive}");
}