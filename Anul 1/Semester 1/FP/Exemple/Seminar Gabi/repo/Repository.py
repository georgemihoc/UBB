from errors.Errors import RepoError
class Repository(object):
    
    
    def __init__(self):
        self.__elems = []

    
    def cauta(self,elem):
        pos = -1
        for i in range(len(self.__elems)):
            if self.__elems[i]==elem:
                pos = i
                break
        if pos == -1:
            raise RepoError("elem inexistent!")
        return self.__elems[pos]

    
    def adauga(self,elem):
        if elem in self.__elems:
            raise RepoError("elem existent!")
        self.__elems.append(elem)
    
    def __len__(self):
        return len(self.__elems)
    
    def getAll(self):
        return self.__elems[:]

    def sterge(self,elem):
        pos = -1
        for i in range(len(self.__elems)):
            if self.__elems[i]==elem:
                pos = i
                break
        if pos == -1:
            raise RepoError("elem inexistent!")
        del self.__elems[pos]

    def update(self,elem):
        pos = -1
        for i in range(len(self.__elems)):
            if self.__elems[i]==elem:
                pos = i
                break
        if pos == -1:
            raise RepoError("elem inexistent!")
        self.__elems[pos] = elem

    



