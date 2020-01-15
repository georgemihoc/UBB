package ubb.scs.map.ir.seminar.studentsmanagement.repository;

import ubb.scs.map.ir.seminar.studentsmanagement.domain.Entity;
import ubb.scs.map.ir.seminar.studentsmanagement.domain.validators.Validator;

import java.util.*;

public class InMemoryRepository<ID, E extends Entity<ID>> implements CrudRepository<ID,E> {
    private Map<ID, E> entities;
    private Validator<E> validator;

    public InMemoryRepository(Validator<E> validator) {
        this.validator = validator;
        entities = new HashMap<ID, E>();
    }

    @Override
    public E findOne(ID id) {
        return null;
    }


    @Override
    public Iterable<E> findAll() {
        return entities.values();
    }

    @Override
    public E save(E entity) {
        if(entity == null) throw new IllegalArgumentException("entity must be not null");
        if(entities.containsKey(entity.getId())) return entity;
        validator.validate(entity);
        entities.put(entity.getId(), entity);
        return null;
    }

    @Override
    public E delete(ID id) {
        return null;
    }

    @Override
    public E update(E entity) {
        return null;
    }
}
