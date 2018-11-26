
def add_list(a,b,nr,nr1,nr2):
    """"
    Functie care adauga un intreg x la finalul listei a si un intreg y la finalul listei b
    input-lista a si lista b, nr-globale, x,y-input
    preconditii-l=[l0,l1,...ln-1]; i= 0,n-1; li-intreg, nr-intreg,x-y-nr intregi;
    output-
    postconditii-l=[l0,l1,...ln-1]
    """


    nr += 1
    """"
    while True:
        x= input()
        try:
            x = int(x)
            a[int(nr)] = x
            break
        except ValueError :
            print("Valoarea introdusa nu este un intreg, va rugam reintroduceti")

    while True:
        y= input()
        try:
            y = int(y)
            b[int(nr)] = y
            break
        except ValueError :
            print("Valoarea introdusa nu este un intreg, va rugam reintroduceti")
    """
    a[int(nr)] = nr1
    b[int(nr)] = nr2
    return nr
