#include "TestScurt.h"
#include <assert.h>
#include <iostream>
#include "Colectie.h"
#include "Iterator.h"


void testAll() { 
	Colectie b;
	assert(b.isEmpty() == true);
	assert(b.size() == 0); 
	b.add(5);
	b.add(1);
	b.add(10);
	b.add(7);
	b.add(1);
	b.add(11);
	b.add(-3);
	assert(b.size() == 7);
	assert(b.search(10) == true);
	assert(b.search(16) == false);
	assert(b.nrOccurrences(1) == 2);
	assert(b.nrOccurrences(7) == 1);
	assert(b.remove(1) == true);
	assert(b.remove(6) == false);
	assert(b.size() == 6);
	assert(b.nrOccurrences(1) == 1);
	Iterator it = b.iterator();
	it.first();
	while (it.valid()) {
		TElem e = it.getCurrent();
		it.next();
	}
}

void testMaxOcc() {
    Colectie b;
    assert(b.isEmpty() == true);
    assert(b.size() == 0);
    b.add(5);
    b.add(1);
    b.add(10);
    b.add(7);
    b.add(1);
    b.add(1);
    b.add(1);
    b.add(11);
    b.add(11);
    b.add(11);
    b.add(11);
    b.add(-3);
    assert(b.elementsWithMaximumFrequency()==2);
}

void testMaxOcc2() {
    Colectie b;
    assert(b.isEmpty() == true);
    assert(b.size() == 0);
    b.add(5);
    b.add(1);
    b.add(10);
    b.add(7);
    b.add(1);
    b.add(1);
    b.add(1);
    b.add(88);
    b.add(88);
    b.add(88);
    b.add(88);
    b.add(-3);
    //std::cout<<b.elementsWithMaximumFrequency();
    assert(b.elementsWithMaximumFrequency()==2);
}
void testAllScurt()
{
    testAll();
    testMaxOcc2();
}