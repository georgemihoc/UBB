//#pragma once
#include "Service.h"
#include "Repository.h"
#include "Vector.h"
#include <string.h>
#include <stdio.h>
Service createService()
{
	Service service;
	service.repository = createVector();
	service.undoList = createUndoVector();
	return service;
}

void destroyService(Service* service) {
	destroyRepository(&service->repository);
	//destroyRepository(&service->undoList);
}

int addPackage(Service* service, int id, char* type, char* destination, char* date, double price) {
	//printf("%s \n",destination);
	Package package = createPackage(id, type, destination, date, price);
	//Package *toUndo = findAllPackages(service);
	Vector* toUndo = copyList(*service->repository);
	/*int i;
	for (i = 0; i <service->repository.length; i++) {
		printf("%d. ID: %d|Type: %s|Destination: %s|Date: %s|Price %lf\n", i + 1,
			   toUndo[i].id, toUndo[i].type, toUndo[i].destination, toUndo[i].date, toUndo[i].price);
	}*/
	printf("\n");
	//Vector* toUndo = findAllPackages(service);
	if (findPosition(service->repository, &package) == -1) {
		append(service->repository, &package);
		printf("%d \n",service->undoList->length);
		//append(service->undoList, &toUndo);
		return 1;
	}else {
		destroyPackage(&package);
		return -1;
	}
}

int undo(Service* service) {
	Package* undolista= findAllUndo(service);

	for (int i = 0; i <service->undoList->length; i++) {
		printf("%d ",undolista[i].id);
		printf("%d. ID: %d|Type: %s|Destination: %s|Date: %s|Price %lf\n", i + 1,
			   undolista[i].id, undolista[i].type, undolista[i].destination, undolista[i].date, undolista[i].price);
	}

	if (service->undoList->length == 0) {
		return 1;//no more undo
	}
	///destroyVector(&service->repository);
	//service->repository = service->undoList[0];
	printf("%d \n",service->undoList->length);
	return 0;

	//Vector *l = removeLast(&service->undoList);
	//service->repository = l;




	//Package *toUndo = findAllUndo(service);
	//printf("%d \n",service->undoList->length);
	//int i;
	/*for (i = 0; i <service->undoList->length; i++) {
		printf("tun");
		printf("%d. ID: %d|Type: %s|Destination: %s|Date: %s|Price %lf\n", i + 1,
			   toUndo[i].id, toUndo[i].type, toUndo[i].destination, toUndo[i].date, toUndo[i].price);
	}*/
	//Vector* l = removeLast(store->undoList);
	//destroyList(store->allPets);
	//service->repository = service->undoList[1];
	/*
	printf("TUN");
	//Package* l = removeLast(service->undoList);
	//destroyVector(service->repository);
	//service->repository = l;
	return 0;*/
}

int remPackage(Service* service, int id) {
	Package* package = findOne(&service->repository,id);
	if (package != NULL) {
		return rem(&service->repository, package);
	}
	return 0;
}
int updatePackage(Service* service, int id, char* type, char* destination, char* date, double price) {
	Package package = createPackage(id, type, destination, date, price);
	return update(&service->repository, &package);
}
Package* findOnePackage(Service* service, int id) {
	return findOne(&service->repository, id);
}
int findPositionOfPackage(Service* service, int id) {
	return findPosition(&service->repository, findOne(&service->repository,id));
}
Package* findAllPackages(Service* service) {
	return findAll(&service->repository);
}
Package* findAllUndo(Service* service)
{
	//return findAll(&service->undoList[service->undoList->length - 5 ]);
	return findAll(&service->undoList[0]);
}
/*
Vector getUndo(Service* service) {
	return service->undoList;
}*/
Vector* getAll(Service* service) {
	return service->repository;
}

Package* sortByPrice(Vector * vector, Service  * service, int reverse) {
	int i, j;
	*vector = *getAll(service);
	//Package package1, package2;
	ElemType package1, package2;
	for (i = 0; i < length(vector) - 1; i++)
	{
		package1 = getPackage(vector, i);
		for (j = i + 1; j < length(vector); j++)
		{
			package2 = getPackage(vector, j);
			if ((reverse == 0) && (getPrice(&package1) > getPrice(&package2)))
			{
				swapElem(vector, i, j);
				package1 = getPackage(vector, i);
			}
			else {
				if ((reverse == 1) && (getPrice(&package1) < getPrice(&package2)))
				{
					swapElem(vector, i, j);
					package1 = getPackage(vector, i);
				}
			}
		}
	}
	return vector->packages;
}

Package* sortByDestination(Vector * vector, Service  * service, int reverse) {
	int i, j;
	*vector = *getAll(service);
	ElemType package1, package2;
	for (i = 0; i < length(vector) - 1; i++)
	{
		package1 = getPackage(vector, i);
		for (j = i + 1; j < length(vector); j++)
		{
			package2 = getPackage(vector, j);
			if ((reverse == 0) && (strcmp(getDestination(&package2),getDestination(&package1)))<0)
			{
				swapElem(vector, i, j);
				package1 = getPackage(vector, i);
			}
			else {
				if ((reverse == 1) && (strcmp(getDestination(&package2), getDestination(&package1)))>0)
				{
					swapElem(vector, i, j);
					package1 = getPackage(vector, i);
				}
			}
		}
	}
	return vector->packages;
}

void filterByDestination(Vector* newVector,Service* service,char* destination) {
	Package package1;
	int i;
	for (i = 0; i < length(&service->repository); i++) {
		package1 = copyPackage(&service->repository,i);
		if (strcmp(getDestination(&package1), destination) == 0) {
			append(newVector, &package1);
		}
		else {
			destroyPackage(&package1);
		}
	}
}

void filterByPrice(Vector* newVector,Service* service,double price) {
	Package package1;
	int i;
	for (i = 0; i < length(&service->repository); i++) {
		package1 = copyPackage(&service->repository, i);
		if (getPrice(&package1) == price) {
			append(newVector, &package1);
		}
		else {
			destroyPackage(&package1);
		}
	}
}

void filterByType(Vector* newVector,Service* service,char* type) {
	Package package1;
	int i;
	for (i = 0; i < length(&service->repository); i++) {
		package1 = copyPackage(&service->repository, i);
		if (strcmp(getType(&package1), type) == 0) {
			append(newVector, &package1);
		}
		else {
			destroyPackage(&package1);
		}
	}
}

void filterByDate(Vector* newVector,Service* service,char* date) {
    Package package1;
    int i;
    for (i = 0; i < length(&service->repository); i++) {
        package1 = copyPackage(&service->repository, i);
        if (strcmp(getDate(&package1), date) == 0) {
            append(newVector, &package1);
        }
        else {
            destroyPackage(&package1);
        }
    }
}