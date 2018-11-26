from model.Elev import Elev
from model.Problema import Problema
from model.Asign import Asign
import string
import random

class ElevController(object):
    
    def __init__(self, repoElev,validElev):
        self.repoElev = repoElev
        self.validElev = validElev
       
    def adaugaElev(self,ident,nume,grup):
        e = Elev(ident,nume,grup)
        self.validElev.valideazaElev(e)
        self.repoElev.adauga(e)
        
    def stergeElev(self,ident,nume,grup):
        e = Elev(ident,nume,grup)
        self.validElev.valideazaElev(e)
        self.repoElev.sterge(e)
    
    def modificaElev(self,ident,nume,grup):
        e = Elev(ident,nume,grup)
        self.validElev.valideazaElev(e)
        self.repoElev.update(e)
        
    def randomElev(self,x):
        Letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        cons = "bcdfghjklmnpqrstvwxyz"
        voc = "aeiou"
        lung = len(self.repoElev)
        for j in range(x):
            if lung == 0:
                ident = j + 1
            else:
                ident = lung + j + 1
            r = random.randint(3,11)
            nume =""
            for i in range(r): 
                if i % 2 == 0:
                    l = random.choice(cons)
                if i % 2 == 1:
                    l = random.choice(voc)
                if i == 0:
                    l = random.choice(Letters)
                nume += l
            grup = random.randint(1,10)
            e = Elev(ident,nume,grup)
            self.repoElev.adauga(e)
    
    def getAllElev(self):
        return self.repoElev.getAll()


class ProblemaController(object):
    
    def __init__(self, repoProblema,validProblema):
        self.repoProblema = repoProblema
        self.validProblema = validProblema
       
    def adaugaProblema(self,lab,desc,dl):
        p = Problema(lab,desc,dl)
        self.validProblema.valideazaProblema(p)
        self.repoProblema.adauga(p)
        
    def getAllProblema(self):
        return self.repoProblema.getAll()
    
    def stergeProblema(self,lab,desc,dl):
        p = Problema(lab,desc,dl)
        self.validProblema.valideazaProblema(p)
        self.repoProblema.sterge(p)
        
    def modificaProblema(self,lab,desc,dl):
        p = Problema(lab,desc,dl)
        self.validProblema.valideazaProblema(p)
        self.repoProblema.update(p)
        
    def randomProblema(self,x):
        Letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        cons = "bcdfghjklmnpqrstvwxyz"
        voc = "aeiou"
        lung = len(self.repoProblema)
        for j in range(x):
            if lung == 0:
                lab = j + 1
            else:
                lab = lung + j + 1
            r = random.randint(3,11)
            desc =""
            for i in range(r): 
                if i % 2 == 0:
                    l = random.choice(cons)
                if i % 2 == 1:
                    l = random.choice(voc)
                if i == 0:
                    l = random.choice(Letters)
                desc += l
            dl = random.randint(1,14)
            p = Problema(lab,desc,dl)
            self.repoProblema.adauga(p)
         

class AsignController(object):
    
    def __init__(self, repoElev, repoProblema, repoAsign,validAsign):
        self.repoElev = repoElev
        self.repoProblema = repoProblema
        self.repoAsign = repoAsign
        self.validAsign = validAsign
        
    def adaugaNota(self,eid,lab,nota):
        a = Asign(eid,lab,nota)
        e = Elev(eid,None,None)
        p = Problema(eid,None,None)
        self.repoElev.cauta(e)
        self.repoProblema.cauta(p)
        self.validAsign.valideazaAsign(a)
        self.repoAsign.adauga(a)
    
    def getAllAsign(self):
        return self.repoAsign.getAll()


