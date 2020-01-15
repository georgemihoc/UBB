#include "Lista.h"
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "domain.h"
#include <stdio.h>
#include "service.h"
/*
*Creeaza o lista goala
*ies:rez - lista goala
*/
Lista *creeaza(DestroyFct f) {
	Lista *rez = malloc(sizeof(Lista));
	rez->lg = 0;
	rez->cap = 5;
	rez->elems = malloc(sizeof(ElemType)*rez->cap);
	rez->dfnc = f;
	return rez;
}

/*
*Returneaza un elem de pe o pozitie data
*int:l,poz
*ies:elem de pe pozitia poz din lista
*pre:pozitia este valida
*/

ElemType elem(Lista* l, int poz) {
	return l->elems[poz];
}

/*
*Modifica elem de pe o pozitia data din lista
*int:l,poz,o
*ies:lista cu elem modificat
*pre:o - oferta valida, poz - pozitia valida
*/
ElemType modific(Lista* l, int poz, ElemType o) {
	ElemType rez = l->elems[poz];
	l->elems[poz] = o;
	return rez;
}

/*
*Returneaza nr de elem din lista
*int:l
*ies:lungimea listei
*/
int lung(Lista* l) {
	return l->lg;
}

/*
Verificare capacitate si alocare daca este necesar
int:l
post:daca nu mai are loc elem care urmeaza sa fie adaugat in lista, se aloca mai mult spatiu(dublu)
*/
void asigurCap(Lista* l) {
	if (l->lg < l->cap) {
		return;
	}

	ElemType* nElems = malloc(sizeof(ElemType)*(l->cap + 2));
	
	for (int i = 0; i < l->lg; i++) {
		nElems[i] = l->elems[i];
	}
	
	free(l->elems);
	l->elems = nElems;
	l->cap += 2;
}

/*
*Adaugare elem in lista
*int:l,el
*pre:el este valid
*post:el este adaugat in lista
*/
void adaug(Lista* l, ElemType el) {
	asigurCap(l);
	l->elems[l->lg] = el;
	l->lg++;
}

/*
*Copiere lista 
*int:l
*ies:rez - copie a lui l
*post:rez contine elem din l
*/
Lista *copieLista(Lista* l, CopyFct cf) {
	/*
		functie care face o copie a unei liste date ca parametru
		in: adresa listei pe care dorim sa o copiem
		cf: funtia pe baza careia se face copierea in functie de ce contine lista
		reutrn: o copie a listei l
	*/
	Lista *rez = creeaza(destroyOferta);
	for (int i = 0; i < lung(l); i++) {
		ElemType o = elem(l, i);
		adaug(rez, cf(o));
	}
	return rez;
}

void testCreeare() {
	Lista *l = creeaza(destroyList);
	assert(lung(l) == 0);
	destroyList(l);
}
void testIterator() {
	Lista *l = creeaza(destroyOferta);
	Data d;
	//add(&l, creeazaOferta("a", "b", 10));
	d = creeazaData(22, 06, 1999);
	adaug(l, creeazaOferta("munte", "Paris", d, 2500));
	//add(&l, creeazaOferta("a2", "b2", 20));
	adaug(l, creeazaOferta("mare", "Santorini", d, 1500));
	assert(lung(l) == 2);
	Oferta *o = elem(l, 0);

	assert(strcmp(o->tip, "munte") == 0);
	o = elem(l, 1);
	assert(strcmp(o->dest, "Santorini") == 0);
	destroyList(l);
	assert(lung(l) == 0);
}

void testCopie() {
	Lista *l = creeaza(destroyOferta);
	Data d;
	d = creeazaData(22, 06, 1999);
	adaug(l, creeazaOferta("munte", "Paris", d, 2500));
	adaug(l, creeazaOferta("mare", "Santorini", d, 1500));
	Lista *l2 = copieLista(l, copyOferta);
	assert(lung(l2) == 2);
	Oferta* o = elem(l2, 0);
	assert(strcmp(o->tip, "munte") == 0);
	destroyList(l);
	destroyList(l2);
}

void testLung() {
	Lista *l = creeaza(destroyOferta);
	Data d;
	d = creeazaData(22, 06, 1999);
	for (int i = 0; i < 10; i++) {
		adaug(l, creeazaOferta("munte", "Paris", d, 2500));
	}
	assert(lung(l) == 10);
	destroyList(l);
	assert(lung(l) == 0);
	assert(l->elems == NULL);
}

ElemType removeLast(Lista* l) {
	/*
		in : l : adresa unei liste
		functie care sterge ultimul element dintrun obiect de tip lista
		return: ultimul obiect de la adresa continuta de l
	*/
	ElemType rez = l->elems[l->lg - 1];
	l->lg--;
	return rez;
}



int size(Lista* l) {
	/*
		functie care returneaza numarul de elemente dintr-o lista data ca parametru prin adresa ei
	*/
	return l->lg;
}

void destroyList(Lista *l) {
	/*
		functie care elibereaza memoria unei liste data ca parametru, folosin functia de distrugere cu care a fost  lista creata
		in: l: o adresa a unui obiet de tip Lista
		out: se elibereaza memoria de la adresa respectiva
	*/
	Oferta *o;
	for (int i = 0; i < l->lg; i++) {
		o = l->elems[i];
		l->dfnc(l->elems[i]);
	}
	free(l->elems);
	free(l);
	l->lg = 0;
	l->elems = NULL;
}
