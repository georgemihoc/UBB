from errors import *
from controllers import *
class Console(object):
    def __init__(self,ctrlJucator):
        self.ctrlJucator = ctrlJucator

    def __uiAddJucator(self,params):
        """
             Functie care adauga un jucator nou in  lista de jucatori
             input-params
             preconditii-
             output-
             postconditii-

        """
        if len(params)!= 4:
            print("nr params invalid")
            return
        nume = params[0]
        prenume = params[1]
        inaltime = int(params[2])
        post = params[3]
        self.ctrlJucator.adaugaJucator(nume,prenume,inaltime,post)

    def __uiPrintJucatori(self,params):
        """
             Functie care printeaza lista de jucatori
             input-params
             preconditii-
             output-
             postconditii-

        """
        if len(params) > 0:
            print("nr params invalid")
            return
        jucator = self.ctrlJucator.getAllJucator()
        if len(jucator)>0:
            for j in jucator:
                print(j)
        else:
            print("EMPTY LIST")

    def __uiModificareInaltime(self,params):
        """
             Functie care modifica inaltimea unui jucator
             input-params
             preconditii-
             output-
             postconditii-

        """
        if len(params) != 3:
            print("nr params invalid")
            return
        nume = params[0]
        prenume = params[1]
        inaltime = params[2]
        self.ctrlJucator.modificareInaltime(nume,prenume,inaltime)

    def __uiTiparire(self,params):
        """
             Functie care tipareste echipa formata din 2 fundasi 2 extreme 1 pivot
             input-params
             preconditii-
             output-
             postconditii-

        """
        if len(params) > 0:
            print("nr params invalid")
            return
        lista = self.ctrlJucator.tiparireEchipa()
        for elem in lista:
            print(elem)

    def __uiImport(self,params):
        """
             Functie care importa jucatori dintr-un alt fisier(date3.txt)
             input-params
             preconditii-
             output-
             postconditii-

        """
        if len(params) != 0:
            print("nr params invalid")
            return
        nr = self.ctrlJucator.importare()
        print("Au fost adaugati :", nr, "jucatori")



    def run(self):
        print("1.Adaugare jucator in lista \n"
              "2.Tipariti jucatorii \n"
              "3.Modificare de inaltime (se introduce nume,prenume,inaltime) doar inaltimea diferita \n"
              "(INALTIMEA TREBUIE SA FIE NR POZITIV)\n"
              "4.Tipariti echipa construita din jucatorii disponibili cu media de inaltime cea mai mare \n"
              "5.Importa jucatori din fisier (doar nume prenume in fisier si se genereaza aleator inaltimea si postul "
              "(daca mai exista un jucator cu acest nume si prenume aceasta nu se importa)"
              "LA FINAL, Se printeaza numarul de jucatori importati din acest fisier")
        comenzi = {"1":self.__uiAddJucator,
                   "2":self.__uiPrintJucatori,
                   "3":self.__uiModificareInaltime,
                   "4":self.__uiTiparire,
                   "5":self.__uiImport

        }
        cmd = 0
        while cmd != "exit":
            cmd = input()
            params = cmd.split(" ")
            if params[0] in comenzi:
                try:
                    comenzi[params[0]](params[1:])
                except ValueError:
                    print("Tip de data invalid")
                    print(ValueError)
                except ValidError as ve:
                    print("Validation exception:")
                    print(ve)
                except RepoError as re:
                    print("Repo Exception")
                    print(re)
            elif cmd != "exit":
                print("Comanda inexistenta")
        print("EXIT")
