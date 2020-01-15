class Asign(object):

    def __init__(self, __pid, __nume, __adresa):
        self.__pid = __pid
        self.__nume = __nume
        self.__adresa = __adresa

    def __str__(self):
        return str(self.__pid) + " " + str(self.__nume) + " " + str(self.__adresa)

    def __eq__(self, value):
        return self.__eid == value.__eid and self.__lab == value.__lab

    def get_pid(self):
        return self.__pid

    def get_nume(self):
        return self.__lab

    def get_a(self):
        return self.__adresa

    def set_eveniment(self, value):
        self.__nota = value

    eid = property(get_eid, None, None, None)
    lab = property(get_lab, None, None, None)
    nota = property(get_nota, set_nota, None, None)


