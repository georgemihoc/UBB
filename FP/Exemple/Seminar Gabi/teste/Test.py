from validare.Validator import SalaValidator
from model.Sala import Sala
from model.Prof import Prof
from model.Asignare import Asignare
from errors.Errors import ValidError,RepoError
from repo.Repository import Repository
class Test(object):

    
    def __init__(self):
        self.__sid = 34
        self.__nume = "L001"
        self.__capacitate =30
        self.__sala = Sala(self.__sid,self.__nume,self.__capacitate)
        self.__bsid = -34
        self.__bnume = ""
        self.__bcapacitate =-30
        self.__bsala = Sala(self.__bsid,self.__bnume,self.__bcapacitate)
        self.__pid = 45
        self.__pnume = "0100Est"
        self.__valoare = 9000.1
        self.__prof = Prof(self.__pid,self.__pnume,self.__valoare)
        self.__sid = 34
        self.__pid = 45
        self.__start_ora = "12:45"
        self.__finish_ora = "14:45"
        self.__detalii = "awesome stuff"
        self.__asign = Asignare(self.__sid,self.__pid,self.__start_ora,self.__finish_ora,self.__detalii)
        
        self.__validator = SalaValidator()
        self.__repo = Repository()
    
    
    
    def __testModel(self):
        assert self.__sala.get_nume() == self.__nume
    
    
    def __testValid(self):
        try:
            self.__validator.valideazaSala(self.__sala)
            assert True
        except ValidError:
            assert False
        try:
            self.__validator.valideazaSala(self.__bsala)
            assert False
        except ValidError as ve:
            assert str(ve)=="id invalid!\nnume invalid!\ncapac invalida!\n"
    

    def __testRepo(self):
        assert len(self.__repo)==0
        try:
            self.__repo.cauta(self.__bsala)
            assert False
        except RepoError as re:
            assert str(re)=="elem inexistent!"
        self.__repo.adauga(self.__sala)
        assert len(self.__repo)==1
        cheieSala = Sala(self.__sid,None,None)
        sala = self.__repo.cauta(cheieSala)
        assert sala == self.__sala
        try:
            self.__repo.adauga(self.__sala)
            assert False
        except RepoError as re:
            assert str(re)=="elem existent!"
        
        
    
    def ruleazaTeste(self):
        self.__testModel()
        self.__testValid()
        self.__testRepo()
    



