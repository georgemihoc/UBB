package ubb.scs.map.ir.seminar.studentsmanagement;

import ubb.scs.map.ir.seminar.studentsmanagement.domain.Student;
import ubb.scs.map.ir.seminar.studentsmanagement.domain.validators.StudentValidator;
import ubb.scs.map.ir.seminar.studentsmanagement.domain.validators.ValidationException;
import ubb.scs.map.ir.seminar.studentsmanagement.repository.InMemoryRepository;
import ubb.scs.map.ir.seminar.studentsmanagement.repository.StudentFileRepository;

public class Seminar3_4 {
    public static void main(String[] args) {
        StudentValidator validator = new StudentValidator();
        InMemoryRepository<Long, Student> repo = new InMemoryRepository<>(validator);

        Student s1 = new Student("Ionescu",5);
        Student s2 =new Student("pop", 6);
        Student s3=null;

        s1.setId(1l);
        s2.setId(1l);
        try {
            //repo.save(s3);
            repo.save(s2);
            Student s=repo.save(s1);
            if(s!=null) System.out.println("Exista acest student!"+s);
        }
        catch (IllegalArgumentException ex){
            System.out.println(ex.getMessage());
        }
        catch (ValidationException ex){
            System.out.println(ex.getMessage());
        }
        //repo.findAll().forEach(student -> System.out.println(student));
        //repo.findAll().forEach(System.out::println);
        StudentFileRepository repository = new StudentFileRepository(validator,"data/students.txt");
        repository.findAll().forEach(System.out::println);


    }
}

