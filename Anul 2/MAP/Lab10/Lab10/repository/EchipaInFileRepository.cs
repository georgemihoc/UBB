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
    class EchipaInFileRepository : InFileRepository<string, Echipa>
    {

        public EchipaInFileRepository( string fileName) : base(null,fileName, EntityToFileMapping.CreateEchipa)
        {
            
        }

    }

}