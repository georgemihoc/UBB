#include "Multime.h"
#include "IteratorMultime.h"
#include <iostream>

// aici implementarea operatiilor din Multime.h


bool rel(TElem e1, TElem e2) {
	return e1 <= e2;
}

Multime::Multime() {
	// TBA 
	cap = 5000;
	lg = 0;
	elems = new TElem[cap];
}

TElem* Multime::expand_cap(int lung) {
	cap = lung * 2;
	TElem* new_elems = new TElem[cap];
	for (int i = 0; i < lung; i++) {
		new_elems[i] = elems[i];
	}
	return new_elems;
}


bool Multime::adauga(TElem e)
{
	int lungime = dim();
	int poz, i;

	for (i = 0; i < lungime; i++) {
		if (e == elems[i])
			return false;
		else if (!rel(elems[i], e))	break;
	}

	poz = i;
	if (lg == cap)	this->elems = this->expand_cap(this->cap);

	
	for (i = lg; i > poz; i--) {
		elems[i] = elems[i - 1];
	}
	elems[poz] = e;
	lg++;
	return true;
}

bool Multime::sterge(TElem e)
{
	int lungime = dim();
	int poz;
	bool gasit = false;
	for (int i = 0; i < lg; i++) {
		if (e == elems[i]) {
			gasit = true;
			poz = i;
			break;
		}
	}
	if (gasit) {
		for (int i = poz; i < lg - 1; i++) {
			elems[i] = elems[i + 1];
		}
		lg--;
		return true;
	}
	else
		return false;
}

bool Multime::cauta(TElem elem) const
{
	int i = 0;
	for (; i < lg; i++) {
		if (elem == elems[i])	return true;
	}
	return false;
}



int Multime::dim() const
{
	return lg;
}

bool Multime::vida() const
{
	return lg == 0;
}

TElem Multime::element(int poz) const {
	return elems[poz];
}


IteratorMultime Multime::iterator() const {
	return IteratorMultime(*this);
}


Multime::~Multime() {
	delete elems;
}


// restul operatiilor