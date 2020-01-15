#pragma once
#include <stddef.h>
#include "Package.h"
#include "Vector.h"
typedef struct {
	Vector* vector;
	//Vector* undoVector;
}Repository;

//Contructor for Repository
Repository createRepository();


//Deconstructor for Repository
void destroyRepository(Repository* repository);
/*
Function that adds a package to the repository
Input:package-Package
Output:1 if package added with succes,0 otherwise
*/
void add(Repository *repository, Package* package);
/*
Function that removes a package to the repository
Input:package-Package
Output:1 if package removed with succes,0 otherwise
*/
//void undoadd(Repository *repository, Package* package)

int rem(Repository *repository, Package* package);
/*
Function that updates a package to the repository
Input:package-Package
Output:1 if package updated with succes,0 otherwise
*/
int update(Repository *repository, Package* package);
/*
Function that finds the position of a package in the repository
Input:package-Package
Output:Position of a given package,-1 if package was not found
*/
int findPosition(Repository *repository, ElemType package);
/*
Function that finds a package in the repository
Input:id-Integer
Output:Package with given id
*/
Package* findOne(Repository *repository, int id);
/*
Function that returns all the packages
Output:All the packages
*/
Package* findAll(Repository *repository);

