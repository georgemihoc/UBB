from Repository import *
from Opere import *
class OpereController(object):
    def __init__(self,repoOpere):
        self.repoOpere = repoOpere
        #self.ValidOpere = validOpere
    def sir(self,opere,sir):
        '''
                Functie care returneaza toate operele care au in denumire caracterul citit
                input- opere, sir
                output- lista cu operele corespunzatoare

        '''
        lista = []
        nr = 0
        for opera in opere:
            if sir in opera.denumire:
                nr += 1
                lista.append(opera)
        lista.sort(key=lambda x: x.get_autor(), reverse=True)
        if lista == []:
            return 0
        else:
            return lista
    def camera(self,opere,camera):
        '''
                        Functie care returneaza o lista cu numele autorilor care au opere expuse intr-o anumita camera
                        input- opere, camera
                        output- lista cu operele corespunzatoare

        '''
        lista = []
        camera = int(camera)
        if camera != int(camera) or int(camera)<1:
            return -1
        nr = 0
        for opera in opere:
            if int(opera.nr) == int(camera):
                ok = 0
                for i in lista:
                    if i == opera.autor:
                        ok = 1
                if ok == 0:
                    lista.append(opera.autor)
                    nr += 1
        if nr == 0:
            return -2
        return lista

    def getAllOpere(self):
        return self.repoOpere.getAll()
