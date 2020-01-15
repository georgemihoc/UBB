#include "IteratorMultime.h"
#include "Multime.h"


IteratorMultime::IteratorMultime(const Multime& c) : con(c) {
	// initializare curent si alte atribute specifice
	poz_curenta = 0;
}

TElem IteratorMultime::element() {
	return con.element(poz_curenta);
}

bool IteratorMultime::valid() {
	if (con.dim() == poz_curenta)
		return false;
	return true;
}

void IteratorMultime::urmator() {
	poz_curenta++;
}

void IteratorMultime::prim() {
	poz_curenta = 0;
}