#include "Artykul.h"

Artykul::Artykul() {
	dzial = "-";
	nazwaArtykulu = "-";
	cena = 0.;
	//for(int i=0;i<NUMER_SERYJNY;i++)
		//numerSeryjny[i] = 'x';
}
/*
Artykul::Artykul(string _dzial, string _nazwaArtykulu, float _cena, char _numerSeryjny[]) {
	dzial = _dzial;
	nazwaArtykulu = _nazwaArtykulu;
	cena = _cena;
	for (int i = 0; i < NUMER_SERYJNY; i++)
		numerSeryjny[i] = _numerSeryjny[i];
}*/

void Artykul::wprowadzanie_Artykulu(string _dzial, string _nazwaArtykulu, float _cena) {
	///metoda do dodaawania artykulu w liscie artykulow [ListaArtykulowWDziale::dodaj_art()]
	dzial = _dzial;
	nazwaArtykulu = _nazwaArtykulu;
	cena = _cena;
}

Artykul::~Artykul() {
	dzial = "-";
	nazwaArtykulu = "-";
	cena = 0.;
	//for (int i = 0; i < NUMER_SERYJNY; i++)
		//numerSeryjny[i] = 'x';
}

void Artykul::wyswietl_info() {
	cout << "INFORAMCJE O PRODUKCIE" << endl;
	cout << "\tNazwa artykulu:" << nazwaArtykulu << endl;
	cout << "\tNazwa dzialu:" << dzial << endl;
	cout << "\tCena artykulu:" << cena << endl;
	//cout << "\tNumer seryjny:";
	//for (int i = 0; i << NUMER_SERYJNY; i++) cout << numerSeryjny[i];
	cout << endl;
}

void Artykul::wyswietl_artykul_z_listy() {
	cout << setw(18) << "Nazwa artykulu: " << setw(10) << nazwaArtykulu << setw(18) << "Nazwa dzialu: " << setw(10) << dzial;
	cout << setw(18) << "Cena artykulu: " << setw(10) << cena;
	cout << endl;
}

void Artykul::wycofaj_artykul() {
	cout << "WYCOFYWANIE ARTYKULU ZE SKLEPU" << endl;

	/// nwm co tu w sumie zrobic
	/// dodatkowa zmienna bool do artykulu czy jest w sprzedazy ????????

}

void Artykul::zmien_nazwe_artykulu() {
	string pom = "";
	cout << "ZMIANA NAZWY ARTYKULU" << endl;

	while (pom == "") {
		cout << "\tPodaj nowa nazwe artykulu: ";
		cin >> pom;
		if (pom != "") {
			nazwaArtykulu = pom;
			cout << "\tPomyslnie zmieniono nazwe." << endl;
		}
	}
}

void Artykul::zmien_cene_artykulu() {
	float pom = 0.;
	cout << "ZMIANA CENY ARTYKULU" << endl;

	while (pom <= 0.) {
		cout << "\tPodaj nowa cene artykulu ( > 0 ): ";
		cin >> pom;
		if (pom != 0.) {
			cena = pom;
			cout << "\tPomyslnie zmieniono cene." << endl;
		}
	}
}
