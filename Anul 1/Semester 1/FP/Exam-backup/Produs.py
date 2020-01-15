class Produs(object):

    def __init__(self, __pid, __nume, __pret):
        self.__pid = __pid
        self.__nume = __nume
        self.__pret = __pret

    def __str__(self):
        return str(self.__pid) + " " + str(self.__nume) + " " + str(self.__pret)

    def __eq__(self, value):
       return self.__pid == value.get_pid()

    def get_pid(self):
        return self.__pid

    def get_nume(self):
        return self.__nume

    def get_pret(self):
        return self.__pret

    def set_nume(self, value):
        self.__nume = value

    def set_pret(self, value):
        self.__adresa = value

    pid = property(get_pid, None, None)
    nume = property(get_nume, set_nume, None)
    pret = property(get_pret, set_pret, None)