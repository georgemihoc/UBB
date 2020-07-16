using System;
using Seminar9.domain;

namespace Seminar9
{
    class Program
    {
        static void Main(string[] args)
        {
            
//            Task t = new Task();
//            t.Id = 1;
//            t.Descriere = "desc";
//
//            Task t1 = new Task()
//            {
//                Descriere = "desc",
//                Id = 2
//            };
            MessageTask m = new MessageTask()
            {
                Descriere = "abc",
                Id = 1,
                Msg = new Message()
                {
                    Content = "content",
                    From = "Mihai",
                    To = "boss"
                },
                data = DateTime.Now
            };
            m.Execute();
        }

    }
}