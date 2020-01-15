#include "Package.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

Package createPackage(int id, char* type, char* destination, char* date, double price)
{
	Package package;
	package.id = id;
	int length = strlen(type) + 1;
	package.type = malloc(sizeof(char)*length);
	strcpy(package.type,  type);
	length = strlen(destination) + 1;
	package.destination = malloc(sizeof(char)*length);
	strcpy(package.destination,destination);
	length = strlen(date) + 1;
	package.date = malloc(sizeof(char)*length);
	strcpy(package.date, date);
	package.price=price;
	//printf("%s",package.destination);
	return package;
}

void destroyPackage(Package* package) {
	free(package->type);
	package->type = NULL;
	free(package->destination);
	package->destination = NULL;
	free(package->date);
	package->date = NULL;
	package->id = -1;
	package->price = -1;
}

int getId(Package * package)
{
	return package->id;
}

char* getType(Package * package)
{
	return package->type;
}

char* getDestination(Package * package)
{
	return package->destination;
}

char* getDate(Package * package)
{
	return package->date;
}

double getPrice(Package * package)
{
	return package->price;
}

Package copyPackage1(Package* p) {
	return createPackage(p->id,p->type, p->destination,p->date, p->price);
}
void setType(Package * package, char* type)
{
	free(package->type);
	int length = strlen(type)+1;
	package->type = malloc(sizeof(char)*length);
	strcpy(package->type,type);
}

void setDestination(Package * package, char* destination)
{
	free(package->destination);
	int length = strlen(destination) + 1;
	package->destination = malloc(sizeof(char)*length);
	strcpy(package->destination, destination);
}

void setDate(Package * package, char* date)
{
	free(package->date);
	int length = strlen(date) + 1;
	package->date = malloc(sizeof(char)*length);
	strcpy(package->date, date);
}

void setPrice(Package * package, double price)
{
	package->price = price;
}

int comparePackages(Package * package1, Package * package2)
{
	if (getId(package1) == getId(package2)) {
		return 1;
	}else return 0;
}

void swap(Package * package1, Package * package2)
{
	Package aux = createPackage(0, "asd", "asd", "asd", 1);
	aux.id = getId(package1);
	setType(&aux, getType(package1));
	setDestination(&aux, getDestination(package1));
	setDate(&aux, getDate(package1));
	setPrice(&aux, getPrice(package1));
	

	(*package1).id = getId(package2);
	setType(package1, getType(package2));
	setDestination(package1, getDestination(package2));
	setDate(package1, getDate(package2));
	setPrice(package1, getPrice(package2));
	

	(*package2).id = getId(&aux);
	setType(package2, getType(&aux));
	setDestination(package2, getDestination(&aux));
	setDate(package2, getDate(&aux));
	setPrice(package2, getPrice(&aux));

	destroyPackage(&aux);
}
