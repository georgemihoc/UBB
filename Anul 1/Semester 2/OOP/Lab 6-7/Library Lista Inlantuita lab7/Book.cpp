#include "Book.h"



bool compara_titlu(const Book& p1, const Book& p2) {
	/*
		functie care compara doua obiecte de gen Book dupa campul titlu
		pre:p1: produs valid, p2: produs valid
		post: true daca titlule lui p1 este alfabetic mai mic decat titlule lui p2
	*/
	
	return p1.get_titlu() < p2.get_titlu();
}
bool compara_autor(const Book& p1, const Book& p2) {
	/*
		functie care compara doua obiecte de gen Book dupa campul titlu
		pre:p1: produs valid, p2: produs valid
		post: true daca titlule lui p1 este alfabetic mai mic decat titlule lui p2
	*/

	return p1.get_autor() < p2.get_autor();
}

bool compara_an(const Book& p1, const Book& p2) {
	/*
		functie care compara doua obiecte de gen Book dupa campul an
		pre:p1,p2 books valide
		post: true daca anul lui p1 este mai mic decat anul lui p2
	*/

	return p1.get_an() < p2.get_an();
}