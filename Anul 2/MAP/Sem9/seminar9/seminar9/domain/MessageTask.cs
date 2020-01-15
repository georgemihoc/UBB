using System;
using System.Collections.Generic;
using System.Text;

namespace seminar9.domain
{
    class MessageTask : Task
    {
        private Message msg;
        private DateTime data;

        public MessageTask() : base(0, "")
        {
            // invoc explicit constructorul clasei Task cu base (0,"") daca nu as avea niciun constructor in Task 
        }

        public MessageTask(int id, string descriere, Message msg, DateTime data) : base(0, "")
        {
            this.Msg = msg;
            this.Data = data;
        }

        public DateTime Data { get => data; set => data = value; }
        internal Message Msg { get => msg; set => msg = value; }

        public override void Execute()
        {
            Console.WriteLine(base.ToString() + " " + Msg.ToString() + " " + Data.ToString());
        }
    }
}
