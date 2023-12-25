using System.Threading;
using IntegralLib;
using _253505_Azarov.Utils;


var integralComputer1 = new IntegralComputer();
var indicator1 = new ComputeIndicator();
integralComputer1.OnCalculateEvent += indicator1.IndicateProc;
integralComputer1.OnFinishEvent += indicator1.IndicateFinish;

var integralComputer2 = new IntegralComputer();
var indicator2 = new ComputeIndicator();
integralComputer2.OnCalculateEvent += indicator2.IndicateProc;
integralComputer2.OnFinishEvent += indicator2.IndicateFinish;

Thread countedThread1 = new Thread(() => integralComputer1.GetIntegralSin())
{Priority = ThreadPriority.Highest};
countedThread1.Start();
Thread countedThread2 = new Thread(() => integralComputer2.GetIntegralSin())
{Priority = ThreadPriority.Lowest};
countedThread2.Start();



for(int i = 0; i<5; i++)
{
    var integralComputer = new IntegralComputer();
    var indicator = new ComputeIndicator();
    integralComputer.OnCalculateEvent += indicator.IndicateProc;
    integralComputer.OnFinishEvent += indicator.IndicateFinish;
    Thread countedThread = new Thread(() => integralComputer.GetIntegralSin());
    countedThread.Start();
}