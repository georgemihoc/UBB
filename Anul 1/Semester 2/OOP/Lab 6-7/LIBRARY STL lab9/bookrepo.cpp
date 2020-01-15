#include "bookrepo.h"
#include <assert.h>
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;


void BookRepo::random_basket(int nr) {
	std::mt19937 mt{std::random_device{}()};
	std::uniform_int_distribution<> dist(0, all.size() - 1);
	std::vector< int > vazut;
	int rndNr = dist(mt);// numar aleator intre [0,size-1]
	for (int i=1;i<=nr;i++) {
		int ok = 0;
		while(ok==0) {
			std::vector<int>::iterator found;
			found = std::find(vazut.begin(), vazut.end(), rndNr);
			auto found2 = std::find_if(all_basket.begin(), all_basket.end(), [=] (const Book& a) { return (a.getTitle() == all[rndNr].getTitle() && a.getWriter() == all[rndNr].getWriter()); } );
			if (found != vazut.end() || found2!=all_basket.end())
				rndNr = dist(mt);
			else{
				vazut.push_back(rndNr);
				ok=1;
			}
		}
		string titlu = all[rndNr].getTitle();
		string autor = all[rndNr].getWriter();
		Book p = find(titlu, autor);
		all_basket.push_back(p);
	}
}
int BookRepo::dim_basket() {
    int d = 0;
    for (const Book& b : all_basket)
        if (b.getYear())
            ++d;
    return d;
}

int BookRepo::dim() {
	int d = 0;
	for (const Book& b : all)
		if (b.getYear())
			++d;
	return d;
}
void BookRepo::store_basket(const Book& p)
{
	if (exist_basket(p)) {
		throw BookRepoException("Exista deja carte titlu:" + p.getTitle() + " autor:" + p.getWriter());
	}
	all_basket.push_back(p);
}
void BookRepo::store(const Book& p)
{
	if (exist(p)) {
		throw BookRepoException("Exista deja carte titlu:" + p.getTitle() + " autor:" + p.getWriter());
	}
	all.push_back(p);
}
void BookRepo::modify(int poz,const Book& p) {
    int ok = 0;
	for(int i = 0;i<dim();i++)
	{
		if(i+1==poz){
			all[i]=p;
			//swap(all[i], p);
			ok = 1;
		}
	}
	if(ok==0)
	    throw BookRepoException("Pozitie invalida");
}
void BookRepo::remove_all()
{
    all.erase(all.begin(),all.end());
}
void BookRepo::remove_basket()
{
	all_basket.erase(all_basket.begin(),all_basket.end());
}

void BookRepo::remove(int poz)
{
	//all.pop_back();
	//if(poz>all.size())
	if (poz > dim())
		throw BookRepoException("Pozitie invalida");
	all.erase(all.begin()+(poz-1));
	//all.erase(1);
	//all.erase(1);
}
bool BookRepo::exist_basket(const Book& p) {
	try {
		find_basket(p.getTitle(), p.getWriter());
		return true;
	}
	catch (BookRepoException& ) {return false;}
}
bool BookRepo::exist(const Book& p) {
	try {
		find(p.getTitle(), p.getWriter());
		return true;
	}
	catch (BookRepoException& ) {return false;}
}
/*
Cauta
arunca exceptie daca nu exista carte
*/
Book BookRepo::find_basket(const string& titlu,const string& autor) const{
	/*for (const Book& p : all) {
		if (p.getTitle() == titlu && p.getWriter() == autor) {
			return p;
		}

	}*/
	auto it = find_if(all_basket.begin(), all_basket.end(), [=] (const Book& a) { return (a.getTitle() == titlu && a.getWriter() == autor); } );
	if(it!= all_basket.end())
		return *it;
	//daca nu exista arunc o exceptie
	throw BookRepoException("Nu exista carte titlu:" + titlu + " autor:" + autor);
}

Book BookRepo::find(const string& titlu,const string& autor) const{
	/*for (const Book& p : all) {
		if (p.getTitle() == titlu && p.getWriter() == autor) {
			return p;
		}

	}*/
	auto it = find_if(all.begin(), all.end(), [=] (const Book& a) { return (a.getTitle() == titlu && a.getWriter() == autor); } );
    if(it!= all.end())
        return *it;
    //daca nu exista arunc o exceptie
	throw BookRepoException("Nu exista carte titlu:" + titlu + " autor:" + autor);
}

/*
returneaza toate cartile salvate
*/
const vector<Book>& BookRepo::getAllBasket() const noexcept{
	return all_basket;
}
const vector<Book>& BookRepo::getAll() const noexcept{
	return all;
}

ostream& operator<<(ostream& out, const BookRepoException& ex) {out << ex.msg;return out;}

void testDim() {
	BookRepo rep;
	rep.store(Book{ "a","a","a",4 });
	assert(rep.dim() == 1);

    rep.store_basket(Book{ "a","a","a",4 });
	assert(rep.dim_basket() == 1);

	rep.remove_basket();
	assert(rep.dim_basket() == 0);

	rep.random_basket(1);
	assert(rep.dim_basket() == 1);

	rep.remove_basket();
	assert(rep.dim_basket() == 0);

}


void testAdauga() {
	BookRepo rep;
	rep.store(Book{ "a","a","a",4 });
	assert(rep.getAll().size() == 1);
	assert(rep.find("a", "a").getWriter() == "a");

	rep.store(Book{ "b","b","b",4 });
	assert(rep.getAll().size() == 2);

	//nu pot adauga 2 cu acelasi titlu si autor
	try {
		rep.store(Book{ "a","a","a",4 }); assert(false);}
	catch (BookRepoException&) {
		assert(true);
	}
}

void testModifyRemove() {
	BookRepo rep;
	rep.store(Book{ "a","a","a",4 });
	try {
		rep.modify(10, Book{ "a","a","a",4 });}
	catch (BookRepoException&) {
		assert(true);
	}
	try {
		rep.remove(10);}
	catch (BookRepoException&) {assert(true);}
	//assert(rep.remove(10);
}

void testCauta() {
	BookRepo rep;
	rep.store(Book{ "a","a","a",4 });
	rep.store(Book{ "b","b","a",4 });

	auto p = rep.find("a", "a");
	assert(p.getWriter() == "a");
	assert(p.getTitle() == "a");

	//arunca exceptie daca nu gaseste
	try {
		rep.find("a", "b");assert(false);}
	catch (BookRepoException&) {assert(true);}
}

void testeRepo() {
	testDim();
	testAdauga();
	testModifyRemove();
	testCauta();
}