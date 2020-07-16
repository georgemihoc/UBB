using System.Collections.Generic;
using System.Linq;
using Curs12.Repository;

namespace Lab10.Service
{
    public class JucatorService
    {
        private IRepository<string, Jucator> repo;

        public JucatorService(IRepository<string, Jucator> repo)
        {
            this.repo = repo;
        }


        public List<Jucator> FindAllJucatori()
        {
            return repo.FindAll().ToList();
        }
    }
}