
using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using Curs12.Repository;
using Lab10.Repository.Validator;


namespace Lab10.Repository
{
    class InMemoryRepository<ID, E> : IRepository<ID, E> where E : Entity<ID>
    {

        protected IDictionary<ID, E> entities=new Dictionary<ID, E>();
        
        protected IValidator<E> vali;


        public InMemoryRepository(IValidator<E> vali)
        {
            this.vali = vali;
        }

        public E Delete(ID id)
        {
            throw new NotImplementedException();
        }

        public IEnumerable<E> FindAll()
        {
            return entities.Values.ToList<E>();
        }

        public E FindOne(ID id)
        {
            throw new NotImplementedException();
        }

        public E Save(E entity)
        {
            if (entity == null)
                throw new ArgumentNullException("entity must not be null");
            try
            {
                this.vali.Validate(entity);
            }
            catch (ValidationException e)
            {
                throw e;
            }
            if(this.entities.ContainsKey(entity.ID)){
                return entity;
            }
            this.entities[entity.ID] = entity;
            return default(E);
        }

        public E Update(E entity)
        {
            throw new NotImplementedException();
        }
    }
}