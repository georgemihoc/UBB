class Asignare(object):
    
    
    def __init__(self, __sid, __pid, __start_ora, __finish_ora, __detalii):
        self.__sid = __sid
        self.__pid = __pid
        self.__start_ora = __start_ora
        self.__finish_ora = __finish_ora
        self.__detalii = __detalii

    def __eq__(self, value):
        return self.__pid==value.__pid and self.__sid==value.__sid and self.__start_ora==value.__start_ora and self.__finish_ora==value.__finish_ora


    def get_sid(self):
        return self.__sid


    def get_pid(self):
        return self.__pid


    def get_start_ora(self):
        return self.__start_ora


    def get_finish_ora(self):
        return self.__finish_ora


    def get_detalii(self):
        return self.__detalii


    def set_detalii(self, value):
        self.__detalii = value

    sid = property(get_sid, None, None, None)
    pid = property(get_pid, None, None, None)
    start_ora = property(get_start_ora, None, None, None)
    finish_ora = property(get_finish_ora, None, None, None)
    detalii = property(get_detalii, set_detalii, None, None)
    
    



