#include "BookStore.h"
#include <functional>
#include <algorithm>
#include <assert.h>
#include <iostream>
#include <map>
using namespace std;

vector<Book> BookStore::generalSort(MaiMicF maiMicF) const {
	vector<Book> v{ rep.getAll() };//fac o copie	
	sort(v.begin(), v.end(), maiMicF);
	//for (size_t i = 0; i < v.size(); i++) {
	//	for (size_t j = i + 1; j < v.size(); j++) {
	//		if (!maiMicF(v[i], v[j])) {
	//			//interschimbam
	//			Book aux = v[i];
	//			v[i] = v[j];
	//			v[j] =  aux;
	//		}
	//	}
	//}
	return v;
}
/*
vector<Book> BookStore::raport(const ){
    vector<Book> v{ rep.getAll() };//fac o copie

}*/
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
vector<Book> BookStore::sortByTitle() const {
	return generalSort(cmpTitle);
}

/*
Sorteaza dupa writer
*/
vector<Book> BookStore::sortByWriter() const {
	return generalSort(cmpWriter);
	
	/*
	return generalSort([](const Book&p1, const Book&p2) {		
		return p1.getWriter() < p2.getWriter();
	});*/
}


/*
Sorteaza dupa writer+year
*/
vector<Book> BookStore::sortByYearGenre() const {
	return generalSort([](const Book&p1, const Book&p2) {
		if (p1.getYear() == p2.getYear()) {
			return p1.getGenre() < p2.getGenre();
		}
		return p1.getYear() < p2.getYear();
	});	
}

vector<Book> BookStore::sortByGenre() const {
	return generalSort(cmpGenre);
}

vector<Book> BookStore::filtreaza(function<bool(const Book&)> fct) const {
	vector<Book> rez;
	auto all=rep.getAll();
	///COPY_IF
	copy_if(all.begin(), all.end(), back_inserter(rez),fct);
	return rez;
	/*
	for (const auto& Book : rep.getAll()) {
		if (fct(Book)) {
			rez.push_back(Book);
		}
	}*/
}

vector<Book> BookStore::filtrareYear(int year) const {
	return filtreaza([year](const Book& p)noexcept {
		return p.getYear() == year;
	});
}

vector<Book> BookStore::filterTitle(const  string& title)const {
	return filtreaza([=](const Book& p) noexcept {
		return p.getTitle() == title;
	});
}

map<string,int> BookStore::filterGenre()const {
    map<string,int> dictionar;

	for (const auto &Book : rep.getAll()) {
    	dictionar[Book.getGenre()]++;
    }
	return dictionar;
    /*
    return filtreaza([=](const Book& p) noexcept {
        return p.getGenre() == genre;
    });*/
}

void BookStore::modify(int poz, const string& title, const string& writer, const string& genre, int year) {
	/*for (const auto &Book : rep.getAll()) {
		//if(Book.getTitle()== title && Book.getWriter()==writer)

	}*/
	Book p{title,writer,genre,year};
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
void testDictionar()
{
	map<string,int> dictionar;
	BookRepo rep;
	BookValidator val;
	BookStore ctr{ rep,val };
	ctr.addBook("a", "a","a", 6);
	ctr.addBook("b", "a","a", 60);
	ctr.addBook("c", "a","a", 600);
	dictionar = ctr.filterGenre();
	for (auto& t : dictionar) {
		assert(t.first == "a");
		assert(t.second==3);
	}

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

    firstP = ctr.sortByGenre()[0];
    assert(firstP.getYear() == 6);

}

void testCtr() {
	testAdaugaCtr();
	testModify();
	testFiltrare();
	testSortare();
	testDictionar();
}