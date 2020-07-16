using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace swim.network.dto
{
    [Serializable]
    public class ParticipantDTO
    {
        private int idParticipant;
        private string nume;
        private int varsta;

        public ParticipantDTO(int idParticipant, string nume, int varsta)
        {
            this.idParticipant = idParticipant;
            this.nume = nume;
            this.varsta = varsta;
        }

        public int IdParticipant
        {
            get => idParticipant;
            set => idParticipant = value;
        }

        public string Nume
        {
            get => nume;
            set => nume = value;
        }

        public int Varsta
        {
            get => varsta;
            set => varsta = value;
        }

        public override string ToString()
        {
            return idParticipant + " " + nume + " " + varsta;
        }
    }
}
