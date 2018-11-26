class Prof(object):
    
    
    def __init__(self, __pid, __pnume, __valoare):
        self.__pid = __pid
        self.__pnume = __pnume
        self.__valoare = __valoare

    def get_pid(self):
        return self.__pid


    def get_pnume(self):
        return self.__pnume


    def get_valoare(self):
        return self.__valoare


    def set_pnume(self, value):
        self.__pnume = value


    def set_valoare(self, value):
        self.__valoare = value

    pid = property(get_pid, None, None, None)
    pnume = property(get_pnume, set_pnume, None, None)
    valoare = property(get_valoare, set_valoare, None, None)
    
    



