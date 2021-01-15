#pragma once
#include "Uzytkownik.h"
#include "Klient.h"
#include <iostream>
#include <string>

using namespace std;

void wyswietl_info(string nazwa_art) { /// zastanawiam sie nad tym, czy to powinno byc tutaj xd
	ifstream plik;
	string pom;
	int pom2;
	plik.open("artykuly.txt");
	if (plik.good()) {
		while (!plik.eof()) {
			plik >> pom;
			if (pom == nazwa_art) cout << "Wyswietlam informacje o artykule: \nNazwa artykulu: " << nazwa_art << "	Cena: ";
			plik >> pom2;
			cout << pom2 << "	Dzial: ";
			plik >> pom;
			cout << pom << "	Ilosc w magazynie: ";
			plik >> pom2;
			cout << pom2 << endl;
		}
	}
	else cout << "BLAD OTWARCIA PLIKU artykuly.txt!\n";
}

class Magazynier : public Uzytkownik {
public:
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
		cin >> k.nr_konta;
		int wybor;
		cout << "\nJaka chcesz dokonac akcje?\n1. Zwrot pieniedzy\n2. Wymiana produktu\n3. Odrzucenie relamacji\n";
		cin >> wybor;
		switch (wybor) {
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