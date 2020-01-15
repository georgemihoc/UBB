using Curs12.Repository;
using System;
using System.Collections.Generic;
using System.Configuration;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Lab10.Service;

namespace Lab10.Repository
{
    class EntityToFileMapping
    {
        public static Elev CreateElev(string line)
        {
            string[] fields = line.Split(','); // new char[] { ',' } 
            Elev elev = new Elev()
            {
                ID =  fields[0],
                Nume = fields[1],
                Scoala =  fields[2]
            };
            return elev;
        }



        public static Echipa CreateEchipa(string line)
        {
            string[] fields = line.Split(','); // new char[] { ',' } 
            Echipa echipa = new Echipa()
            {
                ID = fields[0],
                Nume =  fields[1],
            };
            return echipa;
        }

        public static Meci CreateMeci(string line)
        {
            string[] fields = line.Split(','); // new char[] { ',' } 
            Meci meci = new Meci()
            {
                ID = fields[0],
                IdEchipa1 = fields[1],
                IdEchipa2 = fields[2],
                DateTime = Convert.ToDateTime(fields[3])
            };
            return meci;
        }

        public static Jucator CreateJucator(string line)
        {
            List<Echipa> echipe = DataReader.ReadData("/Users/george/Documents/UBB/Anul 2/MAP/Lab10/Lab10/data/echipe.txt", CreateEchipa);
            List<Elev> elevi = DataReader.ReadData("/Users/george/Documents/UBB/Anul 2/MAP/Lab10/Lab10/data/elevi.txt", CreateElev);
            
            string[] fields = line.Split(',');
            Elev elev = elevi.Find(x => x.ID.Equals(fields[1]));
            Echipa echipa = echipe.Find(x => x.ID.Equals(fields[2]));
            
            Jucator jucator = new Jucator()
            {
                ID = fields[0],
                Echipa = echipa,
                Nume = elev.Nume,
                Scoala = elev.Scoala
            };
            return jucator;
        }

        public static JucatorActiv CreateJucatorActiv(string line)
        {
            string[] fields = line.Split(','); // new char[] { ',' } 
            JucatorActiv jucatorActiv = new JucatorActiv()
            {
                ID = fields[0],
                IdJucator = fields[1],
                IdMeci = fields[2],
                NrPuncteInscrise = Convert.ToInt32(fields[3]),
                Tip = fields[4]
            };
            return jucatorActiv;        
        }
    }
}
