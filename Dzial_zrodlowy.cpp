#include "Dzial.h"

int Dzial::nr_dzialu = 0;

Dzial::Dzial() {
	nr_dzialu++;
}

Dzial::Dzial(string _nazwa) {
	nazwa_dzialu = _nazwa;
}

Dzial::~Dzial() {
	nr_dzialu--;
}

void Dzial::szukaj_art() {
	string pom_nazw;
	cout << "\nWYSZUKIWANIE ARTYKULU\n";
	cout << "\tPodaj nazwe artykulu:";
	cin >> pom_nazw;
	
	if (listaArt.czy_lista_pusta()) {
		Artykul* pom = new Artykul;
		pom = listaArt.head;
		while (pom->next && (pom->nazwaArtykulu != pom_nazw)) pom = pom->next;
		if (pom != nullptr) {
			/// tu chyba trzeba bedzie zwrocic do czegos wsk na ten artykul
			cout << "\n\tZnaleziono artykul\n";
		}
		else cout << "\n\tNie znaleziono artykulu o podanej nazwie\n";
	}
	else {
		cout << "\n\tBRAK ARTYKULOW W DZIALE.\n";
	}
}

void Dzial::sortuj_art_w_dziale() {
	listaArt.quickSort();
}

void Dzial::wyswietl_art_w_dziale() {
	listaArt.wyswietl_liste_art();
}

void Dzial::dodaj_artykul_poczatek(string _dzial, string _nazwaArtykulu, float _cena) {
	listaArt.pushFront(_dzial, _nazwaArtykulu, _cena);
}

void Dzial::dodaj_artykul_koniec(string _dzial, string _nazwaArtykulu, float _cena) {
	listaArt.pushBack(_dzial, _nazwaArtykulu, _cena);
}

