#pragma once
#include"Repository.h"


Repository createRepository() {
	Repository repository;
	repository.vector = createVector();
	//repository.undoVector = createUndoVector();
	return repository;
}

void destroyRepository(Repository* repository) {
	destroyVector(&repository->vector);
}

void add(Repository *repository, Package* package) {
	append(&repository->vector, package);
	//Package* toUndo = findAll(repository);

}
/*
void undoadd(Repository *repository, Package* package)
{
	append(&repository->undoVector, package);
}*/

int findPosition(Repository *repository, ElemType package) {
	int i;
	for (i = 0; i < length(&repository->vector); i++)
	{
		if (comparePackages(package,&repository->vector->packages[i]) == 1)
			return i;
	}
	return -1;
}

Package* findOne(Repository * repository, int id)
{
	int i;
	for (i = 0; i < length(&repository->vector); i++) {
		Package* p = get(repository, i);
		if(p->id==id){
		//if (repository->vector.packages[i].id == id) {
			return &repository->vector->packages[i];
		}
	}
	return NULL;
}

int rem(Repository *repository, Package* package) {
	return del(&repository->vector, package);
}

int update(Repository *repository, Package* package) {
	int position = findPosition(repository, package);
	if (position != -1)
	{
		setDate(&repository->vector->packages[position], package->date);
		setDestination(&repository->vector->packages[position], package->destination);
		setType(&repository->vector->packages[position], package->type);
		setPrice(&repository->vector->packages[position], package->price);
		destroyPackage(package);
		return 1;
	}
	destroyPackage(package);
	return 0;
}

Package* findAll(Repository *repository) {
	return repository->vector->packages;
}