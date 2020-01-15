using System;
using System.Collections.Generic;
using System.Text;

namespace seminar9.domain
{
    class Message
    {
        private string from;
        private string to;
        private string content;

        public string From { get => from; set => from = value; }
        public string To { get => to; set => to = value; }
        public string Content { get => content; set => content = value; }

        public override string ToString()
        {
            return From + " " + To + " " + Content;
        }
    }
}
