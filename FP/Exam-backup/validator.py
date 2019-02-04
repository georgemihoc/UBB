from errors import ValidError

class ProdusValidator(object):

    def valideazaProdus(self,produs):
        erori = ""
        if produs.get_pid() < 0:
            erori += "id invalid!\n"
        if len(erori) > 0:
            raise ValidError(erori)
