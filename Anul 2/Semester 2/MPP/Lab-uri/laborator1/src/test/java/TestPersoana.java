import model.Persoana;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class TestPersoana {
    @Test
    public void testAdd() {
        assertEquals(42, Integer.sum(19, 23));

        Persoana p1 = new Persoana("Andrei", 16);
        assertEquals(p1.getNume(), "Andrei");
    }
}
