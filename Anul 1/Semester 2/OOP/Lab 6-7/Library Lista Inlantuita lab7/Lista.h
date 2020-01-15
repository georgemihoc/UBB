#pragma once
#include<exception>
#include <memory>
template<typename Tip>class Iterator;
template<typename Tip>class Lista;


template <typename Tip>class Nod {
	friend class Iterator<Tip>;
	friend class Lista<Tip>;
	//Tip informatie;
	Nod *next;
	Nod *prev;
public:
	//metode
	Tip informatie;
	Nod() = default;
	Nod(Tip info) :informatie{ info } { prev = NULL; next = NULL; };
	//Nod() { next = NULL; prev = NULL; };
	~Nod() {}
	//Nod(Tip info) { this->informatie = info; next = NULL; prev = NULL; }
	Tip get_info() { return informatie; }

	void set_informatie(Tip info_noua) { this->informatie = info_noua; }
	void set_next(Nod* next) { this->next = next; }
	void set_prev(Nod* prev) { this->prev = prev; }
	//void aloca() { }
};


template<typename Tip>class Iterator;

template <typename Tip>class Lista {
	friend class Iterator<Tip>;
	friend class Nod<Tip>;
	Nod<Tip>* head;
	Nod<Tip>* tail;
	int dimensiune;
public:
	//metode LISTA

	Lista() { head = NULL; tail = NULL; dimensiune = 0; }
	Iterator<Tip> cauta(Tip info_in_nod) const; 
	void adauga_sfarsit(Tip info_nod);
	Tip sterge(Iterator<Tip> poz);
	Tip modifica(Iterator<Tip> poz, const Tip& e);
	int size() { return dimensiune; }
	Iterator<Tip> begin() {
		Iterator<Tip> it(*this);
		it.nod_curent = head;
		return it;
	}
	Tip& produs_de_pe_pozitie(int poz) {
		Iterator<Tip> it(*this);
		int j = 0;
		while (it.valid() && j < poz) {
			it.urmator();
			j++;
		}
		return it.informatie_nod();
	}

};

template<typename Tip>
Tip Lista<Tip>::modifica(Iterator<Tip>poz_de_modificat, const Tip& info_noua) {
	Tip val = poz_de_modificat.informatie_nod();
	Nod<Tip> *nod = poz_de_modificat.nod_curent;
	nod->informatie = info_noua;
	return val;
}



template<typename Tip>
Tip Lista<Tip>::sterge(Iterator<Tip> poz) {
	
	--dimensiune;
	Tip aux = poz.informatie_nod();
	Nod<Tip>* nod_cure = poz.nod_curent;
	if (nod_cure == head) {
		//NodeDL *head_nou = nod_cure->next;
		//head_nou 
		head = head->next;
		if (head != nullptr)
			head->prev = nullptr;
		else
			tail = nullptr;
		return aux;
	}
	if (tail == nod_cure) {
		tail = tail->prev;
		tail->next = nullptr;
	}
	else {
		nod_cure->prev->next = nod_cure->next;
		nod_cure->next->prev = nod_cure->prev;
	}
	free(nod_cure);
	return aux;
}



template<typename Tip>
Iterator<Tip> Lista<Tip>::cauta(Tip info_in_nod) const{
		Iterator<Tip> it(*this);
		bool a = it.valid();
		//Tip p = it.informatie_nod();
		//bool b = it.informatie_nod() != info_in_nod;
		while (it.valid() && it.informatie_nod() != info_in_nod)
		{
			it.urmator();
		}
		return it;
}

template<typename Tip>
void Lista<Tip>::adauga_sfarsit(Tip info_nod) {
	++dimensiune;
	Nod<Tip>* neww = new Nod<Tip>(info_nod);
	//neww->informatie = info_nod;
	//neww->aloca();

	//Nod<Tip> *neww = new Nod<Tip>(info_nod);
	//Nod<Tip> *neww = new Nod<Tip>(); ---> NU MERGE NICI ASA, EROAREA E LA FEL
	//neww->set_informatie (info_nod);
	//neww->set_next(nullptr);
	//neww->set_prev(nullptr);
	if (tail == nullptr) {
		head = tail = neww;
	}
	else {
		tail->next = neww;
		neww->prev = tail;
		tail = neww;
	}
}

template<typename Tip>class Iterator{
	friend class Lista<Tip>;
	friend class Nod<Tip>;

private:
	Iterator(const Lista<Tip>& l);
	const Lista<Tip>& list;
	Nod<Tip> *nod_curent;
public:
	//reseteaza pozitia iteratorului la inceputul containerului
	void begin() { nod_curent = list.head; }

	//muta iteratorul in container
	// arunca exceptie daca iteratorul nu e valid
	void urmator() { if (!valid()) throw std::exception(); nod_curent = nod_curent->next; }

	//verifica daca iteratorul e valid (indica un element al containerului)
	bool valid() const { return nod_curent != NULL; }

	//returneaza valoarea elementului din container referit de iterator
	//arunca exceptie daca iteratorul nu e valid
	Tip& informatie_nod() const { if (!valid()) throw std::exception(); return nod_curent->informatie; }
};

template<typename Tip>class Iterator;
template<typename Tip>
Iterator<Tip>::Iterator(const Lista<Tip>& l) : list{ l } {
	nod_curent = l.head;
}