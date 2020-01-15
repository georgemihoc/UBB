//#pragma once
#include "TestPackage.h"
#include "TestRepository.h"
#include "TestService.h"
#include "TestVector.h"
#include "TestValidator.h"
#include "Console.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
//#include <crtdbg.h>
/*
void tests() {
	callTestsPackage();
	callTestsVector();
	callTestsRepository();
	callTestsService();
	callTestsValidator();
}*/
int main()
{
	//tests();
	run();
	//_CrtDumpMemoryLeaks();
	return 0;
}