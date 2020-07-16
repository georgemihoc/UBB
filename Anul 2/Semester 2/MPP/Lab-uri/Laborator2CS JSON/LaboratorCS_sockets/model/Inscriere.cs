namespace swim.model
{
    public class Inscriere
    {
        private int idInscriere;
        private int idParticipant;
        private int idProba;

        public Inscriere(int idInscriere, int idParticipant, int idProba)
        {
            this.idInscriere = idInscriere;
            this.idParticipant = idParticipant;
            this.idProba = idProba;
        }

        public int IdInscriere
        {
            get => idInscriere;
            set => idInscriere = value;
        }

        public int IdParticipant
        {
            get => idParticipant;
            set => idParticipant = value;
        }

        public int IdProba
        {
            get => idProba;
            set => idProba = value;
        }

        public override string ToString()
        {
            return idInscriere + " " + idParticipant + " " + idProba;
        }
    }
}