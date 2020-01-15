using System;
using System.Collections.Generic;
using System.Linq;
using Curs12.Repository;

namespace Lab10.Service
{
    public class AService
    {
        private IRepository<string, Elev> repoElev;
        private IRepository<string, Echipa> repoEchipa;
        private IRepository<string, Jucator> repoJucator;
        private IRepository<string, Meci> repoMeci;
        private IRepository<string, JucatorActiv> repoJucatorActiv;

        public AService(IRepository<string, Elev> repoElev, IRepository<string, Echipa> repoEchipa, IRepository<string, Jucator> repoJucator, IRepository<string, Meci> repoMeci, IRepository<string, JucatorActiv> repoJucatorActiv)
        {
            this.repoElev = repoElev;
            this.repoEchipa = repoEchipa;
            this.repoJucator = repoJucator;
            this.repoMeci = repoMeci;
            this.repoJucatorActiv = repoJucatorActiv;
        }
        public List<Jucator> TotiJucatoriiUneiEchipe(string echipa)
        {
            List<Jucator> jucatori  = repoJucator.FindAll().ToList();
            return jucatori
                .Where(a => a.Echipa.Nume.Equals(echipa))
                .ToList();
        }
        
        public  List<JucatorActiv> TotiJucatoriiMeci(string idMeci, string numeEchipa)
        {
            var jucatoriActivi  = repoJucatorActiv.FindAll().ToList();
            // Echipa echipa = repoEchipa.FindAll().ToList().Find(x => x.Nume.Equals(numeEchipa));
            // var jucator = repoJucator.FindAll().ToList().Find(x => x.ID.Equals());

            return jucatoriActivi
                .Where(a => a.IdMeci.Equals(idMeci))
                .Where(a => JucatorInEchipa(a.IdJucator,numeEchipa).Equals(true))
                // .Select(a => repoJucator.FindAll().ToList().Find(x => x.ID.Equals(a.IdJucator)).Nume)
                .Select(a => new JucatorActiv()
                {
                    ID = a.ID,
                    IdJucator = repoJucator.FindAll().ToList().Find(x => x.ID.Equals(a.IdJucator)).Nume,
                    IdMeci = a.IdMeci,
                    NrPuncteInscrise = a.NrPuncteInscrise,
                    Tip = a.Tip
                })
            // repoJucator.FindAll().ToList().Find(x => x.ID.Equals(a.IdJucator)).Nume)
                .ToList();
        }

        public bool JucatorInEchipa(string idJucator, string numeEchipa)
        {
            var jucatori  = repoJucator.FindAll().ToList();
            return jucatori.Any(VARIABLE => VARIABLE.ID.Equals(idJucator) && VARIABLE.Echipa.Nume.Equals(numeEchipa));
        }
        public bool JucatorInEchipa2(string idJucator, string idEchipa)
        {
            var jucatori  = repoJucator.FindAll().ToList();
            return jucatori.Any(VARIABLE => VARIABLE.ID.Equals(idJucator) && VARIABLE.Echipa.ID.Equals(idEchipa));
        }

        public List<Meci> ToateMeciurile(DateTime start, DateTime finish)
        {
            // repoEchipa.FindAll().ToList().Find(x => x.ID.Equals(a.IdEchipa1)).Nume
            var meciuri = repoMeci.FindAll().ToList();
            return meciuri
                .Where(a => DateTime.Compare(start, a.DateTime) <=0 && DateTime.Compare(a.DateTime, finish) <= 0)
                .Select(a=> new Meci()
                {
                    ID = a.ID,
                    IdEchipa1 = repoEchipa.FindAll().ToList().Find(x => x.ID.Equals(a.IdEchipa1)).Nume,
                    IdEchipa2 = repoEchipa.FindAll().ToList().Find(x => x.ID.Equals(a.IdEchipa2)).Nume,
                    DateTime = a.DateTime
                })
                .ToList();
        }

        public List<int> ScorMeci(string meci)
        {
            var jucatoriActivi = repoJucatorActiv.FindAll().ToList();
            
            var meci1 = repoMeci.FindAll().ToList().Find(x => x.ID.Equals(meci));
            var echipa1 = meci1.IdEchipa1;
            var echipa2 = meci1.IdEchipa2;
            int suma1 = 0, suma2 = 0;

            foreach (var VARIABLE in jucatoriActivi.Where(VARIABLE => VARIABLE.IdMeci.Equals(meci)))
            {
                if (JucatorInEchipa2(VARIABLE.IdJucator, echipa1))
                    suma1 += VARIABLE.NrPuncteInscrise;
                else if (JucatorInEchipa2(VARIABLE.IdJucator, echipa2))
                    suma2 += VARIABLE.NrPuncteInscrise;
            }

            var scor = new List<int> {suma1, suma2};
            return scor;
        }
    }
}