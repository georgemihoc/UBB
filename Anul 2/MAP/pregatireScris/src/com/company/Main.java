package com.company;

import com.sun.source.tree.Tree;

import java.util.ArrayList;
import java.util.List;
import java.util.TreeSet;

class Student {
    String name;
    int varsta;
    Student(int v) {
        varsta = v;
    }
    Student(String n, int v){
        name = n;
        varsta = v;
    }
}

public class Main {


            public static void main(String argv[]) {
                TreeSet<Integer> i = new TreeSet<Integer>();
                TreeSet<Student> s = new TreeSet<Student>();
                s.add(new Student(19));
                s.add(new Student(20));
                s.add(new Student("Mihai", 19));
                i.add(1);
                i.add(2);
                i.add(1);
                System.out.println(s.size()+ i.size());


//            String[] strings = {"hello", "world"};
//            String[] obj = strings;
//            List<?> list = new ArrayList<String>();
//            for(String o: obj)
//            {
//                System.out.println(obj);
//                if(o.toLowerCase().equals("hello"))
//                {
//                    list.add(o);
//                }
//            }
//            list.forEach(System.out::println);
            }


}