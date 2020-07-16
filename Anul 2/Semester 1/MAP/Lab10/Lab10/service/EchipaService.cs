using Curs12.Repository;
using Curs12.Repository;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab10.Service
{
    public class EchipaService
    {
        private IRepository<string, Echipa> repo;

        public EchipaService(IRepository<string, Echipa> repo)
        {
            this.repo = repo;
        }
        
        public List<Echipa> FindAllEchipe()
        {
            return repo.FindAll().ToList();
        }

        public Echipa findEchipa(string id)
        {
            foreach (var VARIABLE in repo.FindAll().ToList())
            {
                if (VARIABLE.ID.Equals(id))
                    return VARIABLE;
            }
            return null;
        }
        
        public void rewriteFile(Echipa echipa)
        {
            using (StreamWriter sw = File.AppendText("/Users/george/Documents/UBB/Anul 2/MAP/Lab10/Lab10/data/echipe.txt")) 
            {
                sw.WriteLine();
                sw.Write(echipa.ID+","+echipa.Nume);
            }	
        }

        public void AddEchipa(string nume)
        {
             Echipa echipa = new Echipa()
            {
                ID = "E"+ (repo.FindAll().ToList().Count+1),
                Nume = nume,
            };
            repo.Save(echipa);
            rewriteFile(echipa);
        }
    }
}