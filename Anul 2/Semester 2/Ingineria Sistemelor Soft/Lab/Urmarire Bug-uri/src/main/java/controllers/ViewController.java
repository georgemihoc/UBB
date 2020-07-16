package controllers;

import model.Angajat;
import model.Bug;
import model.Pozitie;
import service.Service;

import java.util.List;

public class ViewController {

    private MainViewFXML mainViewFXML;
    private Angajat user;
    private Service service;

    public ViewController(MainViewFXML mainViewFXML, Service service) {
        this.mainViewFXML = mainViewFXML;
        this.service = service;
    }
    public Pozitie login(String username, String password){
        return service.login(username,password);
    }
    public List<Angajat> getListAngajati(){
        return service.getAllAngajati();
    }

    public void addAngajat(String username, String pozitie)throws Exception {
        service.addAngajat(username,pozitie);
    }

    public void deleteAngajat(Angajat angajat) {
        service.deleteAngajat(angajat);
    }

    public void addBug(String denumire, String descriere)throws Exception{
        service.addBug(denumire,descriere);
    }

    public List<Bug> getAllBug(){
        return service.getAllBug();
    }

    public void removeBug(Bug bug) {
        service.removeBug(bug);
    }

    public void updateAngajat(Angajat angajat) {
        service.updateAngajat(angajat);
    }
}
