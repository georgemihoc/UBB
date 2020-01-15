from Opere import *
class OpereRepository(object):
    def __init__(self,filename):
        self.__elems = []
        self.__filename = filename

    def cauta(self,elem):
        '''
        Functie care cauta un element in lista

        '''
        ok = 0
        file = open("date_opere.txt","r")
        for line in file:
            if line != '\n':
                opera = self.__createOpera(line)
                if int(opera.id) == int(elem.id):
                    elem2 = opera
                    ok = 1
        file.close()
        if ok == 0:
            raise RepoError("Element inexistent!")
        return elem2

    def __createOpera(self, line):
        '''
                Functie care creaza o opera dintr-o linie

                '''
        if line != '\n':
            fields = line.strip().split(",")
            st = Opera(int(fields[0]), fields[1], fields[2], fields[3])
            return st

    def __len__(self):
        return len(self.__elems)

    def getAll(self):

        lista = []
        file = open("date_opere.txt","r")
        for line in file:
            line = self.__createOpera(line)
            lista.append(line)
        return lista

class OpereFileRepository(OpereRepository):
    def __init__(self,filename):
        self.__filename = filename
        OpereRepository.__init__(self, self.__filename)

    def __createOpera(self,line):
        fields = line.split(" ")
        st = Opera(int(fields[0]), fields[1], fields[2], fields[3])
        return st

    def __loadFromFile(self):
        f = open(self.__filename)
        for line in f:
            if line.strip() == "":
                continue
            p = self.__createOpera(line)
            Repository.adauga(self, p)
        f.close()
