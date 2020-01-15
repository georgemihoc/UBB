class Opera(object):
    def __init__(self,__id,__denumire,__autor,__nr):
        self.__id = __id
        self.__denumire = __denumire
        self.__autor = __autor
        self.__nr = __nr

    def __str__(self):
        return str(self.__id) + " " + str(self.__denumire) + " " + str(self.__autor) + " " + str(self.__nr)

    def __eq__(self, value):
       return self.__id == value.get_id()

    def get_id(self):
        return self.__id

    def get_denumire(self):
        return self.__denumire

    def get_autor(self):
        return self.__autor

    def get_nr(self):
        return self.__nr

    def set_denumire(self, value):
        self.__denumire = value

    def set_autor(self, value):
        self.__autor = value

    def set_nr(self, value):
        self.__nr= value


    id = property(get_id, None, None, None)
    denumire = property(get_denumire, set_denumire, None, None)
    autor = property(get_autor, set_autor, None, None)
    nr = property(get_nr, set_nr, None, None)

