'''
Generați toate permmutările de dimensiune n (1..n), cu propritatea că pentru orice i 2<=i<=n
exista un j, 1<=j<=i astfel încât |v(i)-v(j)|=1.
'''

#VARIANTA RECURSIVA

def valid(x,k):
    '''
        Functia care verifica elementele din vectorul x sunt distincte doua cate doua
        Date de intrare: x - vectorul in care se genereaza solutiile
                       k- numarul de elemente din x
    '''
    #Verificam daca toate elementele sunt distincte
    for i in range(k):
        if x[i] == x[k]:
            return False
    return True

def valid2(x,k):
    '''
        Functia care verifica daca se verifica proprietatea ceruta si anume daca pt orice i 2<=i<=n exista un j, 1<=j<=i astfel încât |v(i)-v(j)|=1.
        Date de intrare: x - vectorul in care se genereaza solutiile
                       k- numarul deelemente din x
    '''
    for i in range(1,k):
        ok = False
        for j in range(0, i):
            if x[i] - x[j] == 1 or x[i] - x[j] == -1:
                ok = True
        if ok == False:
            return False
    return True


def solutie(n,k):
    '''
        Functia care verifica daca lungimea k a vectorului x este egala cu dimensiunea ceruta de utilizator a unei permutari
        Date de intrare: n - lungimea introdusa de utilizator
                       k- numarul de elemente din vectorul x
    '''
    #Verificam daca secventa construita are lungimea ceruta
    if k == n-1:
        return True
    return False

def afisare(x):
    '''
    Functia care printreaza un vector (vectorul solutie)
    '''
    print(x)

def backtracking(x,n,k):
    '''
       Functia care genereaza solutiile folosind metoda backtracking in mod recursiv
       Date de intrare: x - vectorul in care se genereaza solutiile
                       dim - numarul de elemente care trebuie sa existe intr-o permutare
    '''
    for i in range(1,n+1):
        x[k] = i
        if valid(x,k) and valid2(x,k):
            if solutie(n,k):
                afisare(x)
            else:
                backtracking(x,n,k+1)


#VARIANTA ITERATIVA


def isSet(x):
    '''
        Functia care verifica elementele din vectorul x sunt distincte doua cate doua
        Date de intrare: x - vectorul in care se genereaza solutiile
    '''
    for i in x:
        nr = 0
        for j in x:
            if i==j:
                nr+=1
        if nr!= 1:
            return False
    return True

def backIter(x,dim):
    '''
    Functia care genereaza solutiile folosind metoda backtracking in mod iterativ
    Date de intrare: x - vectorul in care se genereaza solutiile
                    dim - numarul de elemente care trebuie sa existe intr-o permutare
    '''
    x=[0]#candidate solution
    while len(x)>0:
        ok = False
        while not ok and x[-1]<dim:
            x[-1] = x[-1]+1  #increase the last component
            ok = isSet(x)
        if ok:
            if len(x) == dim and valid2(x,dim):
                afisare(x)
            x.append(0) #expand candidate solution
        else:
            x = x[:-1]  #go back one component

def run():
    n = int(input())
    x = []
    for i in range(n):
        x.append(0)
    print("RECURSIV")
    backtracking(x,n,0)
    print("\n")
    print("ITERATIV")
    backIter(x,n)
run()