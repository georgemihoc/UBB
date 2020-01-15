#pragma once
typedef struct {
	int zi;
	int luna;
	int an;
} Data;

typedef struct {
	char* tip;
	char* dest;
	Data data;
	int pret;
} Oferta;


/*
Creeaza Oferta
*/
Oferta* creeazaOferta(char* tip, char* dest, Data data, int pret);
/*
Creeaza Data
*/
Data creeazaData(int zi, int luna, int an);

/*
Eliminare Oferta
*/

Oferta* copieOferta(Oferta o);

void testCreeazaElimin();

Oferta *copyOferta(Oferta *o);

void destroyOferta(Oferta*);
