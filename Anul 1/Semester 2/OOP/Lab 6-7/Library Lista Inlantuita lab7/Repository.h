#pragma once
#include"Book.h"
#include <string>
#include <vector>
#include "Lista.h"

using std::string;
using std::ostream;
using std::vector;

class Repository
{
	Lista<Book> all;
public:
	Repository() = default;
	Repository(const Repository& ot) {
		//cout << "copie repo\n";
	}

	void adauga_repo(const Book&);
	bool exist(const Book&);
	Book cauta(const string &, const string&) const;
	const Lista<Book>& get_all() const;
	void remove(Book);
	void update(Book, const Book&);
	void goleste_repo();
	int size_of_repo() { return all.size(); }

};

class RepositoryException {
	string eroare;
public:
	RepositoryException(string m) :eroare{ m } {};
	string get_eroare() {
		return eroare;
	}
};



void test_repo();