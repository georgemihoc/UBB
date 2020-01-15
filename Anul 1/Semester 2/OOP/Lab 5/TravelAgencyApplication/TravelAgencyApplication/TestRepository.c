#pragma once
#include "TestRepository.h"
#include <assert.h>
/*
void callTestsRepository() {
	 testCreateRepository();
	 testAdd();
	 testUpdate();
	 testRem();
	 testFindPosition();
	 testFindOne();
	 testFindAll();
}
void testCreateRepository() {
	Repository repository = createRepository();
	assert(repository.vector.capacity == 2);
	assert(repository.vector.length == 0);
	destroyRepository(&repository);
}

void testAdd() {
	Repository repository = createRepository();
	Package package1 = createPackage(1, "type", "destination", "date", 200);
	Package package2 = createPackage(2, "type", "destination", "date", 200);
	add(&repository, &package1);
	assert(repository.vector.length == 1);
	add(&repository, &package2);
	assert(repository.vector.length == 2);
	destroyRepository(&repository);
}
void testUpdate() {
	Repository repository = createRepository();
	Package package1 = createPackage(1, "type", "destination", "date", 200);
	Package package2 = createPackage(1, "", "", "", 201);
	add(&repository, &package1);
	assert(strcmp(getType(&repository.vector.packages[0]), "type") == 0);
	update(&repository, &package2);
	assert(strcmp(getType(&repository.vector.packages[0]), "") == 0);
	destroyRepository(&repository);
	destroyPackage(&package2);
}
void testRem() {
	Repository repository = createRepository();
	Package package1 = createPackage(1, "type", "destination", "date", 200);
	Package package2 = createPackage(1, "", "", "", 201);
	add(&repository, &package1);
	assert(repository.vector.length == 1);
	assert(rem(&repository, &package2));
	assert(repository.vector.length == 0);
	destroyRepository(&repository);
	destroyPackage(&package1);
}
void testFindPosition() {
	Repository repository = createRepository();
	Package package1 = createPackage(1, "type", "destination", "date", 200);
	add(&repository, &package1);
	assert(repository.vector.length == 1);
	assert(findPosition(&repository, &package1)==0);
	destroyRepository(&repository);
}

void testFindOne() {
	Repository repository = createRepository();
	Package package1 = createPackage(1, "type", "destination", "date", 200);
	Package package2 = createPackage(2, "", "", "", 201);
	add(&repository, &package1);
	add(&repository, &package2);
	assert(comparePackages(findOne(&repository, 1), &package1) == 1);
	assert(comparePackages(findOne(&repository, 2), &package2) == 1);
	destroyRepository(&repository);
}

void testFindAll() {
	Repository repository = createRepository();
	Package package1 = createPackage(1, "type", "destination", "date", 200);
	Package package2 = createPackage(2, "", "", "", 201);
	add(&repository, &package1);
	add(&repository, &package2);
	Package* packages = findAll(&repository);
	assert(comparePackages(&package1, &packages[0]) == 1);
	assert(comparePackages(&package2, &packages[1]) == 1);
	destroyRepository(&repository);
}*/