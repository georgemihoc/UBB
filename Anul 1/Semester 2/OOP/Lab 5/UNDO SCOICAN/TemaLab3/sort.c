#include "sort.h"

/*
*Sortare dupa un criteriu dat ca fuctie
*int:l, cmpf
*pre:cmpf - este o functie existenta
*post:elem din lista se ordonoeaza dupa functia data
*/
void sort(Lista* l, FunctieComparare cmpF) {
	int i, j;
	for (i = 0; i < lung(l); i++) {
		for (j = i + 1; j < lung(l); j++) {
			ElemType p1 = elem(l, i);
			ElemType p2 = elem(l, j);
			if (cmpF(p1, p2) > 0) {
				modific(l, i, p2);
				modific(l, j, p1);
			}
		}
	}
}