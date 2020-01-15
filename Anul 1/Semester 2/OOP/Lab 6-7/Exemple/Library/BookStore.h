#pragma once

#include "Book.h"
#include "bookrepo.h"
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include "validator.h"

using namespace std;
template <typename ElementT>class VectDinNewDeleteT;
//template <typename Book>

typedef bool(*MaiMicF)(const Book&, const Book&);

class BookStore {
	BookRepo& rep;
	BookValidator& val;

	/*
	 Functie de sortare generala
	 maiMicF - functie care compara 2 Book, verifica daca are loc relatia mai mare
	          - poate fi orice functe (in afara clasei) care respecta signatura (returneaza bool are 2 parametrii Book)
			  - poate fi functie lambda (care nu capteaza nimic in capture list)
	 returneaza o lista sortata dupa criteriu dat ca paramatru
	*/
    template <typename Book>
    VectDinNewDeleteT<Book> generalSort(MaiMicF maiMicF)const;
	/*
	Functie generala de filtrare
	fct - poate fi o functie 
	fct - poate fi lambda, am folosit function<> pentru a permite si functii lambda care au ceva in capture list
	returneaza doar cartile care trec de filtru (fct(Book)==true)
	*/
    VectDinNewDeleteT<Book> filtreaza(function<bool(const Book&)> fct)const;
public:
	BookStore(BookRepo& rep, BookValidator& val) noexcept:rep{ rep }, val{ val } {
	}
	//nu permitem copierea de obiecte Library
	BookStore(const BookStore& ot) = delete;
	/*
	 returneaza toate cartile in ordinea in care au fost adaugate
	*/
    template <typename ElementT>

    const VectDinNewDeleteT<Book>& getAll() const noexcept{
		return rep.getAll();
	}
	/*
	Adauga un nou Book
	arunca exceptie daca: nu se poate salva, nu este valid
	*/
	//void addBook(const string& type, const string& species, int price);
	void addBook(const string& title, const string& writer,const string& genre, int year) ;

	void sterge(int poz);
		/*
        Sorteaza dupa titlu
        */
	//vector<Book> sortByTitle()const;
    //Lista<Book> generalSort(MaiMicF maiMicF)const;

    template <typename ElementT>

    VectDinNewDeleteT<Book> sortByTitle() const ;


        /*
        Sorteaza dupa autor
        */
    template <typename ElementT>

    VectDinNewDeleteT<Book> sortByWriter()const;


	/*
	Sorteaza dupa year+genre
	*/
    template <typename ElementT>

    VectDinNewDeleteT<Book> sortByYearGenre() const;

	/*
	returneaza doar cartile dintr.un anumit an
	*/
    template <typename ElementT>
    VectDinNewDeleteT<Book> filtrareYear(int pret)const;

	/*
	returneaza doar cartile cu un anumit titlu
	*/
    template <typename ElementT>

    VectDinNewDeleteT<Book> filterTitle(const string& title)const;

	void modify(int poz,const string& title, const string& writer,const string& genre , int year);

	Book cauta(const string& title, const string& writer);


};
void testCtr();
