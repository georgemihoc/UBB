//
// Created by George on 2019-03-27.
//

#ifndef TEMALAB3_CONSOLE_H
#define TEMALAB3_CONSOLE_H

#include "domain.h"
#include "service.h"
void test();
void run();
void menu();
void filtrareData(Agentie* agent) ;
void filtrarePret(Agentie* agent);
void filtrareDest(Agentie* agent);
void filtrareTip(Agentie* agent) ;
void sortareDest(Agentie* agent);
void sortarePret(Agentie* agent) ;
void afisOferte(Agentie* agent) ;
void printOferte(Lista* l) ;
void modificareOferta(Agentie* agent, int poz);
void stergereOferta(Agentie* agent, int poz);
void adaugaOferta(Agentie* agent) ;
void test_validare() ;
int validOferta(char* tip, char* dest, int zi, int luna, int an, int p);


#endif //TEMALAB3_CONSOLE_H
