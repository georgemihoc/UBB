namespace Lab10
    {
        public class Jucator :  Elev 
        {
            private Echipa echipa;
            
            // public Jucator(long id, string nume, string scoala, Echipa echipa)
            // {
            //     this.echipa = echipa;
            // }
            public Echipa Echipa
            {
                get => echipa;
                set => echipa = value;
            }

            public override string ToString()
            {
                return ID + " " + Nume + " " + Echipa.Nume;
            }
        }
    }