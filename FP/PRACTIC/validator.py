from errors import ValidError

class JucatorValidator(object):

    def valideazaJucator(self,jucator):
        erori = ""
        if jucator.get_nume() == "":
            erori += "nume invalid!\n"
        if jucator.get_prenume() == "":
            erori += "prenume invalid!\n"
        if jucator.get_inaltime() < 0:
            erori += "inaltime invalida!\n"
        if jucator.get_post() == "Fundas" or jucator.get_post() == "Pivot" or jucator.get_post() == "Extrema":
            ok = True
        else:
            erori += "post invalid!\n"
        if len(erori) > 0:
            raise ValidError(erori)
