
using System.ComponentModel;

namespace seminar9.domain
{
    
    public class AbstractTaskRunner: ITaskRunner
    {
        private IContainer container;
        public AbstractTaskRunner(Strategy strategy)
        {
            container=new TaskContainerFactory().CreateContainer(strategy);
        }

        public void addTask(Task t)
        {
            container.Add(t);
        }

        public void executeAll()
        {
            while (!container.IsEmpty())
            {
                executeOneTask();
            }
        }

        public void executeOneTask()
        {
            container.Remove().Execute();
        }

        public bool hasTask()
        {
            return container.Size != 0;
        }
    }
}