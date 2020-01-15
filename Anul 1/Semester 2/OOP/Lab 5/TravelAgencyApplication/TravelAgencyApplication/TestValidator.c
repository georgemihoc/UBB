#pragma once
#include "TestValidator.h"

void callTestsValidator() {
	testValidateNumber();
	testValidateType();
	testValidateDestination();
	testValidateDate();
	testValidatePrice();
}
void testValidateNumber() {
	assert(validateNumber(0) == 0);
	assert(validateNumber(1) == 1);
}
void testValidatePrice() {
	assert(validatePrice(0) == 0);
	assert(validatePrice(1) == 1);
}
void testValidateType() {
	assert(validateType("Mountain") == 1);
	assert(validateType("Type") == 0);
	assert(validateType("Beach") == 1);
}
void testValidateDestination() {
	assert(validateDestination("Aasdasda1231") == 0);
	assert(validateDestination("Aasdasda") == 1);
	assert(validateDestination("123") == 0);
}
void testValidateDate() {
	assert(validateDate("11/11/2019") == 1);
	assert(validateDate("asdas") == 0);
	assert(validateDate("11 11 2019") == 0);

}