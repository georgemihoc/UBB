
package ubb.scs.map.ir.seminar.studentsmanagement;

import ubb.scs.map.ir.seminar.studentsmanagement.domain.validators.StudentValidator;
import ubb.scs.map.ir.seminar.studentsmanagement.repository.StudentFileRepository;
import ubb.scs.map.ir.seminar.studentsmanagement.services.config.ApplicationContext;

import java.util.*;
import java.util.function.BiFunction;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class ConfigFile {
    public static void main(String[] args) {


        StudentFileRepository studentFileRepository = new StudentFileRepository(new StudentValidator(),
                ApplicationContext.getPROPERTIES().getProperty("data.catalog.students"));

        studentFileRepository.findAll().forEach(System.out::println);


    }
}
