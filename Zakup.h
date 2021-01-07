#include <iostream>
#include "Artykul.h"
#include "Koszyk_klienta.h"

using namespace std;

class Zakup {
protected:
	Koszyk_klienta* koszyk = nullptr;
	
public:
	Zakup(Koszyk_klienta k) {
		koszyk = k;
	}
	Artykul dodaj_art_do_koszyka() {
		Artykul art;
		cout << "Jaki produkt chcesz kupic?\n";
		cin >> art;
		koszyk->dodaj_do_koszyka(art);
	}
};