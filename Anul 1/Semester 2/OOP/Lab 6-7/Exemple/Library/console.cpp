#include "console.h"
#include "Book.h"
#include <iostream>
#include <string>

using namespace std;
void ConsolUI::tipareste(const VectDinNewDeleteT<Book>& Books) {
    cout<<"\n---------------------------------------------\n";
    cout<<"|                  Books                     |\n";
    cout<<"---------------------------------------------\n";
	if(Books.size()==0)
	    cout<<"-------------EMPTY LIST-------------\n\n";
	else{
        for ( const auto& Book : Books) {
            cout << "|Title: " << Book.getTitle() << " | Writer: " << Book.getWriter() << " | Genre: " << Book.getGenre()<< " | Year: " << Book.getYear() << " |\n";
            //cout << '' << Book.getTitle() << ' ' << Book.getWriter() << ' ' << Book.getGenre() << '\n';
        }
        cout<<"------------------------------------\n";
        cout << "\n--------End of Book list-----------\n\n";
	}
}

void ConsolUI::adaugaUI() {
	string ty, wr,gen;
	int year;
	cout << "Dati titlu:";
	cin >> ty;
	cout << "Dati autor:";
	cin >> wr;
	cout << "Dati gen:";
	cin >> gen;
	cout << "Dati an:";
	cin >> year;
	ctr.addBook(ty, wr,gen, year);
	cout << "Adaugat cu succes\n";
}
void ConsolUI::modifica()
{
	int poz, year;
	cout<<"Position:";
	cin>>poz;
	string ty, wr,gen;
	cout<<"Title:";
	cin>> ty;

	cout<<"Writer:";
	cin>>wr;

	cout<<"Genre:";
	cin>>gen;

	cout<<"Year:";
	cin>>year;
	//cout<<ty;
	ctr.modify(poz,ty,wr,gen,year);
	//cout<<"tun";
}
void ConsolUI::stergeUI(){
	cout<<"Introduceti pozitia: \n";
	int poz;
	cin >> poz;
	ctr.sterge(poz);
}
void ConsolUI::cautaUI(){
	string ty,wr;
	cout<<"Title:";
	cin>> ty;

	cout<<"Writer:";
	cin>>wr;

	//if(ctr.cauta(ty,wr))
	//{
	Book p = ctr.cauta(ty,wr);
	cout << "|Title: " << p.getTitle() << " | Writer: " << p.getWriter() << " | Genre: " << p.getGenre()<< " | Year: " << p.getYear() << " |\n";
	//}
}
void ConsolUI::filtrareTitlu(){
	string title;
	cout<<"Title:";
	cin>>title;
	tipareste(ctr.filterTitle(title));

}
void ConsolUI::menu()
{
    cout<<'\n';
	cout<<"------------------------------------\n";
	cout<<"|          Book STORE MENU          |\n";
	cout<<"------------------------------------\n";
	cout<<"| 1. Add a Book                     |\n";
	cout<<"| 2. Show all Books                 |\n";
	cout<<"| 3. Sort Books by title            |\n";
	cout<<"| 4. Sort Books by writer           |\n";
	cout<<"| 5. Sort Books by year+genre       |\n";
	cout<<"| 6. Filter by year                 |\n";
	cout<<"| 7. Filter by title                |\n";
	cout<<"| 8. Erase by position              |\n";
	cout<<"| 9. Modify a book                  |\n";
	cout<<"| 10. Find a book                   |\n";
	cout<<"| 0. EXIT                           |\n";
	cout<<"------------------------------------\n";
    cout<<"Insert command:";

}

void ConsolUI::start() {
	while (true) {
		menu();
		int cmd;
		cin >> cmd;
		try {
			switch (cmd) {
			case 1:
				adaugaUI();
				break;
			case 2:
				tipareste(ctr.getAll());
				break;
			case 3:
				tipareste(ctr.sortByTitle());
				break;
			case 4:
				tipareste(ctr.sortByWriter());
				break;
			case 5:
				tipareste(ctr.sortByYearGenre());
				break;
			case 6:
				cout << "Year:";
				int year;
				cin >> year;
				tipareste(ctr.filtrareYear(year));
				break;
			case 7:
				
				//cout << "Minimum year:";
				//int pretMin;
				//cin >> pretMin;
				//cout << "Maximum year:";
				//int pretMax;
				//cin >> pretMax;
				//tipareste(ctr.filtrarePret(pretMin,pretMax));
				filtrareTitlu();
				break;
			case 8:
				stergeUI();
				break;
			case 9:
				modifica();
				break;
			case 10:
				cautaUI();
				break;
			case 0:
				cout<< "\nEXIT\n";
				return;
			default:
				cout << "Comanda invalida\n";
			}			
		}
		catch (BookRepoException& ex) {
			cout << ex <<'\n';
		}
		catch (ValidateException& ex) {
			cout << ex << '\n';
		}
	}
}