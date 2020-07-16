package service;

import model.*;
import repository.IRepository;

import java.util.List;

public class Service {
    private IRepository<Integer, Angajat> repoAngajat;
    private IRepository<Integer, Bug> repoBug;

    public Service(IRepository<Integer, Angajat> repoAngajat, IRepository<Integer, Bug> repoBug) {
        this.repoAngajat = repoAngajat;
        this.repoBug = repoBug;
    }

    public Pozitie login(String username, String password) {

        return getPozitie(username,password);
    }

    private Pozitie getPozitie(String username, String password) {
        System.out.println(username+ " " + password);
        for (Angajat angajat :
                repoAngajat.findAll()) {
            System.out.print(angajat);
            if (angajat.getUsername().equals(username) && angajat.getPassword().equals(password)){
                switch (angajat.getPozitie()){
                    case "programator":
                        return Pozitie.PROGRAMATOR;
                    case "administrator":
                        return Pozitie.ADMINISTRATOR;
                    case "tester":
                        return Pozitie.TESTER;
                    default: return Pozitie.ERROR;
                }
            }
        }
        return Pozitie.ERROR;
    }

    public List<Angajat> getAllAngajati() {
        return (List<Angajat>) repoAngajat.findAll();
    }

    public void addAngajat(String username, String pozitie) throws Exception {
        for (Angajat angajat :
                repoAngajat.findAll()) {
            if (angajat.getUsername().equals(username) && angajat.getUsername().equals(pozitie)) {
                throw new Exception("Angajat deja existent");
            }
        }
        repoAngajat.save(new Angajat(username,"pass",pozitie));
    }

    public void deleteAngajat(Angajat angajat) {
        repoAngajat.delete(angajat.getIdAngajat());
    }

    public void addBug(String denumire, String descriere) throws Exception {
        Bug bug = new Bug(denumire,descriere,"activ");
        for (Bug elem :
                repoBug.findAll()) {
            if(elem.getDenumire().equals(denumire) && elem.getDescriere().equals(descriere)){
                throw new Exception("Bug deja existent");
            }
        }
        repoBug.save(bug);
    }

    public List<Bug> getAllBug() {
        return (List<Bug>) repoBug.findAll();
    }

    public void removeBug(Bug bug) {
        bug.setRezolvat("rezolvat");
        repoBug.update(bug.getIdBug(), bug);
    }

    public void updateAngajat(Angajat angajat) {
        repoAngajat.update(angajat.getIdAngajat(),angajat);
    }
}
