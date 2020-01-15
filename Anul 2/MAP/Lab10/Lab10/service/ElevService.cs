using Curs12.Repository;

using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab10.Service
{
    public class ElevService
    {
        private IRepository<string, Elev> repo;

        public ElevService(IRepository<string, Elev> repo)
        {
            this.repo = repo;
        }



        public List<Elev> FindAllElevi()
        {
            return repo.FindAll().ToList();
        }

        public void rewriteFile(Elev elev)
        {
            using (StreamWriter sw = File.AppendText("/Users/george/Documents/UBB/Anul 2/MAP/Lab10/Lab10/data/elevi.txt")) 
            {
                sw.WriteLine();
                sw.Write(elev.ID+","+elev.Nume+","+elev.Scoala);
            }	
        }
        public void AddElev(string nume, string scoala)
        {
            Elev elev = new Elev()
            {
                ID = "e"+ (repo.FindAll().ToList().Count+1),
                Nume = nume,
                Scoala = scoala
            };
            try
            {
                repo.Save(elev);
                rewriteFile(elev);
            }
            catch (ValidationException e)
            {
                throw e;
            }
        }
    }
}