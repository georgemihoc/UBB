#pragma once
#include "Book.h"

#include "Lista.h"
#include <string>
using namespace std;

template <typename ElemT>class VectDinNewDeleteT;

class BookRepo {
    VectDinNewDeleteT<Book> all;
	/*
	metoda privata verifica daca exista deja p in repository
	*/
	bool exist(const Book& p);
public:
	BookRepo() = default;
	//nu permitem copierea de obiecte
	BookRepo(const BookRepo& ot) = delete;
	/*
	Salvare Book
	arunca exceptie daca mai exista o carte cu acelasi titlu si autor
	*/
	int dim();
	void store(const Book& p);
	void modify(int poz,const Book&p);
	void remove(int poz);

	/*
	Cauta
	arunca exceptie daca nu exista carte
	*/
	Book find(const string& type, const string& species) const;

	/*
	returneaza toate cartile salvate
	*/
	const VectDinNewDeleteT<Book>& getAll() const noexcept;
};

/*
Folosit pentru a semnala situatii exceptionale care pot aparea in repo
*/
class BookRepoException {
	string msg;
public:
	BookRepoException(string m) :msg{ m } {}
	//functie friend (vreau sa folosesc membru privat msg)
	friend ostream& operator<<(ostream& out, const BookRepoException& ex);
};

ostream& operator<<(ostream& out, const BookRepoException& ex);

void testeRepo();