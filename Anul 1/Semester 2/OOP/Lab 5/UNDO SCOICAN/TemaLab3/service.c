#include "service.h"

#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "sort.h"
#include <stdbool.h>
/*
*Adaugare oferta in lista 
*int:agent,tip,dest,zi,luna,an,pret
*pre:datele sunt valide
*post:se adauga oferta in lista
*/
int adaugOferta(Agentie* agent, char* tip, char* dest, int zi, int luna, int an, int pret) {
	Data d = creeazaData(zi, luna, an);
	Oferta *o = creeazaOferta(tip, dest,d, pret);
	Lista *to_undo = copieLista(agent->Oferte, copyOferta);
	adaug(agent->Oferte, o);
	adaug(agent->undolist, to_undo);
	return 0; 
}

/*
*Stergere oferta din lista
*int:l,poz
*pre:poz este valida
*post:se sterge elem de pe pozitia poz si se elibereaza memoria pt acel elem
*/

void stergeOferta(Lista* l, int poz)
{
	ElemType* rez = malloc(l->cap * sizeof(Oferta));
	int i, j = 0;
	for (i = 0; i < lung(l); i++)
	{
		if (i == poz)
		{
			destroyOferta(l->elems[i]);
		}
		if (i != poz)
		{
			rez[j] = l->elems[i];
			j++;
		}
	}
	free(l->elems);
	l->elems = rez;
	l->lg--;
}

/*
*Returneaza o lista formata din elem care au tipul egal cu un tip dat, iar daca acesta este NULL returneaza o lista cu toate elem
*int:agent,tip
*pre:tip este valid
*ies:rez - lista cu elem care satisfac prop
*post:rez contine elem care au tipul egal cu variabila tip
*/
Lista *FiltOferteTip(Agentie* agent, char* tip) {
	if (tip== NULL || strlen(tip) == 0) {
		return copieLista(agent->Oferte, copyOferta);
	}
	Lista *rez = creeaza(destroyOferta);
	for (int i = 0; i < lung(agent->Oferte); i++) {
		Oferta *o = elem(agent->Oferte, i);
		if (strstr(o->tip, tip) != NULL) {
			adaug(rez, copyOferta(o));
		}
	}
	return rez;
}
/*
*Returneaza o lista formata din elem care au dest egala cu dest data
*int:agent,dest
*ies:rez - lista cu elem cu dest egala cu dest data, sau in cazul in care dest este vida/NULL toate elem 
*/
Lista *FiltOferteDest(Agentie* agent, char* dest) {
	if (dest == NULL || strlen(dest) == 0) {
		return copieLista(agent->Oferte, copyOferta);
	}
	Lista* rez = creeaza(destroyOferta);
	for (int i = 0; i < lung(agent->Oferte); i++) {
		Oferta *o = elem(agent->Oferte, i);
		if (strstr(o->dest, dest) != NULL) {
			adaug(rez, copyOferta(o));
		}
	}
	return rez;
}
/*
*Returneaza o lista formata din elem care au pretul <= cu un pret dat
*int:agent,pret
*ies:rez - lista cu toate elem care respecta prop sau in cazul in care pretul nu este valid rez contine toate elem
*/
Lista* FiltOfertePret(Agentie* agent, int pret) {
	if (pret < 0) {
		return copieLista(agent->Oferte, copyOferta);
	}
	Lista *rez = creeaza(destroyOferta);
	for (int i = 0; i < lung(agent->Oferte); i++) {
		Oferta *o = elem(agent->Oferte, i);
		if (o->pret <= pret) {
			adaug(rez, copyOferta(o));
		}
	}
	return rez;
}

/*
*Returneaza o lista formata din elem care sunt dintr.un an dat
*int:agent,pret
*ies:rez - lista cu toate elem care respecta prop sau in cazul in care pretul nu este valid rez contine toate elem
*/
Lista* FiltOferteYear(Agentie* agent, int year) {
	if (year < 0) {
		return copieLista(agent->Oferte, copyOferta);
	}
	Lista *rez = creeaza(destroyOferta);
	for (int i = 0; i < lung(agent->Oferte); i++) {
		Oferta *o = elem(agent->Oferte, i);
		if (o->data.an == year) {
			adaug(rez, copyOferta(o));
		}
	}
	return rez;
}

/*
*Comparare alfabetica (descrescatoare) a doua destinatii
*int:p1,p2 - oferte
*ies: 1 - daca dest2 > dest1
*	 0 - daca dest2 == dest1
*	-1 - altfel
*pre:p1,p2 - oferte valide
*/
int cmpDest(Oferta* p1, Oferta* p2) {
	return -1 * strcmp(p1->dest, p2->dest);
}

/*
*Comparare a doua preturi
*int:p1,p2 - oferte
*ies: 1 - daca pret1 > pret2
*	 -1 - altfel
*pre:p1,p2 - oferte valide
*/
int cmpPret(Oferta* p1, Oferta* p2) {
	if (p1->pret > p2->pret)
		return 1;
	else
		return -1;
}

/*
*Sortare descrescatoare dupa dest
*int:agent
*ies:l - lista ordonata
*post: elem din lista sunt ordonate descresc dupa dest
*/
Lista *sortDest(Agentie* agent) {
	Lista *l = copieLista(agent->Oferte, copyOferta);
	sort(l, cmpDest);
	return l;
}

/*
*Sortare crescatoare dupa pret
*int:agent
*ies:l - lista ordonata
*post: elem din lista sunt ordonate cresc dupa pret
*/
Lista *sortPret(Agentie* agent) {
	Lista *l = copieLista(agent->Oferte, copyOferta);
	sort(l, cmpPret);
	return l;
}

/*
*Creeaza o agentie
*ies:rez - agentie goala
*post:rez este gol
*/
Agentie creeazaAgent()
{
	Agentie rez;
	//rez->dim_undo = 0;
	rez.Oferte = creeaza(destroyOferta);
	rez.undolist = creeaza(destroyList);
	rez.redoList = creeaza(destroyList);
	return rez;
}

/*
*Distruge agentie
*int:agent
*post:este eliberata memoria ocupata de agent
*/
void distrugeAgent(Agentie * agent)
{
	destroyList(agent->Oferte);
	destroyList(agent->undolist);
}

void testAdaug() {
	Agentie agent = creeazaAgent();
	Data d;
	d = creeazaData(22, 06, 1999);
	adaugOferta(&agent, "Mountain", "tun",22,06,1999, 2500);
	adaugOferta(&agent, "Beach", "tun", 22, 06, 1999, 1500);
	adaugOferta(&agent, "City Break", "tun", 22, 06, 1999, 1900);
	Lista* rez = FiltOferteTip(&agent, NULL);
	assert(lung(rez) == 3);

	stergeOferta(rez, 2);
	assert(lung(rez) == 2);
	destroyList(rez);

	rez = FiltOferteTip(&agent, "Mountain");
	assert(lung(rez) == 1);
	destroyList(rez);

	rez = FiltOferteDest(&agent, NULL);
	assert(lung(rez) == 3);
	destroyList(rez);

	rez = FiltOferteDest(&agent, "tun");
	assert(lung(rez) == 3);
	destroyList(rez);

	rez = FiltOfertePret(&agent, -1);
	assert(lung(rez) == 3);
	destroyList(rez);

	rez = FiltOfertePret(&agent, 2400);
	assert(lung(rez) == 2);
	destroyList(rez);
	adaugOferta(&agent, "City Break", "tun", 22, 06, 2014, 1900);
	rez = FiltOferteYear(&agent, 2014);
	assert(lung(rez) == 1);
	destroyList(rez);

	rez = FiltOferteYear(&agent, 2014);
	destroyList(rez);

	distrugeAgent(&agent);
}

void testSort() {
	Agentie agent = creeazaAgent();
	Data d;
	d = creeazaData(22, 06, 1999);
	adaugOferta(&agent, "Mountain", "tun", 22, 06, 1999, 2500);
	adaugOferta(&agent, "Beach", "tun", 22, 06, 1999, 1500);
	adaugOferta(&agent, "City Break", "tun", 22, 06, 1999, 1900);
	Lista *l = sortDest(&agent);
	Oferta *o = elem(l, 1);
	assert(strcmp(o->tip, "City Break") != 0);
	destroyList(l);
	l = sortPret(&agent);
	o = elem(l, 0);
	assert(strcmp(o->dest, "tun") == 0);
	o = elem(l, 1);
	assert(strcmp(o->dest, "tun") == 0);
	destroyList(l);
	distrugeAgent(&agent);
}

int undo(Agentie *agent) {
	/*
		functie care face undo, copiaza ultimul element din agent.undo, in lista actuala de oferte
	*/
    Lista *to_undo = copieLista(agent->Oferte, copyOferta);
    adaug(agent->redoList, to_undo);

    if (size(agent->undolist) == 0) {
		return 1; // nu se mai poate face undo
	}
	//agent->dim_undo--;
	Lista *l = removeLast(agent->undolist);
	destroyList(agent->Oferte);
	agent->Oferte = l;
	return 0;
}
int redo(Agentie *agent)
{
    if (size(agent->redoList) == 0) {
        return 1; // nu se mai poate face undo
    }
    //agent->dim_undo--;
    Lista *l = removeLast(agent->redoList);
    destroyList(agent->Oferte);
    agent->Oferte = l;
    return 0;
}
Lista *get_all(Agentie* agent) {
	/*
		functe care returneza o lista de oferte din agent.oferte
	*/
	return copieLista(agent->Oferte, copyOferta);
}


void test_undo() {
	Agentie agent = creeazaAgent();
	adaugOferta(&agent, "Mountain", "tun", 22, 06, 1999, 2500);
	adaugOferta(&agent, "Beach", "tun", 22, 06, 1999, 1500);
	undo(&agent);
	Lista* l = get_all(&agent);
	assert(size(l) == 1);
	destroyList(l);

	undo(&agent);
	l = get_all(&agent);
	assert(size(l) == 0);
	destroyList(l);

	assert(undo(&agent) != 0);
	assert(undo(&agent) != 0);
	assert(undo(&agent) != 0);

	distrugeAgent(&agent);
}