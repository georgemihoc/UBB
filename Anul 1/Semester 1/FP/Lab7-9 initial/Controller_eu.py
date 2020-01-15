
#from Repo import *
#from Persoane import Person

from Repository_eu import *

class PersonController(object):
    def __init__(self,person):
        self.Persons = Persons.person
    def add_person(self,person):
        a =Persons.add_person_1(self,person)
        #p = Person(id,nume,adresa)
        return a
        #Persons.boss(self)
    def add_person_random(self,person):
        Persons.add_person_random(self,person)
    def print_person(self,person):
        Persons.print_person(self,person)

    def sterge_lista(self,person):
        Persons.sterge_lista(self,person)
    def modifica_person(self,person):
        a = Persons.modifica_person(self,person)
        return a

    def cautare_persoane(self,person):
        """
                     Functie care cauta o persoana anume in lista de persoane dupa id
                     input-person
                     preconditii-person-lista
                     output-
                     postconditii-

           """
        while True:
            id = input("Introduceti id-ul persoanei:")
            try:
                id = int(id)
                break
            except ValueError:
                print("Valoarea introdusa nu este un intreg, va rugam reintroduceti")
        done = False
        for i in range(0, len(person)):
            if person[i].id == id:
                done = True
                print(person[i].id, person[i].nume, person[i].adresa)
        if done == False:
            print("Persoana cu acest id nu exista")

    def sortare_lista_evenimente(self,person):

        while True:
            id_person = input("Introduceti id-ul persoanei:")
            try:
                id_person = int(id_person)
                break
            except ValueError:
                print("Valoarea introdusa nu este un intreg, va rugam reintroduceti")
        poz = -1
        for i in range(0, len(person)):
            if person[i].id == id_person:
                poz = i
        if poz == -1:
            return poz
        elif person[poz].evenimente == []:
            return 0
        else:
            a = person[poz].evenimente
            # print(person[poz].evenimente)
            for i in range(0, len(a) - 1):
                for j in range(i + 1, len(a)):
                    if a[i][3] > a[j][3]:
                        b = a[i]
                        a[i] = a[j]
                        a[j] = b
                    elif a[i][3] == a[j][3] and a[i][1] > a[j][1]:
                        b = a[i]
                        a[i] = a[j]
                        a[j] = b
        return a

    def persoane_multe_evenimente(self,person):
        maxi = 0
        lista1 = []
        for i in range(0, len(person)):
            nr = len(person[i].evenimente)
            if nr > maxi:
                maxi = nr
        for i in range(0, len(person)):
            # print(person[i].evenimente)
            if len(person[i].evenimente) == maxi:
                # print(person[i].id, person[i].nume, person[i].adresa)
                l = [person[i].id, person[i].nume, person[i].adresa]
                lista1.append(l)
        return lista1




class EventController(object):
    #def __init__(self,Events):
        #self.Events = Events

    def add_event(self,event):
        a = Events.add_event(self,event)
        return a
    def add_event_random(self,event):
        Events.add_event_random(self,event)
    def print_event(self,event):
        Events.print_event(self,event)

    def sterge_lista(self,event):
        Events.sterge_lista(self,event)

    def modifica_event(self,event):
        a = Events.modifica_event(self,event)
        return a

    def cautare_event(self,event):
        """
                        Functie care cauta un eveniment anume in lista de evenimente dupa id
                        input-event
                        preconditii-event-lista
                        output-
                        postconditii-

        """
        while True:
            id = input("Introduceti id-ul evenimentului:")
            try:
                id = int(id)
                break
            except ValueError:
                print("Valoarea introdusa nu este un intreg, va rugam reintroduceti")
        done = False
        for i in range(0, len(event)):
            if event[i].id == id:
                done = True
                print(event[i].id, event[i].data, event[i].timp, event[i].descriere)
        if done == False:
            print("Evenimentul cu acest id nu exista")

class PersonEventController(object):
    def inscriere_eveniment(self,person,event):
        """
                        Functie care inscrie o persoana  data la un eveniment dat
                        input-person, event, lista
                        preconditii-person,event,lista-lista
                        output-
                        postconditii-

        """
        while True:
            id_person = input("Introduceti id-ul persoanei:")
            try:
                id_person = int(id_person)
                break
            except ValueError:
                print("Valoarea introdusa nu este un intreg, va rugam reintroduceti")
        while True:
            id_eveniment = input("Introduceti id-ul evenimentului:")
            try:
                id_eveniment = int(id_eveniment)
                break
            except ValueError:
                print("Valoarea introdusa nu este un intreg, va rugam reintroduceti")
        data = 0
        done = False
        for i in range(0,len(person)):
            if person[i].id == id_person:
                done = True
        if done == True:
            for i in range(0,len(event)):
                if event[i].id == id_eveniment:
                    poz = i
                    data=event[i].data
                    timp=event[i].timp
                    descriere=event[i].descriere
            done = True
            #for i in range(0,len(person[id_person].ev)):
             #   if person[id_person].ev[i] == id_eveniment:
              #      done = False
            if done == True and data != 0:
                for i in range (0,len(person)):
                    if person[i].id == id_person:
                        ok = True
                        for j in range(0,len(person[i].evenimente)):
                            if person[i].evenimente[j][0] == id_eveniment:
                                ok = False
                        if ok == True:
                            person[i].evenimente.append([id_eveniment,data,timp,descriere])
                        else:
                            return 0
                    #print(person[i].evenimente)
            else:
                if data == 0:
                    return -1
                else:
                    return -2
        else:
            return -3

    def numar_participanti(self,person,event):
        """
            Functie care numara cate persoane participa la fiecare eveniment
            input-person, event, lista
            preconditii-person,event,lista-lista
            output-lista de Event
            postconditii-

        """
        for i in range(0,len(event)):
            nr = 0
            for j in range(0,len(person)):
                for k in range(0,len(person[j].evenimente)):
                    if event[i].id == person[j].evenimente[k][0]:
                        nr += 1
            event[i].nrparticipanti = nr

    def evenimente_participanti(self,person,event):
        """
         Functie care numara cate persoane participa la fiecare eveniment
         input-person, event, lista
         preconditii-person,event,lista-lista
         output-lista de Event
         postconditii-

                """
        lista = [[]]
        PersonEventController.numar_participanti(self,person,event)
        numar = 0
        for i in range(0,len(event)):
            numar += event.numarparticipanti
        if numar != 0 :
            for i in range(0,len(event)-1):
                for j in range(i+1,len(event)):
                    if event[i].nrparticipanti < event[j].nrparticipanti:
                        aux = event[i]
                        event[i] = event[j]
                        event[j] = aux
            if len(event) < 5:
                nr = 1
            else:
                nr = len(event) / 5
            for i in range(0,nr):
                lista[i].append([event[i].descriere, event[i].nrparticipanti])
            return lista
        else:
            return -1