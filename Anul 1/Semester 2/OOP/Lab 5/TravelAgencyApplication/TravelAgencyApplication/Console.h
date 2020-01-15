#pragma once
#include "Service.h"
#include "Validator.h"
#include <stdio.h>
int run();
void menu();

//console functions that help at reading data
void readId(int *id);
void readType(char type[40]);
void readDestination(char destination[50]);
void readPrice(double *price);
void readDate(char date[11]);

//console function that adds data
void consoleAdd(Service *service);

//console function that updates data
void consoleUpdate(Service *service);

//console function that removes data
void consoleRem(Service *service);

//console function that prints all the data
void consoleFindAll(Service *service);

//console functions that sort data by specific atributes
void consoleSortByPrice(Service *service,int mode);
void consoleSortByDestination(Service *service,int mode);

//console functions that filter data by specific atributes
void consoleFilterByDestination(Service *service);
void consoleFilterByPrice(Service *service);
void consoleFilterByType(Service *service);
void consoleFilterByDate(Service *service);

