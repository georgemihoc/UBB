class Problema(object):
    
    def __init__(self, __lab, __desc, __dl):
        self.__lab = __lab
        self.__desc = __desc
        self.__dl = __dl

    def __str__(self):
        return str(self.__lab)+" "+self.__desc+" "+str(self.__dl)


    def __eq__(self, value):
        return self.__lab==value.__lab


    def get_lab(self):
        return self.__lab


    def get_desc(self):
        return self.__desc


    def get_dl(self):
        return self.__dl


    def set_desc(self, value):
        self.__desc = value


    def set_dl(self, value):
        self.__dl = value

    lab = property(get_lab, None, None, None)
    desc = property(get_desc, set_desc, None, None)
    dl = property(get_dl, set_dl, None, None)


