#pragma once
#include "TestPackage.h"
#include <stdio.h>
#include <string.h>
void callTestsPackage() {
	testCreatePackage();
	testGetters();
	testSetters();
	testComparePackages();
	testSwap();
}

void testCreatePackage() {
	Package package = createPackage(1,"City break", "Montecarlo", "11/12/2012", 200);
	assert(package.id == 1);
	assert(strcmp(package.type, "City break") == 0);
	assert(strcmp(package.destination, "Montecarlo") == 0);
	assert(strcmp(package.date, "11/12/2012") == 0);
	assert(package.price == 200);
	destroyPackage(&package);
}

void testGetters() {
	Package package = createPackage(1, "City break", "Montecarlo", "11/12/2012", 200);
	assert(getId(&package)== 1);
	assert(strcmp(getType(&package), "City break") == 0);
	assert(strcmp(getDestination(&package), "Montecarlo") == 0);
	assert(strcmp(getDate(&package), "11/12/2012") == 0);
	assert(getPrice(&package) == 200);
	destroyPackage(&package);
}

void testSetters() {
	Package package = createPackage(1, "asd", "asd", "asd", 0);
	setType(&package, "City break");
	setDestination(&package, "Montecarlo");
	setDate(&package, "11/12/2012");
	setPrice(&package, 200);
	assert(getId(&package) == 1);
	assert(strcmp(getType(&package), "City break") == 0);
	assert(strcmp(getDestination(&package), "Montecarlo") == 0);
	assert(strcmp(getDate(&package), "11/12/2012") == 0);
	assert(getPrice(&package) == 200);
	destroyPackage(&package);
}

void testComparePackages() {
	Package package1 = createPackage(1, "type", "destination", "date", 200);
	Package package2 = createPackage(2, "type", "destination", "date", 200);
	assert(comparePackages(&package1, &package2) == 0);
	destroyPackage(&package1);
	destroyPackage(&package2);
}

void testSwap()
{
	Package package1 = createPackage(1, "type", "destination", "date", 200);
	Package package2 = createPackage(2, "type", "destination", "date", 200);
	swap(&package1, &package2);
	assert(package2.id == 1);
	assert(package1.id == 2);
	destroyPackage(&package1);
	destroyPackage(&package2);

}
