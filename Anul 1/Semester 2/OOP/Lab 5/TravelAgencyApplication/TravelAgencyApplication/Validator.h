#pragma once
#include <ctype.h>
#include <string.h>

//Function that validates a number
//Input:number-integer
//Output:1 if paramater is valid,0 otherwise
int validateNumber(int number);

//Function that validates the Type
//Input:type-char
//Output:1 if paramater is valid,0 otherwise
int validateType(char type[40]);

//Function that validates the Destination
//Input:destinantion-char
//Output:1 if paramater is valid,0 otherwise
int validateDestination(char destination[50]);

//Function that validates the Date
//Input:date-char
//Output:1 if paramater is valid,0 otherwise
int validateDate(char date[11]);

//Function that validates the Price
//Input:price-double
//Output:1 if paramater is valid,0 otherwise
int validatePrice(double price);


