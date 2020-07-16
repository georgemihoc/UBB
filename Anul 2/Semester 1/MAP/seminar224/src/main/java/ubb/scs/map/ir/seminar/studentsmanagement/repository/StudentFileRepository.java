package ubb.scs.map.ir.seminar.studentsmanagement.repository;


import ubb.scs.map.ir.seminar.studentsmanagement.domain.Student;
import ubb.scs.map.ir.seminar.studentsmanagement.domain.validators.Validator;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;

public class StudentFileRepository extends InMemoryRepository<Long, Student> {
    private String fileName;
    public StudentFileRepository(Validator validator, String fileName) {
        super(validator);
        this.fileName = fileName;
        loadData();
    }

    private void loadData() {
        Path path = Paths.get(fileName);
        try {
            List<String> lines = Files.readAllLines(path);
            lines.forEach(linie -> {
                //E entity=createEntity(linie);
                String[] l = linie.split(";");
                Student s = new Student(l[1], Float.parseFloat(l[2]));
                s.setId(Long.parseLong(l[0]));
                super.save(s);
            });
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
