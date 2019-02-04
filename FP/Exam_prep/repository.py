from Produs import *
from errors import *
class ProdusRepository(object):

    def __init__(self,filename,filename2):
        self.__elems = []
        self.__filename = filename
        self.__filename2 = filename2

    def __createProdus(self, line):
        """
        Functie care creeaza un produs dintr-o linie a fisierului
        input- line-
        preconditii- linie-linie din fisier
        output- st
        postconditii- st produs
        """
        if line != '\n':
            fields = line.strip().split(" ")
            st = Produs(int(fields[0]), fields[1], fields[2])
        return st

    def adauga(self, elem):
        '''
              Functie care adauga o produs in lista
              input-elem
              preconditii-produs-lista elem- produs
              output-
              postconditii-

        '''
        file = open(self.__filename,"r+")
        ok = False
        for line in file:
            if line != "\n":
                produs = self.__createProdus(line)
                if elem == produs:
                    ok = True
        file.close()

        if ok == False:
            file = open(self.__filename, "a")
            line = str(elem.get_pid()) + " " + str(elem.get_nume()) + " " + str(elem.get_pret())
            #file.write("\n")
            file.write(line + '\n')
            file.close()
        else:
            raise RepoError("Element existent!")

    def sterge(self,cifra):
        '''

        Functie care sterge niste elemente din fiserul date.txt
        input- cifra
        preconditii- cifra cifra 0-9
        output-
        postconditii-
        '''
        file = open(self.__filename, "r+")
        file2 = open(self.__filename2,"w")
        file3 = open("date3.txt", "w")
        ok = 0
        for line in file:
            produs = self.__createProdus(line)
            file3.write(line)
            idul = str(produs.get_pid())
            if cifra in idul:
                ok = 1
            else:
                file2.write(line)
        file.close()
        file2.close()
        file3.close()

        file = open(self.__filename,"w")
        file2 = open(self.__filename2,"r")
        for line in file2:
            file.write(line)
        file.close()
        file2.close()

    def undo(self):
        file = open(self.__filename, "w")
        file2= open("date3.txt","r")
        for line in file2:
            file.write(line)
        file.close()
        file2.close()


    def getAll(self):
        '''
        Functie care culege toate valorile din fisier si creeaza o lista cu ele
        input-
        preconditii-
        output- lista
        postconditii-lista- o lista de produse
        '''

        file = open(self.__filename,"r")
        lista = []
        for line in file:
            produs = self.__createProdus(line)
            lista.append(produs)
        return lista

class ProdusFileRepository(ProdusRepository):
    def __init__(self,filename,filename2):
        self.__filename = filename
        self.__filename2 = filename2
        ProdusRepository.__init__(self,self.__filename, self.__filename2)

    def adaugare(self, p):
        '''
        Functie care adauga in fisier un element p
        '''
        ProdusRepository.adauga(self, p)

    def stergere(self,cifra):
        '''
        Functie care sterge anume elemente din fisier
        :param cifra:
        :return:
        '''
        ProdusRepository.sterge(self,cifra)

    def undo(self):
        ProdusRepository.undo(self)