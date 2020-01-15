using System;
using System.Collections.Generic;
using System.Text;

namespace seminar9.domain
{
    public enum Strategy { LIFO,FIFO}
    interface IFactory
    {
        IContainer CreateContainer(Strategy startegy);
    }
}
