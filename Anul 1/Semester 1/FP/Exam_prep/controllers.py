from repository import *
from Produs import *
class ProdusController(object):
    def __init__(self,repoProdus, validProdus):
        self.repoProdus = repoProdus
        self.validProdus = validProdus
    def adaugaProdus(self,id, nume, pret):
        """
          Functie care adauga o produs in lista
          input-produs
          preconditii-produs-lista
          output-
          postconditii-

        """
        p = Produs(id,nume,pret)
        self.validProdus.valideazaProdus(p)
        self.repoProdus.adaugare(p)

    def stergeProdus(self,cifra):
        """
          Functie care sterge un  produs in lista
          input-produs
          preconditii-produs-lista
          output-
          postconditii-

        """
        self.repoProdus.stergere(cifra)

    def undoStergere(self):
        """
        Functie care face undo la ultima operatie de stergere
        input
        :return:
        """
        self.repoProdus.undo()

    def getAllProdus(self):
        return self.repoProdus.getAll()

