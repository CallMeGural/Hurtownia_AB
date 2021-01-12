#pragma once
#include <iostream>
#include <fstream>
#include "Artykul.h"
#include "Koszyk_klienta.h"

using namespace std;

class Zakup {
protected:
	Koszyk_klienta* koszyk = nullptr;

public:
	Zakup(Koszyk_klienta* k) {
		koszyk = k;
	}
	void dodaj_art_do_koszyka() {
		int numer_produktu,potrz_ilosc;
		cout << "Jaki produkt chcesz kupic?\nPodaj numer produktu: ";
		cin >> numer_produktu;
		cout << "Podaj potrzebna ilosc: ";
		cin >> potrz_ilosc;
		fstream plik;
		plik.open("artykuly.txt", ios::out | ios::app);
		if (plik.good()) {
			cout << "TUTAJ TRZEBA DODAC ZNAJDOWANIE I ZMIENIANIE WARTOSCI PRZY ZAKUPIONYM PRZEDMIOCIE!\n";
		}
		else cout << "BLAD OTWARCIA PLIKU artykuly.txt!\n";
		//koszyk->dodaj_do_koszyka(art);
		plik.close();
	}
};