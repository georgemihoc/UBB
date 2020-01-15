
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Curs12.Repository
{
    class PontajDTO
    {
        public String NumeAngajat { get; set; }
        public Double Salar { get; set; }

        public KnowledgeLevel Nivel { get; set; }

        public override string ToString()
        {
            return $"{NumeAngajat} {Salar} {Nivel.ToString()}"; // incepand cu C#6
        }
    }
}
