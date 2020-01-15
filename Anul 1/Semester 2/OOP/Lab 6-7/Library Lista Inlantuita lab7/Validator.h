#pragma once
#include "Book.h"
#include<vector>
#include <string>

using std::ostream;
using std::vector;
using std::string;
using namespace std;
class Validator
{
public:
	Validator();

	void valideaza(const Book&);

};


class ValidationException {
	vector<string> msgs;
public:
	ValidationException(const vector<string>& errors) :msgs{ errors } {}
	string get_eroare() {
		string rez;
		for (auto&  cuvant : msgs) {
			rez = rez + " " + cuvant;
		}
		return rez;
	}
};
