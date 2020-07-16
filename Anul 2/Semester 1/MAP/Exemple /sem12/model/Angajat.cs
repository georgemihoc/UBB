using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Curs12.Repository
{
    enum KnowledgeLevel
    {
        Junior=1, Medium, Senior
    }
    class Angajat : Entity<string> , ICloneable
    {
        public String Nume { get; set; }
        public double VenitPeOra { get; set; }
        public KnowledgeLevel Nivel { get; set; }

        public object Clone()
        {
            throw new NotImplementedException();
        }

        public override bool Equals(object obj)
        {
            return obj is Angajat angajat &&
                ID.Equals(angajat.ID) &&   
                Nume == angajat.Nume &&
                   VenitPeOra == angajat.VenitPeOra &&
                   Nivel == angajat.Nivel;
        }

        public override int GetHashCode()
        {
            return HashCode.Combine(Nume, VenitPeOra, Nivel);
        }

        public override string ToString()
        {
            return ID+" "+Nume+" "+VenitPeOra+" "+Nivel;
        }
    }
}
