using System;
using Curs12.Repository;

namespace Lab10
{
    public class Echipa : Entity<string> , ICloneable
    {
        private string nume;

        // public Echipa(long id, string nume)
        // {
        //     this.nume = nume;
        // }

        public string Nume
        {
            get => nume;
            set => nume = value;
        }

        public string getId()
        {
            return ID;
        }

        public override string ToString()
        {
            return ID + " " + nume;
        }

        public object Clone()
        {
            throw new NotImplementedException();
        }
    }
}