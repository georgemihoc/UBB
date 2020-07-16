using Curs12.Repository;
using Curs12.Repository.Validator;
using Curs12.Repository;
using Curs12.Repository;
using System;
using System.Collections.Generic;
using System.Configuration;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Curs12.Repository
{


    class PontajInFileRepository : InFileRepository<string, Pontaj>
    {
        public PontajInFileRepository(IValidator<Pontaj> vali, string fileName) : base(vali, fileName, EntityToFileMapping.CreatePontaj)
        {
            
        }

    }
}
