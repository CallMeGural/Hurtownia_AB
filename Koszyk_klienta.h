#pragma once
#include <iostream>
#include "Artykul.h"
#include "Lista_artykulow.h"

using namespace std;

class Koszyk_klienta {
protected:
	Lista_artykulow* next;

public:
	void wypisz_po_dziale();
	void wypisz_po_nazwie();
	void wypisz() {
		cout << "\nOto Twoj caly koszyk:\n";
		next->wypisz(next);
	}
	void dodaj_do_koszyka(Artykul art) {
		next->dodaj_artykul(art, next, 0);
		cout << "\nProdukt pomyslnie zostal dodany do koszyka!";
	}
	void usun_z_koszyka() {
		Artykul art;
		cout << "Jaki produkt chcesz usunac z koszyka?\n";
		cin >> art.nazwa;
		next->usun(art, next);
		cout << "\nUsunieto artykul z koszyka!\n";
	}
	void zaplac() {
		cout << "\nCzy chcesz zakonczyc zakupy i przejsc do platnosci?(t/n)";
		char odpowiedz; //t lub n
		cin >> odpowiedz;
		//?????????????????????????
		cout << "\nPlatnosc zostala zakonczona!";
	}
};
