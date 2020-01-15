#include "Validator.h"
#pragma once

int validateNumber(int number)
{
	if (number > 0) {
		return 1;
	}else return 0;
}

int validateType(char type[40])
{
	if (strcmp(type, "Mountain") == 0 || strcmp(type, "Sea") == 0 || strcmp(type, "Beach") == 0 || strcmp(type, "CityBreak")==0) {
		return 1;
	}else return 0;
}

int validateDestination(char destination[50])
{
	int len = strlen(destination);
	for (int i = 0; i < len; i++) {
		if (isdigit(destination[i]) != 0) {
			return 0;
		}
	}
	return 1;
}

int validateDate(char date[11])
{
	if ((isdigit(date[0]) != 0 && isdigit(date[1]) != 0) &&
		(date[2] == '/') &&
		(isdigit(date[3]) != 0 && isdigit(date[4]) != 0) &&
		(date[5] == '/') &&
		(isdigit(date[6]) != 0 && isdigit(date[7]) != 0 && 
			isdigit(date[8]) != 0 && isdigit(date[9]) != 0)
		) {
		return 1;
	}
	return 0;
}

int validatePrice(double price)
{
	if (price > 0) {
		return 1;
	}else return 0;
}

