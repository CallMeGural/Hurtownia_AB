#pragma once
#include "Uzytkownik.h"
#include <iostream>

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
		wyswietl_dane(nazwa_ar);
	}

	void proces_reklamacyjny();
};
