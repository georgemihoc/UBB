#include "Console.h"
#include "Service.h"
#include "Repository.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
//#include <crtdbg.h>
#include <iostream>
using std::cout;

void adaugaCateva(Service& serv) {
	serv.adauga("a", "zz",2006,"a");
	serv.adauga("b", "aa",2010,"a");
	serv.adauga("c", "bb",2016,"a");
	serv.adauga("d", "cc",2017,"a");

}

void test_all() {
	test_repo();
	test_service();
}

int main(void) {

	Validator val;
	Repository repo;
	Service serv{ repo, val };
	adaugaCateva(serv);//adaugam cateva carti
	Ui_obj Ui{ serv };
	
	test_all();
	cout << "All tests passed";
	Ui.run();
	return 0;
}




