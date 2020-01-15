#pragma once

#include "Lista.h"

typedef struct {
	Lista *Oferte;
	Lista *undolist;
	Lista *redoList;
	int dim_undo;
} Agentie;

Agentie creeazaAgent();

void distrugeAgent(Agentie* agent);

int adaugOferta(Agentie* agent, char* tip, char* dest,int zi,int luna,int an ,int price);

void stergeOferta(Lista* l, int poz);

Lista *FiltOferteTip(Agentie* agent, char* tip);
Lista *FiltOferteDest(Agentie* agent, char* dest);
Lista *FiltOfertePret(Agentie* agent, int pret);
Lista* FiltOferteYear(Agentie* agent, int year);


int cmpDest(Oferta* p1, Oferta* p2);
int cmpPret(Oferta* p1, Oferta* p2);
/*
Sort ascending by dest
*/
Lista *sortDest(Agentie* agent);

/*
Sort ascending by pret
*/
Lista *sortPret(Agentie* agent);


void testAdaug();
void testSort();

int undo(Agentie *agent);
int redo(Agentie *agent);
void test_undo();

Lista *get_all(Agentie*);