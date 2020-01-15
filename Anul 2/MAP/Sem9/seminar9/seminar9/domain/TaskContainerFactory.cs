using System;
using System.Collections.Generic;
using System.Text;

namespace seminar9.domain
{
    class TaskContainerFactory : IFactory
    {
        public IContainer CreateContainer(Strategy startegy)
        {
            if (startegy == Strategy.LIFO) return new StackContainer();
            else return null; //return new QueueContainer();
        }
    }
}
