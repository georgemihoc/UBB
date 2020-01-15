#pragma once
#include "TestPackage.h"
#include "Package.h"
#include <assert.h>

//Function that calls all the Package tests
void callTestsPackage();

//Functions that test all the Package functions
void testCreatePackage();
void testGetters();
void testSetters();
void testComparePackages();
void testSwap();