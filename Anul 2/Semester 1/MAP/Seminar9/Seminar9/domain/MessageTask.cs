using System;

namespace Seminar9.domain
{
    public class MessageTask:Task
    {
        private Message msg;
        public DateTime data;

        public MessageTask():base(0,"") { }

        public MessageTask(int id, string desc, Message msg, DateTime data):base(id,desc)
        {
            this.msg = msg;
            this.data = data;
        }

        public Message Msg
        {
            get => msg;
            set => msg = value;
        }

        public MessageTask(DateTime data)
        {
            this.data = data;
        }

        public override void Execute()
        {
            Console.WriteLine(base.ToString() + " " + Msg.ToString() + " " + data.ToString());
        }
    }
}