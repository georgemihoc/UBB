import math
from add import *

def print_nr_complex(x,y):
    """
    Functie care printeaza un numar complex
    input-x,y
    preconditii-x->numar intreg y->numar intreg
    output-print
    postconditii-

    """
    if int(y) >= 0:
        print(x, "+", y, "i")
    else:
        print(x, y, "i")


def teste_calcul_modul():
    assert int(calcul_modul(6,8)) == 10
    assert int(calcul_modul(6,7)) == 9
    assert int(calcul_modul(5, 4)) == 6
    assert int(calcul_modul(7, 10)) == 12
    assert int(calcul_modul(3, 2)) == 3

def calcul_modul(a,b):
    """
    Functie care calculeaza modulul unui numar complex
    input-a,b-numere intregi
    preconditii-a-numar intreg, b-numar intreg
    output-return modulul unui numar complex
    postconditii-

    """
    a = int(a)
    b = int(b)
    return math.sqrt(a*a+b*b)


def modul10(a,b,nr):
    """
    Functie care verifica daca numarul complex de pe pozitia i are modulul egal cu 10
    input-lista a si lista b, nr
    preconditii-l=[l0,l1,...ln-1]; i= 0,n-1; li-intreg, nr-intreg;
    output-print
    postconditii-l=[l0,l1,...ln-1]

    """
    if nr == -1:
        print("Lista goala, imposibil")
    else:
        for i in range(nr+1):
            if calcul_modul(a[i],b[i]) == 10:
                print_nr_complex(a[i],b[i])

def sterge(a,b,nr,poz):
    """
       Functie care sterge un numar de pe o pozitie data prin parametru
       input-lista a si lista b, nr, poz
       preconditii-l=[l0,l1,...ln-1]; i= 0,n-1; li-intreg,poz -intreg;
       output-lista
       postconditii-l=[l0,l1,...ln-1]

       """
    if poz<0 or poz > nr-1:
        print("Nu se poate efectua stergerea")
    else:
        del a[poz]
        del b[poz]
        if poz != nr:
            # nr -= 1
            if nr == -1:
                a = {}
                b = {}
            nr = int(nr)
            for i in range(poz, nr):
                a[i] = a[i + 1]
            for i in range(poz, nr):
                b[i] = b[i + 1]
            del a[nr]
            del b[nr]
        nr = nr - 1
    return nr

def sterge_element(a,b,nr,poz):
    """
    Functie care sterge un numar de pe o pozitie introdusa de la tastatura
    input-lista a si lista b, nr, poz
    preconditii-l=[l0,l1,...ln-1]; i= 0,n-1; li-intreg,poz -intreg;
    output-
    postconditii-l=[l0,l1,...ln-1]

    """
    """
    while True:
        poz= input("Pozitia:")
        try:
            poz = int(poz)
            break
        except ValueError :
            print("Valoarea introdusa nu este un intreg, va rugam reintroduceti")
    if poz>nr:
        print("Elementul nu exista")
    """
    nr = sterge(a,b,nr,poz)
    return nr

def suma_nr(a,b,nr,poz1,poz2):
    """
    Functie care calculeaza suma numerelor complexe de o pozitie de inceput la o pozitie de sfarsit
    input-lista a si lista b, nr, poz1,poz2
    preconditii-l=[l0,l1,...ln-1]; i= 0,n-1; li-intreg,poz1-intreg, poz2-intreg;
    output-s1,s2
    postconditii-s1,s2-numere intregi

    """
    if nr == 0:
        print_nr_complex(a[0],b[0])
    else:
        """"
        while True:
            poz1 = input("Pozitia inceput:")
            try:
                poz1 = int(poz1)
                break
            except ValueError:
                print("Valoarea introdusa nu este un intreg, va rugam reintroduceti")
        while True:
            poz2 = input("Pozitia sfarsit:")
            try:
                poz2 = int(poz2)
                break
            except ValueError:
                print("Valoarea introdusa nu este un intreg, va rugam reintroduceti")
        """
        s1 = 0
        s2 = 0

        if poz2>nr or poz1>nr:
            print("Imposibil")
        else:
            for i in range (poz1,poz2+1):
                s1 += int(a[i])
                s2 += int(b[i])
            print_nr_complex(s1,s2)

def teste_prim():
    """
    Functie care testeaza functia prim(x)
    input-
    preconditii-l=[l0,l1,...ln-1]; i= 0,n-1; li-intreg;
    output-
    postconditii-l=[l0,l1,...ln-1]

    """
    assert prim(5) == True
    assert prim(0) == False
    assert prim(1) == False
    assert prim(2) == True
    assert prim(13) == True
    assert prim(25) == False


def prim(x):
    """
    Functie care verifica daca un numar este prim
    input-variabila x
    preconditii-x variabila de tip intreg
    output-True - daca numarul este prim
           False - daca numarul nu este prim
    postconditii-True/False

    """
    x = int(x)
    if x < 2:
        return False
    i=2
    if x == 2:
        return True
    i = int(i)
    while i*i<=x:
        if x%i == 0:
            return False
        i += 1
    return True



def eliminare_prim(a,b,nr):
    """
    Functie care elimina numerele care au partea reala numar prim
    input-lista a si lista b, nr
    preconditii-l=[l0,l1,...ln-1]; i= 0,n-1; li-intreg;
    output-
    postconditii-l=[l0,l1,...ln-1]

    """

    i = 0
    if nr == -1:
        print("Lista goala, imposibil")
    else:
        while i<= nr:
            if prim(a[i]):
                i = int(i)
                del a[i]
                del b[i]
                for j in range(i, nr):
                    a[j] = a[j + 1]
                #del a[int(nr)]
                for j in range(i, nr):
                    b[j] = b[j + 1]
                #del b[nr]
                nr -= 1
            else: i = i + 1

    if nr == -1:
        a = {}
        b = {}
    return nr

def print_list(a,b,nr):
    """
    Printeaza listele a si b
    input-lista a si lista b, nr
    preconditii-l=[l0,l1,...ln-1]; i= 0,n-1; li-intreg;
    output-
    postconditii-l=[l0,l1,...ln-1]

    """
    if nr == -1 :
        print("EMPTY LIST")
    else:
        for i in range (0,nr+1):
            #i = int (i)
            #print("boss")
            print_nr_complex(a[i],b[i])

def print_list_sequence(a,b,start,finish):
    """
        Printeaza o secventa din listele a si b
        input-lista a si lista b, start,finish
        preconditii-l=[l0,l1,...ln-1]; i= 0,n-1; li-intreg,start,finish-intreg;
        output-
        postconditii-l=[l0,l1,...ln-1]

        """
    for i in range (start,finish):
        print_nr_complex(a[i],b[i])

def print_numar(x):
    """
       Printeaza numarul x
       input-x
       preconditii-x-intreg
       output-printare
       postconditii-

       """
    print(x)

def imaginara(a,b,nr,poz1,poz2):
    """
       Tipareste partea imaginara pentru numerele dintr-o secventa data
       input-lista a si lista b, nr, poz1 ,poz2
       preconditii-l=[l0,l1,...ln-1]; i= 0,n-1; li-intreg, poz1,poz2-intreg poz1,poz2<=nr;
       output-
       postconditii-l=[l0,l1,...ln-1]

       """
    """
    while True:
        poz1 = input("Pozitia inceput:")
        try:
            poz1 = int(poz1)
            break
        except ValueError:
            print("Valoarea introdusa nu este un intreg, va rugam reintroduceti")
    while True:
        poz2 = input("Pozitia sfarsit:")
        try:
            poz2 = int(poz2)
            break
        except ValueError:
            print("Valoarea introdusa nu este un intreg, va rugam reintroduceti")
    if nr == 0:
        print_numar(b[0])
    elif nr == -1 or poz1>nr or poz2>nr:
        print("Imposibil")
    else:"""
    for i in range (poz1,poz2+1):
        print_numar(b[i])

def produsul_nr(a,b,nr):
    """
    Functie care calculeaza produsul numerelor complexe de o pozitie de inceput la o pozitie de sfarsit
    input-lista a si lista b, nr, poz1,poz2
    preconditii-l=[l0,l1,...ln-1]; i= 0,n-1; li-intreg,poz1-intreg, poz2-intreg;
    output-p1,p2
    postconditii-p1,p2-numere intregi

    """
    if nr == 0:
        print_nr_complex(a[0],b[0])
    else:
        while True:
            poz1 = input("Pozitia inceput:")
            try:
                poz1 = int(poz1)
                break
            except ValueError:
                print("Valoarea introdusa nu este un intreg, va rugam reintroduceti")
        while True:
            poz2 = input("Pozitia sfarsit:")
            try:
                poz2 = int(poz2)
                break
            except ValueError:
                print("Valoarea introdusa nu este un intreg, va rugam reintroduceti")
        p1 = a[poz1]
        p2 = b[poz1]
        if poz2>nr or poz1>nr:
            print("Imposibil")
        else:
            for i in range (poz1+1,poz2+1):
                cp1 = p1
                cp2 = p2
                p1 = cp1*a[i] - cp2*b[i]
                p2 = cp1*b[i] + a[i]*cp2
            print_nr_complex(p1,p2)

def eliminare_modul(a,b,nr,m):
    """
    Functie care elimina numerele care au modulul mai mic decat M
    input-lista a si lista b, nr, M
    preconditii-l=[l0,l1,...ln-1]; i= 0,n-1; li-intreg;
    output-
    postconditii-l=[l0,l1,...ln-1]

    """

    i = 0
    """"
    while True:
        m = input("Dati M:")
        try:
            m = int(m)
            break
        except ValueError:
            print("Valoarea introdusa nu este un intreg, va rugam reintroduceti")
    """
    if nr == -1:
        print("Lista goala, imposibil")
    else:
        while i <= nr :
            if calcul_modul(a[i],b[i]) < m:
                i = int(i)
                del a[i]
                del b[i]
                for j in range(i, nr):
                    a[j] = a[j + 1]
                # del a[int(nr)]
                for j in range(i, nr):
                    b[j] = b[j + 1]
                # del b[nr]
                nr -= 1
            else: i = i + 1

    if nr == -1:
        a = {}
        b = {}
    return nr
def inserare_poz(a,b,nr):
    """
        Functie care adauga un intreg x pe o pozitie anume in lista a si un intreg y pe o pozitie anume in lista  b
        input-lista a si lista b, nr-globale,poz-input x,y-input
        preconditii-l=[l0,l1,...ln-1]; i= 0,n-1; li-intreg, nr-intreg,x-y-nr intregi,poz-intreg;
        output-
        postconditii-l=[l0,l1,...ln-1]

        """
    nr += 1
    while True:
        poz = input("Dati pozitia:")
        try:
            poz = int(poz)
            break
        except ValueError:
            print("Valoarea introdusa nu este un intreg, va rugam reintroduceti")
    if poz > nr or poz < 0:
        print("Imposibil")
    else:
        while True:
            x = input()
            try:
                x = int(x)
                #a[int(nr)] = x
                i = nr
                if poz != nr and i != -1:
                    while i > poz:
                        a[i]= a[i-1]
                        i = i-1
                a[poz] = x
                break
            except ValueError:
                print("Valoarea introdusa nu este un intreg, va rugam reintroduceti")

        while True:
            y = input()
            try:
                y = int(y)
                i = nr
                if poz != nr:
                    while i > poz:
                        b[i] = b[i - 1]
                        i = i-1
                b[poz] = y
                break
            except ValueError:
                print("Valoarea introdusa nu este un intreg, va rugam reintroduceti")
    return nr

def sterge_elemente_pozitii(a,b,nr):
    """
        Functie care sterge un numar de pe un interval introdus de la tastatura
        input-lista a si lista b, nr, poz1,poz2-input
        preconditii-l=[l0,l1,...ln-1]; i= 0,n-1; li-intreg,poz1,poz2 -intreg;
        output-
        postconditii-l=[l0,l1,...ln-1]

        """
    while True:
        poz1 = input("Pozitia:")
        try:
            poz1 = int(poz1)
            break
        except ValueError:
            print("Valoarea introdusa nu este un intreg, va rugam reintroduceti")
    while True:
        poz2 = input("Pozitia:")
        try:
            poz2 = int(poz2)
            break
        except ValueError:
            print("Valoarea introdusa nu este un intreg, va rugam reintroduceti")

    for i in range(poz1,poz2+1):
        if i<=nr+1:
            nr= sterge(a,b,nr,poz1)
    return nr
def citire_numar_complex():
    while True:
        x = input("")
        try:
            x = int(x)
            break
        except ValueError:
            print("Valoarea introdusa nu este un intreg, va rugam reintroduceti")
    while True:
        y = input("")
        try:
            y = int(y)
            break
        except ValueError:
            print("Valoarea introdusa nu este un intreg, va rugam reintroduceti")
    return [x,y]
def inlocuire(a,b,nr):
    """
        Functie care inlocuieste toate aparitiile unui numar complex citit cu un alt numar complex
        input-lista a si lista b, nr, poz1,poz2-input
        preconditii-l=[l0,l1,...ln-1]; i= 0,n-1; li-intreg,poz1,poz2 -intreg;
        output-
        postconditii-l=[l0,l1,...ln-1]

    """
    x=citire_numar_complex()
    y=citire_numar_complex()
    for i in range(nr+1):
        if x[0] == a[i] and x[1] == b[i]:
            a[i] = y[0]
            b[i] = y[1]
def modul_mic_10(a,b,nr):
    """
        Functie care determina numerele complexe care au modulul mai mic decat 10
        input-lista a si lista b, nr
        preconditii-l=[l0,l1,...ln-1]; i= 0,n-1; li-intreg;
        output-
        postconditii-l=[l0,l1,...ln-1]

    """
    for i in range(nr+1):
        if calcul_modul(a[i],b[i]) < 10:
            print_nr_complex(a[i],b[i])

def sortare_descrescator(a,b,nr):
    """
        Functie care sorteaza numerele complexe din lista descrescator dupa partea lor imaginara
        input-lista a si lista b, nr
        preconditii-l=[l0,l1,...ln-1]; i= 0,n-1; li-intreg;
        output-
        postconditii-l=[l0,l1,...ln-1]

    """
    for i in range(nr):
        for j in range(i+1,nr+1):
            if b[i]<b[j] or b[i] == b[j] and a[i] < a[j]:
                b[i],b[j] = b[j],b[i]
                a[i],a[j] = a[j],a[i]
    print_list(a,b,nr)

def print_module(i,nr):
    print("[",i,",",i+10,"] contine ", nr,"numere")

def modul_in_interval(a,b,nr):
    """
            Functie care afiseaza toate numerele complexe care au modulul in intervalul dat
            input-lista a si lista b, nr,val1,val2
            preconditii-l=[l0,l1,...ln-1]; i= 0,n-1; li-intreg,val1,val2-intreg;
            output-
            postconditii-l=[l0,l1,...ln-1]

    """

    i = 0
    i = int(i)
    while i <= 40:
        nrvalori = 0
        i = int(i)
        for j in range(nr+1):
            if calcul_modul(a[j],b[j]) > i and calcul_modul(a[j],b[j]) <= i+10:
                nrvalori += 1
        if nrvalori>0:
            print_module(i,nrvalori)
        i += 10

def appendHistory(history1,history2,a,b):
    history1.append(a.copy())
    history2.append(b.copy())
    #print(history1)
    #print(history2)


def undo(a,b,history1,history2):
    if len(history1)==0:
         print("No undos left")
         return [a,b,-1]
    else:
        a = {}
        b = {}
        #print(history1)
        #print(history2)
        #print(b)
        a = history1.pop()
        b = history2.pop()
        nr=len(a)-1
        #print(nr)
    return [a,b,nr]

def teste_undo():
    z = {0:1,1:2,2:3}
    w = {0:1,1:2,2:3}
    x = [[1],[1,2],[1,2,3]]
    y = [[1],[1,2],[1,2,3]]
    f= [1,2,3]
    g = [1,2,3]
    c = 2
    d = 1
    add_list(z,w,3,4,5)
    #sterge_element(z,w,3,0)
    assert undo(z,w,x,y) == [f,g,c]
    z = {0: 1, 1: 2, 2: 3}
    w = {0: 1, 1: 2, 2: 3}
    x = [[1], [1, 2], [1, 2, 3]]
    y = [[1], [1, 2], [1, 2, 3]]
    f = [1, 2,3]
    g = [1, 2,3]
    c = 2
    eliminare_prim(z,w,c)
    #print(z)
    assert undo(z,w,x,y) == [f,g,c]
    #print(undo(z, w, x, y))



