package ubb.scs.map.ir.seminar.studentsmanagement;

import ubb.scs.map.ir.seminar.studentsmanagement.domain.Student;
import ubb.scs.map.ir.seminar.studentsmanagement.domain.validators.StudentValidator;
import ubb.scs.map.ir.seminar.studentsmanagement.repository.StudentSerializedRepository;
import ubb.scs.map.ir.seminar.studentsmanagement.services.config.ApplicationContext;

public class Sem5 {
    public static void main(String[] args) {

        StudentSerializedRepository repo = new StudentSerializedRepository(new StudentValidator(),
                ApplicationContext.getPROPERTIES().getProperty("data.catalog.studentsser"));
        Student s1 = new Student("nume1", 10);
        s1.setId(1L);
        Student s2 = new Student("nume2", 2);
        s2.setId(2L);
        repo.save(s1);
        repo.save(s2);
        repo.findAll().forEach(System.out::println);
    }
}