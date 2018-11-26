class Elev(object):
    
    def __init__(self, __eid, __nume, __grup):
        self.__eid = __eid
        self.__nume = __nume
        self.__grup = __grup

    def __str__(self):
        return str(self.__eid)+" "+self.__nume+" "+str(self.__grup)


    def __eq__(self, value):
        return self.__eid==value.__eid


    def get_eid(self):
        return self.__eid


    def get_nume(self):
        return self.__nume


    def get_grup(self):
        return self.__grup


    def set_nume(self, value):
        self.__nume = value


    def set_grup(self, value):
        self.__grup = value

    eid = property(get_eid, None, None, None)
    nume = property(get_nume, set_nume, None, None)
    grup = property(get_grup, set_grup, None, None)
    


