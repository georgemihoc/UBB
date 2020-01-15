//
// Created by George on 2019-03-13.
//

#include <string.h>
#include "Domain.h"
#include <stdlib.h>

Materie creeaza(char* nume, char* producator,float cantitate)
{
    /*
	Functie care creeaza un obiect de tip Materie  si il returneaza
	input: nume, producator, cantitate
    output: Elementul de tip Materie construit
    */
    Materie m;
    int numarCaractere = strlen(nume) + 1;
    m.nume = malloc(sizeof(char)*numarCaractere);
    strcpy(m.nume, nume);

    numarCaractere = strlen(producator) + 1;
    m.producator = malloc(sizeof(char)*numarCaractere);
    strcpy(m.producator,producator);

    m.cantitate = cantitate;
    return m;

}

char* get_nume(Materie* m)
{
    /*
	Functie care returneaza numele unui obiect de tip Materie
    */
    return m->nume;
}

char* get_producator(Materie *m)
{
    /*
	Functie care returneaza producatorul unui obiect de tip Materie
    */
    return m->producator;
}

float get_cantitate(Materie* m)
{
    /*
	Functie care returneaza cantitatea unui obiect de tip Materie
    */
    return m->cantitate;
}

void set_nume(Materie* m, char* nume)
{
    /*
	* Functie care seteaza numele  unui obiect la numele dat
    */
    int numarCaractere = strlen(nume) + 1;
    free(m->nume);
    m->nume = malloc(sizeof(char)*numarCaractere);
    strcpy(m->nume, nume);
}

void set_producator(Materie* m, char* producator)
{
    /*
	* Functie care seteaza producatorul  unui obiect la producatorul dat
    */
    int numarCaractere = strlen(producator) + 1;
    free(m->producator);
    m->producator = malloc(sizeof(char)*numarCaractere);
    strcpy(m->producator, producator);
}

void set_cantitate(Materie* m, float cantitate)
{
    /*
	* Functie care seteaza cantitatea   unui obiect la cantitatea data
    */
    m->cantitate = cantitate;
}
void distruge_materie(Materie*m)
{
    /*
	 Functie care dealoca memoria in care era retinuta un obiect de tip Materie
    */

    free(m->nume);
    free(m->producator);

    m->nume = NULL;
    m->producator = NULL;
    m->cantitate = -1;
}