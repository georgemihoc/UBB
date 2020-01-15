package ubb.scs.map.ir.seminar.ex.java.util;

import ubb.scs.map.ir.seminar.studentsmanagement.domain.Student;

import java.util.*;

public class TestSem3 {
    public static void main(String[] args) {
        Student s1 = new Student("Dan", 4.5f);
        Student s2 = new Student("Ana", 8.5f);
        Student s3 = new Student("Dan", 4.5f);
        Student s4 = new Student("Andrei", 1.1f);
        Student s5 = new Student("Barbu", 10.0f);

        Set<Student> set1 = new HashSet<>();
        set1.addAll(Arrays.asList(s1, s2, s3, s4, s5));
        //System.out.println(set1);

        TreeSet<Student> set2 = new TreeSet<>();
        set2.addAll(Arrays.asList(s1, s2, s3, s4, s5));
        //System.out.println(set2);

        TreeSet<Student> set3 = new TreeSet<>(new Comparator<Student>() {
            @Override
            public int compare(Student o1, Student o2) {
                return o1.getName().compareTo(o2.getName());
            }
        });
        set3.addAll(Arrays.asList(s1, s2, s3, s4, s5));

//        for (Student s: set3) {
//            System.out.println(s);
//        }
        Map<String, Student> map = new HashMap<>();
        map.put(s1.getName(), s1);
        map.put(s2.getName(), s2);
        map.put(s3.getName(), s3);
        map.put(s4.getName(), s4);
        map.put(s5.getName(), s5);
        for (Map.Entry<String, Student> pereche : map.entrySet()
        ) {
         //   System.out.println("key = " + pereche.getKey() + " value = " + pereche.getValue());
        }

        Map<String, Student> map2 = new TreeMap<>();
        map2.put(s1.getName(), s1);
        map2.put(s2.getName(), s2);
        map2.put(s3.getName(), s3);
        map2.put(s4.getName(), s4);
        map2.put(s5.getName(), s5);
        for (Map.Entry<String, Student> pereche : map2.entrySet()
        ) {
            System.out.println("key = " + pereche.getKey() + " value = " + pereche.getValue());
        }
    }
}
