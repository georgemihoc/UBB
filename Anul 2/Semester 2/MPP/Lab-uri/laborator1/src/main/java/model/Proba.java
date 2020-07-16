package model;

public class Proba {
    int distanta;
    String stilul;
    int nrParticipanti;

    public Proba(int distanta, String stilul) {
        this.distanta = distanta;
        this.stilul = stilul;
        this.nrParticipanti = 0;
    }

    public int getDistanta() {
        return distanta;
    }

    public void setDistanta(int distanta) {
        this.distanta = distanta;
    }

    public String getStilul() {
        return stilul;
    }

    public void setStilul(String stilul) {
        this.stilul = stilul;
    }

    public int getNrParticipanti() {
        return nrParticipanti;
    }

    public void setNrParticipanti(int nrParticipanti) {
        this.nrParticipanti = nrParticipanti;
    }
}
