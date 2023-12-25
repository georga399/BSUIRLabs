using System.IO;
using System.Security.Cryptography;
using Interfaces;
namespace Entities;
public class FileService<T>:IFileService<T> where T: IWorker, new()
{
    public IEnumerable<T> ReadFile(string filename)
    {
        using(var reader = new BinaryReader(File.Open(filename, FileMode.Open)))
        {
            while(reader.PeekChar() > -1)
            {
                string name = "";
                int age = 0;
                bool body = false;
                try 
                {
                    name = reader.ReadString();
                    age = reader.ReadInt32();
                    body = reader.ReadBoolean();
                }
                catch(System.Exception)
                {
                    Console.WriteLine("Error on reading data");
                }
                T worker = new T();
                worker.Name = name;
                worker.Age = age;
                worker.BodyPositive = body;
                yield return worker;
            }
            yield break;
        }
    }
    public void SaveData(IEnumerable<T> data, string filename)
    {
        using (var writer = new BinaryWriter(File.Open(filename, FileMode.Open, FileAccess.Write, FileShare.Write)))
        {
            try
            {
                foreach(var i in data)
                {
                    writer.Write(i.Name);
                    writer.Write(i.Age);
                    writer.Write(i.BodyPositive);
                }
            }
            catch (System.Exception)
            {
                
                Console.WriteLine("Error on saving data.");
            }
            
        }
        
    }
}