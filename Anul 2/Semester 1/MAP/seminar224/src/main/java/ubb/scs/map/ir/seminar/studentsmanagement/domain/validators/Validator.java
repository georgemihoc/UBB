package ubb.scs.map.ir.seminar.studentsmanagement.domain.validators;

public interface Validator<T> {
    void validate(T entity) throws ValidationException;
}
