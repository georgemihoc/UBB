import random
import string

class Persons:
   # person = []
    def __init__(self, id, name, adress):
        self.id = id
        self.nume = name
        self.adresa = adress
        self.evenimente =[]

    def citire_person(self):
        """
           Functie care citeste toate elementele atribuite unei persoane
           input-
           preconditii-
           output-id,nume,adresa
           postconditii-

        """
        while True:
            id = input("Id:")
            try:
                id = int(id)
                break
            except ValueError:
                print("Valoarea introdusa nu este un intreg, va rugam reintroduceti")
        while True:
            nume = input("Nume:")
            if nume[0] == nume[0].upper() and nume[1:] == nume[1:].lower() and nume[1:].isalpha():
                break
            else:
                 print("Valoarea introdusa nu este un nume, va rugam reintroduceti")
        while True:
            adresa = input("Adresa:")
            try:
                adresa = str(adresa)
                break
            except ValueError:
                print("Valoarea introdusa nu este un nume, va rugam reintroduceti")
        return id, nume, adresa

    def add_person_1(self,person):
        """
           Functie care adauga o persoana noua la lista de persoane
           input-person
           preconditii-person-lista
           output-
           postconditii-

        """
        id, nume, adresa = Persons.citire_person(self)
        ok = True
        for i in range(0, len(person)):
            if person[i].id == id:
                ok = False
        if ok:
            person.append(Persons(id, nume, adresa))
        else:
            return 0

    def name_generator(self, chars_high=string.ascii_uppercase,chars_low=string.ascii_lowercase):
        """"
            Functie care genereaza un nume random
            input-
            preconditii-
            output-nume generat
            postconditii-numele generat sa fie cu litera mare prima litera si restul literelor litere mici

        """
        size = random.randint(2, 10)
        return ''.join(random.choice(chars_high) if _ == 0 else random.choice(chars_low) for _ in range(size))

    def number_generator(self,person):
        """"
        Functie care genereaza un numar random
        input-person
        preconditii-lista
        output-a
        postconditii-a-numar intreg diferit de id-urile de la restul evenimentelor

                """
        ok = True
        while ok:
            a = random.randint(1,100)
            for i in range(0, len(person)):
                if a == person[i].id:
                    ok = False
            if ok == True:
                break
        return a

    def add_person_random(self,person):
        """"

         Functie care adauga persoane random in lista de persoane
         input-person
         preconditii-lista
         output-
         postconditii-

        """
        while True:
            x = input("Numarul de persoane:")
            try:
                x = int(x)
                break
            except ValueError:
                print("Valoarea introdusa nu este un intreg, va rugam reintroduceti")
        for i in range(0, x):
            id = Persons.number_generator(self,person)
            name = Persons.name_generator(self)
            adress = Persons.name_generator(self)
            person.append(Persons(id, name, adress))

    def print_person(self,person):
        """
               Functie care printeaza lista de persoane
               input-
               preconditii-
               output-id,nume,adresa
               postconditii-

               """
        if len(person) > 0:
            for i in range(0, len(person)):
                print(person[i].id, person[i].nume, person[i].adresa)
                # print(person[i].id, person[i].nume, person[i].adresa, person[i].evenimente)
        else:
            print("EMPTY LIST")

    def sterge_lista(self,lista):
        """
                  Functie care sterge un element dat din lista
                  input-lista
                  preconditii-lista-lista
                  output-lista schimbata
                  postconditii-

        """
        poz = 0
        while True:
            poz = input("Pozitia:")
            try:
                poz = int(poz)
                break
            except ValueError:
                print("Valoarea introdusa nu este un nume, va rugam reintroduceti")
        if poz > len(lista) - 1:
            print("Imposibil")
        else:
            del lista[poz]

    def modifica_person(self,person):
        """
                  Functie care modifica lista de persoane
                  input-person
                  preconditii-person-lista
                  output-lista schimbata
                  postconditii-

        """

        #id1, nume1, adresa1 = Persons.citire_person(self)
        while True:
            id1 = input("Id:")
            try:
                id1 = int(id1)
                break
            except ValueError:
                print("Valoarea introdusa nu este un intreg, va rugam reintroduceti")
        id2, nume2, adresa2 = Persons.citire_person(self)
        ok = True
        for i in range(0,len(person)):
            if person[i].id == id2:
                ok = False
        if ok == True:
            for i in range(0, len(person)):
                if person[i].id == id1: #and person[i].nume == nume1 and person[i].adresa == adresa1:
                    person[i].id = id2
                    person[i].nume = nume2
                    person[i].adresa = adresa2
            return 0
        else:
            return -1


class Events:
    #event = []
    def __init__(self, id, data, time, description):
        self.id = id
        self.data = data
        self.timp = time
        self.descriere = description
        self.nrparticipanti = 0

    def citire_event(self):
        """
               Functie care citeste toate elementele atribuite unui eveniment
               input-
               preconditii-
               output-id,nume,adresa
               postconditii-

        """
        while True:
            id = input("Id:")
            try:
                id = int(id)
                break
            except ValueError:
                print("Valoarea introdusa nu este un intreg, va rugam reintroduceti")
        while True:
            data = input("Data:")
            try:
                data = int(data)
                break
            except ValueError:
                print("Valoarea introdusa nu este un nume, va rugam reintroduceti")
        while True:
            timp = input("Timp:")
            try:
                timp = int(timp)
                break
            except ValueError:
                print("Valoarea introdusa nu este un nume, va rugam reintroduceti")
        while True:
            descriere = input("Descriere:")
            try:
                descriere = str(descriere)
                break
            except ValueError:
                print("Valoarea introdusa nu este o propozitie, va rugam reintroduceti")
        return id, data, timp, descriere

    def add_event(self,event):
        """
               Functie care adauga un eveniment nou la lista de evenimente
               input-event
               preconditii-event-lista
               output-
               postconditii-

        """
        id, data, timp, descriere = Events.citire_event(self)
        ok = True
        for i in range(0, len(event)):
            if event[i].id == id:
                ok = False
        if ok:
            event.append(Events(id, data, timp, descriere))
        else:
            return 0

    def name_generator(self, chars_high=string.ascii_uppercase,chars_low=string.ascii_lowercase):
        """"
                               Functie care genereaza un nume random
                               input-
                               preconditii-
                               output-numele generat
                               postconditii-numele generat sa fie cu prima litera mare si restul literelor mici

                """
        size = random.randint(2, 10)
        return ''.join(random.choice(chars_high) if _ == 0 else random.choice(chars_low) for _ in range(size))

    def number_generator(self,event):
        """"
                       Functie care genereaza un id random
                       input-event
                       preconditii-lista
                       output-a
                       postconditii-a-numar intreg diferit de id-urile de la restul evenimentelor

        """
        ok = True
        while ok:
            a = random.randint(1,100)
            for i in range(0, len(event)):
                if a == event[i].id:
                    ok = False
            if ok == True:
                break
        return a
    def number_generator_2(self):
        """"
               Functie care genereaza un numar random
               input-
               preconditii-
               output-
               postconditii

               """
        a = random.randint(1,100)
        return a

    def add_event_random(self,event):
        """"
        Functie care adauga evenimente random in lista de evenimente
        input-event
        preconditii-lista
        output-
        postconditii

        """
        while True:
            x = input("Numarul de evenimente:")
            try:
                x = int(x)
                break
            except ValueError:
                print("Valoarea introdusa nu este un intreg, va rugam reintroduceti")
        for i in range(0, x):
            id = Events.number_generator(self,event)
            data = Events.number_generator_2(self)
            timp = Events.number_generator_2(self)
            descriere = Events.name_generator(self)
            event.append(Events(id, data, timp, descriere))

    def print_event(self,event):
        """
                  Functie care printeaza lista de evenimente
                  input-event
                  preconditii-event-lista
                  output-
                  postconditii-

        """
        if len(event) > 0:
            for i in range(0, len(event)):
                print(event[i].id, event[i].data, event[i].timp, event[i].descriere)
        else:
            print("EMPTY LIST")

    def sterge_lista(self,lista):
        """
                  Functie care sterge un element dat din lista
                  input-lista
                  preconditii-lista-lista
                  output-lista schimbata
                  postconditii-

        """
        poz = 0
        while True:
            poz = input("Pozitia:")
            try:
                poz = int(poz)
                break
            except ValueError:
                print("Valoarea introdusa nu este un nume, va rugam reintroduceti")
        if poz > len(lista) - 1:
            print("Imposibil")
        else:
            del lista[poz]

    def modifica_event(self,event):
        """
                     Functie care modifica lista de evenimente
                     input-event
                     preconditii-event-lista
                     output-lista schimbata
                     postconditii-

        """
        #id1, data1, timp1, descriere1 = Events.citire_event(self)
        while True:
            id1 = input("Id:")
            try:
                id1 = int(id1)
                break
            except ValueError:
                print("Valoarea introdusa nu este un intreg, va rugam reintroduceti")
        id2, data2, timp2, descriere2 = Events.citire_event(self)
        ok = True
        for i in range(0, len(event)):
            if event[i].id == id2:
                ok = False
        if ok == True:
            for i in range(0, len(event)):
                if event[i].id == id1: #and event[i].data == data1 and event[i].timp == timp1 and event[i].descriere == descriere1:
                    event[i].id = id2
                    event[i].data = data2
                    event[i].timp = timp2
                    event[i].descriere = descriere2
            return 0
        else :
            return -1

