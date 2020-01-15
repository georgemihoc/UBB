#pragma once
#include "Book.h"

#include <vector>
#include <string>
using namespace std;


class BookRepo {
	vector<Book> all;
	vector<Book> all_basket;
	/*
	metoda privata verifica daca exista deja p in repository
	*/
	bool exist(const Book& p);
	bool exist_basket(const Book& p);

public:
	BookRepo() = default;
	//nu permitem copierea de obiecte
	BookRepo(const BookRepo& ot) = delete;
	/*
	Salvare Book
	arunca exceptie daca mai exista o carte cu acelasi titlu si autor
	*/
	int dim();
	int dim_basket();
	void store(const Book& p);
	void store_basket(const Book& p);
	void random_basket(int nr);
	void modify(int poz,const Book&p);
	void remove(int poz);
	void remove_all();
	void remove_basket();


	/*
	Cauta
	arunca exceptie daca nu exista carte
	*/
	Book find(const string& titlu, const string& autor) const;
	Book find_basket(const string& titlu, const string& autor) const;

	/*
	returneaza toate cartile salvate
	*/
	const vector<Book>& getAll() const noexcept;
	const vector<Book>& getAllBasket() const noexcept;


};
/*
class Basket{
	vector<Book> all_basket;
public:
	Basket() = default;
	//nu permitem copierea de obiecte
	Basket(const Basket& ot) = delete;

	Salvare Book
	arunca exceptie daca mai exista o carte cu acelasi titlu si autor

	int dim_basket();


	Cauta
	arunca exceptie daca nu exista carte



	returneaza toate cartile salvate

};*/
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