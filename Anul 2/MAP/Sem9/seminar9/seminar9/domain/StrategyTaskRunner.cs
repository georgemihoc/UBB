using System;
using System.Collections.Generic;
using System.Text;

namespace seminar9.domain
{
    class StrategyTaskRunner : ITaskRunner
    {
        private IContainer container;
        public StrategyTaskRunner(Strategy strategy)
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
