#pragma once
#include <utility>
#include <list>

using namespace std;

typedef int TElem;


int parinte(int i);

int left(int i);

int right(int i);

// in cazul in care k<=0 se arunca exceptie
// in cazul in care k este mai mare decat numarul de elemente din lista, se sterg toate elementele
void stergeMin(list<TElem>& elemente, int k);
