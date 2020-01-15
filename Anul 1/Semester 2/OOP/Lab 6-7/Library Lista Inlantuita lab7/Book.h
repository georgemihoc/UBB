#pragma once
#include<iostream>
#include <string>
using std::string;
using std::cout;

class Book
{
	string titlu;
	string gen;
	float an;
	string autor;
public:
	Book() = default;
	Book(const string n, const string t, const float p, const string pr) :titlu{ n }, gen{ t }, an{ p }, autor{ pr } {};
	Book(const Book& ot) :titlu{ ot.titlu }, gen{ ot.gen }, an{ ot.an }, autor{ ot.autor }{
		cout << "COPIE!\n";
	}
	string get_titlu() const {
		return titlu;
	}
	string get_gen() const {
		return gen;
	}
	int get_an() const {
		return an;
	}
	string get_autor() const {
		return autor;
	}

	bool operator==(const Book& p) {
		return p.titlu == titlu && p.autor == autor;
	}
	bool operator!=(const Book& p) {
		bool a = p.titlu != titlu || p.autor != autor;
		return a;
	}

};

bool compara_titlu(const Book&, const Book&);
bool compara_autor(const Book&, const Book&);

bool compara_an(const Book&, const Book&);
