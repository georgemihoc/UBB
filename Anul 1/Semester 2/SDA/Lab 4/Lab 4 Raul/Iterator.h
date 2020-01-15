#pragma once
#include "Lista.h"

typedef int TElem;
class Lista;
class IteratorLP {
	friend class Lista;
private:
	int curent; //index
	const Lista& list;



public:

	IteratorLP (const Lista& l);
	~IteratorLP();
	void prim();
	void urmator();
	bool valid() const;
	TElem element();
};