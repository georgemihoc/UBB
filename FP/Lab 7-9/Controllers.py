from Person import *
from Event import *
from Asign import *
from Repository import *
import string
import random


class PersonController(object):

    def __init__(self, repoPerson, validPerson):
        self.repoPerson = repoPerson
        self.validPerson = validPerson

    def adaugaPerson(self, ident, nume, grup):
        """
                                             Functie care adauga o persoana in lista
                                             input-person, event, lista
                                             preconditii-person,event,lista-lista
                                             output-
                                             postconditii-

                       """
        e = Person(ident, nume, grup)
        self.validPerson.valideazaPerson(e)
        self.repoPerson.adauga(e)

    def stergePerson(self, ident, nume, grup):
        """
                                            Functie care sterge o persoana din lista
                                            input-person, event, lista
                                            preconditii-person,event,lista-lista
                                            output-
                                            postconditii-

                      """
        e = Person(ident, nume, grup)
        self.validPerson.valideazaPerson(e)
        self.repoPerson.sterge(e)

    def modificaPerson(self, ident, nume, grup):
        """
                                             Functie care modifica un element din lista de persoane
                                             input-person, event, lista
                                             preconditii-person,event,lista-lista
                                             output-
                                             postconditii-

                       """
        e = Person(ident, nume, grup)
        self.validPerson.valideazaPerson(e)
        self.repoPerson.update(e)

    def cautaPerson(self,elem):
        return self.repoPerson.cauta(elem)

    def randomPerson(self, x):
        """
                                             Functie care inscrie persoane random in lista
                                             input-person, event, lista
                                             preconditii-person,event,lista-lista
                                             output-
                                             postconditii-

         """
        Letters_high = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        Letters_low = "aeioubcdfghjklmnpqrstvwxyz"
        lung = len(self.repoPerson)
        for j in range(x):
            if lung == 0:
                ident = j + 1
            else:
                ident = lung + j + 1
            r = random.randint(3, 11)
            nume = ""
            for i in range(r):
                l = random.choice(Letters_low)
                if i == 0:
                    l = random.choice(Letters_high)
                nume += l
            grup = random.randint(1, 10)
            e = Person(ident, nume, grup)
            self.repoPerson.adauga(e)


    def getAllPerson(self):
        return self.repoPerson.getAll()


class EventController(object):

    def __init__(self, repoEvent, validEvent):
        self.repoEvent = repoEvent
        self.validEvent = validEvent

    def adaugaEvent(self, lab, desc, dl,el):
        """
                                            Functie care adauga un eveniment in lista de evenimente
                                            input-person, event, lista
                                            preconditii-person,event,lista-lista
                                            output-
                                            postconditii-

                      """
        p = Event(lab, desc, dl,el)
        self.validEvent.valideazaEvent(p)
        self.repoEvent.adauga(p)

    def getAllEvent(self):
        return self.repoEvent.getAll()

    def stergeEvent(self, lab, desc, dl,el):
        """
                                             Functie care sterge un eveniment din lista
                                             input- event, lista
                                             preconditii-person,event,lista-lista
                                             output-
                                             postconditii-

                       """
        p = Event(lab, desc, dl,el)
        self.validEvent.valideazaEvent(p)
        self.repoEvent.sterge(p)

    def modificaEvent(self, lab, desc, dl,el):
        """
                                           Functie care modifica un element din lista de evenimente
                                           input-person, event, lista
                                           preconditii-person,event,lista-lista
                                           output-
                                           postconditii-

                     """
        p = Event(lab, desc, dl,el)
        self.validEvent.valideazaEvent(p)
        self.repoEvent.update(p)

    def cautaEvent(self,elem):
        return self.repoEvent.cauta(elem)

    def randomEvent(self, x):
        """
                                             Functie care inscrie evenimente random in lista
                                             input-person, event, lista
                                             preconditii-person,event,lista-lista
                                             output-
                                             postconditii-

                       """
        Letters_high = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        Letters_low = "aeioubcdfghjklmnpqrstvwxyz"
        lung = len(self.repoEvent)
        for j in range(x):
            if lung == 0:
                lab = j + 1
            else:
                lab = lung + j + 1
            r = random.randint(3, 11)
            desc = ""
            for i in range(r):
                l = random.choice(Letters_low)
                if i == 0:
                    l = random.choice(Letters_high)
                desc += l
            dl = random.randint(1, 14)
            el = random.randint(1, 14)
            p = Event(lab, dl, el, desc)
            self.repoEvent.adauga(p)


class AsignController(object):

    def __init__(self, repoPerson, repoEvent, repoAsign, validAsign):
        self.repoPerson = repoPerson
        self.repoEvent = repoEvent
        self.repoAsign = repoAsign
        self.validAsign = validAsign

    def nr_participanti(self, a, b, x):
        """
                Functie care numara cate persoane participa la fiecare eveniment
                input-person, event, lista
                preconditii-person,event,lista-lista
                output-lista de Event
                postconditii-

        """
        nr = 0
        for p in a:
            if b[x].id == p.eid:
                nr += 1
        return nr

    def inscriere(self, pid, eid):
        """
                                      Functie care inscrie o persoana  data la un eveniment dat
                                      input-person, event, lista
                                      preconditii-person,event,lista-lista
                                      output-
                                      postconditii-

                """
        a = Asign(pid, eid)
        p = Person(pid, None, None)
        e = Event(eid, None, None,None)
        self.repoPerson.cauta(p)
        self.repoEvent.cauta(e)
        self.validAsign.valideazaAsign(a)
        self.repoAsign.adauga(a)

    def Ordonare(self,a,b,poz):
        """
                                             Functie care ordoneaza lista de evenimente la care participa o anume persoana
                                             input-person, event, lista
                                             preconditii-person,event,lista-lista
                                             output-
                                             postconditii-

                       """
        lista = []
        lista2 = []
        final = []
        for p in a:
            if p.pid == poz:
                lista.append(p.eid)
        for p in b:
            if p.id in lista:
                lista2.append(p.desc)
        lista2.sort()
        #print(lista2)
        for i in range(0,len(lista2)):
            for p in b:
                if p.desc == lista2[i]:
                    final.append([p.id, p.data, p.timp, p.desc])
                    #print(p)
        return final

    def MostEvents(self,a,b):
        """
                                            Functie care tipareste persoanele care participa la cele mai multe evenimente
                                            input-person, event, lista
                                            preconditii-person,event,lista-lista
                                            output-
                                            postconditii-

                      """
        sir = [0] * 1000
        maxi = 0
        final = []
        for p in a:
            sir[p.pid] += 1
        for i in range(1000):
            if sir[i] > maxi:
                maxi = sir[i]
        for i in range(0, 1000):
            if sir[i] == maxi and maxi != 0:
                final.append(i)
        return final

    def Raport(self,a,b):
        """
                                             Functie care tipareste primele 20% evenimente cu cele mai multe persoane inscrise
                                             input-person, event, lista
                                             preconditii-person,event,lista-lista
                                             output-
                                             postconditii-

                       """
        for i in range(0,len(b)):
            #print(Console.nr_participanti(self, a, b, i))
            for j in range(i , len(b)):
                if AsignController.nr_participanti(self,a,b,i) < AsignController.nr_participanti(self,a,b,j):
                    #print("boss")
                    aux = b[i]
                    b[i] = b[j]
                    b[j] = aux
        if len(b) < 5 and len(b)>0 :
            nr = 1
        elif len(b) == 0 :
            nr = 0
        else:
            nr = len(b) / 5
        if len(a) == 0:
            nr = 0
        if nr>0:
            #for i in range(0, nr):
             #   print(b[i].desc)
            return nr
        else:
            return -1

    def Functionalitate(self,a,b,c):
        """
                                                 Functie care tipareste lista a timpurilor ordonate descrescator dupa cate persoane participa la un eveniment de acea durata
                                                 input-person, event, lista
                                                 preconditii-person,event,lista-lista
                                                 output-
                                                 postconditii-

        """
        lista = []
        j = -1
        for p in c:
            j+=1
            poz1 = -1
            for w in b:
                poz1 += 1
                if w.id == p.eid:
                    break
            nr = AsignController.nr_participanti(self,c,b,poz1)
            n = -1
            for q in b:
                n += 1
                if q.id == p.eid:
                    poz = n
            ok = 0
            for i in lista:
                if i[0] == b[poz].timp:
                    ok = 1
                    #print("boss")
                    i[1] += nr
            if ok == 0:
                lista.append([b[poz].timp, nr])
        for i in range(0,len(lista)-1):
            for j in range(i+1,len(lista)):
                if lista[i][1]<lista[j][1]:
                    aux = lista[i]
                    lista[i] = lista[j]
                    lista[j] = aux
        return lista


    def getAllAsign(self):
        return self.repoAsign.getAll()






