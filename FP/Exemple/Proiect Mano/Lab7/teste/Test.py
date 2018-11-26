from validare.Validator import ElevValidator,ProblemaValidator, AsignValidator
from model.Elev import Elev
from model.Problema import Problema
from model.Asign import Asign
from errors.Errors import ValidError,RepoError
from repo.Repository import Repository

class Test(object):
   
    def __init__(self):
        self.__eid = 1
        self.__nume = "Ion"
        self.__grup = 7
        self.__elev = Elev(self.__eid,self.__nume,self.__grup)
        self.__beid = -34
        self.__bnume = ""
        self.__bgrup =-30
        self.__belev = Elev(self.__beid,self.__bnume,self.__bgrup)
        self.__lab = 2
        self.__desc = "Liste"
        self.__dl = 4
        self.__prob = Problema(self.__lab,self.__desc,self.__dl)
        self.__nota = 10
        self.__bnota = 0
        self.__validator = ElevValidator()
        self.__validator2 = ProblemaValidator()
        self.__validator3 = AsignValidator()
        self.__asignare = Asign(self.__eid,self.__lab,self.__nota)
        self.__basignare = Asign(self.__beid,self.__lab,self.__bnota)
        self.__repo = Repository() 
        
    
    def __testModel(self):
        assert self.__elev.get_nume() == self.__nume
    
    def __testValid(self):
        try:
            self.__validator.valideazaElev(self.__elev)
            assert True
        except ValidError:
            assert False
        try:
            self.__validator.valideazaElev(self.__belev)
            assert False
        except ValidError as ve:
            assert str(ve)=="id invalid!\nnume invalid!\ngrup invalid!\n"
            
        try:
            self.__validator3.valideazaAsign(self.__asignare)
            assert True
        except ValidError:
            assert False 
            
        try:
            self.__validator3.valideazaAsign(self.__basignare)
            assert False
        except ValidError as ve:
            assert str(ve)=="id elev invalid!\nnota invalida\n"
    
    def __testRepo(self):
        assert len(self.__repo)==0
        try:
            self.__repo.cauta(self.__belev)
            assert False
        except RepoError as re:
            assert str(re)=="elem inexistent!"
        self.__repo.adauga(self.__elev)
        assert len(self.__repo)==1
        cheieElev = Elev(self.__eid,None,None)
        elev = self.__repo.cauta(cheieElev)
        assert elev == self.__elev
        try:
            self.__repo.adauga(self.__elev)
            assert False
        except RepoError as re:
            assert str(re)=="elem existent!"      
    
    def ruleazaTeste(self):
        self.__testModel()
        self.__testValid()
        self.__testRepo()


