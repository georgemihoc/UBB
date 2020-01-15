from controllers import *
from errors import *
class Console(object):
    def __init__(self,ctrlProdus):
        self.ctrlProdus = ctrlProdus

    def __uiAddProdus(self,params):
        """
             Functie care adauga un produs nou in  lista de produse
             input-params
             preconditii-
             output-
             postconditii-

        """
        if len(params)!= 3:
            print("nr params invalid")
            return
        id = int(params[0])
        nume = params[1]
        pret = int(params[2])
        self.ctrlProdus.adaugaProdus(id,nume,pret)

    def __uiPrintProdus(self, params):
        """
             Functie care printeaza lista de produse
             input-params
             preconditii-
             output-
             postconditii-

        """
        if len(params) > 0:
            print("nr params invalid!")
            return

        produs = self.ctrlProdus.getAllProdus()
        if len(produs) > 0:
            for p in produs:
                print(p)
        else:
            print("EMPTY LIST!")
    def __uiStergeProdus(self,params):
        """
             Functie care adauga sterge un produs din lista de produse
             input-params
             preconditii-
             output-
             postconditii-
        """

        if len(params) != 1:
            print("nr params invalid")
            return
        cifra = params[0]
        self.ctrlProdus.stergeProdus(cifra)

    def __uiUndoStergere(self,params):
        """
        Functie care face undo la ultima operatie de stergere
        input-params
        preconditii-params-lista de parametrii
        output-
        postconditii
        """
        if len(params) >0:
            print("nr params invalid")
            return
        self.ctrlProdus.undoStergere()

    def run(self):
        print("1.Adaugati produse \n"
              "2.Printati produsele \n"
              "3.Sterge produse care au in id cifra introdusa \n"
              "4.Undo ultima operatie de stergere")
        comenzi = {"1":self.__uiAddProdus,
                   "2":self.__uiPrintProdus,
                   "3":self.__uiStergeProdus,
                   "4":self.__uiUndoStergere
        }
        cmd = 0
        while cmd!="exit":
            cmd = input()
            params = cmd.split(" ")
            if params[0] in comenzi:
                try :
                    comenzi[params[0]](params[1:])
                except ValueError:
                    print("Tip de data invalid")
                except ValidError as ve:
                    print("Validation exception:")
                    print(ve)
                except RepoError as re:
                    print("Repo Exception")
                    print(re)
            elif cmd !="exit":
                print("Comanda inexistenta")
        print("EXIT")



