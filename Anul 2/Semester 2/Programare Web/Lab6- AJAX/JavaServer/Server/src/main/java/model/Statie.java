package model;

public class Statie {

    int idStatie;
    String start;
    String stop;

    public Statie(int idStatie, String start, String stop) {
        this.idStatie = idStatie;
        this.start = start;
        this.stop = stop;
    }

    public String getStart() {
        return start;
    }

    public String getStop() {
        return stop;
    }

    @Override
    public String toString() {
        return idStatie + " " + start + " " + stop;
    }
}
