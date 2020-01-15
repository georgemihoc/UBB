package ubb.scs.map.ir.seminar.ex.java.util;


import ubb.scs.map.ir.seminar.studentsmanagement.domain.Student;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;

public class MyMap {
    private Map<Integer, List<Student>> map;

    public MyMap() {
        this.map = new TreeMap<>();

    }

    public void add(Student s) {
        float med = s.getMedia();
        Integer rot = Math.round(med);
        List<Student> lista = map.get(rot);
        if (lista == null) {
            lista = new ArrayList<Student>();
            lista.add(s);
            map.put(rot, lista);
        } else {
            lista.add(s);
        }
    }
}

