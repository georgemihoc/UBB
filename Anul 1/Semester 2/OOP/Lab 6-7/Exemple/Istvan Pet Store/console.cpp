#include "console.h"

#include "Pet.h"
#include <iostream>
#include <string>

using namespace std;

void ConsolUI::tipareste(const vector<Pet>& pets) {
	//cout << "\nPets:\n\n";
    cout<<"\n------------------------------------\n";
    cout<<"|              PETS                |\n";
    cout<<"------------------------------------\n";
	if(pets.size()==0)
	    cout<<"-------------EMPTY LIST-------------\n\n";
	else{
        for (const auto& pet : pets) {
            cout << "|Type: " << pet.getType() << " | Species: " << pet.getSpecies() << " | Price: " << pet.getPrice() << " |\n";
            //cout << '' << pet.getType() << ' ' << pet.getSpecies() << ' ' << pet.getPrice() << '\n';
        }
        cout<<"------------------------------------\n";
        cout << "\n--------End of pet lists--------\n\n";
	}
}

void ConsolUI::adaugaUI() {
	string ty, sp;
	int price;
	cout << "Dati tip:";
	cin >> ty;
	cout << "Dati specie:";
	cin >> sp;
	cout << "Dati pret:";
	cin >> price;
	ctr.addPet(ty, sp, price);
	cout << "Adaugat cu succes\n";
}

void ConsolUI::menu()
{
    cout<<'\n';
	cout<<"------------------------------------\n";
	cout<<"|          PET STORE MENU          |\n";
	cout<<"------------------------------------\n";
	cout<<"| 1. Add a pet                     |\n";
	cout<<"| 2. Show all pets                 |\n";
	cout<<"| 3. Sort pets by type             |\n";
	cout<<"| 4. Sort pets by species          |\n";
	cout<<"| 5. Sort pets by species+price    |\n";
	cout<<"| 6. Filter by price               |\n";
	cout<<"| 7. Filter by price MIN|>MAX      |\n";
	cout<<"| 0. EXIT                          |\n";
	cout<<"------------------------------------\n";
    cout<<"Insert command:";

}

void ConsolUI::start() {
	while (true) {
		menu();
		//cout << "Meniu:\n";
		//cout << "1 adauga\n2 tipareste\n3 sort by type\n4 sort by species\n5 sort by species+price\n6 filtrare pret\n7 Filtrare pret min max\n0 Iesire\nDati comanda:";
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
				tipareste(ctr.sortByType());
				break;
			case 4:
				tipareste(ctr.sortBySpecies());
				break;
			case 5:
				tipareste(ctr.sortBySpeciesPrice());
				break;
			case 6:
				cout << "Dati pret maxim:";
				int pret;
				cin >> pret;
				tipareste(ctr.filtrarePretMaiMic(pret));
				break;
			case 7:
				cout << "Dati pret minim:";
				int pretMin;
				cin >> pretMin;
				cout << "Dati pret maxim:";
				int pretMax;
				cin >> pretMax;
				tipareste(ctr.filtrarePret(pretMin,pretMax));
				break;
			case 0:
				cout<< "\nEXIT\n";
				return;
			default:
				cout << "Comanda invalida\n";
			}			
		}
		catch (PetRepoException& ex) {
			cout << ex <<'\n';
		}
		catch (ValidateException& ex) {
			cout << ex << '\n';
		}
	}
}