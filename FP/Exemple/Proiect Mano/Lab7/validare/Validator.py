from errors.Errors import ValidError
class ElevValidator(object):
    
    def valideazaElev(self,elev):
        erori=""
        if elev.get_eid()<0:
            erori+="id invalid!\n"
        if elev.get_nume()=="" or elev.get_nume()[0] != elev.get_nume()[0].upper() or elev.get_nume()[1:] != elev.get_nume()[1:].lower() or not(elev.get_nume()[0:].isalpha()):
            erori+="nume invalid!\n"
        if elev.get_grup()<0 or elev.get_grup()>10:
            erori+="grup invalid!\n"
        if len(erori)>0:
            raise ValidError(erori)

class ProblemaValidator(object):
    
    def valideazaProblema(self,problema):
        erori=""
        if problema.get_lab()<0:
            erori+="lab invalid!\n"
        if problema.get_desc()=="":
            erori+="desc invalida!\n"
        if problema.get_dl()<0 or problema.get_dl()>14:
            erori+="dl invalid!\n"
        if len(erori)>0:
            raise ValidError(erori)
        
class AsignValidator(object):
    
    def valideazaAsign(self,asignare):
        erori=""
        if asignare.get_eid()<0:
            erori+="id elev invalid!\n"
        if asignare.get_lab()<0:
            erori+="lab invalid!\n"
        if asignare.get_nota()<1 or asignare.get_nota()>10:
            erori+="nota invalida\n"
        if len(erori)>0:
            raise ValidError(erori)


