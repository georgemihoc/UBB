from Person import *
from Event import *
from Asign import *
from Repository import *
import string
import random
from Repository import PersonRepository


def getNextGap(gap):
    """
            Functie care returneaza noul gap pentru Comb Sort
            input-gap
            preconditii-gap-numar intreg
            output- gap
            postconditii-gap-numar intreg
    """
    gap = (gap * 10) / 13
    if gap < 1:
        return 1
    return gap


def CombSort(lista,key,reverse):
    """
        Functie care ordoneaza o lista cu metoda Comb Sort
        input-aa
        preconditii-a-lista
        output- lista a ordonata folosind Comb sort
        postconditii-

    """
    n = len(lista)
    gap = n
    ok = True

    while gap != 1 or ok == 1:
        gap = getNextGap(gap)
        ok = False
        gap = int(gap)
        for i in range(0, int(n - gap)):
            if lista[i] > lista[i + gap]:
                lista[i], lista[i + gap] = lista[i + gap], lista[i]
                ok = True
    return lista


def InsertionSortRecursive(lista, n,key,reverse):
    """
        Functie care ordoneaza o lista cu metoda insertion sort varianta recursiva
         input-arr,n
         preconditii-arr-lista, n-lungimea listei arr , un nr intreg
         output- lista arr ordonata folosind insertion sort
         postconditii-

    """
    if n <= 1:
        return lista

    InsertionSortRecursive(lista, n - 1,key,reverse)

    last = lista[n - 1]
    j = n - 2

    while (j >= 0 and lista[j] > last):
        lista[j + 1] = lista[j]
        j = j - 1

    lista[j + 1] = last

def mergeSort(arr, key, reverse):
    """
    Functie care ordoneaza o lista cu metoda merge sort
     input-lista
     preconditii-lista-lista
     output- lista ordonata folosind merge sort
     postconditii-lista-lista

     Complexitatea:
     TIMP:
         ALL CASE: Complexitatea este ϴ(n logn)
     SPATIU:
        O(n)
    arr: lista de obiecte ce va fi sortata
    """
    if reverse == True:
        if len(arr) > 1:
            mid = len(arr) // 2
            L = arr[:mid]
            R = arr[mid:]

            mergeSort(L, key, reverse)
            mergeSort(R, key, reverse)

            i = j = k = 0

            while i < len(L) and j < len(R):
                if key(L[i]) < key(R[j]):
                    arr[k] = L[i]
                    i += 1
                else:
                    arr[k] = R[j]
                    j += 1
                k += 1

            while i < len(L):
                arr[k] = L[i]
                i += 1
                k += 1

            while j < len(R):
                arr[k] = R[j]
                j += 1
                k += 1
    else:
        if len(arr) > 1:
            mid = len(arr) // 2
            L = arr[:mid]
            R = arr[mid:]

            mergeSort(L, key, reverse)
            mergeSort(R, key, reverse)

            i = j = k = 0

            while i < len(L) and j < len(R):
                if key(L[i]) > key(R[j]):
                    arr[k] = L[i]
                    i += 1
                else:
                    arr[k] = R[j]
                    j += 1
                k += 1

            while i < len(L):
                arr[k] = L[i]
                i += 1
                k += 1

            while j < len(R):
                arr[k] = R[j]
                j += 1
                k += 1

def MergeSort(list,key,reverse):
    """
             Functie care ordoneaza o lista cu metoda merge sort
             input-lista
             preconditii-lista-lista
             output- lista ordonata folosind merge sort
             postconditii-lista-lista

             Complexitatea:
             TIMP:
                 ALL CASE: Complexitatea este ϴ(n logn)
             SPATIU:
                O(n)

    """
    if len(list) > 1:
        mijloc = len(list) // 2
        stanga = list[:mijloc]
        dreapta = list[mijloc:]

        mergeSort(stanga,key,reverse)
        mergeSort(dreapta,key,reverse)

        i = 0
        j = 0
        k = 0
        while i < len(stanga) and j < len(dreapta):
            if stanga[i] < dreapta[j]:
                list[k] = stanga[i]
                i = i + 1
            else:
                list[k] = dreapta[j]
                j = j + 1
            k = k + 1

        while i < len(stanga):
            list[k] = stanga[i]
            i = i + 1
            k = k + 1

        while j < len(dreapta):
            list[k] = dreapta[j]
            j = j + 1
            k = k + 1


class PersonController(object):

    def __init__(self, repoPerson, validPerson):
        self.repoPerson = repoPerson
        self.validPerson = validPerson

    def adaugaPerson(self, ident, nume, adresa):
        """
                                             Functie care adauga o persoana in lista
                                             input-person, event, lista
                                             preconditii-person,event,lista-lista
                                             output-
                                             postconditii-

                       """
        e = Person(ident, nume, adresa)
        self.validPerson.valideazaPerson(e)
        #self.repoPerson.adauga(e)
        self.repoPerson.adaugare(e)

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



    def cautaPerson(self,id,nume,adresa):
        person = Person(id, nume, adresa)
        return self.repoPerson.cauta(person)

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

        file = open("date_person.txt","r")
        maxi = 0
        maxi = int(maxi)
        for line in file:
            line = line.strip().split(" ")
            #print(line[0])
            if int(line[0]) > maxi:
                maxi = int(line[0])
        lung = maxi
        lung = int(lung)
        #print(maxi)
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
            self.repoPerson.adaugare(e)
        file.close()


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
        #self.repoEvent.adauga(p)
        self.repoEvent.adaugare(p)

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

    def cautaEvent(self,id,data,timp,desc):
        event = Event(id,data,timp,desc)
        return self.repoEvent.cauta(event)

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
        file = open("date_event.txt", "r")
        maxi = 0
        maxi = int(maxi)
        for line in file:
            line = line.strip().split(" ")
            if int(line[0]) > maxi:
                maxi = int(line[0])
        lung = maxi
        lung = int(lung)

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
            self.repoEvent.adaugare(p)


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
    def nr_participanti_recursiv(self,a,i,b,x):
        """
                Functie care numara cate persoane participa la fiecare eveniment in mod RECURSIV
                input-a,i,b,x
                preconditii-a,b,x-liste ,i numar intreg
                output-nr-numarul de persoane participante la un anumit event
                postconditii-nr-numar intreg

        """
        i = int(i)
        if i == len(a):
            return 0
        if b[x].id == a[i].eid:
            return int(1)+AsignController.nr_participanti_recursiv(self,a,i+1,b,x)
        return AsignController.nr_participanti_recursiv(self,a,i+1,b,x)
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
        self.repoAsign.adaugare(a)

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
        mergeSort(b, key=lambda x: x.get_desc(), reverse=True)
        for i in range(0,len(lista2)):
            for p in b:
                if p.desc == lista2[i]:
                    final.append([p.id, p.data, p.timp, p.desc])
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
            for j in range(i , len(b)):
                if AsignController.nr_participanti_recursiv(self,a,0,b,i) < AsignController.nr_participanti_recursiv(self,a,0,b,j):
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
            nr = AsignController.nr_participanti_recursiv(self,c,0,b,poz1)
            n = -1
            for q in b:
                n += 1
                if q.id == p.eid:
                    poz = n
            ok = 0
            for i in lista:
                if i[0] == b[poz].timp:
                    ok = 1
                    i[1] = nr
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