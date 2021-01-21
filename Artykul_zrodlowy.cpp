#include "Artykul.h"

Artykul::Artykul() {
	dzial = "-";
	nazwaArtykulu = "-";
	cena = 0.;
	ilosc_szt = 0;
}

void Artykul::wprowadzanie_Artykulu(string _dzial, string _nazwaArtykulu, float _cena, int _ilosc_szt) {
	dzial = _dzial;
	nazwaArtykulu = _nazwaArtykulu;
	cena = _cena;
	ilosc_szt = _ilosc_szt;
}

Artykul::~Artykul() {
	dzial = "-";
	nazwaArtykulu = "-";
	cena = 0.;
	ilosc_szt = 0;
}

void Artykul::wyswietl_info() {
	cout << "INFORAMCJE O PRODUKCIE" << endl;
	cout << "\tNazwa artykulu:" << nazwaArtykulu << endl;
	cout << "\tNazwa dzialu:" << dzial << endl;
	cout << "\tCena artykulu:" << cena << endl;
	cout << "\tIlosc [szt]:" << ilosc_szt << endl;
}

void Artykul::wyswietl_artykul_z_listy() {
	cout << "|" << setw(10) << dzial << " |" << setw(30) << nazwaArtykulu << " |" << setw(20) << cena << " |" << setw(20) << ilosc_szt << endl;
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
