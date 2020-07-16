package ubb.scs.map.ir.seminar.studentsmanagement.domain;


import java.util.Objects;

public class Student extends Entity<Long> implements Comparable<Student> {
    private String name;
    private float media;

    public Student() {
    }

    public Student(String name, float media) {
        this.name = name;
        this.media = media;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }


    public float getMedia() {
        return media;
    }

    public void setMedia(float media) {
        this.media = media;
    }

    @Override
    public String toString() {
        return "Student{" +
                "id="+ getId()+" "+
                "name='" + name + '\'' +
                ", media=" + media +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Student)) return false;
        Student student = (Student) o;
        return Float.compare(student.getMedia(), getMedia()) == 0 &&
                getName().equals(student.getName());
    }

    @Override
    public int hashCode() {
        return Objects.hash(getName(), getMedia());
    }


    @Override
    public int compareTo(Student o) {
        return (int)(o.getMedia()-this.getMedia());
    }
}
