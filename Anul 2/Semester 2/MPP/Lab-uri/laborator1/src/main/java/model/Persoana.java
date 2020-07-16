package model;

import java.util.ArrayList;
import java.util.List;

public class Persoana {
    String nume;
    int varsta;
    List<String> probe = new ArrayList<>();

    public Persoana(String nume, int varsta) {
        this.nume = nume;
        this.varsta = varsta;
    }

    public String getNume() {
        return nume;
    }

    public void setNume(String nume) {
        this.nume = nume;
    }

    public int getVarsta() {
        return varsta;
    }

    public void setVarsta(int varsta) {
        this.varsta = varsta;
    }

    public List<String> getProbe() {
        return probe;
    }

    public void setProbe(ArrayList<String> probe) {
        this.probe = probe;
    }
}
