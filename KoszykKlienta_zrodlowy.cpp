#include "KoszykKlienta.h"

Artykul* KoszykKlienta::wypisz_koszyk() {
	Artykul* art = listaZakupow.wyswietl_liste_art();
	return art;
}

void KoszykKlienta::dodaj_do_koszyka(Artykul* art, int ilosc) {
	fstream plik;
	plik.open("zakup.txt", ios::out | ios::app);
	plik << endl << art->dzial << " " << art->nazwaArtykulu << " " << art->cena << " " << ilosc;
	plik.close();
}