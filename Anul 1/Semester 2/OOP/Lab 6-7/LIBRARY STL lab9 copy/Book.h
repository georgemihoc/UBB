#pragma once
#include <string>
#include <iostream>

using namespace std;
class Book {
	std::string title;
	std::string writer;
	std::string genre;
	int year;
public:
	Book(const string t, const string w,const string g, int y):title{t},writer{w},genre{g},year{y}{}

	Book(const Book& ot):title{ ot.title }, writer{ ot.writer }, genre{ ot.genre },year{ ot.year} {
		cout << "COPIE!!!!\n";
	}

	string getTitle() const {
		return title;
	}
	string getWriter() const {
		return writer;
	}
    string getGenre() const {
        return genre;
    }
	int getYear() const noexcept {
		return year;
	}
};
/*
Compara dupa titlu
returneaza true daca p1.title e mai mic decat p2.title
*/
bool cmpTitle(const Book& p1, const Book& p2);
/*
Compara dupa specie
returneaza true daca p1.autor e mai mic decat p2.autor
*/
bool cmpWriter(const Book& p1, const Book& p2);

bool cmpGenre(const Book& p1, const Book& p2);