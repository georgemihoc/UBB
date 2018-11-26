from Validator import PersonValidator, EventValidator, AsignValidator
from Person import *
from Event import *
from Asign import *
from Errors import ValidError, RepoError
from Repository import Repository


class Test(object):

    def __init__(self):
        self.__pid = 1
        self.__nume = "Ion"
        self.__adresa = 7
        self.__eid = 1
        self.__person = Person(self.__pid, self.__nume, self.__adresa)
        self.__bpid = -34
        self.__bnume = ""
        self.__badresa = -30
        self.__bperson = Person(self.__bpid, self.__bnume, self.__badresa)
        self.__id = 2
        self.__data = 5
        self.__timp = 4
        self.__desc = "Abc"
        self.__event = Event(self.__id, self.__data, self.__timp, self.__desc)
        self.__bpid = 1
        self.__beid = 1
        self.__validator = PersonValidator()
        self.__validator2 = EventValidator()
        self.__validator3 = AsignValidator()
        self.__asignare = Asign(self.__pid, self.__eid)
        self.__basignare = Asign(self.__bpid, self.__beid)
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
            self.__validator.valideazaPerson(self.__bperson)
            assert False
        except ValidError as ve:
            assert str(ve) == "id invalid!\nnume invalid!\nadresa invalida!\n"

        try:
            self.__validator3.valideazaAsign(self.__asignare)
            assert True
        except ValidError:
            assert False

        try:
            self.__validator3.valideazaAsign(self.__basignare)
            assert False
        except ValidError as ve:
            assert str(ve) == "id persoana invalid!\nid event invalid\n"

    def __testRepo(self):
        assert len(self.__repo) == 0
        try:
            self.__repo.cauta(self.__bperson)
            assert False
        except RepoError as re:
            assert str(re) == "elem inexistent!"
        self.__repo.adauga(self.__person)
        assert len(self.__repo) == 1
        cheiePerson = Person(self.__pid, None, None)
        person = self.__repo.cauta(cheiePerson)
        assert person == self.__person
        try:
            self.__repo.adauga(self.__person)
            assert False
        except RepoError as re:
            assert str(re) == "elem existent!"
    def ruleaza_Teste(self):
        pass


    def ruleazaTeste(self):
        self.__testModel()
        self.__testValid()
        self.__testRepo()


