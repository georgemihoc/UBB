//
// Created by George on 2019-03-13.
//

#include "Vector.h"
#include <stdlib.h>
#include <string.h>
#include "Service.h"

VectorDinamic * creeaza_vector()
{
    /*
	Functie care creeaza un vector gol in care se retin obiectele de tip Materie  si il returneaza
    */
    VectorDinamic *v = malloc(sizeof(VectorDinamic));
    v->elems = malloc(100 * sizeof(Materie));
    v->capacitate = 100;
    v->lg = 0;
    return v;
}

void distruge(VectorDinamic *v)
{
    /*
	Functie care elibereaza memoria de date
	Vectorul v va fi gol dupa executie
*/
    int i;
    for (i = 0; i < v->lg; i++)
    {
        distruge_materie(&v->elems[i]);
    }
    free(v->elems);
    free(v);

}

void resize(VectorDinamic *v)
{
    /*
	Functie care realoca in memorie spatiu pentru vector, dublandu-i capacitatea
    */
    int nCap = 2 * v->capacitate;
    Materie *nElems = malloc(nCap * sizeof(Materie));
    int i;
    for (i = 0; i < v->lg; i++)
    {
        nElems[i] = v->elems[i];
    }
    free(v->elems);
    v->elems = nElems;
    v->capacitate = nCap;
}

VectorDinamic* copy(VectorDinamic* v)
{
    /*
	Functie care returneaza o copie a listei date, ca si pointer
    */
    VectorDinamic* copie = creeaza_vector();
    int i = 0;
    for (i = 0; i < v->lg; i++)
    {
        adauga(copie, get_nume(&v->elems[i]), get_producator(&v->elems[i]), get_cantitate(&v->elems[i]));
    }
    return copie;

}

int exista(VectorDinamic *v, char* cod)
{
    /*
	Functie care returneaza -1 daca obiectul de tip Materie nu exista in lista sau indexul la care se obiectul, daca exista
    */
    int i = 0;
    for (i = 0; i < v->lg; i++)
    {
        if (strcmp(get_nume(&v->elems[i]), cod) == 0)
        {
            return i;
        }
    }
    return -1;
}