class Event(object):

    def __init__(self, __id, __data,__timp, __desc):
        self.__id = __id
        self.__data = __data
        self.__timp = __timp
        self.__desc = __desc


    def __str__(self):
        return str(self.__id) + " " + str(self.__data) + " " + str(self.__timp) + " " + str(self.__desc)

    def __eq__(self, value):
        return self.__id == value.get_id()

    def get_id(self):
        return self.__id

    def get_data(self):
        return self.__data

    def get_timp(self):
        return self.__timp

    def get_desc(self):
        return self.__desc

    def set_data(self, value):
        self.__data = value

    def set_timp(self, value):
        self.__timp = value

    def set_desc(self, value):
        self.__desc = value

    id = property(get_id, None, None, None)
    data = property(get_data, set_data, None, None)
    timp = property(get_timp, set_timp, None, None)
    desc = property(get_desc, set_desc, None, None)


