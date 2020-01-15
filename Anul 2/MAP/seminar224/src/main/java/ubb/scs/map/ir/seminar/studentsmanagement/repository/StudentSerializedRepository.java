package ubb.scs.map.ir.seminar.studentsmanagement.repository;

import ubb.scs.map.ir.seminar.studentsmanagement.domain.Student;
import ubb.scs.map.ir.seminar.studentsmanagement.domain.validators.Validator;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class StudentSerializedRepository extends InMemoryRepository<Long, Student> {

    String fileName;

    public StudentSerializedRepository(Validator<Student> validator, String fileName) {
        super(validator);
        this.fileName = fileName;
        loadData();
    }

    private void loadData() {
        List<Student> students = new ArrayList<>();
        try(ObjectInputStream is = new ObjectInputStream(new FileInputStream(fileName))){
            students = (List<Student>) is.readObject();
            students.forEach(x -> super.save(x));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
    }


    public void writeData(){

        List<Student> students = new ArrayList<>();
        super.findAll().forEach((Student x) -> students.add(x));
        try(ObjectOutputStream os = new ObjectOutputStream(new FileOutputStream(fileName))){
            os.writeObject(students);

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    @Override
    public Student save(Student entity) {

        Student s = super.save(entity);
        if(s == null)
            this.writeData();
        return s;

    }
}
