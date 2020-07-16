using Curs12.Repository;
using Curs12.Repository;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab10.Repository
{
    class MeciInFileRepository : InFileRepository<string, Meci>
    {

        public MeciInFileRepository( string fileName) : base(null,fileName, EntityToFileMapping.CreateMeci)
        {
            
        }

    }

}