using System.Threading;
namespace IntegralLib;
public class IntegralComputer
{
    static Semaphore sem = new Semaphore(2, 2, "sem1");
    public event Action<int, long>? OnCalculateEvent;
    public event Action<int, long, double>? OnFinishEvent;
    private readonly double iterStep = 0.00000001;
    private readonly long countOfIters = 10;
    private long timeCompute {get; set;} = 0;
    public double GetIntegralSin()
    {
        sem.WaitOne();
        double x = 1;
        DateTime startTime = DateTime.Now;
        int sign = (x < 0) ? -1 : 1;
        x = Math.Abs(x);
        double sum = 0;
        double it = 0;
        int countOfSteps = (int)(1d/iterStep);
        for(int i = 0; i < countOfSteps; i++)
        {
            sum += iterStep*Math.Sin(it);
            it += iterStep;
            for(int j = 0; j<countOfIters; j++)
            {
                int a = j*j;
            }                                                                                                                                                                                                                                                 
            if(i%1000 == 0) 
                OnCalculateEvent?.Invoke(Thread.CurrentThread.ManagedThreadId, (long)(it*100/x));
        }
        DateTime endTime = DateTime.Now;
        timeCompute = (endTime - startTime).Microseconds;
        OnFinishEvent?.Invoke(Thread.CurrentThread.ManagedThreadId, timeCompute, sum);
        sem.Release();
        return sum;
    }

    public long StopWatch()
    {
        return timeCompute;
    }
}
