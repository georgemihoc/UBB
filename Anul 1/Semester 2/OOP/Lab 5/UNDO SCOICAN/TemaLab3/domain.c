#include "domain.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "Lista.h"

/*
*Creeaza oferta noua
*int:tip,dest,d,pret
*ies:oferta formata din campurile date
*pre:campurile sunt valide
*/
Oferta* creeazaOferta(char* tip, char* dest,Data d,int pret) {
	Oferta *rez = malloc(sizeof(Oferta));
	int nrC = strlen(tip) + 1;
	rez->tip = malloc(sizeof(char)*nrC);
	strcpy(rez->tip, tip);
	nrC = strlen(dest) + 1;
	rez->dest = malloc(sizeof(char)*nrC);
	strcpy(rez->dest,  dest);
	rez->data.zi = d.zi;
	rez->data.luna = d.luna;
	rez->data.an = d.an;
	rez->pret = pret;
	return rez;
}

/*
*Creeaza data noua
*int: zi,luna,an - int-uri
*pre: zi,luna,an sunt int-uri
*post:se creeaza structura data
*ies: data D
*/

Data creeazaData(int zi, int luna, int an) {
	Data rez;
	rez.zi = zi;
	rez.luna = luna;
	rez.an = an;
	return rez;
}

void testCreeazaElimin() {
	Data d = creeazaData(22, 6, 1999);
	assert(d.zi == 22);
	assert(d.luna == 6);
	assert(d.an == 1999);

	Oferta *o = creeazaOferta("munte","Apuseni",d,500);
	assert(strcmp(o->tip, "munte") == 0);
	assert(strcmp(o->dest, "Apuseni") == 0);
	assert(o->data.zi == 22);
	assert(o->data.luna == 6);
	assert(o->data.an == 1999);
	assert(o->pret == 500);

	destroyOferta(o);
	assert(o->tip == NULL);
	assert(o->dest == NULL);
	assert(o->pret == -1);
}

Oferta *copyOferta(Oferta *o) {
	return creeazaOferta(o->tip, o->dest, o->data, o->pret);
}

void destroyOferta(Oferta *o) {
	free(o->tip);
	free(o->dest);
	free(o);
	o->tip = NULL;
	o->dest = NULL;
	o->pret = -1;
}