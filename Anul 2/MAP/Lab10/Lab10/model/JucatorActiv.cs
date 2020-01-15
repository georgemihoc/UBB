using System;
using Curs12.Repository;

namespace Lab10
{
    public class JucatorActiv : Entity<string> , ICloneable
    {
        private string idJucator;
        private string idMeci;
        private int nrPuncteInscrise;
        private string tip;

        public string IdJucator
        {
            get => idJucator;
            set => idJucator = value;
        }

        public string IdMeci
        {
            get => idMeci;
            set => idMeci = value;
        }

        public int NrPuncteInscrise
        {
            get => nrPuncteInscrise;
            set => nrPuncteInscrise = value;
        }

        public string Tip
        {
            get => tip;
            set => tip = value;
        }

        public override string ToString()
        {
            return ID + " " + idJucator + " " + idMeci + " " + nrPuncteInscrise + " " + tip;
        }

        public object Clone()
        {
            throw new NotImplementedException();
        }
    }
}