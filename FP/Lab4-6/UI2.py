
from add import *

from functions import *


def meniu():
    v = 0
    #global nr
    a = {}
    b = {}
    history1 = []
    history2 = []
    nr = -1
    rand =input()
    v = rand.split(" ")
    i = 0
    ok = 1
    i = 0
    if ok == 1:
        while int(v[i])!=9:
            nr = int(nr)
            """
            while True:
                
                v = input("1.Adaugare numar in lista -add \n"
                          "2.Sterge element de pe pozitia data \n"
                          "3.Tipariti partea imaginara pentru numerele dintr-o secventa data(poz inceput, poz sfarsit) \n"
                          "4.Afisati suma numerelor dintr-o secventa data (poz inceput,poz sfarsit) \n"
                          "5.Eliminati din lista numerele cu partea reala numar prim \n"
                          "6.Eliminati din lista numerele care au modulul mai mic ca M \n"
                          "7.Tiparire lista \n"
                          "8.Undo \n"
                          "9.Iesire din aplicatie \n")
    
                try:
                    v = int(v)
                    break
                except ValueError:
                    print("Comanda introdusa nu exista")
            """""
            if int(v[i])==1:
                if v[i+1].isalpha() or v[i+2].isalpha():
                    print("Comanda add nu poate fi realizata")
                else:
                    appendHistory(history1, history2, a, b)
                    nr = add_list(a,b,nr,int(v[i+1]),int(v[i+2]))
                i += 3
            elif int(v[i])==2:
                if v[i+1].isalpha():
                    print("Comanda add nu poate fi realizata")
                else:
                    appendHistory(history1, history2, a, b)
                    nr=sterge_element(a,b,nr,int(v[i+1]))
                i += 2
            elif int(v[i])==3:
                if v[i+1].isalpha() or v[i+2].isalpha():
                    print("Comanda add nu poate fi realizata")
                else:
                    imaginara(a,b,nr,int(v[i+1]),int(v[i+2]))
                i += 3
            elif int(v[i])==4:
                if v[i+1].isalpha() or v[i+2].isalpha():
                    print("Comanda add nu poate fi realizata")
                else:
                    suma_nr(a,b,nr,int(v[i+1]),int(v[i+2]))
                i += 3
            elif int(v[i])==5:
                appendHistory(history1, history2, a, b)
                nr=eliminare_prim(a,b,nr)
                i +=1
            elif int(v[i])==6:
                if v[i+1].isalpha():
                    print("Comanda add nu poate fi realizata")
                else:
                    appendHistory(history1, history2, a, b)
                    nr=eliminare_modul(a,b,nr,int(v[i+1]))
                i += 2
            elif int(v[i])==7:
                print_list(a,b,nr)
                print("\n")
                i += 1
            elif int(v[i])==8:
                [a,b,nr]=undo(a,b,history1,history2)
                i += 1
            #elif v != 9: print("Comanda introdusa nu exista")
        if int(v[i])==9:
            print("EXIT")
teste_calcul_modul()
teste_undo()
teste_prim()
meniu()

""""
from add import *

from functions import *


def meniu():
    v = 0
    #global nr
    a = {}
    b = {}
    history1 = []
    history2 = []
    nr = -1
    while int(v)!=17:
        nr = int(nr)
        while True:
            v = input("1.Adaugare numar in lista -add \n"
                      "2.Insereaza numar complex pe o pozitie data \n"
                      "3.Sterge element de pe pozitia data \n"
                      "4.Stergeti elementele din intervalul de pozitii dat \n"
                      "5.Inlocuiti aparitiile unui numar complex cu un alt numar complex \n"
                      "6.Tipariti partea imaginara pentru numerele dintr-o secventa data(poz inceput, poz sfarsit) \n"
                      "7.Tipăriti toate numerele complexe care au modulul mai mic decât 10 \n"
                      "8.Tipareste numerele care au modulul egal cu 10 \n"
                      "9.Afisati suma numerelor dintr-o secventa data (poz inceput,poz sfarsit) \n"
                      "10.Afisati produsul numerelor dintr-o secventa data (poz inceput,poz sfarsit) \n"
                      "11.Tipăriti lista sortată descrescător după partea imaginara \n"
                      "12.Eliminati din lista numerele cu partea reala numar prim \n"
                      "13.Eliminati din lista numerele care au modulul mai mic ca M \n"
                      "14.Tiparire lista \n"
                      "15.Afisati toate numerele complexe care au modulul in interval  \n"
                      "16.Undo \n"
                      "17.Iesire din aplicatie \n")
            try:
                v = int(v)
                break
            except ValueError:
                print("Comanda introdusa nu exista")
        if v==1:
            appendHistory(history1, history2, a, b)
            nr = add_list(a,b,nr)
        elif v==2:
            appendHistory(history1, history2,a,b)
            nr=inserare_poz(a,b,nr)
        elif v==3:
            appendHistory(history1, history2, a, b)
            nr=sterge_element(a,b,nr)
        elif v==4:
            appendHistory(history1, history2, a, b)
            nr=sterge_elemente_pozitii(a,b,nr)
        elif v==5:
            appendHistory(history1, history2, a, b)
            inlocuire(a,b,nr)
        elif v==6: imaginara(a,b,nr)
        elif v==7: modul_mic_10(a,b,nr)
        elif v==8: modul10(a,b,nr)
        elif v==9: suma_nr(a,b,nr)
        elif v==10: produsul_nr(a,b,nr)
        elif v==11:
            appendHistory(history1, history2, a, b)
            sortare_descrescator(a,b,nr)
        elif v==12:
            appendHistory(history1, history2, a, b)
            nr=eliminare_prim(a,b,nr)
        elif v==13:
            appendHistory(history1, history2, a, b)
            nr=eliminare_modul(a,b,nr)
        elif v==14: print_list(a,b,nr)
        elif v==15: modul_in_interval(a,b,nr)
        elif v==16: [a,b,nr]=undo(a,b,history1,history2)
        elif v != 17: print("Comanda introdusa nu exista")
    if v==17:
        print("EXIT")
teste_calcul_modul()
teste_prim()
meniu()
"""