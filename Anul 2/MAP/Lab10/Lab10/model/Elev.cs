using System;
using Curs12.Repository;

namespace Lab10
{
    public class Elev : Entity<string> , ICloneable
    {
        private string nume;
        private string scoala;

        // public Elev(long id, string nume, string scoala)
        // {
        //     this.id = id;
        //     this.nume = nume;
        //     this.scoala = scoala;
        // }
        public string Nume
        {
            get => nume;
            set => nume = value;
        }

        public string Scoala
        {
            get => scoala;
            set => scoala = value;
        }

        public override string ToString()
        {
            return ID + " " + nume + " " + scoala;
        }

        public object Clone()
        {
            throw new NotImplementedException();
        }
    }
}