from validator import *
from errors import *
from Produs import *
from repository import *

class Test(object):
    def __init__(self):
        self.__pid = 1
        self.__nume = "Abc"
        self.__pret = 2
        self.__produs = Produs(self.__pid, self.__nume, self.__pret)

    def __testRepo(self):
        assert len(self.__repo) == 0
        try:
            self.__repo.cauta(self.__produs)
            assert False
        except RepoError as re:
            assert str(re) == "Element inexistent!"
            assert len(self.__repo) == 0
        cheieProdus = Produs(self.__pid, None, None)
        produs = self.__repo.cauta(cheieProdus)
        assert produs == self.__person
        try:
            self.__repo.adauga(self.__produs)
            assert False
        except RepoError as re:
            assert str(re) == "Element existent!"
    def ruleaza_teste(self):
        pass
    def ruleazaTeste(self):
        self.__testRepo()
