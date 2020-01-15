#include "BookStore.h"
#include <functional>
#include <algorithm>
#include <assert.h>
#include <iostream>
#include<fstream>
#include <map>
#include <stdio.h>
#include<stack>
#include "ActiuneUndo.h"
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
Adauga un nou Book
arunca exceptie daca: nu se poate salva, nu este valid
*/
void BookStore::addBook(const string& title, const string& writer,const string& genre, int year) {
	Book p{ title,writer,genre,year };
	val.validate(p);
	rep.store(p);
	undoActions.push_back(rep.getAll());
	undoActions1.push_back(new UndoAdauga{rep,p});
}
void BookStore::undo(stack<int>comenzi) {
    if(comenzi.size()==1 && comenzi.top()==17)
        throw BookRepoException{"Nu mai exista operatii"};

    while(comenzi.top()==17 || comenzi.top()==2 || comenzi.top()==3 || comenzi.top()==4 || comenzi.top()==5 ||
    comenzi.top()==6 || comenzi.top()==7 || comenzi.top()==10 || comenzi.top()==11 || comenzi.top()==12 || comenzi.top()==13 || comenzi.top()==-1)
        comenzi.pop();
    //cout<<comenzi.top()<<" ";
	if(comenzi.empty())
		throw BookRepoException{"Nu mai exista operatii"};
    else {
		int cmd = comenzi.top();
		comenzi.pop();
		//if (cmd <= 12) {
		if (cmd==1 || cmd == 8 || cmd == 9) {
			//cout<<cmd<<"carti";
			//comenzi.pop();
			undoActions.pop_back();
			if (undoActions.empty()) {
				throw BookRepoException{"Nu mai exista operatii"};
			}
			vector<Book> a = undoActions.back();
			undoActions.pop_back();
			rep.remove_all();
			for (const auto &Book : a) {
				addBook(Book.getTitle(), Book.getWriter(), Book.getGenre(), Book.getYear());
			}
		} else if(cmd==14 || cmd == 15 || cmd==16){
			//cout<<cmd<<"basket";
			//comenzi.pop();
			undoBasket.pop_back();
			if (undoBasket.empty()) {
				throw BookRepoException{"Nu mai exista operatii"};
			}
			vector<Book> a = undoBasket.back();
			undoBasket.pop_back();
			rep.remove_basket();
			for (const auto &Book : a) {
				addBookBasket(Book.getTitle(), Book.getWriter());
			}
		}
	}
}

void BookStore::undo1() {
    if (undoActions1.empty()) {
        throw BookRepoException{ "Nu mai exista operatii" };
    }
    ActiuneUndo* act = undoActions1.back();
    act->doUndo(); //nu e exception safe – vezi varianta cu unique_ptr
    undoActions1.pop_back();
    delete act;
}

void BookStore::addBookBasket(const string& title, const string& writer) {
	Book p{ cauta(title,writer) };
	val.validate(p);
	rep.store_basket(p);
	undoBasket.push_back(rep.getAllBasket());
}
void BookStore::randomService(int nr) {
	rep.random_basket(nr);
	undoBasket.push_back(rep.getAllBasket());
}
void BookStore::sterge(int poz) {
	string titlu, autor;
	auto all{ rep.getAll() };
	if (poz-1 >= all.size() || poz-1 < 0) {
		throw BookRepoException("Pozitie invalida");
	}
	auto c = all[poz-1];
	titlu = c.getTitle();
	//std::cout << titlu << '\n';
	autor = c.getWriter();

	auto c1{ rep.find(titlu,autor) };
	rep.remove(poz);
	undoActions.push_back(rep.getAll());
	undoActions1.push_back(new UndoSterge{ rep, c1 });
}
void BookStore::stergeBasket() {
	rep.remove_basket();
	undoBasket.push_back(rep.getAllBasket());
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
	string titlu1, autor1;
	auto all{ rep.getAll() };
	if (poz - 1 >= all.size() || poz - 1 < 0) {
		throw BookRepoException("Pozitie invalida");
	}
	auto c2 = all[poz - 1];
	titlu1 = c2.getTitle();
	//std::cout << titlu << '\n';
	autor1 = c2.getWriter();
	auto c1{ rep.find(titlu1,autor1) };


	Book p{title,writer,genre,year};
	rep.modify(poz,p);
	undoActions.push_back(rep.getAll());
	undoActions1.push_back(new UndoModific { rep, c1,poz});
}

Book BookStore::cauta(const string& title, const string& writer){
	return rep.find(title,writer);
}

void BookStore::saveFile()
{
    ofstream g("books.html");
    g<<"<html>\n";
    g<<"<body>\n";
	g<<"\n<h1>Bookstore</h1>\n\n";

	for (const auto &Book : rep.getAll())
    {
        g<<"<p>"<<Book.getTitle()<<","<<Book.getWriter()<<","<<Book.getGenre()<<","<<Book.getYear()<<"</p>\n";
    }
	g<<"\n";
	g<<"</body>\n";
	g<<"</html>";
}
void BookStore::saveFileBasket()
{
	ofstream g("basket.html");
	//ofstream g;
	//g.open("basket.html",std::ios_base::app);
	g<<"<html>\n";
	g<<"<body>\n";
	g<<"\n<h1>Basket</h1>\n\n";

	for (const auto &Book : rep.getAllBasket())
	{
		g<<"<p>"<<Book.getTitle()<<","<<Book.getWriter()<<","<<Book.getGenre()<<","<<Book.getYear()<<"</p>\n";
	}
	g<<"\n";
	g<<"</body>\n";
	g<<"</html>";
}
void BookStore::dealoc()
{
	//cout<<"tun";
	while (!undoActions1.empty()) {
		ActiuneUndo* act = undoActions1.back();
		delete act;
		undoActions1.pop_back();
	}
	//delete[]undoActions1;
}
void testAdaugaCtr() {
	BookRepo rep;
	BookValidator val;
	BookStore ctr{ rep,val };
	ctr.addBook("a", "a","a", 6);
	assert(ctr.getAll().size() == 1);

    ctr.addBookBasket("a", "a");
	assert(ctr.getAllBasket().size() == 1);
	ctr.saveFile();
	ctr.saveFileBasket();
	ctr.stergeBasket();
	assert(ctr.getAllBasket().size() == 0);

	//test random
	ctr.randomService(1);
	assert(ctr.getAllBasket().size() == 1);

	ctr.stergeBasket();
	assert(ctr.getAllBasket().size() == 0);

	//adaug ceva invalid
	try {
		ctr.addBook("", "","", -1);assert(false);}
	catch (ValidateException&) {assert(true);}
	//incerc sa adaug ceva ce existadeja
	try {
		ctr.addBook("a", "a","a", -1);assert(false);}
	catch (ValidateException&) {assert(true);}
	ctr.sterge(1);

	ctr.dealoc();
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

	ctr.dealoc();
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

	ctr.dealoc();
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
	ctr.dealoc();
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

	ctr.dealoc();
}

void testUndo(){
	BookRepo rep;
	BookValidator val;
	BookStore ctr{ rep,val };
	ctr.addBook("a", "a","a", 6);
	assert(ctr.getAll().size() == 1);

	ctr.addBook("b", "b","a", 6);
	assert(ctr.getAll().size() == 2);

	ctr.addBookBasket("a", "a");
	ctr.addBookBasket("b", "b");
	assert(ctr.getAllBasket().size() == 2);
    stack<int> a;
    a.push(1);
	ctr.undo(a);
	assert(ctr.getAll().size() == 1);
    a.push(14);
	ctr.undo(a);
	assert(ctr.getAllBasket().size() == 1);
    a.push(14);
	try{
		ctr.undo(a);
	}
	catch (BookRepoException& ex) {
		assert(true);
	}

	ctr.dealoc();
}
void testUndo1()
{
	BookRepo rep;
	BookValidator val;
	BookStore ctr{ rep,val };
	ctr.addBook("a", "a","a", 6);
	assert(ctr.getAll().size() == 1);

	ctr.addBook("b", "b","a", 6);
	assert(ctr.getAll().size() == 2);

	ctr.undo1();
	assert(ctr.getAll().size() == 1);
	ctr.sterge(1);
	assert(ctr.getAll().size() == 0);
	ctr.undo1();
	assert(ctr.getAll().size() == 1);
	ctr.modify(1,"g","g","g",2020);
	assert(ctr.getAll()[0].getTitle()=="g");
	ctr.undo1();
	assert(ctr.getAll()[0].getTitle()=="a");


	try{
		ctr.undo1();
	}
	catch (BookRepoException& ex) {
		assert(true);
	}
	ctr.dealoc();
}
void testCtr() {
	testAdaugaCtr();
	testModify();
	testFiltrare();
	testSortare();
	testDictionar();
	testUndo();
	testUndo1();
}