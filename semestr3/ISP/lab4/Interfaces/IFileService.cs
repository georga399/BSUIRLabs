namespace Interfaces;
public interface IFileService<T>
{
    IEnumerable<T> ReadFile(string filename);
    void SaveData(IEnumerable<T> data, string filename);
}