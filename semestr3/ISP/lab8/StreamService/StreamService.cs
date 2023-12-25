using Manufacture;
using Manufacture.Interfaces;
using System.Text.Json;
using System.Text;
using Microsoft.VisualBasic;
using System.Text.Json.Nodes;

namespace StreamService;
public class StreamService<T> where T: IWorker, new()
{
    
    static AutoResetEvent notifier = new AutoResetEvent(true);
    public async Task WriteToStreamAsync(Stream stream, IEnumerable<T> data, IProgress<string> progress)
    {
        notifier.WaitOne();
        var threadId = Thread.CurrentThread.ManagedThreadId;
        progress.Report($"Thread {threadId}: Writing to stream was started"); 
        // await stream.FlushAsync();
        using (var writer = new Utf8JsonWriter(stream))
        {
            writer.WriteStartArray();
            {
                var pi = 0;
                var dataLength = data.Count();
                foreach(var w in data)
                {
                    await Task.Delay(10);
                    var json = JsonSerializer.Serialize(w);
                    writer.WriteRawValue(json);
                    pi++;
                    progress.Report($"Thread {threadId}: Processing writing to stream: {(pi*100)/dataLength}%"); 
                }
            }
            writer.WriteEndArray();
            
        }
        notifier.Set();
        progress.Report($"Thread {threadId}: Writing to stream was finished");
    }
    public async Task CopyFromStreamAsync(Stream stream, string filename, IProgress<string> progress)
    {
        notifier.WaitOne();
        var threadId = Thread.CurrentThread.ManagedThreadId;
        progress.Report($"Thread {threadId}: Copying stream to file {filename} was started");
        using (var streamToWriteTo = File.Open(filename, FileMode.Create))
        {
            stream.Seek(0, SeekOrigin.Begin);
            await stream.CopyToAsync(streamToWriteTo);
        }
        progress.Report($"Thread {threadId}: Copying from stream to file {filename} was finished");
        notifier.Set();
    }
    public async Task<int> GetStatisticsAsync(string fileName, Func<T, bool> filter)
    {        
        List<T>? objs = new();
        using(var fstream = File.Open(fileName, FileMode.Open))
        {  
            objs = await JsonSerializer.DeserializeAsync<List<T>>(fstream);
        }
        return objs!.Where(filter).Count();
    }
}
