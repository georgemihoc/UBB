//
// Created by George on 2019-03-10.
//

#include "Validator.h"
#include <math.h>
#include "Materie.h"
#include <string.h>
int valideaza_materie(char nume[20], char producator[20], int cantitate)
{
    /*
     * Functie care valideaza un element(daca are numele,producatorul bun si daca cantitatea este numar pozitiv)
     * input- nume, producator, cantitate
     * preconditii- nume, producator-> sir de caractere , cantitate->numar natural intreg
     * output- erori->tipul de eroare gasita
     * postconditii- erori-numar natural
     */
    int erori = 0;
    if (strlen(nume)==0)
        erori=1;
    if (strlen(producator)==0)
        erori=2;
    if (cantitate<=0 || floor(cantitate)!=cantitate)
        erori=3;
    return erori;
}
