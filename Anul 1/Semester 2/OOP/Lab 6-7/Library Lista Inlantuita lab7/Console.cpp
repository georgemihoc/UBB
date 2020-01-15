#include "Console.h"
#include<iostream>
using std::cout;
using std::cin;



void Ui_obj::meniu()
{
	cout << "\n\n";
	cout << "-------------------------------------\n";
	cout << "|            BOOK STORE		      |\n";
	cout << "-------------------------------------\n";
	cout << "| 1. Adauga carte                   |\n";
	cout << "| 2. Stergere                       |\n";
	cout << "| 3. Modificare		                |\n";
	cout << "| 4. Cautare			            |\n";
	cout << "| 5. Filtrare dupa an               |\n";
	cout << "| 6. Filtrare dupa titlu            |\n";
	cout << "| 7. Filtrare dupa autor            |\n";
	cout << "| 8. Sortare dupa titlu             |\n";
	cout << "| 9. Sortare dupa an                |\n";
	cout << "| 10. Sortare dupa an+gen           |\n";
	cout << "| 11. Afisare carti                 |\n";
	cout << "| 0. EXIT                           |\n";
	cout << "-------------------------------------\n\n";
	cout << "Introduceti comanda: ";
}


void Ui_obj::ui_adauga() {
	string titlu, gen, autor;
	float an;
	cout << "Dati titlul: "; cin >> titlu;
    cout << "Dati autorul: "; cin >> autor;
    cout << "Dati genul: "; cin >> gen;
	cout << "Dati anul: "; cin >> an;
	serv.adauga(titlu, gen, an, autor);
}


void Ui_obj::print(Lista<Book> books) {
	Iterator<Book> it = books.begin();
	while (it.valid())
	{
		cout << "titlu: " + it.informatie_nod().get_titlu() + "; gen: " + it.informatie_nod().get_gen() + "; an: " << it.informatie_nod().get_an() << "; autor: " + it.informatie_nod().get_autor() + "\n";
		it.urmator();
	}
}

void Ui_obj::ui_sterge() {
	string titlu, autor;
	cout << "Introduceti titlule si autorul produsului pe care doriti sa il stergeti:\n";
	cout << "titlul: "; cin >> titlu;
	cout << "autorul: "; cin >> autor;
	serv.sterge(titlu, autor);
}

void Ui_obj::ui_modifica() {
	string titlu_de_modificat, titlu_autor_de_modificat, titlu_nou, gen_nou, autor_nou;
	float an_nou;
	cout << "Introduceti titlul si autorul produsului pe care doriti sa il modificati:\n";
	cout << "Introduceti titlul: "; cin >> titlu_de_modificat;
	cout << "Introduceti autorul: "; cin >> titlu_autor_de_modificat;
	cout << "Introduceti date noii carti:\n";
	cout << "titlul: "; cin >> titlu_nou;
	cout << "autorul: "; cin >> autor_nou;
	cout << "genul: "; cin >> gen_nou;
	cout << "anul: "; cin >> an_nou;
	serv.modifica(titlu_de_modificat, titlu_autor_de_modificat, titlu_nou, gen_nou, an_nou, autor_nou);
}

void Ui_obj::ui_cautare() {
	string titlu, autor;
	cout << "Introduceti titlule si autorul produsului pe care doriti sa il cautati:\n";
	cout << "Introduceti titlule: "; cin >> titlu;
	cout << "Introduceti autorul: "; cin >> autor;
	Book p = serv.cauta_prod(titlu, autor);
	//daca trece de asta, produsul exita
	printf("Cartea introdusa exista!\n");
}


void Ui_obj::filtrare_dupa_titlu() {
	string titlu;
	cout << "Se afiseaza cartile care au ca titlu, ce se introduce mai jos\nIntroduceti titlule: "; cin >> titlu;
	print(serv.produse_cu_titlul_dat(titlu));
}


void Ui_obj::filtrare_dupa_autor() {
	string autor;
	cout << "Se afiseaza cartile care au ca titlu, ce se introduce mai jos\nIntroduceti titlule: "; cin >> autor;
	print(serv.produse_cu_autor_dat(autor));
}

void Ui_obj::elibereaza() {
	serv.s_goleste_repo();
}


void Ui_obj::run() {
	while (true) {
		meniu();
		int command;
		cin >> command;
		try {
			switch (command) {
			case 1:
				ui_adauga();
				break;
			case 2:
				ui_sterge();
				break;
			case 3:
				ui_modifica();
				break;
			case 4:
				ui_cautare();
				break;
			case 5:
				float an;
				cout << "Se afiseaza cartile dintr-un an dat\nDati anul: "; cin >> an;
				print(serv.produse_mai_mici_decat_un_an(an));
				break;
			case 6:
				filtrare_dupa_titlu();
				break;
			case 7:
				filtrare_dupa_autor();
				break;
			case 8:
				cout << "Cartile sortate dupa titlu sunt:\n";
				print(serv.sorteaza_dupa_titlu());
				break;
			case 9:
				cout << "Cartile sortate dupa autor sunt:\n";
				print(serv.sorteaza_dupa_autor());
				break;
			case 10:
				cout << "Cartile sortate dupa an si gen sunt:\n";
				print(serv.sorteaza_dupa_an_si_gen());
				break;
			case 11:
				print(serv.getAll());
				break;
			case 0:
				//elibereaza();
				cout << "\nEXIT\n";
				return;
			default:
				cout << "Comanda invalida\n";
			}
		}
		catch (RepositoryException& ex) {
			cout << ex.get_eroare() << '\n';
		}
		catch (ValidationException& ex) {
			cout << ex.get_eroare() << '\n';
		}
	}
}