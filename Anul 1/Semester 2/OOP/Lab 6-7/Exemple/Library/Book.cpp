#include "Book.h"


bool cmpTitle(const Book& p1, const Book& p2) {
	return p1.getTitle() < p2.getTitle();
}

bool cmpWriter(const Book& p1, const Book& p2) {
	return p1.getWriter() < p2.getWriter();
}