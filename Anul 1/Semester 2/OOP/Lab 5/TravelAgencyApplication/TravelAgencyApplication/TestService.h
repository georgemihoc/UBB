#pragma once
#include "Service.h"
#include <assert.h>
#include "Package.h"

//Function that calls all the Service tests
void callTestsService();

//Functions that test all the Service functions
void testCreateService();
void testAddPackage();
void testRemPackage();
void testUpdatePackage();
void testFindOnePackage();
void testFindPositionOfPackage();
void testFindAllPackages();
void testGetAll();
void testSortByPrice();
void testSortByDestination();
void testFilterByDestination();
void testFilterByType();
void testFilterByPrice();