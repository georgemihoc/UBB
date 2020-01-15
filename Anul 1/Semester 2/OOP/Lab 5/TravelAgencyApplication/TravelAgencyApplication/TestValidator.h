#pragma once
#include "Validator.h"
#include <assert.h>

//Function that calls all the Validator tests
void callTestsValidator();

//Functions that test all the Validator functions
void testValidateNumber();
void testValidateType();
void testValidateDestination();
void testValidateDate();
void testValidatePrice();