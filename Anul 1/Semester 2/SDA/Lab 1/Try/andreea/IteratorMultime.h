#pragma once

#include "Multime.h"

//class Multime;

class IteratorMultime
{
	friend class Multime;

private:
	//iteratorul memoreaza o referinta catre container
	const Multime& con;
	//aici alte atribute specifice: curent, etc
	int poz_curenta;

	IteratorMultime(const Multime& c);

	

public:
	TElem element();
	bool valid();
	void urmator();
	void prim();
};
