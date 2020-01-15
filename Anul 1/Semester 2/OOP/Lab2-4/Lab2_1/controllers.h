//
// Created by George on 2019-03-08.
//

#ifndef LAB2_CONTROLLERS_H
#define LAB2_CONTROLLERS_H
#include "Materie.h"
int adaugare(char nume[20],char producator[20], int cantitate);
int modificare_controller(char nume_1[20],char producator_nou[20],int cantitate_nou);
int stergere_controller(char nume_1[20]);
int vizualizare_litera(Materie *a[100],char litera);
int vizualizare_numar(Materie *a[100], int nr);
void sortare_nume_controller(char ordine[20]);
int sortare_cantitate_controller(char ordine[20]);
int getAll(Materie *a[100]);
#endif //LAB2_CONTROLLERS_H
