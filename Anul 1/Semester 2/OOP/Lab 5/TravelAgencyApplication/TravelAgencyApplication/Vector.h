#pragma once
#include "Package.h"
#include <stdlib.h>
typedef void* ElemType;
typedef ElemType(*CopyFct) (ElemType);
typedef void(*DestroyFct) (ElemType);

typedef struct {
	ElemType * packages;
	int length;
	int capacity;
    DestroyFct dfnc;//used on destroy to release elements
}Vector;
ElemType get(Vector* l, int poz);

int size(Vector* l);
Vector* copyList(Vector l);

//Constructor for Vector
Vector* createVector();
Vector* createUndoVector();
//UndoVector createUndoVector();


//Deconstructor for vector
void destroyVector(Vector* vector);
ElemType removeLast(Vector* l);


//Function that ensures there is room in the vector
void ensureCapacity(Vector* vector);

//Function that returns a package
//Returns the package from the given position in the vector
ElemType getPackage(Vector* vector, int position);
Package* getVector(Vector* vector);


//Function that returns a copy of a package
Package copyPackage(Vector * vector, int position);

//Function that swaps the elements from 2 given positions in a given vector
void swapElem(Vector* vector, int i, int j);

//Function that returns the number of elements in a given vector
int length(Vector* vector);

//Function that returns the capacity of a given vector
int getCapacity(Vector* vector);

//Function that searches a given vector for a given package
//Returns the position in the vector of the package,or -1 if the package is not found
int search(Vector* vector, Package* package);

//Function that appends a given package to a given vector
//Returns 1 if package added with succes,0 otherwise
void append(Vector * vector, ElemType package);
///void appendUndo(Vector *vector, Vector * v);

//void append(Vector* vector, ElemType package);

//Function that removes a given package to a given vector
//Returns 1 if package is removed with succes,0 otherwise
int del(Vector* vector, Package* package);