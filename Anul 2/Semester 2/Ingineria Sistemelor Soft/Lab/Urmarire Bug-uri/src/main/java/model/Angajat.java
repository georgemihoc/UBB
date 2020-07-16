package model;

public class Angajat {
     int idAngajat;
     String username;
     String password;
     String pozitie;

    public Angajat(String username, String password, String pozitie) {
        this.username = username;
        this.password = password;
        this.pozitie = pozitie;
    }
    public Angajat(){

    }

    public int getIdAngajat() {
        return idAngajat;
    }

    public void setIdAngajat(int idAngajat) {
        this.idAngajat = idAngajat;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getPozitie() {
        return pozitie;
    }

    public void setPozitie(String pozitie) {
        this.pozitie = pozitie;
    }

    @Override
    public String toString() {
        return username + " " + pozitie;
    }
}
