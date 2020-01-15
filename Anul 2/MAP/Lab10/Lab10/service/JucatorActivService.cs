using System.Collections.Generic;
using System.Linq;
using Curs12.Repository;

namespace Lab10.Service
{
    public class JucatorActivService
    {
        private IRepository<string, JucatorActiv> repo;

        public JucatorActivService(IRepository<string, JucatorActiv> repo)
        {
            this.repo = repo;
        }

        // public  List<JucatorActiv> TotiJucatoriiMeci(string idMeci)
        // {
        //     List<JucatorActiv> jucatoriActivi  = repo.FindAll().ToList();
        //
        //     jucatoriActivi
        //         .Where(a => a.IdMeci.Equals(idMeci))
        //         .ToList();
        //     return jucatoriActivi;
        // }

        public List<JucatorActiv> FindAllJucatoriActivi()
        {
            return repo.FindAll().ToList();
        }
    }
}