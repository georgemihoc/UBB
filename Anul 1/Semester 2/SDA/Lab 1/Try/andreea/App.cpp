#include <iostream>

#include "Multime.h"
#include "IteratorMultime.h"
#include "TestScurt.h"
#include "TestExtins.h"

using namespace std;


int main() {

	testAll();

	cout << "End TestScurt"<<'\n';

	testAllExtins();

	cout << "End TestExtins"<<'\n';
	return 0;
}