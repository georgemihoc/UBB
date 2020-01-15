using System;
using Curs12.Repository;

namespace Lab10
{
    public class Meci : Entity<string> , ICloneable
    {
        private string idEchipa1;
        private string idEchipa2;
        private DateTime dateTime;

        public string IdEchipa1
        {
            get => idEchipa1;
            set => idEchipa1 = value;
        }

        public string IdEchipa2
        {
            get => idEchipa2;
            set => idEchipa2 = value;
        }

        public DateTime DateTime
        {
            get => dateTime;
            set => dateTime = value;
        }
        public override string ToString()
        {
            return ID + " " + idEchipa1 + " " + idEchipa2 + " " + dateTime;
        }

        public object Clone()
        {
            throw new NotImplementedException();
        }
    }
}
