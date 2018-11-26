from Errors import ValidError, RepoError
from Controllers import *

class Console(object):

    def __init__(self, ctrlPerson, ctrlEvent, ctrlAsign):
        self.ctrlPerson = ctrlPerson
        self.ctrlEvent = ctrlEvent
        self.ctrlAsign = ctrlAsign

    def __uiAddPerson(self, params):
        """
                                     Functie care adauga o persoana in lista
                                     input-person, event, lista
                                     preconditii-person,event,lista-lista
                                     output-
                                     postconditii-

               """
        if len(params) != 3:
            print("nr params invalid!")
            return
        ident = int(params[0])
        nume = params[1]
        adresa = params[2]
        self.ctrlPerson.adaugaPerson(ident, nume, adresa)

    def __uiPrintPerson(self, params):
        """
                                     Functie care printeaza lista de persoane
                                     input-person, event, lista
                                     preconditii-person,event,lista-lista
                                     output-
                                     postconditii-

               """
        if len(params) > 0:
            print("nr params invalid!")
            return
        person = self.ctrlPerson.getAllPerson()
        if len(person) > 0:
            for e in person:
                print(e)
        else:
            print("EMPTY LIST!")

    def __uiDeletePerson(self, params):
        """
                                     Functie care sterge o persoana din lista
                                     input-person, event, lista
                                     preconditii-person,event,lista-lista
                                     output-
                                     postconditii-

               """
        if len(params) != 1:
            print("Nr parametrii invalid!")
            return
        ident = int(params[0])
        nume = "Nume"
        adresa = 1
        self.ctrlPerson.stergePerson(ident, nume, adresa)

    def __uiUpdatePerson(self, params):
        """
                                     Functie care modifica un element din lista de persoane
                                     input-person, event, lista
                                     preconditii-person,event,lista-lista
                                     output-
                                     postconditii-

               """
        if len(params) != 3:
            print("Nr parametrii invalid!")
            return
        ident = int(params[0])
        nume = params[1]
        adresa = params[2]
        self.ctrlPerson.modificaPerson(ident, nume, adresa)

    def __uiAddEvent(self, params):
        """
                                     Functie care adauga un eveniment in lista de evenimente
                                     input-person, event, lista
                                     preconditii-person,event,lista-lista
                                     output-
                                     postconditii-

               """
        if len(params) != 4:
            print("Nr parametrii invalid!")
            return
        id = int(params[0])
        data = int(params[1])
        timp = int(params[2])
        desc = params[3]
        self.ctrlEvent.adaugaEvent(id, data,timp, desc)

    def __uiPrintEvent(self, params):
        """
                                     Functie care printeaza lista de evenimente
                                     input-person, event, lista
                                     preconditii-person,event,lista-lista
                                     output-
                                     postconditii-

               """
        if len(params) > 0:
            print("Nr parametrii invalid!")
            return
        event = self.ctrlEvent.getAllEvent()
        if len(event) > 0:
            for p in event:
                print(p)
        else:
            print("EMPTY LIST!")

    def __uiDeleteEvent(self, params):
        """
                                     Functie care sterge un eveniment din lista
                                     input- event, lista
                                     preconditii-person,event,lista-lista
                                     output-
                                     postconditii-

               """
        if len(params) != 1:
            print("Nr parametrii invalid!")
            return
        id = int(params[0])
        data = "Nume"
        timp = 1
        desc = "Descriere"
        self.ctrlEvent.stergeEvent(id, data, timp, desc)

    def __uiUpdateEvent(self, params):
        """
                                     Functie care modifica un element din lista de evenimente
                                     input-person, event, lista
                                     preconditii-person,event,lista-lista
                                     output-
                                     postconditii-

               """
        if len(params) != 4:
            print("Nr parametrii invalid!")
            return
        id = int(params[0])
        data = params[1]
        timp = int(params[2])
        desc = int(params[3])
        self.ctrlEvent.modificaEvent(id, data, timp,desc)


    def __uiRandomPerson(self, params):
        """
                                     Functie care inscrie persoane random in lista
                                     input-person, event, lista
                                     preconditii-person,event,lista-lista
                                     output-
                                     postconditii-

               """
        if len(params) != 1:
            print("Nr parametrii invalid!")
            return
        self.ctrlPerson.randomPerson(int(params[0]))

    def __uiRandomEvent(self, params):
        """
                                     Functie care inscrie evenimente random in lista
                                     input-person, event, lista
                                     preconditii-person,event,lista-lista
                                     output-
                                     postconditii-

               """
        if len(params) != 1:
            print("Nr parametrii invalid!")
            return
        self.ctrlEvent.randomEvent(int(params[0]))

    def __uiCautaPerson(self, params):
        """
                            Functie care cauta o persoana anume in lista de persoane dupa id
                            input-person
                            preconditii-person-lista
                            output-
                            postconditii-

        """
        if len(params) != 1:
            print("Nr parametrii invalid!")
            return
        a = self.ctrlPerson.cautaPerson(int(params[0]))
        if a:
            print(a)

    def __uiCautaEvent(self, params):
        """
                                Functie care cauta un eveniment anume in lista de evenimente dupa id
                                input-event
                                preconditii-event-lista
                                output-
                                postconditii-

                """
        if len(params) != 1:
            print("Nr parametrii invalid!")
            return
        a = self.ctrlEvent.cautaEvent(int(params[0]))
        if a:
            print(a)
    def __uiInscriere(self,params):
        """
                              Functie care inscrie o persoana  data la un eveniment dat
                              input-person, event, lista
                              preconditii-person,event,lista-lista
                              output-
                              postconditii-

        """
        if len(params) != 2:
            print("Nr parametrii invalid!")
            return
        pid = int(params[0])
        eid = int(params[1])
        self.ctrlAsign.inscriere(pid,eid)

    def __uiPrintInscrieri(self, params):
        """
                                     Functie care printeaza lista de inscrieri la evenimente
                                     input-person, event, lista
                                     preconditii-person,event,lista-lista
                                     output-
                                     postconditii-

               """
        if len(params) > 0:
            print("Nr parametrii invalid!")
            return
        a = self.ctrlAsign.getAllAsign()
        if len(a) > 0:
            for p in a:
                print(p)
        else:
            print("EMPTY LIST!")

    def __uiOrdonare(self,params):
        """
                                     Functie care ordoneaza lista de evenimente la care participa o anume persoana
                                     input-person, event, lista
                                     preconditii-person,event,lista-lista
                                     output-
                                     postconditii-

               """
        if len(params) != 1:
            print("Nr parametrii invalid!")
            return
        poz = params[0]
        poz = int(poz)
        a = self.ctrlAsign.getAllAsign()
        b = self.ctrlEvent.getAllEvent()
        final = self.ctrlAsign.Ordonare(a,b,poz)
        if len(final) != 0:
            for x in final:
                print(x)
        else:
            print("Imposibil")

    def __uiMostEvents(self,params):
        """
                                     Functie care tipareste persoanele care participa la cele mai multe evenimente
                                     input-person, event, lista
                                     preconditii-person,event,lista-lista
                                     output-
                                     postconditii-

               """
        if len(params) != 0:
            print("Nr parametrii invalid!")
            return

        # for i in range(0,1000):
        #   sir[i] = 0
        a = self.ctrlAsign.getAllAsign()
        b = self.ctrlEvent.getAllEvent()
        final = self.ctrlAsign.MostEvents(a,b)
        if len(final) != 0:
            for x in final:
                print(x)
        else:
            print("Imposibil")



    def __uiRaport(self,params):
        """
                                     Functie care tipareste primele 20% evenimente cu cele mai multe persoane inscrise
                                     input-person, event, lista
                                     preconditii-person,event,lista-lista
                                     output-
                                     postconditii-

               """
        if len(params) != 0:
            print("Nr parametrii invalid!")
            return
        a = self.ctrlAsign.getAllAsign()
        b = self.ctrlEvent.getAllEvent()
        nr = self.ctrlAsign.Raport(a,b)
        if nr != -1:
            for i in range(0, nr):
               print(b[i].desc," ",AsignController.nr_participanti(self,a,b,i))
        else:
            print("Imposibil")

    def __uiFunctionalitate(self,params):
        if len(params) != 0:
            print("Nr parametrii invalid!")
            return
        a=self.ctrlPerson.getAllPerson()
        b=self.ctrlEvent.getAllEvent()
        c=self.ctrlAsign.getAllAsign()
        lista = AsignController.Functionalitate(self,a,b,c)
        for i in lista:
            print(i)


    def run(self):
        print("1.Adaugati persoana in lista \n"
              "2.Adaugati eveniment in lista  \n"
              "2.Adaugati eveniment in lista  \n"
              "3.Printati lista de persoane \n"
              "4.Printati lista de evenimente \n"
              "5.Sterge element din lista de persoane(se da pozitia) \n"
              "6.Sterge element din lista de evenimente(se da pozitia) \n"
              "7.Modifica un element din lista de persoane(se da elementul si noile sale valori \n"
              "8.Modifica un element din lista de evenimente(se da elementul si noile sale valori \n"
              "9.Cauta o persoana dupa id \n"
              "10.Cauta un eveniment dupa id-ul sau \n"
              "11.Inscriere o persoana la un eveniment \n"
              "12.Afisati lista de inscrieri \n"
              "13.Tipariti lista de evenimente la care participă o persoană ordonata alfabetic după descriere, după dată  \n"
              "14.Afisati persoanele care participa la cele mai multe evenimente \n"
              "15.Tipariti primele 20% evenimente cu cei mai mulți participanți (descriere, număr participanți) \n"
              "16.Adaugare persoane random \n"
              "17.Adaugare evenimente random \n"
              "18.Functionalitate noua \n"
              "19.Exit")
        comenzi = {"1": self.__uiAddPerson,
                   "2": self.__uiAddEvent,
                   "3": self.__uiPrintPerson,
                   "4": self.__uiPrintEvent,
                   "5": self.__uiDeletePerson,
                   "6": self.__uiDeleteEvent,
                   "7": self.__uiUpdatePerson,
                   "8": self.__uiUpdateEvent,
                   "9": self.__uiCautaPerson,
                   "10": self.__uiCautaEvent,
                   "11": self.__uiInscriere,
                   "12": self.__uiPrintInscrieri,
                   "13": self.__uiOrdonare,
                   "14": self.__uiMostEvents,
                   "15": self.__uiRaport,
                   "16": self.__uiRandomPerson,
                   "17": self.__uiRandomEvent,
                   "18": self.__uiFunctionalitate}
        while True:
            cmd = input()
            params = cmd.split(" ")
            if cmd == "19":
                print("EXIT")
                return
            elif params[0] in comenzi:
                try:
                    comenzi[params[0]](params[1:])
                except ValueError:
                    print("Tip de data invalid!")
                except ValidError as ve:
                    print("Validation exception:")
                    print(ve)
                except RepoError as re:
                    print("Repo exception:")
                    print(re)

            else:
                print("Comanda inexistenta")