#include "Service.h"
#include <assert.h>



void Service::adauga(const string& titlu, const string& gen, const float an, const string& autor) {
	/*
		functie care creeaza un obiect de gen produs cu datele primite, il valideaza si il trimite la 
		repo pentru adaugare in caz de succes la validare
		post: se adauga in repo obiectul creat, sau se arunca exceptie in caz de eroare la validare
	*/
	
	Book prod{ titlu, gen, an, autor };
	val.valideaza(prod);
	// produsul a trecut de validare
	repo.adauga_repo(prod);
}

void Service::sterge(const string& titlu, const string& autor) {
	/*
		functie care primeste de la ui un titlu si un autor si sterge din repo obiectul care le contine
		post: se sterge din repo acel obiect, sau se arunca exceptie in cazul in care nu exista
	*/
	
	Book p{ repo.cauta(titlu, autor) };
	//daca am ajuns aici inseamna ca exista produsul de sters
	repo.remove(p);
}

void Service::modifica(const string& titlu_de_modificat, const string& autor_de_modificat, const string& titlu_nou, const string& gen_nou, float an_nou, const string& priducator_nou) {
	/*
		functie care modifica un produs din repo pe baza nunmelui si a autorului
		creeaza un nou produs care va fi pus in loc
		post: se modifica obiectul dorit sau se arunca exceptie in cazul in care acesta nu este gasit
	*/
	
	Book prod_de_modificat{ repo.cauta(titlu_de_modificat, autor_de_modificat) };
	//daca am ajuns aici inseamna ca exista produsul pe care vrem sa il modificam
	Book prod_inlocuitor{ titlu_nou, gen_nou, an_nou, priducator_nou };
	val.valideaza(prod_inlocuitor);
	// datele noi sunt valide
	repo.update(prod_de_modificat, prod_inlocuitor);
}

Book Service::cauta_prod(const string& titlu, const string& prod) const {
	/*
		functie care cauta un produs in repo pe baza titlului si a autorului
	*/
	
	return repo.cauta(titlu, prod);
}

//functia universala de filtrare
Lista<Book> Service::filtreaza(function<bool(const Book&)> func) const {
	/*
		functie care filtreaza elementele dupa parametrul 'func'
	*/
	Lista<Book> rez;
	Lista<Book> toate = repo.get_all();
	Iterator<Book> it = toate.begin();
	while(it.valid()) {
		if (func(it.informatie_nod())) {
			rez.adauga_sfarsit(it.informatie_nod());
		}
		it.urmator();
	}
	return rez;
}

Lista<Book>Service::produse_mai_mici_decat_un_an(float an) const {
	/*
		functie care returneaza produsele mai mici decat produsul an
	*/
	return filtreaza([an](const Book& p) {
		return p.get_an() == an; });
}


Lista<Book> Service::produse_cu_titlul_dat(string titlu) const {
	/*
		functie care returneaza o lista cu elementele care au campul titlu egal cu titlu
	*/
	return filtreaza([titlu](const Book& p) {
		return p.get_titlu() == titlu;
	});
}

Lista<Book> Service::produse_cu_autor_dat(string autor) const {
	/*
		functie care returneaza o lista cu toate elementele care au un autor egal cu autor
	*/
	
	return filtreaza([autor](const Book& p) {
		return p.get_autor() == autor;
	});
}

Lista<Book> Service::sortare_generala_repo(CMPF fct) {
	/*
		functie care sorteaza repositoryul dupa functia de comparare data ca parametru
	*/
	Lista<Book> rez{ repo.get_all() };
	// sortam rez
	for(int i=0;i<rez.size()-1;i++)
		for (int j = i + 1; j < rez.size(); j++) {
			if (fct(rez.produs_de_pe_pozitie(i), rez.produs_de_pe_pozitie(j))) {
				//std::cout<<rez.produs_de_pe_pozitie(i)<<" "<<rez.produs_de_pe_pozitie(j)<<std::endl;
				auto aux = rez.produs_de_pe_pozitie(i);
				Iterator<Book> it1 = rez.cauta(rez.produs_de_pe_pozitie(i));
				rez.modifica(it1, rez.produs_de_pe_pozitie(j));
				Iterator<Book> it2 = rez.cauta(rez.produs_de_pe_pozitie(j));
				rez.modifica(it2, aux);
			}
		}
	return rez;
}


Lista<Book> Service::sorteaza_dupa_titlu() {
	return sortare_generala_repo(compara_titlu);
}

Lista<Book> Service::sorteaza_dupa_autor() {
	return sortare_generala_repo(compara_autor);
}

Lista<Book> Service::sorteaza_dupa_an_si_gen() {
	return sortare_generala_repo([](const Book& p1, const Book& p2) {
		if (p1.get_an() == p2.get_an()) {
			return p1.get_gen() < p1.get_gen();
		}
		return p1.get_an() < p2.get_an();
	});
}

void Service::s_goleste_repo() {
	repo.goleste_repo();
}

// ***********************************************************


void test_adauga_service() {
	Repository repo;
	Validator val;
	Service serv{ repo,val };
	serv.adauga("aa", "as", 32, "a");
	assert(serv.size_of_all() == 1);

	try {
		serv.adauga("as", "ds", -33, "ds");
		assert(false);
	}
	catch (ValidationException& ex) {
		assert(ex.get_eroare() == " anul este invalid!");
	}
	
	try {
		serv.adauga("as", "ac", -44, "a");
		assert(false);
	}
	catch (ValidationException&) {
		assert(true);
	}
}
void test_modificare() {
	Repository repo;
	Validator val;
	Service serv{ repo,val };
	serv.adauga("at", "adfd", 2, "ad");
	assert(serv.size_of_all() == 1);


		serv.modifica("at", "ad", "ttt", "ttt", 20, "ttt");
		Book p = serv.cauta_prod("ttt", "ttt");
		assert(p.get_titlu() == "ttt");
		assert(p.get_autor() == "ttt");
	try{	
		serv.modifica("tttgfgf", "ttt", "dsds", "dsd", 333, "ffd");}
	catch (RepositoryException&) {
		assert(true);
	}
}

void test_filtrari() {
	Repository repo;
	Validator val;
	Service serv{ repo,val };
	serv.adauga("aar", "ast", 32, "ay");
	serv.adauga("aap", "aso", 32, "au");
	serv.adauga("aag", "asf", 32, "ad");
	serv.adauga("aag", "asd", 32, "as");
	assert(serv.produse_cu_titlul_dat("aar").size() == 1);
	assert(serv.produse_cu_autor_dat("au").size() == 1);
	assert(serv.produse_mai_mici_decat_un_an(32).size() == 4);
	assert(serv.produse_mai_mici_decat_un_an(11).size() == 0);
}

void test_sortare() {
	Repository repo;
	Validator val;
	Service serv{ repo,val };
	serv.adauga("a", "ast", 3, "asa");
	serv.adauga("a", "aso", 322, "au");
	serv.adauga("c", "asf", 3244, "ad");
	serv.adauga("d", "asd", 32, "as");

	auto primul_produs = serv.sorteaza_dupa_autor().begin().informatie_nod();
	assert(primul_produs.get_titlu() == "a");

	primul_produs = serv.sorteaza_dupa_titlu().begin().informatie_nod();
	assert(primul_produs.get_titlu() == "a");

	primul_produs = serv.sorteaza_dupa_an_si_gen().begin().informatie_nod();
	assert(primul_produs.get_an() == 3);

}

void test_sterge_service() {
	Repository repo;
	Validator val;
	Service serv{ repo,val };
	serv.adauga("a", "ast", 3, "asa");
	serv.adauga("a", "aso", 322, "au");
	serv.sterge("a", "asa");
	try {
		serv.sterge("fdfd", "dfdfd");
		assert(false);
	}
	catch (RepositoryException &) {
		assert(true);
	}
	serv.s_goleste_repo();
}

void test_service() {
	test_adauga_service();
	test_sterge_service();
	test_modificare();
	test_filtrari();
	test_sortare();
}