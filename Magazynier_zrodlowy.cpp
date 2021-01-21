#include "Magazynier.h"

Magazynier::Magazynier() {
	haslo = 0;
	imie = "-";
	nazwisko = "-";
	next = nullptr;
}

void Magazynier::menu_magazynier(Dzial& _Dzial) {
	int opcja = -1;
	bool dzialanie = 1;
	///petla glowna - container
	while (dzialanie) {
		system("cls");
		///graficzne przedstawienie
		cout << "=======================================================================================" << endl;
		cout << "---------------------------------- MENU - MAGAZYNIER ----------------------------------" << endl;
		cout << "---------------------------------------------------------------------------------------" << endl;
		cout << "\nWybierz opcje:" << endl;
		cout << "\t1. Wyswietl liste artykulow" << endl;
		cout << "\t2. Szukaj artykul" << endl;
		cout << "\t0. Wyloguj" << endl;
		cout << "\nPodaj numer opcji: ";
		cin >> opcja;

		switch (opcja) {
		case 1:
			przegladaj_art_m(_Dzial);
			break;
		case 2:
			szukaj_art_m(_Dzial);
			break;
		case 0:
			dzialanie = 0;
			break;
		default:
			cout << "\nNie ma takiej opcji!\n";
		}
	}
}
///sprawdzanie poprawnosci hasla
bool Magazynier::logowanie_magazynier(int pom) {
	cout << "Podaj haslo uwierzytelniajace: ...\n\tHaslo: ";
	int pom_haslo = -1, proba = 3;
	while (proba >= 0) {
		cin >> pom_haslo;
		if (pom == pom_haslo) {
			cout << "\tHaslo prawidlowe\n";
			Sleep(500);
			return true;
		}
		else {
			proba -= 1;
			cout << "\tBledne haslo! Pozostalo " << proba << " prob\n\tHaslo: ";
		}
	}
	return false;
}
/// wybieranie danych magazyniera z listy
int Magazynier::logowanie() {
	int opcja;
	int pom_haslo = -1, pom_licznik;
	string pom_im, pom_naz;
	cout << "Wybierz dane z listy lub utworz nowego magazyniera\n\t0. Utworz nowego magazyniera\n";
	pom_licznik = wypisz_liste_magazynierow();
	fstream plik_magazyn;
	plik_magazyn.open("magazynierzy.txt", ios::in | ios::app);
	do {
		cout << "Podaj numer opcji: ";
		cin >> opcja;
	} while (opcja > pom_licznik);
	if (opcja == 0) {
		///tworzymy nowego magazyniera
		if (plik_magazyn.good()) {
			cout << "Tworzenie nowego magazyniera.\n\tPodaj swoje imie: ";
			cin >> pom_im;
			imie = pom_im;
			cout << "\tPodaj swoje nazwisko: ";
			cin >> pom_naz;
			nazwisko = pom_naz;
			cout << "\tPodaj swoje haslo dostepowe: ";
			cin >> pom_haslo;
			haslo = pom_haslo;
			plik_magazyn << endl << pom_im << ' ' << pom_naz << ' ' << pom_haslo;
		}

	}
	else {
		///wybieramy z dostepnych
		if (plik_magazyn.good()) {
			for (int i = 0; i < opcja; i++)
				plik_magazyn >> pom_im >> pom_naz >> pom_haslo;
		}
	}
	plik_magazyn.close();
	return pom_haslo;
}
///wypisywanie z pliku txt danych magazynierow
int Magazynier::wypisz_liste_magazynierow() {
	ifstream plik_magazyn;
	string pom_im, pom_naz;
	int pom_haslo;
	int licznik = 1;
	plik_magazyn.open("magazynierzy.txt", ios::in | ios::app);
	if (plik_magazyn.good()) {
		while (!plik_magazyn.eof()) {
			plik_magazyn >> pom_im >> pom_naz >> pom_haslo;
			cout << "\t" << licznik << ". " << pom_im << ' ' << pom_naz << endl;
			licznik++;
		}
	}
	return licznik;
}

void Magazynier::przegladaj_art_m(Dzial& _dzial) {
	Artykul* art = new Artykul;
	art = _dzial.wyswietl_art_w_dziale();
	if (art) {
		system("cls");
		cout << "=======================================================================================================================" << endl;
		cout << "---------------------------------------------- WYSZUKIWANIE - ARTYKULU ------------------------------------------------" << endl;
		cout << "-------------------------------- DOSTEPNE - DZIALANIA - DLA - ZNALEZIONEGO - ARTYKULU----------------------------------" << endl;
		cout << "=======================================================================================================================" << endl;
		cout << endl << endl << "\tBRAK UPRAWNIEN!" << endl << endl << "\tWcisnij spacje aby wrocic do MENU." << endl << endl;
		system("PAUSE");
	}
}

void Magazynier::szukaj_art_m(Dzial& _dzial) {
	Artykul* art = new Artykul;
	art = _dzial.szukaj_art();
	if (art) {
		system("cls");
		cout << "=======================================================================================================================" << endl;
		cout << "---------------------------------------------- WYSZUKIWANIE - ARTYKULU ------------------------------------------------" << endl;
		cout << "-------------------------------- DOSTEPNE - DZIALANIA - DLA - ZNALEZIONEGO - ARTYKULU----------------------------------" << endl;
		cout << "=======================================================================================================================" << endl;
		cout << endl << endl << "\tBRAK UPRAWNIEN!" << endl << endl << "\tWcisnij spacje aby wrocic do MENU." << endl << endl;
		system("PAUSE");
	}
}