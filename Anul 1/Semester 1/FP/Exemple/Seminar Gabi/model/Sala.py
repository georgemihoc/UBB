class Sala(object):
    
    
    def __init__(self, __sid, __nume, __capacitate):
        self.__sid = __sid
        self.__nume = __nume
        self.__capacitate = __capacitate

    def __str__(self):
        return str(self.__sid)+" "+self.__nume+" "+str(self.__capacitate)


    def __eq__(self, value):
        return self.__sid==value.__sid


    def get_sid(self):
        return self.__sid


    def get_nume(self):
        return self.__nume


    def get_capacitate(self):
        return self.__capacitate


    def set_nume(self, value):
        self.__nume = value


    def set_capacitate(self, value):
        self.__capacitate = value

    sid = property(get_sid, None, None, None)
    nume = property(get_nume, set_nume, None, None)
    capacitate = property(get_capacitate, set_capacitate, None, None)
    
    



