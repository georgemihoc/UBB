#pragma once
#include "Lista.h"
/*
*Tipul functie de comparare pentru 2 elemente si returneaza 0 daca sunt egale, 1 daca o1>o2, -1 altfel
*/
typedef int(*FunctieComparare)(Oferta* o1, Oferta* o2);

/*
*Sorteaza in place
*/
void sort(Lista* l, FunctieComparare cmpF);