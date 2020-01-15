#pragma once
#include "Console.h"
#include "Service.h"

void readPackage(Package *package) {
	int id = 0;
	char type[40];
	char destination[50];
	char date[11];
	double price = 0;
	readId(&id);
	readType(type);
	readDestination(destination);
	readDate(date);
	readPrice(&price);

	*package = createPackage(id, type, destination, date, price);
}

void readId(int *id) {
	do {
	printf("Id: ");
	scanf("%d", id);
	} while (validateNumber(*id) == 0);
}

void readType(char type[40]) {
	do {
	printf("Type: ");
	scanf("%s", type);
	} while (validateType(type) == 0);
}

void readDestination(char destination[50]) {
	do {
	printf("Destiantion: ");
	scanf("%s", destination);
	} while (validateDestination(destination) == 0);
}

void readDate(char date[11]) {
	do {
	printf("Date: ");
	scanf("%s", date);

	} while (validateDate(date) == 0);
}

void readPrice(double *price) {
	do {
	printf("Price: ");
	scanf("%lf", price);

	} while (validatePrice(*price) == 0);
}

void menu()
{
	printf("------------------------------------\n");
	printf("-          TravelAgency            -\n");
	printf("------------------------------------\n");
	printf("- 1. Add a travel package          -\n");
	printf("- 2. Update a travel package       -\n");
	printf("- 3. Remove a travel package       -\n");
	printf("- 4. View all packages             -\n");
	printf("- 5. Sort packages by price        -\n");
	printf("- 6. Sort packages by destination  -\n");
	printf("- 7. Filter packages by type       -\n");
	printf("- 8. Filter packages by price      -\n");
	printf("- 9. Filter packages by destination-\n");
	printf("- 10. Undo                         -\n");
	printf("- 11. Filter packages by date      -\n");
	printf("- 0. Iesire                        -\n");
	printf("------------------------------------\n");
}

void consoleAdd(Service *service) {
	int id;
	char type[40];
	char destination[50];
	char date[11];
	double price;
	readId(&id);
	readType(type);
	readDestination(destination);
	readDate(date);
	readPrice(&price);
	if (addPackage(service, id, type, destination, date, price) == 1) {
		printf("Package was added!\n");
	}
	else {
		printf("Package was not added!\n");
	}
}

void consoleUpdate(Service *service){
	int id;
	char type[40];
	char destination[50];
	char date[11];
	double price;
	readId(&id);
	readType(type);
	readDestination(destination);
	readDate(date);
	readPrice(&price);
	if (updatePackage(service, id, type, destination, date, price) == 1) {
		printf("Package was updated!\n");
	}
	else {
		printf("Package was not updated!\n");
	}
}

void consoleRem(Service *service){
	int id;
	readId(&id);
	if (remPackage(service, id) == 1) {
		printf("Package was removed!\n");
	}
	else {
		printf("Package was not removed!\n");
	}
}

void consoleFindAll(Service *service){
	Package* packages = findAllPackages(service);
	int i;
	if (service->repository->length == 0) {
		printf("No packages available!\n");
	}
	else {
		for (i = 0; i <service->repository->length; i++) {
			Package* p = get(service->repository, i);
			printf("%d. ID: %d|Type: %s|Destination: %s|Date: %s|Price %lf\n", i + 1,
				   p->id, p->type, p->destination, p->date, p->price);
			//printf("%d. ID: %d|Type: %s|Destination: %s|Date: %s|Price %lf\n", i+1,
				//packages[i].id, packages[i].type, packages[i].destination, packages[i].date, packages[i].price);
		}
	}
}

void consoleSortByPrice(Service *service,int mode) {
	Vector vector;
	Package* packages = sortByPrice(&vector,service,mode);
	int i;
	if (service->repository->length == 0) {
		printf("No packages available!\n");
	}
	else {
		for (i = 0; i < service->repository->length; i++) {
			printf("%d. ID: %d|Type: %s|Destination: %s|Date: %s|Price %lf\n", i + 1,
				packages[i].id, packages[i].type, packages[i].destination, packages[i].date, packages[i].price);
		}
	}
}

void consoleSortByDestination(Service * service,int mode){
	Vector vector;
	Package* packages = sortByDestination(&vector, service, mode);
	int i;
	if (service->repository->length == 0) {
		printf("No packages available!\n");
	}
	else {
		for (i = 0; i < service->repository->length; i++) {
			printf("%d. ID: %d|Type: %s|Destination: %s|Date: %s|Price %lf\n", i + 1,
				packages[i].id, packages[i].type, packages[i].destination, packages[i].date, packages[i].price);
		}
	}
}

void consoleFilterByDestination(Service * service)
{
	
	Vector* vector = createVector();
	char destinantion[50];
	readDestination(destinantion);
	filterByDestination(vector,service,destinantion);
	int i;
	if (length(vector) == 0) {
		printf("No packages available!\n");
	}
	else {
		for (i = 0; i < length(vector); i++) {
			Package* p = get(vector, i);
			printf("%d. ID: %d|Type: %s|Destination: %s|Date: %s|Price %lf\n", i + 1,
				   p->id, p->type, p->destination, p->date, p->price);

			//printf("%d. ID: %d|Type: %s|Destination: %s|Date: %s|Price %lf\n", i + 1,
			//	vector.packages[i].id, vector.packages[i].type, vector.packages[i].destination, vector.packages[i].date, vector.packages[i].price);
		}
	}
	destroyVector(vector);
}

void consoleFilterByPrice(Service * service)
{
	
	Vector* vector = createVector();
	double price = 0;
	readPrice(&price);
	filterByPrice(vector, service, price);
	int i;
	if (length(vector) == 0) {
		printf("No packages available!\n");
	}
	else {
		for (i = 0; i < length(vector); i++) {
			Package* p = get(vector, i);
			printf("%d. ID: %d|Type: %s|Destination: %s|Date: %s|Price %lf\n", i + 1,
				   p->id, p->type, p->destination, p->date, p->price);
			//printf("%d. ID: %d|Type: %s|Destination: %s|Date: %s|Price %lf\n", i + 1,
			//	vector.packages[i].id, vector.packages[i].type, vector.packages[i].destination, vector.packages[i].date, vector.packages[i].price);
		}
	}
	destroyVector(vector);
}

void consoleFilterByType(Service * service)
{
	
	Vector* vector = createVector();
	char type[40];
	readType(type);
	filterByType(vector, service, type);
	int i;
	if (length(vector) == 0) {
		printf("No packages available!\n");
	}
	else {
		for (i = 0; i < length(vector); i++) {
			Package* p = get(vector, i);
			printf("%d. ID: %d|Type: %s|Destination: %s|Date: %s|Price %lf\n", i + 1,
				   p->id, p->type, p->destination, p->date, p->price);
			//printf("%d. ID: %d|Type: %s|Destination: %s|Date: %s|Price %lf\n", i + 1,
				//vector.packages[i].id, vector.packages[i].type, vector.packages[i].destination, vector.packages[i].date, vector.packages[i].price);
		}
	}
	destroyVector(vector);
	
}

void consoleFilterByDate(Service* service)
{
    Vector* vector = createVector();
    char date[40];
    readDate(date);
    filterByDate(vector, service, date);
    int i;
    if (length(vector) == 0) {
        printf("No packages available!\n");
    }
    else {
        for (i = 0; i < length(vector); i++) {
			Package* p = get(vector, i);
			printf("%d. ID: %d|Type: %s|Destination: %s|Date: %s|Price %lf\n", i + 1,
				   p->id, p->type, p->destination, p->date, p->price);
            //printf("%d. ID: %d|Type: %s|Destination: %s|Date: %s|Price %lf\n", i + 1,
              //     vector.packages[i].id, vector.packages[i].type, vector.packages[i].destination, vector.packages[i].date, vector.packages[i].price);
        }
    }
    destroyVector(vector);
}

void consoleUndo(Service *service)
{
	undo(service);
}

int run() {
	Service service = createService();
	addPackage(&service, 1, "Beach", "asd", "asd", 20);
	/*addPackage(&service, 2, "Beach", "asdasd", "asd",  600);
	addPackage(&service, 3, "Mountain", "dsaasd", "asd", 19);
	addPackage(&service, 4, "asd", "asd", "asd", 400);
	addPackage(&service, 5, "asd", "rvgdsasd", "asd", 5);
	addPackage(&service, 6, "asd", "asfvsd", "asd", 600);
	addPackage(&service, 7, "asd", "vseasd", "asd", 7);
	addPackage(&service, 8, "asd", "avwrsd", "asd", 8);
	addPackage(&service, 9, "asd", "1asd", "asd", 19);
	addPackage(&service, 10, "asd", "werasd", "asd", 1);*/
	int cmd = -1;
	int mode = -1;
	//menu();
	while (1) {
		menu();
		printf("Please choose a command:");
		scanf("%d", &cmd);
		switch (cmd) {
		case 1:
			consoleAdd(&service);
			break;
		case 2:
			consoleUpdate(&service);
			break;
		case 3:
			consoleRem(&service);
			break;
		case 4:
			consoleFindAll(&service);
			break;
		case 5:
			printf("1.Price ascending\n");
			printf("2.Price descending\n");
			printf("Please choose a command:");
			scanf("%d", &mode);
			consoleSortByPrice(&service,mode-1);
			break;
		case 6:
			printf("1.Destination ascending\n");
			printf("2.Destination descending\n");
			printf("Please choose a command:");
			scanf("%d", &mode);
			consoleSortByDestination(&service,mode-1);
			break;
		case 7:
			consoleFilterByType(&service);
			break;
		case 8:
			consoleFilterByPrice(&service);
			break;
		case 9:
			consoleFilterByDestination(&service);
			break;
		case 10:
			consoleUndo(&service);
			break;
        case 11:
            consoleFilterByDate(&service);
            break;
		case 0:
			printf("EXIT");
			destroyService(&service);
			return 0;
		default:
			printf("Please insert a valid command!\n");
			break;
		}
	}
	destroyService(&service);
	return 0;
}
