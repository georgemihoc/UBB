pachetul studentmanagement contine rezolvarile cerintelor din sem 3 si 4

III.	1) Definiti o interfata care specifica operatiile CRUD pentru un Repository cu elemente generice care au un id de un tip generic ID.

public interface CrudRepository<E, ID> {
    E save(E entity);
    E delete(ID id);
    E findOne(ID id);
    Iterable<E> findAll();
}

public class Entity<ID> {
    private ID id;
    public ID getId() {
        return id;
    }
    public void setId(ID id) {
        this.id = id;
    }
}

2)	Definiți clasa abstractă InMemoryRepository,
        public abstract class InMemoryRepository <E extends HasId<ID>, ID> implements Repository<E, ID> {...},
care contine un dictionar, denumit entities,  cu elemente generice de tipul E,
si un validator generic pentru validarea entitatilor de tipul E din repository.

3) Definiti clasa StudentFileRepository care extinde  InMemoryRepository<Long, Student> care asigura persistenta
entitatilor de tip Student intr-un fisier text

4) Asigurati persistenta entitatilor de tip Student folosind serializare -> va urma sem 5

 ....