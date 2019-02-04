from validator import *
from errors import *
from Jucator import *
from repository import *

class Test(object):
    def __init__(self):
        self.__nume = "abc"
        self.__prenume = "Abc"
        self.__inaltime = 2
        self.__post = "Fundas"
        self.__jucator = Jucator(self.__nume, self.__prenume, self.__inaltime, self.__post)

    def __testRepo(self):
        assert len(self.__repo) == 0
        try:
            self.__jucator.cauta(self.__jucator)
            assert False
        except RepoError as re:
            assert str(re) == "Element inexistent!"
            assert len(self.__jucator) == 0

        cheieJucator = Jucator(self.__nume, None, None,None)
        jucator = self.__jucator.cauta(cheieJucator)
        assert jucator == self.__jucator
        try:
            self.__jucator.adauga(self.__jucator)
            assert False
        except RepoError as re:
            assert str(re) == "Element existent!"
    def ruleaza_teste(self):
        pass
    def ruleazaTeste(self):
        self.__testRepo()
