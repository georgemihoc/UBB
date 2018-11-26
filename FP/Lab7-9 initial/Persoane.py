class Person(object):

    def __init__(self, __pid, __nume, __adresa):
        self.__pid = __pid
        self.__nume = __nume
        self.__adresa = __adresa

    def __str__(self):
        return str(self.__pid) + " " + self.__nume + " " + str(self.__adresa)

    def __eq__(self, value):
        return self.__pid == value.__pid

    def get_eid(self):
        return self.__pid

    def get_nume(self):
        return self.__nume

    def get_grup(self):
        return self.__adresa

    def set_nume(self, value):
        self.__nume = value

    def set_adresa(self, value):
        self.__adresa = value

    pid = property(get_pid, None, None, None)
    nume = property(get_nume, set_nume, None, None)
    adresa = property(get_grup, set_adresa, None, None)



