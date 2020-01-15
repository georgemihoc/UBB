#pragma once

typedef struct {
	int id;
	char* type;
	char* destination;
	char* date;
	double price;
}Package;

//Constructor for Pacakge
Package createPackage(int id, char* type, char* destination, char* date, double price);
void destroyPackage(Package* package);

//Getters
Package copyPackage1(Package* p);
int getId(Package* package);
char* getType(Package* package);
char* getDestination(Package* package);
char* getDate(Package* package);
double getPrice(Package* package);

//Setters
void setType(Package* package, char* type);
void setDestination(Package* package, char* destination);
void setDate(Package* package, char* date);
void setPrice(Package* package, double price);

//Function that compares 2 packages
//Returns 1 if equals,0 otherwise
int comparePackages(Package* package1, Package* package2);

//Function that swaps 2 packages
void swap(Package* package1, Package* package2);

