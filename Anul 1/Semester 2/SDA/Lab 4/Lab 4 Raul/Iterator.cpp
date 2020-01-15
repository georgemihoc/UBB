#include "Iterator.h"
#include<exception>

class Lista;

IteratorLP::IteratorLP(const Lista&l):list(l)
{
	curent = l.primul;
}


IteratorLP::~IteratorLP()
{
}

void IteratorLP::prim() {
	curent = list.primul;
}

void IteratorLP::urmator() {
	if (curent == -1)
		throw std::exception();
	curent = list.urmator[curent];
}

bool IteratorLP::valid() const {
	return curent != -1;
}

TElem IteratorLP::element() {
	if (this->curent == -1)
		throw std::exception();
	return this->list.elemente[this->curent];
}

















