
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Lab10.Repository.Validator;

namespace Lab10.Repository
{
    class ElevInFileRepository : InFileRepository<string, Elev>
    {

        public ElevInFileRepository(IValidator<Elev> validator,string fileName) : base(validator,fileName, EntityToFileMapping.CreateElev)           
        {
           
        }

    }
}