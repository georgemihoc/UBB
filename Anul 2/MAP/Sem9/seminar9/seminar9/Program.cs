using seminar9.domain;
using System;

namespace seminar9
{
    class Program
    {
        static void Main(string[] args)
        {
            //Task t = new Task();
            //t.Id = 1;
            //t.Descriere = "desc";

            //Task t1 = new Task()
            //{
            //    Descriere = "desc1";
            //    Id = 2
            //};

            MessageTask m = new domain.MessageTask()
            {
                Descriere = "Descriere",
                Id = 1,
                Msg = new Message()
                {
                    Content = "Salut baaa",
                    From = "George",
                    To = "Mano"
                },
                Data = DateTime.Now
            };
            //m.Execute();
            StackContainer stackContainer = new StackContainer();
            /*IContainer stackContainer=new StackContainer()
             * --> astfel nu mai merge indexatorul, daca il declaram de tipul interfetei
             * -->punem proprietatea de indexare si in interfata
            */
            //stackContainer.Add(m);
            stackContainer[0] = m;
//            stackContainer[0].Execute();
            
            
            PrinterTaskRunner printerTaskRunner = new PrinterTaskRunner(Strategy.LIFO);
            printerTaskRunner.addTask(m);
            printerTaskRunner.executeOneTask();
            
            
            
            
            /* 
             * TEMA!!!!
             * Pana data viitoare sa venim cu metodele remove si etc si sa facem TaskContainerFactory Singleton
            */
        
        }
    }
}
