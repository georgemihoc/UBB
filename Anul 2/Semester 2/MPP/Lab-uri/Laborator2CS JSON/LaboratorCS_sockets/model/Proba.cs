namespace swim.model
{
    public class Proba
    {
        private int idProba;
        private int lungime;
        private string stil;
        private int nrParticipanti;

        public Proba(int idProba, int lungime, string stil, int nrParticipanti)
        {
            this.idProba = idProba;
            this.lungime = lungime;
            this.stil = stil;
            this.nrParticipanti = nrParticipanti;
        }

        public int IdProba
        {
            get => idProba;
            set => idProba = value;
        }

        public int Lungime
        {
            get => lungime;
            set => lungime = value;
        }

        public string Stil
        {
            get => stil;
            set => stil = value;
        }

        public int NrParticipanti
        {
            get => nrParticipanti;
            set => nrParticipanti = value;
        }

        public override string ToString()
        {
            return idProba + " " + lungime + "m | " + stil + " | participanti: " + nrParticipanti;
        }
    }
}