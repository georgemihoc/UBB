class Asign(object):
    
    def __init__(self, __eid, __lab, __nota):
        self.__eid = __eid
        self.__lab = __lab
        self.__nota = __nota

    def __str__(self):
        return str(self.__eid) +" "+ str(self.__lab)+" " + str(self.__nota)

    def __eq__(self, value):
        return self.__eid == value.__eid and self.__lab == value.__lab

    def get_eid(self):
        return self.__eid


    def get_lab(self):
        return self.__lab


    def get_nota(self):
        return self.__nota


    def set_nota(self, value):
        self.__nota = value

    eid = property(get_eid, None, None, None)
    lab = property(get_lab, None, None, None)
    nota = property(get_nota, set_nota, None, None)


