using Curs12.Repository;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Curs12.Service
{
    class PontajService
    {
        private IRepository<string, Pontaj> repo;

        public PontajService(IRepository<string, Pontaj> repo)
        {
            this.repo = repo;
        }

        public List<Pontaj> FindAllPontaje()
        {
            return repo.FindAll().ToList();
        }

        public Dictionary<Angajat, Double> CeiMaiHarnici()
        {
            List<Pontaj> pontaje = repo.FindAll().ToList();
            //List<Angajat> angajati = 

            var res = (from p in pontaje
                       group p by p.Angajat into g
                       select new KeyValuePair<Angajat, Double>(g.Key, g.Key.VenitPeOra * g.Sum(x => x.Sarcina.NrOreEstimate)));
            Console.WriteLine(res.Count());
            //List < KeyValuePair < Angajat, Double > > rez = res.ToList();
            //Dictionary<Angajat, Double> dict = new Dictionary<Angajat, Double>();
            //rez.ForEach(x => dict.Add(x.Key, x.Value));
            var dict= res.ToDictionary(x => x.Key, x => x.Value);
            Double d= dict.Max(x=>x.Value);
            return dict.Where(x=>x.Value==d).ToDictionary(x=>x.Key,x=>x.Value);


            //var list = new List<KeyValuePair<string, object>> { kvp };
            //var dictionary = list.ToDictionary(x => x.Key, x => x.Value);
        }


        public List<PontajDTO> Salar(int luna)  //4
        {
            
            List<PontajDTO> list = new List<PontajDTO>();
            Dictionary<Angajat,Double> map  = new Dictionary<Angajat, double>(); 
            
            foreach (var p in repo.FindAll())
            {
                
                Angajat a = p.Angajat;
                double plata = a.VenitPeOra * p.Sarcina.NrOreEstimate;
                
                if(p.Date.Month != luna)
                    continue;
                
                if (map.ContainsKey(a))
                {
                    plata += map[a];
                    map[a] = plata;
                }
                else
                {
                    map.Add(a,plata);
                }
            }

            foreach (Angajat a in map.Keys)
            {
                list.Add(new PontajDTO
                {
                    NumeAngajat = a.Nume,
                    Salar = map[a],
                    Nivel = a.Nivel
                });
            }

            var rezList = (from p in list
                orderby p.Nivel ascending, p.Salar ascending 
                select p).ToList();
            
            return rezList;
        }
    }
}
