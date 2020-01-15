#pragma once

#include "Book.h"
#include "bookrepo.h"
#include <string>
#include <vector>
#include <map>
#include <functional>
#include "validator.h"
#include <stack>
#include "ActiuneUndo.h"

using namespace std;

typedef bool(*MaiMicF)(const Book&, const Book&);

class BookStore {
	BookRepo& rep;
	BookValidator& val;
	vector<vector<Book>> undoActions;//vector undo
	vector<vector<Book>> undoBasket;//vector undo cos

	vector<ActiuneUndo*> undoActions1; //vector undo

	/*
	 Functie de sortare generala
	 maiMicF - functie care compara 2 Book, verifica daca are loc relatia mai mare
	          - poate fi orice functe (in afara clasei) care respecta signatura (returneaza bool are 2 parametrii Book)
			  - poate fi functie lambda (care nu capteaza nimic in capture list)
	 returneaza o lista sortata dupa criteriu dat ca paramatru
	*/
	vector<Book> generalSort(MaiMicF maiMicF)const;
	//vector<Book> raport()const;

		/*
        Functie generala de filtrare
        fct - poate fi o functie
        fct - poate fi lambda, am folosit function<> pentru a permite si functii lambda care au ceva in capture list
        returneaza doar cartile care trec de filtru (fct(Book)==true)
        */
	vector<Book> filtreaza(function<bool(const Book&)> fct)const;
public:
	BookStore(BookRepo& rep, BookValidator& val) noexcept:rep{ rep }, val{ val }{
	}
	//nu permitem copierea de obiecte Library
	BookStore(const BookStore& ot) = delete;
	/*
	 returneaza toate cartile in ordinea in care au fost adaugate
	*/
	const vector<Book>& getAll() const noexcept{
		return rep.getAll();
	}
	const vector<Book>& getAllBasket() const noexcept{
		return rep.getAllBasket();
	}
	/*
	Adauga un nou Book
	arunca exceptie daca: nu se poate salva, nu este valid
	*/
	//void addBook(const string& type, const string& species, int price);
	void addBook(const string& title, const string& writer,const string& genre, int year) ;
	void addBookBasket(const string& title, const string& writer) ;
	void randomService(int nr);
	void sterge(int poz);
    void stergeBasket();
    void saveFile();
    void saveFileBasket();
    void undo(stack<int>comenzi);
    void undo1();
	void dealoc();
	/*
        Sorteaza dupa titlu
	*/
	vector<Book> sortByTitle()const;
	/*
	Sorteaza dupa autor
	*/
	vector<Book> sortByWriter()const;
	/*
	Sorteaza dupa year+genre
	*/
	vector<Book> sortByYearGenre() const;
	vector<Book> sortByGenre() const;
	/*
	returneaza doar cartile dintr.un anumit an
	*/
	vector<Book> filtrareYear(int pret)const;

	/*
	returneaza doar cartile cu un anumit titlu
	*/
	vector<Book> filterTitle(const string& title)const;
	map<string,int> filterGenre()const;
	void modify(int poz,const string& title, const string& writer,const string& genre , int year);
	Book cauta(const string& title, const string& writer);
};
void testCtr();