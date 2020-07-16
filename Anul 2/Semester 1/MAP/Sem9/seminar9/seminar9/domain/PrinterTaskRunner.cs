using System;

namespace seminar9.domain
{
    public class PrinterTaskRunner : AbstractTaskRunner
    {
        public PrinterTaskRunner(Strategy strategy) : base(strategy)
        {
        }
        public void executeOneTask()
        {
            base.executeOneTask();
            Console.WriteLine(DateTime.Now.ToString("h:mm:ss tt"));
        }
    }
}