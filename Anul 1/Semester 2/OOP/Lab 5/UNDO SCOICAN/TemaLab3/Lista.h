#pragma once
#include "domain.h"
typedef void* ElemType;
typedef void(*DestroyFct)(ElemType);

typedef struct {
	ElemType* elems;
	int lg;
	int cap; 
	DestroyFct dfnc;
} Lista;

typedef ElemType(*CopyFct)(ElemType);

/*
  Create an empty list
*/
Lista *creeaza(DestroyFct);

/*
  Destroy list
*/
void distruge(Lista* l);

/*
  Get an element from the list
  poz - position of the element, need to be valid
  return element on the given position
*/
ElemType elem(Lista* l, int poz);

/*
Modify the element on the given pozition
return the overwrited element
*/
ElemType modific(Lista* l, int poz, ElemType o);

/*
  return number of elements in the list
*/
int lung(Lista* l);

void asigurCap(Lista* l);

/*
  Add element into the list
  post: element is added to the end of the list
*/
void adaug(Lista* l, ElemType el);
Lista sterge(Lista *l,int poz);

/*
  Make a shallow copy of the list
  return Mylist containing the same elements as l
*/
Lista *copieLista(Lista*, CopyFct);

void testCreeare();
void testIterator();
void testCopie();
void testLung();

ElemType removeLast(Lista* l);


int size(Lista* l);

void destroyList(Lista*);