from UI_eu import *
from Controller_eu import *
from Repository_eu import *

class Test(object):

    def __init__(self):
        self.__pid = 34
        self.__pnume = "Mihai"
        self.__padresa = "abc"
        self.__person= Persons(self.__pid, self.__pnume, self.__padresa)
        self.__pid = -30
        self.__pnume = "Andrei"
        self.__padresa = "abc"
        self.__person = Persons(self.__pid, self.__pnume, self.__padresa)
        self.__pid = 100
        self.__pnume = "Stefan"
        self.__padresa = "abc"
        self.__person = Persons(self.__pid, self.__pnume, self.__padresa)
        self.__sid = 34
        self.__pid = 45
        self.__data = "16.10"
        self.__timp = "19:25"
        self.__descrier = "eveniment"
        self.__asign = Asignare(self.__sid, self.__pid, self.__data, self.__timp, self.__descriere)

        self.__validator = PersonValidator()
        self.__repo = Repository()

    def __testModel(self):
        assert self.__person.get_nume() == self.__nume

    def __testValid(self):
        try:
            self.__validator.valideazaPerson(self.__person)
            assert True
        except ValidError:
            assert False
        try:
            self.__validator.valideazaPerson(self.__bPerson)
            assert False
        except ValidError as ve:
            assert str(ve) == "id invalid!\nnume invalid!\nadresa invalida!\n"

    def __testRepo(self):
        assert len(self.__repo) == 0
        try:
            self.__repo.cauta(self.__person)
            assert False
        except RepoError as re:
            assert str(re) == "Persoana inexistent!"
        self.__repo.adauga(self.__person)
        assert len(self.__repo) == 1
        cheiePerson = Person(self.__sid, None, None)
        person = self.__repo.cauta(cheiePerson)
        assert person == self.__person
        try:
            self.__repo.adauga(self.__person)
            assert False
        except RepoError as re:
            assert str(re) == "Eveniment existent!"

    def ruleaza_teste(self):
        pass

    def ruleazaTeste(self):
        self.__testModel()
        self.__testValid()
        self.__testRepo()
