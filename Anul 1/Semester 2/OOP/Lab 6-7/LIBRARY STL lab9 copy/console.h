#pragma once
#include "BookStore.h"
#include "Book.h"
class ConsolUI {
	BookStore& ctr;
	/*
	Citeste datele de la tastatura si adauga Book
	arunca exceptie daca: nu se poate salva, nu e valid
	*/
	void menu();
	void adaugaUI();
	void adaugaUIBasket();
	void stergeUI();
	void stergeUIBasket();
	void modifica();
	void cautaUI();
	void genuriUI();
	void randomUI();
	void filtrareTitlu();
	void saveFileUI();
	void saveFileBasketUI();
	/*
	Tipareste o lista de carti la consola
	*/
	void tipareste(const vector<Book>& Books);
public:
	ConsolUI(BookStore& ctr) noexcept:ctr{ ctr } {
	}
	//nu permitem copierea obiectelor
	ConsolUI(const ConsolUI& ot) = delete;

	void start();
};