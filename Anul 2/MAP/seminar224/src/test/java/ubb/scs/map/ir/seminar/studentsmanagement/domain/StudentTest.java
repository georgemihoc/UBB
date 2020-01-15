package ubb.scs.map.ir.seminar.studentsmanagement.domain;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class StudentTest {

    private static Student s;

    @BeforeEach
    void setUp() {
        s=new Student("Dan",4.5f);
        s.setId(3l);
    }

    @AfterEach
    void tearDown() {
    }

    @Test
    void getName() {

        assertEquals("Dan",s.getName(),"Student getName() method failed");
    }

    @Test
    void setName() {
    }

    @Test
    void getMedia() {
    }

    @Test
    void setMedia() {
    }

    @Test
    void testEquals() {
    }

    @Test
    void compareTo() {
    }
}