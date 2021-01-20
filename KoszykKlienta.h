#pragma once
#include <iostream>
#include <fstream>
#include "Artykul.h"
#include "ListaArtykulowWKoszyku.h"

using namespace std;

class Koszyk_klienta {
protected:
	ListaArtykulowWKoszyku listaZakupow;
	
public:
	Artykul* wypisz_koszyk() {
		Artykul* art = listaZakupow.wyswietl_liste_art();
		return art;
	}

	void dodaj_do_koszyka(Artykul* art, int ilosc) {
		fstream plik;
		plik.open("zakup.txt", ios::out | ios::app);
		plik << endl << art->dzial << " " << art->nazwaArtykulu << " " << art->cena << " " << ilosc;
		plik.close();
	}
};
