#pragma once
#include "TestVector.h"
#include <assert.h>

/*
void callTestsVector() {
	testCreateVector();
	testGetPackage();
	testSwapElem();
	testLength();
	testGetCapacaity();
	testSearch();
	testAppend();
	testDel();
}
void testCreateVector() {
	Vector vector = createVector();
	assert(getCapacity(&vector) == 2);
	assert(length(&vector) == 0);
	destroyVector(&vector);
}
void testGetPackage()
{
	Vector vector = createVector();
	assert(length(&vector) == 0);
	Package package = createPackage(1, "", "", "", 1);
	append(&vector, &package);
	assert(getPackage(&vector, 0).id == package.id);
	destroyVector(&vector);
}
void testSwapElem()
{
	Vector vector = createVector();
	Package package1 = createPackage(2, "", "", "", 1);
	Package package2 = createPackage(1, "", "", "", 1);
	append(&vector, &package1);
	append(&vector, &package2);
	swapElem(&vector, 0, 1);
	assert(getPackage(&vector, 0).id == package2.id);
	assert(getPackage(&vector, 1).id == package1.id);
	destroyVector(&vector);
}
void testLength() {
	Vector vector = createVector();
	assert(length(&vector) == 0);
	Package package = createPackage(1, "", "", "", 1);
	append(&vector, &package);
	assert(length(&vector) == 1);
	destroyVector(&vector);
}
void testGetCapacaity() {
	Vector vector = createVector();
	assert(getCapacity(&vector) == 2);
	destroyVector(&vector);
}
void testSearch() {
	Vector vector = createVector();
	Package package = createPackage(1, "", "", "", 1);
	Package package2 = createPackage(2, "", "", "", 1);
	append(&vector, &package);
	assert(search(&vector, &package) == 0);
	assert(search(&vector, &package2) == -1);
	destroyVector(&vector);
	destroyPackage(&package2);
}
void testAppend() {
	Vector vector = createVector();
	assert(length(&vector) == 0);
	Package package = createPackage(1, "", "", "", 1);
	append(&vector, &package);
	assert(length(&vector) == 1);
	destroyVector(&vector);
}
void testDel() {
	Vector vector = createVector();
	assert(length(&vector) == 0);
	Package package = createPackage(1, "", "", "", 1);
	Package package2 = createPackage(2, "", "", "", 1);
	append(&vector, &package);
	append(&vector, &package2);
	assert(length(&vector) == 2);
	assert(del(&vector, &package) == 1);
	assert(length(&vector) == 1);
	assert(del(&vector, &package2) == 1);
	assert(length(&vector) == 0);
	assert(del(&vector, &package) == 0);
	destroyVector(&vector);
}*/