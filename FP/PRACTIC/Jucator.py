class Jucator(object):

    def __init__(self, __nume, __prenume, __inaltime, __post):
        self.__nume = __nume
        self.__prenume = __prenume
        self.__inaltime= __inaltime
        self.__post= __post

    def __str__(self):
        return str(self.__nume) + " " + str(self.__prenume) + " " + str(self.__inaltime) + " " + str(self.__post)

    def __eq__(self, value):
       return self.__nume == value.get_nume() and self.__prenume == value.get_prenume()

    def get_nume(self):
        return self.__nume

    def get_prenume(self):
        return self.__prenume

    def get_inaltime(self):
        return self.__inaltime

    def get_post(self):
        return self.__post


    def set_nume(self, value):
        self.__nume = value

    def set_prenume(self, value):
        self.__prenume = value


    def set_inaltime(self, value):
        self.__inaltime = value

    def set_post(self,value):
        self.__post = value


    nume = property(get_nume, set_nume, None,None)
    prenume = property(get_prenume, set_prenume, None,None)
    inaltime = property(get_inaltime, set_inaltime, None,None)
    post = property(get_post,set_post,None,None)