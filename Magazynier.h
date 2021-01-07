#include "Uzytkownik.h"
#include <iostream>
#include <string>
#include "Klient.h"

using namespace std;

class Magazynier : public Uzytkownik {
public:
	//Magazynier() { licznik++; }
	//~Magazynier() { licznik--; }
	void wyswietl_dane() {
		cout << "Imie i nazwisko magazyniera: " << imie << " " << nazwisko << endl;
	}

	void wyswietl_info_artykul() {
		cout << "Podaj nazwe artykulu, na temat ktorego informacje chcesz wyswietlic: ";
		string nazwa_ar;
		cin >> nazwa_ar;
		wyswietl_info(nazwa_ar);
	}

	void proces_reklamacyjny() {
		cout << "Dla ktorego klienta chcesz zaczac proces reklamacyjny?\n";
		Klient k;
		cin >> k;
		int wybor;
		cout << "\nJaka chcesz dokonac akcje?\n1. Zwrot pieniedzy\n2. Wymiana produktu\n3. Odrzucenie relamacji\n";
		cin >> wybor;
		switch (wybor){
		case 1:
			k.reklamacja.zwrot_pieniedzy();
			break;
		case 2:
			k.reklamacja.wymiana();
			break;
		case 3:
			k.reklamacja.odrzucenie();
			break;
		default:
			cout << "\nZly wybor!\n";
			break;
		}
		cout << "\nZakonczono proces reklamacji!\n";
	}
};
