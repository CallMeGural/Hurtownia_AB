#include <iostream>
#include <time.h>
#include "Koszyk_klienta.h"
#include "Artykul.h"

using namespace std;

class Wypozyczenie {
protected:
	friend class Klient;
	time_t data_wypozyczenia;
	time_t data_zdania;
	unsigned long float koszt_wypozyczenia = -1;
	Koszyk_klienta koszyk_na_wypozyczenia;
	static int liczba_dni = 10;
	Artykul art;

public:
	void dodaj_do_koszyka() {
		Artykul a;
		cout << "\nJaki produkt chcesz wypozyczyc?\n";
		cin >> a;
		art = a;
		cout << "\nDodaje produkt na wypozyczenie\n";
		koszyk_na_wypozyczenia.dodaj_do_koszyka(art);
	}
	void usun_z_koszyka() {
		cout << "\nUsuwam produkt z koszyka na wypozyczenie\n";
		koszyk_na_wypozyczenia.usun_z_koszyka();
	}
};