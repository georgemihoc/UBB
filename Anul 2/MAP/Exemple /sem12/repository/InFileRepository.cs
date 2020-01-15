
using Curs12.Repository;
using Curs12.Repository.Validator;
using System;
using System.Collections.Generic;


namespace Curs12.Repository
{
    public delegate E CreateEntity<E>(string line);
    public delegate String EntityToString<E>(E entity);

    abstract class InFileRepository<ID, E> : InMemoryRepository<ID, E> where E : Entity<ID>
    {
        protected string fileName;

        public InFileRepository(IValidator<E> vali, String fileName, CreateEntity<E> createEntity) : base(vali)
        {
            this.fileName = fileName;
            if (createEntity != null)
                loadFromFile(createEntity);
        }

        protected virtual void loadFromFile(CreateEntity<E> createEntity)
        {
            List<E> list = DataReader.ReadData(fileName, createEntity);
            list.ForEach(x => entities[x.ID] = x);
        }


    }
}
