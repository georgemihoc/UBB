import model.Proba;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class TestProba {
    @Test
    public void testAdd() {
        assertEquals(42, Integer.sum(19, 23));

        Proba p = new Proba(50, "liber");
        assertEquals(p.getDistanta(),50);
        assertEquals(p.getStilul(), "liber");
    }
}
