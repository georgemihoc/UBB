
class Colectie:

    # construieste o colectie noua
    def __init__(self):
        self.colectie= []

    # adauga un element in colectie
    def adauga(self, e):
        ok = 0
        for elem in self.colectie:
            if elem[0] == e:
                elem[1] += 1
                ok = 1
        if ok == 0:
            self.colectie.append([e, 1])

    # sterge o aparitie a elementului e din colectie
    # returneaza True daca elementul a fost sters, False altfel (daca e nu era in colectie)
    def sterge(self, e):
        for i in range(len(self.colectie)):
            if self.colectie[i][0] == e:
                if self.colectie[i][1] == 1:
                    del self.colectie[i]
                    return True
                else:
                    self.colectie[i][1] -= 1
                    return True
        return False

    # cauta un element e in colectie
    # returneaza True daca e apartine colectiei, False altfel
    def cauta(self, e):
        for elem in self.colectie:
            if elem[0] == e:
                return True
        return False

    # numara de cate ori apare un element e in colectie
    # returneaza numarul de aparitii pentru e
    def nrAparitii(self, e):
        for elem in self.colectie:
            if elem[0] == e:
                return elem[1]
        return 0

    # returneaza dimensiunea colectiei (numarul de elemente)
    def dim(self):
        s = 0
        for elem in self.colectie:
            s += elem[1]
        return s

    # returneaza True daca colectia e vida, False altfel
    def vida(self):
        if len(self.colectie) == 0:
            return True
        return False

    # returneaza un IteratorColectie pentru colectie
    def iterator(self):
        it = IteratorColectie(self)
        return it


class IteratorColectie:

    # creeaza un iterator pentru colectia c
    def __init__(self, c):
        self.c = c
        self.poz = 0
        if len(self.c.colectie) == 0:
            self.fr = 0 #frecventa
        else:
            self.fr = self.c.colectie[0][1]

    # returneaza True daca iteratorul este valid, False altfel
    def valid(self):
        if self.poz >= len(self.c.colectie) or len(self.c.colectie) == 0:
            return False
        return True

    # returneaza elementul curent din iterator
    def element(self):
        if self.valid() == False:
            raise ValueError
        return self.c.colectie[self.poz][0]

    # muta iteratorul la urmatorul element
    def urmator(self):
        if self.valid() == False:
            raise ValueError
        self.fr -= 1
        if self.fr <= 0:
            self.poz += 1
            if self.poz >= len(self.c.colectie):
                pass
            else:
                self.fr = self.c.colectie[self.poz][1]

    # seteaza iteratorul la primul element
    def prim(self):
        self.poz = 0
        if len(self.c.colectie) == 0:
            self.fr = 0
        else:
            self.fr = self.c.colectie[0][1]