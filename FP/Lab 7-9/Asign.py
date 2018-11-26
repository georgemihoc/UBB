class Asign(object):

    def __init__(self, __pid, __eid):
        self.__pid = __pid
        self.__eid = __eid

    def __str__(self):
        return str(self.__pid) + " " + str(self.__eid)

    def __eq__(self, value):
        return self.__pid == value.__pid and self.__eid == value.__eid

    def get_pid(self):
        return self.__pid

    def get_eid(self):
        return self.__eid

    #def set_eid(self, value):
     #   self.__eid = value

    pid = property(get_pid, None, None, None)
    eid = property(get_eid, None, None, None)


