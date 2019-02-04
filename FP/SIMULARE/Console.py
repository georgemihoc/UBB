from Controllers import *
class Console(object):
    def __init__(self,ctrlOpere):
        self.ctrlOpere = ctrlOpere

    def __uiFunctionalitatea1(self,params):
        if len(params) != 1:
            print("Nr invalid de parametrii")
            return
        sir = params[0]
        opere = self.ctrlOpere.getAllOpere()
        lista = OpereController.sir(self,opere,sir)
        if lista == 0:
            print("Nu exista nicio opera care sa contina acest sir de caractere")
        else:
            for elem in lista:
                print(elem)

    def __uiFunctionalitatea2(self,params):
        if len(params) != 1:
            print("Nr invalid de parametrii")
            return
        camera = params[0]
        opere = self.ctrlOpere.getAllOpere()
        lista = OpereController.camera(self,opere,camera)
        if lista == -1:
            print("Numarul camerei este invalid")
        elif lista ==-2:
            print("Numarul camerei este inexistent")
        else:
            for elem in lista:
                print(elem)
        #print(camera)
    def __uiPrint(self,params):
        if len(params) != 0:
            print("Nr invalid de parametrii")
            return
        opere = self.ctrlOpere.getAllOpere()
        #for opera in opere:
            #print(opera.autor)
        #p = self.
    def run(self):
        print("1.Afisati toate operele de arta care contin un anume sir de caractere\n"
            "2.Afisati toate operele de arta care sunt expuse intr-o anume camera\n"
            "3.EXIT")
        comenzi = {
            "1":self.__uiFunctionalitatea1,
            "2":self.__uiFunctionalitatea2,
            "4":self.__uiPrint
        }
        while True:
            cmd = input()
            params = cmd.split(" ")
            if cmd == "3":
                print("EXIT")
                return
            elif params[0] in comenzi:
                try:
                    comenzi[params[0]](params[1:])
                except ValueError:
                    print("Tip de data invalid")
