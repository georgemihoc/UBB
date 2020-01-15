#include "BookStore.h"
#include <functional>
#include <algorithm>
#include <assert.h>
#include <iostream>
using namespace std;

template <typename ElementT>class VectDinNewDeleteT;

Lista<Book> BookStore::generalSort(MaiMicF maiMicF) const {
	VectDinNewDeleteT<Book> v{ rep.getAll() };//fac o copie
	//sort(v.begin(), v.end(), maiMicF);
	for (size_t i = 0; i < v.size(); i++) {
		for (size_t j = i + 1; j < v.size(); j++) {
			if (!maiMicF(v[i], v[j])) {
				//interschimbam
				Book aux = v[i];
				v[i] = v[j];
				v[j] =  aux;
			}
		}
	}
	return v;
}

/*
Adauga un nou Book
arunca exceptie daca: nu se poate salva, nu este valid
*/
void BookStore::addBook(const string& title, const string& writer,const string& genre, int year) {
	Book p{ title,writer,genre,year };
	val.validate(p);
	rep.store(p);
}
void BookStore::sterge(int poz) {
	rep.remove(poz);
}
/*
Sorteaza dupa tip
*/
template <typename ElementT>
VectDinNewDeleteT<Book> BookStore::sortByTitle() const {
	return generalSort(cmpTitle);
}

/*
Sorteaza dupa writer
*/
template<typename ElementT>
VectDinNewDeleteT<Book> BookStore::sortByWriter() const {
	return generalSort(cmpWriter);
	
	/*
	return generalSort([](const Book&p1, const Book&p2) {		
		return p1.getWriter() < p2.getWriter();
	});*/
}


/*
Sorteaza dupa writer+year
*/
template <typename ElementT>

VectDinNewDeleteT<Book> BookStore::sortByYearGenre() const {
	return generalSort([](const Book&p1, const Book&p2) {
		if (p1.getYear() == p2.getYear()) {
			return p1.getGenre() < p2.getGenre();
		}
		return p1.getYear() < p2.getYear();
	});	
}
template <typename ElementT>

VectDinNewDeleteT<Book> BookStore::filtreaza(function<bool(const Book&)> fct) const {
	vector<Book> rez;
	for (const auto& Book : rep.getAll()) {
		if (fct(Book)) {
			rez.push_back(Book);
		}
	}
	return rez;
}
template <typename ElementT>
VectDinNewDeleteT<Book> BookStore::filtrareYear(int year) const {
	return filtreaza([year](const Book& p)noexcept {
		return p.getYear() == year;
	});
}
template <typename ElementT>
Lista<Book> BookStore::filterTitle(const  string& title)const {

	return filtreaza([=](const Book& p) noexcept {
		return p.getTitle() == title;
	});
}

void BookStore::modify(int poz, const string& title, const string& writer, const string& genre, int year) {
	/*for (const auto &Book : rep.getAll()) {
		//if(Book.getTitle()== title && Book.getWriter()==writer)

	}*/
	Book p{title,writer,genre,year};
	//cout<<title;
	rep.modify(poz,p);
}

Book BookStore::cauta(const string& title, const string& writer){
	return rep.find(title,writer);
}

void testAdaugaCtr() {
	BookRepo rep;
	BookValidator val;
	BookStore ctr{ rep,val };
	ctr.addBook("a", "a","a", 6);
	assert(ctr.getAll().size() == 1);

	//adaug ceva invalid
	try {
		ctr.addBook("", "","", -1);assert(false);}
	catch (ValidateException&) {assert(true);}
	//incerc sa adaug ceva ce existadeja
	try {
		ctr.addBook("a", "a","a", -1);assert(false);}
	catch (ValidateException&) {assert(true);}
	ctr.sterge(1);
}
void testModify() {
	BookRepo rep;
	BookValidator val;
	BookStore ctr{ rep,val };
	ctr.addBook("a", "a","a", 6);
	string a,b;
	a="abc";
	b="abc";
	//assert(ctr.getAll().size() == 1);

	//adaug ceva invalid
	try {
		ctr.modify(1,"abc", "abc","abc", 2012);
		//rep=ctr.cauta(a,a);
		Book p = ctr.cauta(a,a);
		assert(p.getTitle()=="abc");
		assert(p.getWriter()=="abc");
	}
	catch (BookRepoException&) {assert(true);}
}
void testFiltrare() {
	BookRepo rep;
	BookValidator val;
	BookStore ctr{ rep,val };
	ctr.addBook("a", "a","a", 6);
	ctr.addBook("b", "a","a", 60);
	ctr.addBook("c", "a","a", 600);
	assert(ctr.filterTitle("a").size() == 1);
	assert(ctr.filterTitle("b").size() == 1);
	assert(ctr.filtrareYear(60).size() == 1);
	assert(ctr.filtrareYear(7).size() == 0);
	assert(ctr.filtrareYear(6).size() == 1);
}

void testSortare() {
	BookRepo rep;
	BookValidator val;
	BookStore ctr{ rep,val };
	ctr.addBook("z", "z","a", 6);
	ctr.addBook("b", "a","a", 60);
	ctr.addBook("c", "a","a", 60);

	auto firstP = ctr.sortByTitle()[0];
	assert(firstP.getTitle() == "b");

	firstP = ctr.sortByWriter()[0];
	assert(firstP.getWriter() == "a");

	firstP = ctr.sortByYearGenre()[0];
	assert(firstP.getYear() == 6);

}

void testCtr() {
	testAdaugaCtr();
	testModify();
	testFiltrare();
	testSortare();
}