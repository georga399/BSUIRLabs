using Microsoft.VisualBasic;

namespace _253505_Azarov.Utils;

public class ComputeIndicator
{
    private long prevProgressVal = -1;
    public void IndicateProc(int id, long progress)
    {
        if(progress - prevProgressVal < 1) return;
        prevProgressVal = progress;
        string progressBar = $"Thread {id}:[";
        int iters = (int)(progress)/5;
        for(int i = 0; i<iters; i++)
        {
            progressBar += "=";
        }
        progressBar += ">";
        for(int i = iters; i<20; i++)
        {
            progressBar += ' ';
        }
        progressBar += $"]{(int)(progress)}%";
        Console.WriteLine(progressBar);
    }
    public void IndicateFinish(int id, long time, double res)
    {
        Console.WriteLine($"Thread {id}: has been finished with result: {res}");
        Console.WriteLine($"Thread {id}: was processing {time} mcrsec");
    }
}