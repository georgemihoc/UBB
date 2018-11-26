from model.Sala import Sala
class SaliController(object):
    
    
    def __init__(self, repoSali,validSala):
        self.repoSali = repoSali
        self.validSala = validSala
    
    
    def adaugaSala(self,ident,nume,capac):
        s = Sala(ident,nume,capac)
        self.validSala.valideazaSala(s)
        self.repoSali.adauga(s)
        
    def getAllSali(self):
        return self.repoSali.getAll()
        


class ProfiController(object):
    
    
    def __init__(self, repoProfi):
        self.repoProfi = repoProfi
    
    



class AsignController(object):
    
    
    def __init__(self, repoSali, repoProfi, repoAsign):
        self.repoSali = repoSali
        self.repoProfi = repoProfi
        self.repoAsign = repoAsign
    
    



