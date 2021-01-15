#include "Dzial.h"
#include "Artykul.h"

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
	system("cls");
	cout << "=============================================================================================" << endl;
	cout << "---------------------------------- WYSZUKIWANIE - ARTYKULU ----------------------------------" << endl;
	cout << "---------------------------------------------------------------------------------------------" << endl;
	cout << "\n\tPodaj nazwe artykulu:";
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
Artykul* Dzial::szukaj_art_return_wsk(string nazw_art) {
	
	if (listaArt.czy_lista_pusta()) {
		Artykul* pom = new Artykul;
		pom = listaArt.head;
		while (pom->next && (pom->nazwaArtykulu != nazw_art)) pom = pom->next;
		if (pom != nullptr) {
			/// tu chyba trzeba bedzie zwrocic do czegos wsk na ten artykul
			return pom;
		}
		else return nullptr;
		//else cout << "\n\tNie znaleziono artykulu o podanej nazwie\n";
	}
	else {
		cout << "\n\tBRAK ARTYKULOW W DZIALE.\n";
		return nullptr;
	}
}

void Dzial::sortuj_art_w_dziale() {
	listaArt.quickSort();
}

void Dzial::wyswietl_art_w_dziale() {
	listaArt.wyswietl_liste_art();
	system("PAUSE");
}

void Dzial::dodaj_artykul_poczatek(string _dzial, string _nazwaArtykulu, float _cena) {
	listaArt.pushFront(_dzial, _nazwaArtykulu, _cena);
}
/*
void Dzial::dodaj_artykul_koniec(string _dzial, string _nazwaArtykulu, float _cena) {
	listaArt.pushBack(_dzial, _nazwaArtykulu, _cena);
}*/

void Dzial::dodaj_artykul() {
	string pom_nazw = "";
	float pom_cena = 0.;
	char decyzja = ' ';
	system("cls");
	cout << "=============================================================================================" << endl;
	cout << "----------------------------------- DODAWANIE - ARTYKUKU£U ----------------------------------" << endl;
	cout << "---------------------------------------------------------------------------------------------" << endl;
	cout << "\n Dzia³: " << this->nazwa_dzialu << endl;
	cout << "\nPodaj nazwe artykulu: ";
	cin >> pom_nazw;
	cout << "Podaj cene artykulu: ";	/// sprawdzenie poprawnosci danych?
	cin >> pom_cena;					///
	cout << "\nCzy na pewno dodaæ ten artykul? [t/n]: ";
	cin >> decyzja;
	if (decyzja == 't') {
		listaArt.pushBack(this->nazwa_dzialu, pom_nazw, pom_cena);
		cout << "\nDodano artykul do dzialu." << endl;
	}
	else {
		cout << "\nAnulowano dodawanie artykulu." << endl;
	}
	system("PAUSE");
}

void Dzial::usun_artykul() {
	string pom_nazw = "";
	char decyzja = ' ';
	Artykul* usuwany = new Artykul;
	
	system("cls");
	cout << "=============================================================================================" << endl;
	cout << "----------------------------------- USUWANIE - ARTYKUKU£U -----------------------------------" << endl;
	cout << "---------------------------------------------------------------------------------------------" << endl;
	cout << "\n Dzia³: " << this->nazwa_dzialu << endl;
	cout << "\nPodaj nazwe artykulu, ktory chcesz usunac: ";
	cin >> pom_nazw;

	usuwany = this->szukaj_art_return_wsk(pom_nazw);
	this->listaArt.removeArt(usuwany);

	cout << "\nPomyslnie usunieto artykul z dzialu.\nWcisnij ENTER...";
	if (getchar()) return;
}

