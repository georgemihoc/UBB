using System;
using System.Collections.Generic;
using Curs12.Repository;
using Lab10.Repository.Validator;

namespace Lab10.Repository
{
        public delegate E CreateEntity<E>(string line);
        public delegate String EntityToString<E>(E entity);

        abstract class InFileRepository<ID, E> : InMemoryRepository<ID, E> where E : Entity<ID>
        {
            protected string fileName;

            public InFileRepository(IValidator<E> validator, string fileName, CreateEntity<E> createEntity) : base(validator)
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