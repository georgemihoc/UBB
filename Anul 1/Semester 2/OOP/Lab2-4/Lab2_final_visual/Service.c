//
// Created by George on 2019-03-13.
//

#include <stdlib.h>
#include <string.h>
#include "Service.h"
#include "Validator.h"
#include "Domain.h"

int adauga(VectorDinamic *v, char * nume,char *producator, float cantitate)
{
    /*
     * Functie care apeleaza functia de adaugare din repository pentru a adauga un element nou
     * in lista de elemente si returneaza tipul de eroare(daca exista).
     * input- nume, producator, cantitate
     * preconditii- nume,producator-sir de caractere, cantitate-nr intreg
     * output- erori
     * postconditii- erori-nr intreg
     */
    int index = -1;
    if (valideazaMaterie(nume, producator, cantitate) == -1)
    {
        return -2;
    }
    index = exista(v, nume);
    if (index != -1)
    {
        set_producator(&v->elems[index], producator);
        set_cantitate(&v->elems[index], cantitate);
        return -1;
    }
    if (v->lg == v->capacitate)
    {
        resize(v);
    }
    v->elems[v->lg] = creeaza(nume,producator, cantitate);
    v->lg++;
    return 1;
}

int modificare(VectorDinamic *v, char * nume, char *producator, float cantitate)
{
    /*
     * Functie care apeleaza functia de modificare din repository pentru a modifica un element
     * din lista de elemente si returneaza tipul de eroare(daca exista)
     * input- v, nume, producator, cantitate
     * preconditii- v-vector dinamic, nume,producator-sir de caractere, cantitate-nr intreg
     * output- erori
     * postconditii- erori - nr intreg
     */
    int index;
    if (valideazaMaterie(nume,producator, 1) == -1)
    {
        return -2;
    }
    index = exista(v, nume);
    if (index >= 0)
    {
        if (strcmp(nume, "0") != 0)
        {
            set_nume(&v->elems[index], nume);
        }
        if (strcmp(producator, "0") != 0)
        {
            set_producator(&v->elems[index], producator);
        }
        if (cantitate >= 0)
        {
            set_cantitate(&v->elems[index], cantitate);
        }
    }
    else
    {
        return -1;
    }
    return 1;
}


int sterge(VectorDinamic* v, char* nume)
{
    /*
     * Functie care  sterge un element din vectorul dinamic
     * din lista de elemente si returneaza tipul de eroare(daca exista)
     * input- v-vectorul dinamic, nume-numele elementului care trebuie sters
     * preconditii- nume-sir de caractere
     * output- 1/-1
     * postconditii- -1 daca a fost gasit elementul de sters si 1 altfel
     */
    int index = exista(v, nume);
    if (index == -1)
    {
        return -1;
    }

    Materie *Elems = malloc(v->capacitate * sizeof(Materie));
    int i, j = 0;
    for (i = 0; i < v->lg; i++)
    {
        if (i == index)
        {
            distruge_materie(&v->elems[i]);
        }
        if (i != index)
        {
            Elems[j] = v->elems[i];
            j++;
        }
    }
    free(v->elems);
    v->elems = Elems;
    v->lg--;
    return 1;
}

VectorDinamic * vizualizare_cantitate(VectorDinamic *v, int cant)
{
    /*
     * Functie care permite vizualizarea elementelor care au cantitatea mai mica ca un nr dat
     * input- v,cant
     * preconditii- v-un vectorul dinamic ,cant un nr intreg
     * output- c- vectorul dinamic creat
     * postconditii- c- vector dinamic
     */
    VectorDinamic *c;
    c = creeaza_vector();
    int i = 0;
    for (i = 0; i < v->lg; i++)
    {
        if (get_cantitate(&v->elems[i]) < cant)
        {
            adauga(c, get_nume(&v->elems[i]), get_producator(&v->elems[i]), get_cantitate(&v->elems[i]));
        }
    }
    return c;
}

VectorDinamic* vizualizare_litera(VectorDinamic*v, char litera)
{
    /*
     * Functie care permite vizualizarea elementelor care incep cu o anumita litera
     * input- v,litera
     * preconditii- v-un vectorul dinamic ,litera -un caracter(litera)
     * output- p- vectorul dinamic creat
     * postconditii- p- vector dinamic
     */
    VectorDinamic* p;
    p = creeaza_vector();
    int i = 0;
    for (i = 0; i < v->lg; i++)
    {
        if (get_nume(&v->elems[i])[0] == litera)
        {
            adauga(p, get_nume(&v->elems[i]), get_producator(&v->elems[i]), get_cantitate(&v->elems[i]));
        }
    }
    return p;
}

void ordonare(VectorDinamic* v, int(*func_sortare)(Materie* x, Materie* y), int ordine)
{
    /*
     * Functie care sorteaza elementele dupa criteriul ales si in modul ales(crescator/Descrescator)
     * input- v, criteriu, ordine
     * preconditii- v-vector dinamic, ordine-> caracter care semnifica modul de sortare (1-crescator, 2-descrescator)
     * output- Functie void
     * postconditii- Ø
     */
    Materie  aux;
    int i = 0, j = 0;
    if (ordine == 2)
        ordine = 0;
    for (i = 0; i < v->lg; i++)
    {
        aux = v->elems[i];
        j = i - 1;
        if (ordine == 1)
        {
            while (j >= 0 && (*func_sortare)(&aux, &v->elems[j]))
            {

                v->elems[j + 1] = v->elems[j];
                j--;
            }
            v->elems[j + 1] = aux;
        }
        else
        {
            while (j >= 0 && !(*func_sortare)(&aux, &v->elems[j]))
            {

                v->elems[j + 1] = v->elems[j];
                j--;
            }
            v->elems[j + 1] = aux;
        }
    }
}

int comparare(Materie* first, Materie* second)
{
    /*
     * Functie care compara 2 materii prime in functie de cantitate
     * input- first, second
     * preconditii- first, second materii prime
     * output- 0 first e mai mica cantitatea /1 altfel
     * postconditii- 0/1
     */
    if (get_cantitate(first) < get_cantitate(second))
    {
        return 1;
    }
    return 0;
}

int comparareNume(Materie* first, Materie* other)
{
    /*
    * Functie care compara 2 materii prime in functie de nume
    * input- first, second
    * preconditii- first, second materii prime
    * output- 0 first e mai "mic" numele /1 altfel
    * postconditii- 0/1
    */
    if (strcmp(get_nume(first), get_nume(other)) < 0)
    {
        return 1;
    }
    return 0;
}