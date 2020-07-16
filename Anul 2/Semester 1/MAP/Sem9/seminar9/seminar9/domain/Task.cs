using System;
using System.Collections.Generic;
using System.Text;

namespace seminar9.domain
{
    public abstract class Task
    {
        private int id;

        protected Task(int id, string descriere)
        {
            Id = id;
            Descriere = descriere;
        }

        // private string descriere;

        public Task()
        {
            // constructor fara parametrii
        }

        public int Id
        {
            get { return id; }
            set { id = value; }
        }

        public string Descriere { get; set; }

        //clasele abstracte sunt implicit virtuale!!!
        public abstract void Execute();

        public override string ToString()
        {
            return Id + " " + Descriere;
        }

    }
}
