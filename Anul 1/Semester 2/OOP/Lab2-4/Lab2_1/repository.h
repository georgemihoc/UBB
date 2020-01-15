//
// Created by George on 2019-03-07.
//

//#ifndef LAB2_MAXIM_H
//#define LAB2_MAXIM_H
#pragma once
#include "Materie.h"
/*
Vector static care are o lungime si un sir de elemente
*/
//int i=0;
int adaugare_repo(char nume[20], char producator[20], int cantitate);
int modificare_repo(char nume_1[20],char producator_nou[20],int cantitate_nou);
int stergere_repo(char nume_1[20]);
void sortare_nume_repo(char ordine[20]);
void sortare_cantitate_repo(char ordine[20]);
int getAll_repo(Materie *a[100]);
void teste_repo();
void teste_adaugare();
void teste_stergere();
void teste_modificare();
void teste_sortare();

/*
Citire vector
v-element de tip Vector
*/
//void citire(Materie *v);

//#endif //LAB2_MAXIM_H