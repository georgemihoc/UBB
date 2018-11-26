

def is_prime(x):
    #functie care verifica daca nr intreg x este prim sau nu
    # input x
    #preconditii x intreg
    #output r
    #postconditii r == true daca x e prim
    #r == false altfel
    if x <2 :
        return False
    if x == 2:
        return True
    if x%2 == 0:
        return False
    d = 3
    while d*d<=x:
        if x%i == 0:
            return False
        d += 2
    return True



def primes_in_list():
    pass


def test_is_prime():
    assert is_prime(1) == False
    assert is_prime(-1) == False
    assert is_prime(2) == True
    assert is_prime(97) == True
    assert is_prime(0) == False
    assert is_prime(26) == False
    assert is_prime(27) == False
    assert is_prime(25) == False




def test_primes_in_list():
    l = [23,2,4,9,25,37]
    assert primes_in_list(l)= [25,37]
    
def add_int_to_list(l,x):
    #functie care adauga un intreg la finalul unei liste de intregi
    #input l,x
    #preconditii l = [10,11,...,ln-1], li
    l.append(x)

def test_add_int_to_tests():
    l = []
    add_int_to_list(l,1)
    assert l == [1]
    add_int_to_list(l,2)
    assert l == [1,2]

def ui_print(l):
    print("Elementele intregi din lista sunt :")
    s = ""
    for x in l :
        s += str(x)+ " "
        

def ui_add(l):
    while True:
        x = input("Introduceti un nr intreg")
        try: 
            x = int (x)
            add_int_to_list(l,x)
            return 
        except ValueError as ve :
            print ("Valoarea introdusa nu reprezinta un nr intreg ! Reintroduceti")
    
def run_tests():
    pass

def run ():
    l=[]
    while True:
        x= input(">")
        if x == "add":
            ui_add(1)
        elif  x == "exit":
            return
        if x == "exit":
            return
        else:
            print ("Comanda invalida")

run_tests()

run()
