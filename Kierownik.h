#pragma once
#include <iostream>
#include <fstream>
#include "Artykul.h"
#include "Uzytkownik.h"

using namespace std;

class Kierownik : public Uzytkownik {
public:
	Kierownik() {
		cout << "Podaj imie kierownika: ";
		cin >> imie;
		cout << "Podaj nazwisko kierownika: ";
		cin >> nazwisko;
		cout << "Podaj miejsce zamieszkania kierownika (miejscowosc): ";
		cin >> miejscowosc;
	};
	~Kierownik() {};

	void dodaj_artykul() {
		ofstream plik;
		plik.open("artykuly.txt");
		if (plik.good()) {
			Artykul pom_art;
			cout << "Dodawanie artykulu do magazynu.\nPodaj nazwe artykulu: ";
			cin >> pom_art.nazwa;
			plik << pom_art.nazwa;
			cout << "Podaj nr dzialu, do ktorego chcesz przypisac artykul " << pom_art.nazwa << ": ";
			cin >> pom_art.dzial;
			plik << pom_art.dzial;
			cout << "Podaj cene za jedna sztuke artykulu " << pom_art.nazwa << ": ";
			cin >> pom_art.cena;
			plik << pom_art.cena;
			cout << "Podaj ilosc danego artykulu: ";
			cin >> pom_art.ilosc;
			plik << pom_art.ilosc;
			plik.close();
			cout << "Artykul " << pom_art.nazwa << " dodano do magazynu.\n";
		}
		else cout << "Nie udalo sie otworzyc pliku z artykulami!\n";
	}
};