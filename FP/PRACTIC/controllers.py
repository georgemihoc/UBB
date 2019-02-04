from repository import *
from Jucator import *
class JucatorController(object):
    def __init__(self,repoJucator, validJucator):
        self.repoJucator = repoJucator
        self.validJucator = validJucator
    def adaugaJucator(self,nume, prenume, inaltime,post):
        """
          Functie care adauga un jucator in lista
          input-jucator
          preconditii-jucator-lista
          output-
          postconditii-

        """
        j = Jucator(nume,prenume,inaltime,post)
        self.validJucator.valideazaJucator(j)
        self.repoJucator.adaugare(j)
    def modificareInaltime(self,nume,prenume,inaltime):
        """
              Functie care adauga modifica inaltimea unui jucator
              input-jucator
              preconditii-jucator-lista
              output-
              postconditii-

        """
        self.repoJucator.modificare(nume,prenume,inaltime)
    def tiparireEchipa(self):
        """
             Functie care tipareste echipa formata din 2 fundasi 2 extreme 1 pivot
             input-
             preconditii-
             output-lista construita
             postconditii-lista-lista de jucatori cei mai inalti

        """
        jucatori = self.getAllJucator()
        a = int(2)
        b = int(2)
        c = int(1)
        lista = []
        jucatori.sort(key = lambda x: x.get_inaltime(), reverse = True)
        for jucator in jucatori:
            if jucator.get_post() == "Fundas" and a:
                a= a-1
                lista.append(jucator)
            if jucator.get_post() == "Extrema" and b:
                b = b-1
                lista.append(jucator)
            if jucator.get_post() == "Pivot" and c:
                c = c-1
                lista.append(jucator)
        return lista
    def importare(self):
        '''

                Functie care importa jucatori noi din alt fisier
                input-nume fisier
                preconditii-
                output-numarul jucatorilor importati
                postconditii-numar-nr intreg pozitiv
        '''
        nr = self.repoJucator.importare()
        return nr

    def getAllJucator(self):
        return self.repoJucator.getAll()

