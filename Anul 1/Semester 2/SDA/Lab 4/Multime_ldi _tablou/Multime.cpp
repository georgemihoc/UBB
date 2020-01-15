//
// Created by george on 30/03/2019.
//

#include "Multime.h"
#include <iostream>
using namespace std;
typedef int TElem;
Multime::Multime(int capacity) {
    dimensiune=capacity;
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

Multime::~Multime() {
    dimensiune = 0;
    capacitate = 0;
    delete[] elemente;
    delete[] urmator;
    delete[] precedent;
}

void Multime::initializeaza_spatiu_liber() {
    for (int i = 0; i < dimensiune-1; i++) {
        urmator[i] = i + 1;
        precedent[i + 1] = i;
    }
    urmator[capacitate - 1] = -1;// urmatorul ultimului este NIL
    precedent[0] = -1;// precedentul primului este NIL
    prim_liber = 0; // lista e vida la inceput
}

int Multime::aloca() {
    int i = prim_liber;
    if (i != -1)
        prim_liber = urmator[i];
    return i;
}

void Multime::dealoca(int i) {
    urmator[i] = prim_liber;
    prim_liber = i;
}

int Multime::creeazaNod(TElem e) {
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

int Multime::size() const { return dimensiune;}

MultimeIterator Multime::prim() const {
    return MultimeIterator(*this);
}

bool Multime::search(TElem e) const {
    if(dimensiune==0)
        return false;
    MultimeIterator it = prim();

    int j = 0;
    //cout<<dimensiune;
    while(j<=dimensiune) {
        if (elemente[j] == e) {
            return true;
        }
        j++;
    }
    return false;

}

bool Multime::add(TElem e) {
    if(search(e))
        return false;
    int nou;
    nou = creeazaNod(e);
    if (primul == -1) { //lista e vida
        primul = nou;
        ultimul = nou;
        ++dimensiune;
        //prim_liber=1;
    }
    else {
        //std::cout<<"tun";
        //adaugam dupa ultimul
        precedent[nou] = ultimul;
        urmator[ultimul] = nou;
        ultimul = nou;
        //prim_liber=;
        ++dimensiune;
    }
    //for(int i=0;i<dimensiune;i++)
        //std::cout<<elemente[i]<<" "<<std::endl;
    return true;
}


bool Multime::remove(TElem e)
{

    if(!search(e))
        return false;
    MultimeIterator poz = prim();

    int j = 0;
    //cout<<dimensiune;
    while(j<=dimensiune) {
        if (elemente[j] == e) {
            elemente[j]=-999;
            break;
            //return true;
        }
        poz.next();
        j++;
    }
/*
    if (!poz.valid()) {
		throw std::exception();
	}*/

	int de_sters = poz.curent;
	int de_dealocat = poz.curent;
	if (primul == ultimul && de_sters == primul) {
		//in lista se afla un singur element
		primul = -1;
		ultimul = -1;
		--dimensiune;

		return true;
	}

	if (de_sters == primul) {
		// stergem primul element din lista
		precedent[urmator[de_sters]] = -1;
		primul = urmator[de_sters];
		--dimensiune;
		return true;
	}

	if (de_sters == ultimul) {
		//stergem ultimul element din lista
		urmator[precedent[de_sters]] = -1;
		ultimul = precedent[de_sters];
		--dimensiune;
		return true;
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
		return true;
	}
    dealoca(de_dealocat);

    //nu exista elementul de sters

}

bool Multime::isEmpty() const { return (dimensiune==0);}

MultimeIterator Multime::iterator() const {
    return MultimeIterator(*this);
}