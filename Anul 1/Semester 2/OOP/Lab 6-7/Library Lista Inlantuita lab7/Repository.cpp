#include "Repository.h"
#include <assert.h>



Book Repository::cauta(const string& titlu, const string& autor) const {
	/*
		functie care cauta in repo un produs dupa campul titlu si campul autor si returneaza referinta la acel obiect
		post:obiect de tip Book
	*/
	Book p{ titlu, "", 0, autor };
	Iterator<Book> it = all.cauta(p);
	if(it.valid())
		return it.informatie_nod();

	// daca am ajuns aici inseamana ca nu exista elementul in repo si aruncam exceptie
	throw RepositoryException("Nu exista produsul " + titlu + " de la autorul " + autor);
}

bool Repository::exist(const Book& p) {
	/*
		functie care verifica daca un produs exista in repo
		pre: p Book
		post: true daca obiectul p exista in repo si false altfel
	*/
	
	try {
		Book prod = cauta(p.get_titlu(), p.get_autor());
		return true;
	}
	catch (RepositoryException&) {
		return false;}
}

void Repository::adauga_repo(const Book& p) {
	/*
		functie care adauga in repo un obiect
		pre: p Book validat
		post:se adauga p in repo, sau se arunca exceptie in cazul in care p exista deja
	*/
	
	if (exist(p))
		throw RepositoryException("Element deja existent cu titlule " + p.get_titlu() + " de la autorul " + p.get_autor());
	//nu mai exista acel element in repo
	all.adauga_sfarsit(p);
}

const Lista<Book>& Repository::get_all() const {
	/*
		functie care returneaza intreg repositoryul actual ca si referinta la acesta
	*/
	return all;
}

void Repository::remove(Book p) {
	/*
		functie care sterge din repo obiectul p
		pre: p Book valid
			 se stie ca p exista in repo de cand a fost creat
		post: se sterge din repo obiectul p
	*/
	Iterator<Book> poz = all.cauta(p);
	
	all.sterge(poz);
}

void Repository::update(Book de_inlouit, const Book& inlocuitor) {
	/*
		functie care inlocuieste un produs dat, cu altul
		pre: de_inlocuit: Book valid, care va fi inlocuit
			inlocuitor: Book validat cu care se va inlocuii
		post: in repo in loc de "de_inlocuit" o sa fie "inlocuitor"
	*/
	
	Iterator<Book> poz_de_modificat = all.cauta(de_inlouit);
	all.modifica(poz_de_modificat, inlocuitor);
}

void Repository::goleste_repo() {
	/*
		functie care goleste repositoryul
		post:size(repo) = 0
	*/
	
	while (all.size()) {
		all.sterge(all.begin());
	}

}





void test_adauga() {
	/*
		functia care testeaza adaugarile in repo
	*/
	
	Repository repo;
	const Book& p = Book{ "as","aas",4, "tr" };
	repo.adauga_repo(p);
	assert(repo.size_of_repo() == 1);
	try {
		repo.adauga_repo(Book{ "as", "aas", 4, "tr" });
		assert(false);
	}
	catch (RepositoryException& text) {
		assert(text.get_eroare() == "Element deja existent cu titlule as de la autorul tr");
		//assert(true);
	}
	assert(repo.cauta("as", "tr").get_titlu() == "as");

	repo.adauga_repo(Book{ "bb","ba",4, "ty" });
	assert(repo.size_of_repo() == 2);

	try {
		repo.adauga_repo(Book{ "as","asa",4, "tr" });
		assert(false);
	}
	catch (RepositoryException&) {
		assert(true);
	}
}

void test_cauta() {
	/*
		functia care testeaza cautarile in repo
	*/
	
	Repository repo;
	repo.adauga_repo(Book{ "aa","as", 4, "ad" });
	repo.adauga_repo(Book{ "br","bt", 4, "av" });

	auto p = repo.cauta("aa", "ad");
	assert(p.get_titlu() == "aa");
	assert(p.get_autor() == "ad");


	try {
		Book p = repo.cauta("azz", "eigei");
		assert(false);
	}
	catch (RepositoryException&) {
		assert(true);
	}
}

void test_repo(){
	/*
		functia care testeaza operatiile pe repository
	*/
	
	test_adauga();
	test_cauta();
}