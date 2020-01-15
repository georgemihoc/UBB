#include "console.h"
#include "Book.h"
#include <iostream>
#include <string>
#include <map>
#include <stack>

using namespace std;
void ConsolUI::tipareste(const vector<Book>& Books) {
    cout<<"\n---------------------------------------------\n";
    cout<<"|                  Books                     |\n";
    cout<<"---------------------------------------------\n";
	if(Books.size()==0)
	    cout<<"------------------EMPTY LIST-----------------\n\n";
	else{
        for (const auto& Book : Books) {
            cout << "|Title: " << Book.getTitle() << " | Writer: " << Book.getWriter() << " | Genre: " << Book.getGenre()<< " | Year: " << Book.getYear() << " |\n";
            //cout << '' << Book.getTitle() << ' ' << Book.getWriter() << ' ' << Book.getGenre() << '\n';
        }
        cout<<"------------------------------------\n";
        cout << "\n------------End of Book list--------------\n\n";
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
void ConsolUI::adaugaUIBasket() {
	string ty, wr;
	cout << "Dati titlu:";
	cin >> ty;
	cout << "Dati autor:";
	cin >> wr;

	ctr.addBookBasket(ty, wr);
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
    cout << "Sters cu succes\n";

}
void ConsolUI::stergeUIBasket(){
	ctr.stergeBasket();
    cout << "Cos sters cu succes\n";
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
void ConsolUI::genuriUI(){
	map<string,int> dictionar;
	dictionar = ctr.filterGenre();
	for (auto& t : dictionar)
		cout <<"Sunt " <<t.second<< " genuri "<<t.first<<"\n";
}
void ConsolUI::randomUI()
{
	int nr;
	cout<<"Number of books:";
	cin>>nr;
	if(nr+ctr.getAllBasket().size() > ctr.getAll().size())
		cout<<"Nu exista atatea carti in stoc \n";
	else
		ctr.randomService(nr);
}
void ConsolUI::saveFileUI()
{
    ctr.saveFile();
}
void ConsolUI::saveFileBasketUI()
{
	ctr.saveFileBasket();
}
void ConsolUI::menu()
{
    cout<<'\n';
	cout<<"--------------------------------------------\n";
	cout<<"|                Book STORE MENU            |\n";
	cout<<"--------------------------------------------\n";
	cout<<"| 1. Add a Book                             |\n";
	cout<<"| 2. Show all Books                         |\n";
	cout<<"| 3. Sort Books by title                    |\n";
	cout<<"| 4. Sort Books by writer                   |\n";
	cout<<"| 5. Sort Books by year+genre               |\n";
	cout<<"| 6. Filter by year                         |\n";
	cout<<"| 7. Filter by title                        |\n";
	cout<<"| 8. Erase by position                      |\n";
	cout<<"| 9. Modify a book                          |\n";
	cout<<"| 10. Find a book                           |\n";
	cout<<"| 11. Sort Books by genre                   |\n";
	cout<<"| 12. Dictionar                             |\n";
	cout<<"| ------------------Basket------------------|\n";
	cout<<"| 13. Show basket <- NEW                    |\n";
	cout<<"| 14. Add book to the basket <- NEW         |\n";
	cout<<"| 15. Delete basket <- NEW                  |\n";
	cout<<"| 16. Add random books to the basket <- NEW |\n";
	cout<<" -------------------------------------------\n";
	cout<<"| 17. UNDO  <- NEW                          |\n";
	cout<<"| 18. UNDO NOU <- NEW                       |\n";
	cout<<"| 0. EXIT                                   |\n";
	cout<<"--------------------------------------------\n";
    cout<<"Insert command:";

}

void ConsolUI::start() {
    stack<int>comenzi;
    int cmd=-1;
    for(;;) {
	    saveFileUI();
	    saveFileBasketUI();
		menu();
		cin >> cmd;
		comenzi.push(cmd);
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
			case 11:
				tipareste(ctr.sortByGenre());
				break;
            case 12:
            	genuriUI();
                break;
            case 13:
                tipareste(ctr.getAllBasket());
                cout<<"Numarul cartilor din cos: "<<ctr.getAllBasket().size()<<"\n";
                break;
			case 14:
				adaugaUIBasket();
				cout<<"Numarul cartilor din cos: "<<ctr.getAllBasket().size()<<"\n";
				break;
			case 15:
				stergeUIBasket();
				cout<<"Numarul cartilor din cos: "<<ctr.getAllBasket().size()<<"\n";
				break;
			case 16:
				randomUI();
				cout<<"Numarul cartilor din cos: "<<ctr.getAllBasket().size()<<"\n";
				break;
            case 17:
			    ctr.undo(comenzi);
			    break;
            case 18:
                ctr.undo1();
                break;
			case 0:
				cout<< "\nEXIT\n";
				ctr.dealoc();
				return;
			default:
				cout << "Comanda invalida\n";
				comenzi.pop();
			}			
		}
		catch (BookRepoException& ex) {
			cout << ex <<'\n';
			comenzi.pop();
		}
		catch (ValidateException& ex) {
			cout << ex << '\n';
			comenzi.pop();
		}
	}
}