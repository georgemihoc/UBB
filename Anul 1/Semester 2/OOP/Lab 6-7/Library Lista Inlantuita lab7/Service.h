#pragma once
#include "Repository.h"
#include "Validator.h"
#include <functional>
#include <algorithm>

typedef bool(*CMPF)(const Book&, const Book&);
using namespace std;

class Service
{
	Repository &repo;
	Validator &val;

	Lista<Book> filtreaza(function<bool(const Book&)> func) const;

public:
	Service() = default;
	Service(Repository& rep, Validator &val) :repo{ rep }, val{ val }{};
	Service(const Service& ot) :repo{ ot.repo }, val{ot.val} {
		//cout << "copie la service!\n";
	}

	void adauga(const string&, const string&, float, const string&);
	
	const Lista<Book>& getAll() const {
		return repo.get_all();
	}

	void sterge(const string&, const string&);
	void modifica(const string&, const string&, const string&, const string&, float, const string&);
	Book cauta_prod(const string&, const string&) const;
	Lista<Book> produse_mai_mici_decat_un_an(float) const;
	Lista<Book> produse_cu_titlul_dat(string) const;
	Lista<Book> produse_cu_autor_dat(string) const;
	Lista<Book> sorteaza_dupa_titlu();
	Lista<Book> sortare_generala_repo(CMPF);
	Lista<Book> sorteaza_dupa_autor();
	Lista<Book> sorteaza_dupa_an_si_gen();
	void s_goleste_repo();
	int size_of_all() { return repo.size_of_repo(); }

};

void test_service();