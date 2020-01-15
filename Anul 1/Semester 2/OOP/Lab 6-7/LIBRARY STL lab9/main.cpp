#include "console.h"
#include "BookStore.h"
#include "bookrepo.h"
#include "validator.h"
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
/*
void adaugaCateva(BookStore& ctr) {
	ctr.addBook("a", "zz","a", 2010);
	ctr.addBook("b", "aa","a", 2006);
	ctr.addBook("z", "cc","a", 2016);
	ctr.addBook("c", "bb","a", 2017);
}*/
void adaugFromFile(BookStore& ctr){
	ifstream f("books.html");
	string a,b,c;
	string d;
	f>>b>>c;
	//int year=std::stoi (a,100);

	string titlu,autor,gen,an;
	while(!f.eof()){
		f>>a;
		//std::cout << a << "\n";
		if(a[1]=='p') {
			a.erase(0, 3);
			a.erase(a.end() - 4, a.end());
			//std::cout << a << '\n';
			int i, j;
			string s1,s2,s3,s4;
			i = 0;

			for (char &c : a) {
				if (c != ',')
					++i;
				else {
					s1 = a.substr(0, i);
					break;
				}
			}
			titlu = s1;
			a = a.substr(i+1,a.size());
			j = 0;

			for (char &c : a) {
				if (c != ',')
					++j;
				else {
					s2 = a.substr(0, j);
					break;
				}
			}

			autor = s2;
			a = a.substr(j + 1, a.size());
			j = 0;

			for (char &c : a) {
				if (c != ',')
					++j;
				else {
					s3 = a.substr(0, j);
					break;
				}
			}

			gen = s3;
			a = a.substr(j + 1, a.size());
			an = a;
			//std::cout << an << "\n";
			int rez = 0;
			for (char &c : an)
				rez = rez * 10 + c - '0';
			cout << titlu << " " << autor << " " << gen << " " << rez << "\n";
			ctr.addBook(titlu, autor, gen, rez);


		}
	}
}
void adaugFromFileBasket(BookStore& ctr){
	ifstream f("basket.html");
	string a,b,c;
	string d;
	f>>b>>c;
	//int year=std::stoi (a,100);

	string titlu,autor,gen,an;
	while(!f.eof()){
		f>>a;
		//std::cout << a << "\n";
		if(a[1]=='p') {
			a.erase(0, 3);
			a.erase(a.end() - 4, a.end());
			//std::cout << a << '\n';
			int i, j;
			string s1,s2,s3,s4;
			i = 0;

			for (char &c : a) {
				if (c != ',')
					++i;
				else {
					s1 = a.substr(0, i);
					break;
				}
			}
			titlu = s1;
			a = a.substr(i+1,a.size());
			j = 0;

			for (char &c : a) {
				if (c != ',')
					++j;
				else {
					s2 = a.substr(0, j);
					break;
				}
			}

			autor = s2;
			a = a.substr(j + 1, a.size());
			j = 0;

			for (char &c : a) {
				if (c != ',')
					++j;
				else {
					s3 = a.substr(0, j);
					break;
				}
			}

			gen = s3;
			a = a.substr(j + 1, a.size());
			an = a;
			//std::cout << an << "\n";
			int rez = 0;
			for (char &c : an)
				rez = rez * 10 + c - '0';
			cout << titlu << " " << autor << " " << gen << " " << rez << "\n";
			ctr.addBookBasket(titlu, autor);


		}
	}
}

void testAll() {
	testeRepo();
	testCtr();
}

int main() {
	BookRepo rep;
	BookValidator val;
	BookStore ctr{rep, val};
	//adaugaCateva(ctr);//adaugam cateva carti
	ConsolUI ui{ctr};

	adaugFromFile(ctr);//incarcam datele din fisier
	adaugFromFileBasket(ctr);//incarcam datele din fisier in cos

	testAll();
	cout << "All test passed";

	ui.start();
	return 0;
}