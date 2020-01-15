package ubb.scs.map.ir.seminar.studentsmanagement.services.service;

import ubb.scs.map.ir.seminar.studentsmanagement.domain.Student;
import ubb.scs.map.ir.seminar.studentsmanagement.repository.CrudRepository;

public class StudentService {
    private CrudRepository<Long, Student> repository;

    public StudentService(CrudRepository<Long, Student> repository) {
        this.repository = repository;
    }
}
