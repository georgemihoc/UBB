#pragma once
#include "Service.h"
#include <iostream>

using std::cout;
class Ui_obj
{
	Service& serv;
public:
	Ui_obj()=default;
	Ui_obj(Service& serv) :serv{ serv } {};
	Ui_obj(const Ui_obj& ot) :serv{ ot.serv } {
		cout << "copie ui!\n";
	}
	void run();
	void meniu();
	void ui_adauga();
	void print(Lista<Book>);
	void ui_sterge();
	void ui_modifica();
	void ui_cautare();
	void filtrare_dupa_titlu();
	void filtrare_dupa_autor();
	void elibereaza();
};

