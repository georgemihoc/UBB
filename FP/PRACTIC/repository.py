from Jucator import *
from errors import *
import random
class JucatorRepository(object):

    def __init__(self,filename,filename2):
        self.__elems = []
        self.__filename = filename
        self.__filename2 = filename2

    def __createJucator(self, line):
        """
        Functie care creeaza un jucator dintr-o linie a fisierului
        input- line-
        preconditii- linie-linie din fisier
        output- st
        postconditii- st jucator
        """
        if line != '\n':
            fields = line.strip().split(" ")
            #print (fields[3])
            st = Jucator(fields[0], fields[1], int(fields[2]), fields[3])
        return st

    def adauga(self, elem):
        '''
              Functie care adauga un jucator in lista
              input-elem
              preconditii-produs-lista elem- jucator
              output-Raise repo error daca este
              postconditii-

        '''
        file = open(self.__filename,"r+")
        ok = False
        for line in file:
            if line != "\n":
                jucator = self.__createJucator(line)
                if elem == jucator:
                    ok = True
        file.close()

        if ok == False:
            file = open(self.__filename, "a")
            line = str(elem.get_nume()) + " " + str(elem.get_prenume()) + " " + str(elem.get_inaltime()) + " " + str(elem.get_post()) + " "
            #file.write("\n")
            file.write(line + '\n')
            file.close()
        else:
            raise RepoError("Element existent!")

    def modificare(self,nume,prenume,inaltime):
        '''

        Functie care modifica inaltimea jucatorilor din date.txt
        input-
        preconditii-
        output-
        postconditii-
        '''
        file = open(self.__filename, "r+")
        file2 = open(self.__filename2,"w")
        ok = False
        for line in file:
            jucator = self.__createJucator(line)
            nume1 = str(jucator.get_nume())
            prenume1 = str(jucator.get_prenume())
            post = str(jucator.get_post())
            if nume1== nume and prenume1 == prenume:
                line2=str(nume)+ " " + str(prenume) + " " +str(inaltime) + " " + str(post) + '\n'
                file2.write(line2)
                ok = True
            else:
                file2.write(line)
        file.close()
        file2.close()

        file = open(self.__filename,"w")
        file2 = open(self.__filename2,"r")
        for line in file2:
            file.write(line)
        file.close()
        file2.close()

    def importare(self):
        '''

            Functie care importa jucatori noi din alt fisier
            input-nume fisier
            preconditii-
            output-numarul jucatorilor importati
            postconditii-numar-nr intreg pozitiv
        '''
        file = open(self.__filename, "a")
        file2 = open("date3.txt", "r")
        jucatori = self.getAll()
        ok = True
        numar = int(0)
        for line in file2:
            if line != '\n':
                ok = True
                fields = line.strip().split(" ")
                for jucator in jucatori:
                    if jucator.get_nume() == fields[0] and jucator.get_prenume() == fields[1]:
                        ok = False
                if ok == True:
                    inaltime = random.randint(170,250)
                    post=random.randint(1,3)
                    if post == 1:
                        post = "Fundas"
                    elif post == 2:
                        post = "Extrema"
                    else:
                        post = "Pivot"
                    file.write(fields[0] + " " + fields[1]+ " "+ str(inaltime) + " " + str(post) + '\n')
                    numar += 1
        return numar


    def getAll(self):
        '''
        Functie care culege toate valorile din fisier si creeaza o lista cu ele
        input-
        preconditii-
        output- lista
        postconditii-lista- o lista de jucatori
        '''

        file = open(self.__filename,"r")
        lista = []
        for line in file:
            jucator = self.__createJucator(line)
            lista.append(jucator)
        return lista

class JucatorFileRepository(JucatorRepository):
    def __init__(self,filename,filename2):
        '''
            Functie care intitializeaza repository-ul
            input-filename1 filename2
            preconditii-
            output-
            postconditii-
        '''
        self.__filename = filename
        self.__filename2 = filename2
        JucatorRepository.__init__(self,self.__filename, self.__filename2)

    def adaugare(self, j):
        '''
        Functie care adauga in fisier un element p
        '''
        JucatorRepository.adauga(self, j)
