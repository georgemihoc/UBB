from Repository import *
class Test(object):
    def __init__(self):
        self.__id = 9
        self.__denumire = "ion"
        self.__autor = 7
        self.__nr = 1
        self.__opera = Opera(self.__id, self.__denumire, self.__autor, self.__nr)

        self.__bid = 9
        self.__bdenumire = "ion"
        self.__bautor = 7
        self.__bnr = 1
        self.__bopera = Opera(self.__bid, self.__bdenumire, self.__bautor, self.__bnr)

        self.__repo = OpereRepository(0)

    def __testModel(self):
        assert self.__person.get_nume() == self.__nume

    def ruleazaTeste(self):
        pass