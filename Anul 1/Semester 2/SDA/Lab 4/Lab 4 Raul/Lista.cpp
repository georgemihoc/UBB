#include "Lista.h"
#include <exception>


Lista::Lista()
{
	capacitate = 3;
	dimensiune = 0;
	elemente = new TElem[capacitate];
	urmator = new int[capacitate];
	precedent = new int[capacitate];
	prim_liber = -1;
	primul = -1;
	ultimul = -1;
	initializeaza_spatiu_liber();
}


Lista::~Lista()
{
	dimensiune = 0;
	capacitate = 0;
	delete[] elemente;
	delete[] urmator;
	delete[] precedent;
}

int Lista::dim() const {
	return dimensiune;
}

bool Lista::vida() const {
	return  dimensiune == 0;
}

void Lista::initializeaza_spatiu_liber() {
	for (int i = 0; i < capacitate-1; i++) {
		urmator[i] = i + 1;
		precedent[i + 1] = i;
	}
	urmator[capacitate - 1] = -1;// urmatorul ultimului este NIL
	precedent[0] = -1;// precedentul primului este NIL
	prim_liber = 0; // lista e vida la inceput
}

int Lista::aloca() {
	int i = prim_liber;
	if (i != -1)
		prim_liber = urmator[i];
	return i;
}

void Lista::dealoca(int i) {
	urmator[i] = prim_liber;
	prim_liber = i;
}

int Lista::creeazaNod(TElem e) {
	if (prim_liber == -1) { //lista plina
		// redimensionare
		// copiere elemente + legaturi
		// reinitializam lista spatiului liber

		TElem *vector_nou = new TElem[capacitate * 2];
		int *urmator_nou = new int[capacitate * 2];
		int *precedent_nou = new int[capacitate * 2];

		for (int i = 0; i < capacitate; i++) {
			vector_nou[i] = elemente[i];
			urmator_nou[i] = urmator[i];
			precedent_nou[i] = precedent[i];
		}

		prim_liber = capacitate; // prima pozitie libera e prima pozitie din a doua jum a noului tablou
		
		// formam o ordine intre elementele libere
		for (int i = capacitate; i < capacitate * 2 - 1; i++) {
			urmator_nou[i] = i + 1;
			precedent_nou[i + 1] = i;
		}

		urmator_nou[capacitate * 2 - 1] = -1;
		precedent_nou[capacitate] = -1;

		capacitate *= 2;

		delete[] elemente;
		delete[] urmator;
		delete[] precedent;

		elemente = vector_nou;
		urmator = urmator_nou;
		precedent = precedent_nou;
	}
	int poz_noua = aloca();
	elemente[poz_noua] = e;
	urmator[poz_noua] = -1;
	precedent[poz_noua] = -1;
	return poz_noua;
}

IteratorLP Lista::prim() const {
	return IteratorLP(*this);
}

TElem Lista::element(IteratorLP it) const {
	if (!it.valid()) {
		throw std::exception();
	}
	if (it.curent == -1)
		return -1;
	return elemente[it.curent];
}

TElem Lista::modifica(IteratorLP poz, TElem e) {
	if (!poz.valid()) {
		throw std::exception();
	}
	int i = poz.curent;
	TElem aux = elemente[i];
	elemente[i] = e;
	return aux;
}

void Lista::adaugaSfarsit(TElem e) {
	int nou = creeazaNod(e);
	if (primul == -1) { //lista e vida
		primul = nou;
		ultimul = nou;
		++dimensiune;
		return;
	}
	//adaugam dupa ultimul
	precedent[nou] = ultimul;
	urmator[ultimul] = nou;
	ultimul = nou;
	++dimensiune;
}

void Lista::adauga(IteratorLP& poz, TElem e) {
	if (!poz.valid())
		throw std::exception();
	++dimensiune;
	int nou = creeazaNod(e);
	// verificam daca lista e vida
	if (primul == -1) {
		primul = nou;
		ultimul = nou;
		return;
	}
	precedent[nou] = precedent[poz.curent];
	urmator[precedent[poz.curent]] = nou;
	urmator[nou] = poz.curent;
	precedent[poz.curent] = nou;
	TElem aux = elemente[poz.curent];
	elemente[poz.curent] = e;
	elemente[urmator[poz.curent]] = aux;
}

TElem Lista::sterge(IteratorLP& poz) {
	if (!poz.valid()) {
		throw std::exception();
	}

	int de_sters = poz.curent;
	int de_dealocat = poz.curent;
	if (primul == ultimul && de_sters == primul) {
		//in lista se afla un singur element
		primul = -1;
		ultimul = -1;
		--dimensiune;

		TElem aux = elemente[de_sters];
		poz.curent = -1;
		return aux;
	}

	if (de_sters == primul) {
		// stergem primul element din lista
		precedent[urmator[de_sters]] = -1;
		primul = urmator[de_sters];
		--dimensiune;

		int pozitie_noua = urmator[de_sters];
		TElem aux = elemente[de_sters];
		poz.curent = pozitie_noua;
		return aux;
	}

	if (de_sters == ultimul) {
		//stergem ultimul element din lista
		urmator[precedent[de_sters]] = -1;
		ultimul = precedent[de_sters];
		--dimensiune;

		TElem aux = elemente[de_sters];
		poz.curent = -1;
		return aux;
	}

	//se sterge din interiorul listei
	de_sters = primul;
	while (de_sters != poz.curent && urmator[de_sters] != -1) {
		de_sters = urmator[de_sters];
	}

	int pozitie_noua = urmator[de_sters];
	if (urmator[de_sters] != -1) {
		// elementul de sters a fost gasit
		urmator[precedent[de_sters]] = urmator[de_sters];
		precedent[urmator[de_sters]] = precedent[de_sters];
		--dimensiune;

		TElem aux = elemente[poz.curent];
		poz.curent = pozitie_noua;
		return aux;
	}

	//nu exista elementul de sters
	return -1;
	dealoca(de_dealocat);
}

IteratorLP Lista::cauta(TElem e) const {
	IteratorLP it = prim();
	if (elemente[it.curent] == e) {
		return it;
	}

	int j = primul;
	if (!it.valid())
		return it;
	while (j != -1 && elemente[j] != e)
		j = urmator[j];
	if (j != -1 && elemente[j] == e) {
		it.curent = j;
		return it;
	}
	//pozitia unde ar trebui sa fie elementul dar este loc liber
	it.curent = -1;
	return it;
}