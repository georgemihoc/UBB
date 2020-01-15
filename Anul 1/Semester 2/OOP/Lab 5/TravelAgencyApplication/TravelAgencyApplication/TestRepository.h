#pragma once
#include "Repository.h"
#include <string.h>
#include <stdio.h>

//Function that calls all the Repository tests
void callTestsRepository();

//Functions that tests all the Repository functions
void testCreateRepository();
void testAdd();
void testUpdate();
void testRem();
void testFindPosition();
void testFindOne();
void testFindAll();