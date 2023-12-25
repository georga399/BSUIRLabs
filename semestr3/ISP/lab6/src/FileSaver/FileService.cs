using _253505_Azarov.Interfaces;
using _253505_Azarov.Entities;
using System.Text.Json;
namespace FileSaver;
public class FileService: IFileService<Employee>
{
    public IEnumerable<Employee> ReadFile(string fileName)
    {
        using (FileStream fs = new FileStream(fileName, FileMode.OpenOrCreate))
        {
            var employees = JsonSerializer.Deserialize<IEnumerable<Employee>>(fs);
            return employees!;
        }
    }
    public void SaveData(IEnumerable<Employee> data, string fileName)
    {
        using (FileStream fs = new FileStream(fileName, FileMode.OpenOrCreate))
        {
            JsonSerializer.Serialize<IEnumerable<Employee>>(fs, data);
        }
    }
}
