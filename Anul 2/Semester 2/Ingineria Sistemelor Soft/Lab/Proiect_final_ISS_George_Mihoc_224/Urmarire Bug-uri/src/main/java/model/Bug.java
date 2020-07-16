package model;

public class Bug {
    private int idBug;
    private String denumire;
    private String descriere;
    private String rezolvat;

    public Bug(String denumire, String descriere, String rezolvat) {
        this.denumire = denumire;
        this.descriere = descriere;
        this.rezolvat = rezolvat;
    }
    public Bug(){

    }

    public int getIdBug() {
        return idBug;
    }

    public void setIdBug(int idBug) {
        this.idBug = idBug;
    }

    public String getDenumire() {
        return denumire;
    }

    public void setDenumire(String denumire) {
        this.denumire = denumire;
    }

    public String getDescriere() {
        return descriere;
    }

    public void setDescriere(String descriere) {
        this.descriere = descriere;
    }

    public String getRezolvat() {
        return rezolvat;
    }

    public void setRezolvat(String rezolvat) {
        this.rezolvat = rezolvat;
    }

    @Override
    public String toString() {
        return "Denumire: " + denumire + " | Descriere: " + descriere;
    }
}
