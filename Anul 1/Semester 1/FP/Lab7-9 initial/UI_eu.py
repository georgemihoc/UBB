from Controller_eu import *

class classUI(object):
    def __init__(self, ctrlPersoana, ctrlEveniment, ctrlAsign):
        self.ctrlPersoana = ctrlPersoana
        self.ctrlEveniment = ctrlEveniment
        self.ctrlAsign = ctrlAsign

    def run(self):
        person =[]
        event = []
        v = 0
        while int(v)!= 17:
            while True:
                v = input("1.Adaugati persoana in lista \n"
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
                         "12.Tipariti lista de evenimente la care participă o persoană ordonat alfabetic după descriere, după dată  \n"
                         "13.Afisati persoanele care participa la cele mai multe evenimente \n"
                         "14.Tipariti primele 20% evenimente cu cei mai mulți participanți (descriere, număr participanți) \n"
                         "15.Adaugare persoane random \n"
                         "16.Adaugare evenimente random \n"
                         "17.Exit")
                try:
                    v = int(v)
                    break
                except ValueError:
                    print("Comanda introdusa nu exista")

            if v==1:
                if PersonController.add_person(self,person) == 0:
                   print("Exista deja o persoana cu acest id")
            #if v==1:

            elif v==2:
                if EventController.add_event(self,event) == 0:
                    print("Exista deja un event cu acest id")
            elif v==3: PersonController.print_person(self,person)
            elif v==4: EventController.print_event(self,event)
            elif v==5: PersonController.sterge_lista(self,person)
            elif v==6: EventController.sterge_lista(self,event)
            elif v==7:
                a= PersonController.modifica_person(self,person)
                if a== -1:
                    print("Persoana nu a putut fi modificata deoarece exista deja o persoana cu acest id")
            elif v==8:
                a = EventController.modifica_event(self,event)
                if a == -1 :
                    print("Evenimentul nu a putut fi modidicat deoarece exista deja un eveniment cu acest id")
            elif v==9: PersonController.cautare_persoane(self,person)
            elif v==10: EventController.cautare_event(self,event)
            elif v==11:
                y = PersonEventController.inscriere_eveniment(self,person,event)
                if y == 0: print("Persoana este deja inscrisa la eveniment")
                elif y == -1: print("Evenimentul nu exista")
                elif y == -2 or y == -3 : print("Persoana cu acest id nu exista")
            elif v==12:
                x = PersonController.sortare_lista_evenimente(self,person)
                if  x == -1:
                    print("Persoana cu acest id nu exista")
                elif x == 0:
                    print("Persoana cu acest id nu este inscrisa la niciun eveniment")
                else:
                    print(x)
            elif v==13:
                lista1 = PersonController.persoane_multe_evenimente(self,person)
                print (lista1)
            elif v==14:
                lista2 = PersonEventController.evenimente_participanti(self,person,event)
                if lista2 == -1:
                    print("Nu exista evenimente care au participanti")
                else:
                    print(lista2)
            elif v==15:
                PersonController.add_person_random(self,person)
            elif v==16:
                EventController.add_event_random(self,event)
            elif v!=17:
                print("Comanda introdusa nu exista")
        if v == 17:
            print("Exit")