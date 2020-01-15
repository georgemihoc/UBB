using System;
using Curs12.Repository;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace Lab10.Service
{
    public class MeciService
    {
        private IRepository<string, Meci> repo;

        public MeciService(IRepository<string, Meci> repo)
        {
            this.repo = repo;
        }
        
        public List<Meci> FindAllMeciuri()
        {
            return repo.FindAll().ToList();
        }

        public void rewriteFile(Meci meci)
        {
            using (StreamWriter sw = File.AppendText("/Users/george/Documents/UBB/Anul 2/MAP/Lab10/Lab10/data/meciuri.txt")) 
            {
                sw.WriteLine();
                sw.Write(meci.ID+","+meci.IdEchipa1+","+meci.IdEchipa2+","+meci.DateTime);
            }	
        }
        
        public void AddMeci(string echipa1, string echipa2, in DateTime date)
        {
            Meci meci = new Meci()
            {
                ID = "m" + (repo.FindAll().ToList().Count + 1),
                IdEchipa1 = echipa1,
                IdEchipa2 = echipa2,
                DateTime = date
            };
            
            try
            {
                repo.Save(meci);
                rewriteFile(meci);
            }
            catch (Exception ignore){}
        }
    }
}