#pragma once

class IteratorColectie;
typedef int TElem;
typedef bool(*Relatie)(TElem, TElem);

//in implementarea operatiilor se va folosi functia (relatia) rel (de ex, pentru <=)
// va fi declarata in .h si implementata in .cpp ca functie externa colectiei
bool rel(TElem, TElem);

class Nod {
public:

	TElem element;
	int frecventa;
	Nod *st, *dr, *parinte;
	Nod(TElem element1, int frecventa1)
	{
		element = element1;
		frecventa = frecventa1;
		st = dr = parinte = nullptr;
	}

	~Nod()
	{
		element = 0;
		frecventa = -999999;
		st = dr = parinte = nullptr;
	}
};



//interfata colectiei nu se modifica
class Colectie {
private:

	friend IteratorColectie;
	Nod *rad;
	Relatie relatie;
	Nod* minim(Nod* subarbore);
	Nod* succesor(Nod* nod);
	void sterge_rec(Nod *arbore, TElem e);
	int nrElem = 0;

public:
	//constructorul implicit
	Colectie();

	Nod* search(TElem elem);

	//adauga un element in colectie
	void adauga(TElem e);

	//sterge o aparitie a unui element din colectie
	//returneaza adevarat daca s-a putut sterge
	bool sterge(TElem e);
	
	//verifica daca un element se afla in colectie
	bool cauta(TElem elem) const;
	
	
	//returneaza numar de aparitii ale unui element in colectie
	int nrAparitii(TElem elem) const;

	
	//intoarce numarul de elemente din colectie;
	int dim() const;

	
	//verifica daca colectia e vida;
	bool vida() const;

	//returneaza un iterator pe colectie
	IteratorColectie iterator() const;

	// destructorul colectiei
	~Colectie();

	void diferenta(Colectie &c2);
};
