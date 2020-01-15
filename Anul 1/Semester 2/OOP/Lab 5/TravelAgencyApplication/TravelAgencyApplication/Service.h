#pragma once
#include "Repository.h"

typedef struct {
	//Repository repository;
	Vector* repository;
	Vector* undoList;
}Service;

//Constructor for Service
Service createService();

//Decontructor for Service
void destroyService(Service* service);

//Function that adds a package
//Input:id-integer
//		type,destination,date-char
//		price-double
//Output:1 if package was added with succes,0 if there is no space to add,-1 if the package is already in the system
int addPackage(Service* service, int id, char* type, char* destination, char* date, double price);
/*
Function that removes a package
Input:id-integer
Output:1 if package was removed with succes,0 otherwise
*/
int undo(Service* service);

int remPackage(Service* service,int id);
/*
Function that updates a package
Input:id-integer
		type,destination,date-char
		price-double
Output:1 if package was update with succes,0 otherwise
*/
int updatePackage(Service* service, int id, char* type, char* destination, char* date, double price);
/*
Function that finds a package by its id
Input:id-integer
Output:Package with given id
*/
Package* findOnePackage(Service* service,int id);
/*
Function that finds the position of a Package
Input:id-integer
Output:Position of the package with given id
*/
int findPositionOfPackage(Service* service,int id);
/*
Function that returns the vector of Packages
Output:Vector
*/
Vector* getAll(Service* service);
Vector getUndo(Service* service) ;

/*
Function that returns all the packages
Output:Packages
*/
Package* findAllPackages(Service* service);
/*
Function that returns all the packages,sorted by price
Output:Packages
*/
Package* findAllUndo(Service* service);

Package* sortByPrice(Vector * vector, Service  * service, int reverse);
/*
Function that returns all the packages,sorted by destination
Output:Packages
*/
Package* sortByDestination(Vector * vector, Service  * service, int reverse);
/*
Function that returns all the packages filtered by destination
Output:Packages
*/
void filterByDestination(Vector* vector,Service* service, char* destination);
/*
Function that returns all the packages filtered by price
Output:Packages
*/
void filterByPrice(Vector* newVector,Service* service, double price);
/*
Function that returns all the packages filtered by type
Output:Packages
*/
void filterByType(Vector* newVector,Service* service, char* type);

void filterByDate(Vector* newVector,Service* service, char* type);