using Curs12.Repository;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Curs12.Repository
{
    class DataReader
    {
        public static List<T> ReadData<T>(string fileName, CreateEntity<T> createEntity)
        {
            if (createEntity != null)
            {
                List<T> list = new List<T>();
                using (StreamReader reader = new StreamReader(fileName))
                {
                    string line;
                    while ((line = reader.ReadLine()) != null)
                    {
                        T t = createEntity(line);
                        list.Add(t);
                    }
                };
                return list;
            }
            else throw new ArgumentNullException();
        }
    }
}

