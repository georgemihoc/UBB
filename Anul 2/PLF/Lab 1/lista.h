#ifndef LISTA_H
#define LISTA_H


//tip de data generic (pentru moment este intreg)
typedef int TElem;

//referire a structurii Nod;
struct Nod;

//se defineste tipul PNod ca fiind adresa unui Nod
typedef Nod *PNod;

typedef struct Nod{
    TElem e;
    PNod urm;
};

typedef struct{
//prim este adresa primului Nod din lista
    PNod _prim;
} Lista;

//operatii pe lista - INTERFATA

//crearea unei liste din valori citite pana la 0
Lista creare();
//tiparirea elementelor unei liste
int suma_rec(Lista l, int poz);
int suma(Lista l);
void tipar(Lista l);
void parcurgere(Lista a, Lista b);
// destructorul listei
void distruge(Lista l);

#endif