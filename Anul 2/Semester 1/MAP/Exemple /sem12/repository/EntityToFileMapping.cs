using Curs12.Repository;
using System;
using System.Collections.Generic;
using System.Configuration;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Curs12.Repository
{
    class EntityToFileMapping
    {
        public static Angajat CreateAngajat(string line)
        {
            string[] fields = line.Split(','); // new char[] { ',' } 
            Angajat angajat = new Angajat()
            {

                ID = fields[0],
                Nume = fields[1],
                VenitPeOra = Double.Parse(fields[2]),
                Nivel = (KnowledgeLevel)Enum.Parse(typeof(KnowledgeLevel), fields[3])
            };
            return angajat;
        }



        public static Sarcina CreateSarcina(string line)
        {
            string[] fields = line.Split(','); // new char[] { ',' } 
            Sarcina sarcina = new Sarcina()
            {

                ID = fields[0],
                TipDificultate = (Dificultate)Enum.Parse(typeof(Dificultate), fields[1]),
                NrOreEstimate = Int32.Parse(fields[2])
            };
            return sarcina;
        }

        public static Pontaj CreatePontaj(string line)
        {

            string fileNameAngajati = ConfigurationManager.AppSettings["angajatiFileName"];
            string fileNameSarcini = ConfigurationManager.AppSettings["sarciniFileName"];
            List<Angajat> angajati = DataReader.ReadData(fileNameAngajati, CreateAngajat);
            List<Sarcina> sarcini = DataReader.ReadData(fileNameSarcini, CreateSarcina);
            string[] fields = line.Split(',');
            String idPontaj = fields[0] + ',' + fields[1];
            Angajat ang = angajati.Find(x => x.ID.Equals(fields[0]));
            Sarcina sarc = sarcini.Find(x => x.ID.Equals(fields[1]));
            Pontaj pontaj = new Pontaj()
            {
                ID = idPontaj,
                Angajat = ang,
                Sarcina = sarc,
                Date = DateTime.ParseExact(fields[2], "d/M/yyyy", null)
            };
            return pontaj;
        }

    }
}
