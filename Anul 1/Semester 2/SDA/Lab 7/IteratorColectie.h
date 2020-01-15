#pragma once
#include<stack>
using namespace std;

class Colectie;
class Nod;

//iterator unidirectional pe un Container
class IteratorColectie {
private:
	//constructorul primeste o referinta catre Container
	//iteratorul va referi primul element din container
	
	//contine o referinta catre containerul pe care il itereaza
	const Colectie& c;
	stack<Nod*> st;

	Nod *pozElem;
	int frecvElem;

	/* aici e reprezentarea specifica a iteratorului*/

public:

	IteratorColectie(const Colectie& c);

	//reseteaza pozitia iteratorului la inceputul containerului
	void prim();

	//muta iteratorul in container
	// arunca exceptie daca iteratorul nu e valid
	void urmator();

	//verifica daca iteratorul e valid (indica un element al containerului)
	bool valid() const;

	//returneaza valoarea elementului din container referit de iterator
	//arunca exceptie daca iteratorul nu e valid
	int element() const;

};
