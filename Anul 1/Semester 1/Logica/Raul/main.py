

def binary_to_octal(a):
    lista = []
    nr = len(a)
    if nr%3 == 1:
        b = [0, 0]
        for elem in a:
            b.append(elem)
        a = b
        nr += 2
        #print(a)
    elif nr% 3== 2:
        b = [0]
        for elem in a:
            b.append(elem)
        a = b
        nr += 1
        #print(a)

    aux = 0
    doi = 0
    for i in range(nr-1,0,-3):
        #print("boss")
        aux = int(0)
        aux = int(a[i])+ int(a[i-1])*2+int(a[i-2])*4
        lista.append(aux)
    lista.reverse()
    r = ''
    for elem in lista:
        r = r+ str(elem)
    return r



def binary_to_hexa(a):
    lista = []
    nr = len(a)
    if nr%4 == 1:
        b = [0, 0,0]
        for elem in a:
            b.append(elem)
        a = b
        nr += 3
        #print(a)
    elif nr% 4== 2:
        b = [0,0]
        for elem in a:
            b.append(elem)
        a = b
        nr += 2
        #print(a)
    elif nr % 4 == 3:
        b = [0]
        for elem in a:
            b.append(elem)
        a = b
        nr += 1

    aux = 0
    doi = 0
    for i in range(nr-1,0,-4):
        #print("boss")
        aux = int(0)
        aux = int(a[i])+ int(a[i-1])*2+int(a[i-2])*4 + int(a[i-3])*8
        if aux == 10: aux = 'a'
        elif aux == 11: aux = 'b'
        elif aux == 12: aux = 'c'
        elif aux == 13: aux = 'd'
        elif aux == 14: aux = 'e'
        elif aux == 15: aux = 'f'
        lista.append(aux)
    lista.reverse()
    r = ''
    for elem in lista:
        r = r+ str(elem)
    #print(r)
    return r

def binary_to_4(a):
    lista = []
    nr = len(a)
    if nr%2 == 1:
        b = [0]
        for elem in a:
            b.append(elem)
        a = b
        nr += 1
        #print(a)

    aux = 0
    doi = 0
    for i in range(nr-1,0,-2):
        #print("boss")
        aux = int(0)
        aux = int(a[i])+ int(a[i-1])*2
        lista.append(aux)
    lista.reverse()
    r = ''
    for elem in lista:
        r = r+ str(elem)
    #print(r)
    return r

def number_to_binary(a,baza):
    s = ''
    if baza == "4":
        numar = int(2)
    elif baza == "8":
        numar = int(3)
    elif baza == "16":
        numar = int(4)
    for elem in a:
        lista = []
        elem = int(elem)
        if elem == 0:
            for i in range(numar):
                lista.append(0)

        while elem:
            elem = int(elem)
            if elem != 0:
                lista.append(elem%2)
            #print(elem%2)
            elem = elem/2
        if baza == "4":
            while len(lista)!=2:
                lista.append(0)
        if baza == "8":
            while len(lista)!=3:
                lista.append(0)
        if baza == "16":
            while len(lista)!=4:
                lista.append(0)

        r = ''
        lista.reverse()
        for elem1 in lista:
            r = r+ str(elem1)
        s = s+ str(r)
    #print(s)
    return s

def run():
    dec = input("Numarul:")
    base = input("Baza initiala:")
    dest_base = input("Baza destinatie:")

    for cifra in dec:
        if cifra>= base:
            print("Numarul introdus nu corespunde bazei date")
            return
    if base != "2":
        dec = number_to_binary(dec,base)
        #print(dec)

    if dest_base == "2": print(dec)
    elif dest_base == "4": print(binary_to_4(dec))
    elif dest_base == "8": print(binary_to_octal(dec))
    elif dest_base == "16": print(binary_to_hexa(dec))
    else: print("Baza introdusa este incorecta")

run()