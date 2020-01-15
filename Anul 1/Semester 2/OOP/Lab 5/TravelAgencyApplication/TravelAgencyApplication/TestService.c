#include "TestService.h"
#include <stdio.h>
/*
void callTestsService() {
	testCreateService();
	testAddPackage();
	testRemPackage();
	testUpdatePackage();
	testFindOnePackage();
	testFindPositionOfPackage();
	testFindAllPackages();
	testGetAll();
	testSortByPrice();
	testSortByDestination();
	testFilterByDestination();
	testFilterByType();
	testFilterByPrice();
}
void testCreateService() {
	Service service = createService();
	Package package1 = createPackage(1, "type", "destination", "date", 200);
	assert(service.repository.capacity == 2);
	assert(service.repository.length == 0);
	add(&service.repository, &package1);
	assert(comparePackages(&service.repository.packages[0], &package1) == 1);
	destroyService(&service);
}
void testAddPackage() {
	Service service = createService();
	assert(addPackage(&service, 1, "type", "destination", "date", 200) == 1);
	assert(addPackage(&service, 1, "type", "destination", "date", 200) == -1);
	destroyService(&service);
}
void testRemPackage() {
	Service service = createService();
	assert(addPackage(&service, 1, "type", "destination", "date", 200) == 1);
	assert(remPackage(&service, 1) == 1);
	assert(remPackage(&service, 1) == 0);
	destroyService(&service);
}
void testUpdatePackage() {
	Service service = createService();
	assert(addPackage(&service, 1, "type", "destination", "date", 200) == 1);
	assert(updatePackage(&service, 1, "type", "destination", "date", 200) == 1);
	assert(updatePackage(&service, 2, "type", "destination", "date", 200) == 0);
	destroyService(&service);
}
void testFindOnePackage() {
	Service service = createService();
	assert(findOnePackage(&service,1) == NULL);
	assert(addPackage(&service, 1, "type", "destination", "date", 200) == 1);
	assert(comparePackages(findOnePackage(&service, 1),&service.repository.vector.packages[0])==1);
	destroyService(&service);
}
void testFindPositionOfPackage() {
	Service service = createService();
	assert(addPackage(&service, 1, "type", "destination", "date", 200) == 1);
	assert(findPositionOfPackage(&service, 1) == 0);
	destroyService(&service);
}
void testFindAllPackages() {
	Service service = createService();
	assert(addPackage(&service, 1, "type", "destination", "date", 200) == 1);
	assert(addPackage(&service, 2, "type", "destination", "date", 200) == 1);
	Package* packages= findAllPackages(&service);
	assert(comparePackages(&packages[0], &service.repository.vector.packages[0]) == 1);
	assert(comparePackages(&packages[1], &service.repository.vector.packages[1]) == 1);
	destroyService(&service);
}

void testGetAll() {
	Service service = createService();
	assert(addPackage(&service, 1, "type", "destination", "date", 200) == 1);
	assert(addPackage(&service, 2, "type", "destination", "date", 200) == 1);
	Vector vector = getAll(&service);
	assert(getPackage(&vector, 0).id == 1);
	destroyService(&service);
}
void testSortByPrice() {
	Service service = createService();
	assert(addPackage(&service, 1, "type", "destination", "date", 100) == 1);
	assert(addPackage(&service, 2, "type", "destination", "date", 200) == 1);
	ensureCapacity(&service.repository.vector);
	assert(addPackage(&service, 3, "type", "destination", "date", 150) == 1);
	Vector vector;
	Package* packages = sortByPrice(&vector, &service, 1);
	assert(packages[0].id == 2);
	packages = sortByPrice(&vector, &service, 0);
	assert(packages[0].id == 1);
	destroyService(&service);
}
void testSortByDestination() {
	Service service = createService();
	assert(addPackage(&service, 1, "type", "xdestination", "date", 100) == 1);
	assert(addPackage(&service, 2, "type", "destination", "date", 200) == 1);
	ensureCapacity(&service.repository.vector);
	assert(addPackage(&service, 3, "type", "restination", "date", 200) == 1);
	Vector vector;
	Package* packages = sortByDestination(&vector, &service, 0);
	assert(packages[0].id == 2);
	packages = sortByDestination(&vector, &service, 1);
	assert(packages[0].id == 1);
	destroyService(&service);

}
void testFilterByDestination() {
	Service service = createService();
	assert(addPackage(&service, 1, "type", "xdestination", "date", 100) == 1);
	assert(addPackage(&service, 2, "type", "destination", "date", 200) == 1);
	Vector vector = createVector();
	filterByDestination(&vector, &service,"destination");
	assert(vector.packages[0].id == 2);
	assert(length(&vector) == 1);
	destroyService(&service);
	destroyVector(&vector);

}
void testFilterByType() {
	Service service = createService();
	assert(addPackage(&service, 1, "xtype", "xdestination", "date", 100) == 1);
	assert(addPackage(&service, 2, "type", "destination", "date", 200) == 1);
	Vector vector = createVector();
	filterByType(&vector, &service, "type");
	assert(vector.packages[0].id == 2);
	assert(length(&vector) == 1);
	destroyService(&service);
	destroyVector(&vector);
	
}
void testFilterByPrice() {
	Service service = createService();
	assert(addPackage(&service, 1, "type", "xdestination", "date", 100) == 1);
	assert(addPackage(&service, 2, "type", "destination", "date", 200) == 1);
	Vector vector = createVector();
	filterByPrice(&vector, &service, 200);
	assert(vector.packages[0].id == 2);
	assert(length(&vector) == 1);
	destroyService(&service);
	destroyVector(&vector);
}*/