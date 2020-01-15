#include "ShortTest.h"
#include <assert.h>
#include <iostream>
#include "Multime.h"
#include "MultimeIterator.h"

void testAll() {

	Multime s;
	assert(s.isEmpty() == true);
	assert(s.size() == 0);

	assert(s.add(5)==true);
	assert(s.add(1)==true);
	assert(s.add(10)==true);
	assert(s.add(7)==true);
	assert(s.add(1)==false);
	assert(s.add(10)==false);
	assert(s.add(-3)==true);
	assert(s.size() == 5);
	assert(s.search(10) == true);
	assert(s.search(16) == false);
	assert(s.remove(1) == true);
	assert(s.remove(6) == false);
	assert(s.size() == 4);

	assert(s.search(1) == false);





	MultimeIterator it = s.iterator();

	it.first();
	int sum = 0;
	while (it.valid()) {
		TElem e = it.getCurrent();
		sum += e;
		it.next();
	}
	assert(sum == 14);

}