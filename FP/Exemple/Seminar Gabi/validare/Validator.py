from errors.Errors import ValidError
class SalaValidator(object):
    
    
    def valideazaSala(self,sala):
        erori=""
        if sala.get_sid()<0:
            erori+="id invalid!\n"
        if sala.get_nume()=="":
            erori+="nume invalid!\n"
        if sala.get_capacitate()<0 or sala.get_capacitate()>100:
            erori+="capac invalida!\n"
        if len(erori)>0:
            raise ValidError(erori)