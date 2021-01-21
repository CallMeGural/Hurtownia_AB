#include "Klient.h"
#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include "Artykul.h"
#include "Dzial.h"


Klient::Klient() {
	imie = "";
	nazwisko = "";
	haslo = 0;
}

bool Klient::logowanie_klient(int pom) {
	///sprawdzanie zgodnosci hasla
	cout << "Podaj haslo uwierzytelniajace: ...\n\tHaslo: ";
	int pom_haslo, proba = 3;
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

int Klient::logowanie() {
	///inicjalizacja zmiennych
	int opcja;
	int pom_haslo, pom_licznik;
	string pom_im, pom_naz;
	pom_licznik = wypisz_liste_klientow();
	fstream plik_klient;
	///wybieranie danych klienta
	cout << "Wybierz dane z listy lub utworz nowego klienta\n\t0. Utworz nowego klienta\n";
	plik_klient.open("klienci.txt", ios::in | ios::app);
	do {
		cout << "Podaj numer opcji: ";
		cin >> opcja;
	} while (opcja > pom_licznik);
	///jesli opcja -> 0 - tworzymy nowego klienta
	if (opcja == 0) {
		if (plik_klient.good()) {
			cout << "Tworzenie nowego klienta.\n\tPodaj swoje imie: ";
			cin >> pom_im;
			imie = pom_im;
			cout << "\tPodaj swoje nazwisko: ";
			cin >> pom_naz;
			nazwisko = pom_naz;
			cout << "\tPodaj swoje haslo dostepowe: ";
			cin >> pom_haslo;
			haslo = pom_haslo;
			plik_klient << endl <<pom_im << ' ' << pom_naz << ' ' << pom_haslo;
		}

	}
	else {
		if (plik_klient.good()) {
			for (int i = 0; i < opcja; i++)
				plik_klient >> pom_im >> pom_naz >> pom_haslo;
		}
	}
	plik_klient.close();
	return pom_haslo;
}

void Klient::menu_Klient(Dzial& _Dzial) {
	///inicjalizacja zmiennych
	remove("zakup.txt");
	int opcja = -1;
	bool dzialanie = 1;
	/// petla glowna - container
	while (dzialanie) {
		system("cls");
		///graficzne przedstawienie
		cout << "=======================================================================================" << endl;
		cout << "----------------------------------- MENU - KLIENT ------------------------------------" << endl;
		cout << "---------------------------------------------------------------------------------------" << endl;
		cout << "\nWybierz opcje:" << endl;
		cout << "\t1. Pzegladaj artykuly" << endl;
		cout << "\t2. Wyszukaj artykul [po nazwie]" << endl;
		cout << "\t3. Zobacz koszyk" << endl;
		cout << "\t4. Zaplac" << endl;
		cout << "\t0. Wyloguj" << endl;

		cout << "\nPodaj numer opcji: ";
		cin >> opcja;
		/// wybor opcji
		switch (opcja) {
		case 1:
			przegladaj_art_k(_Dzial);
			break;
		case 2:
			szukaj_art_k(_Dzial);
			break;
		case 3:
			przegladaj_koszyk();
			break;
		case 4:
			zaplac();
			break;
		case 0:
			dzialanie = 0;
			break;
		default:
			cout << "\nNie ma takiej opcji!\n";
		}
	}
}

void Klient::przegladaj_art_k(Dzial& _dzial) {
	///inicjalizacja zmiennych
	int numer_artykulu = -1;
	char opcja = 0;
	int opcja_2 = 0;
	bool dzialanie = true;
	int ilosc = 0;
	int licznik_pom = 0;
	Artykul* pom = _dzial.listaArt.head;
	///petla glowna - container
	while (dzialanie) {
		numer_artykulu = _dzial.wyswietl_art_w_dziale_return_nr();
		if (numer_artykulu > -1) {
			system("cls");
			///graficzne przedstawienie
			cout << "=======================================================================================================================" << endl;
			cout << "---------------------------------------------- PRZEGLADANIE - ARTYKULU ------------------------------------------------" << endl;
			cout << "-------------------------------- DOSTEPNE - DZIALANIA - DLA - ZNALEZIONEGO - ARTYKULU----------------------------------" << endl;
			cout << "=======================================================================================================================" << endl;
			cout << "      |" << setw(12) << "Dzial |" << setw(32) << "Nazwa artykulu |" << setw(22) << "Cena artykulu |" << setw(20) << "Ilosc [szt] " << endl;
			cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
			///petla przechodzaca do odpowiedniego artykulu
			while (licznik_pom < numer_artykulu) {
				pom = pom->next;
				licznik_pom++;
			}
			pom->wyswietl_artykul_z_listy();
			///cd graficzne przedstawienie
			cout << "\n\n=======================================================================================================================\n";
			cout << "[D - dodaj artykul do koszyka] [W - wyjdz] ";
			cout << "\nWybierz opcje: ";

			cin >> opcja;
			switch (opcja) {
			case 'w':
			case 'W':
				dzialanie = false;
				break;
			case 'D':
			case 'd':
				///dodawanie do koszyka klienta
				do {
					cout << "\nPodaj ilosc artykulu (ile chcesz kupic): ";
					cin >> ilosc;
					if (ilosc > pom->ilosc_szt) cout << "\tNiedozwolona ilosc...\n";
				} while (ilosc > pom->ilosc_szt);

				koszyk.dodaj_do_koszyka(pom, ilosc);
				pom->ilosc_szt -= ilosc;
				system("cls");
				cout << "=======================================================================================================================" << endl;
				cout << "\n\tDODANO ARTYKUL DO LISTY.\n\nWybierz opcje:\n\t1. Powrot do listy\n\t2. Wroc do MENU\n";
				cin >> opcja_2;
				switch (opcja_2) {
				case 1:
					dzialanie = true;
					break;
				case 2:
					dzialanie = false;
					break;
				default:
					cout << "\n\n\tNIE MA TAKIEJ OPCJI.\n";
					system("PAUSE");
				}
				break;
			default:
				break;
			}
		}
		dzialanie = false;
	}
}

void Klient::szukaj_art_k(Dzial& _dzial) {
	///inicjalizacja zmiennych
	Artykul* art = new Artykul;
	art = _dzial.szukaj_art();
	char opcja = 0;
	if (art) {
		system("cls");
		///graficzne przedstawienie
		cout << "=======================================================================================================================" << endl;
		cout << "---------------------------------------------- WYSZUKIWANIE - ARTYKULU ------------------------------------------------" << endl;
		cout << "-------------------------------- DOSTEPNE - DZIALANIA - DLA - ZNALEZIONEGO - ARTYKULU----------------------------------" << endl;
		cout << "=======================================================================================================================" << endl;
		cout << endl;
		art->wyswietl_artykul_z_listy();

		cout << "\n\n=======================================================================================================================\n";
		cout << "[D - dodaj artykul do koszyka] [W - wyjdz] ";
		cout << "\nWybierz opcje: ";

		cin >> opcja;
		switch (opcja) {
		case 'w':
		case 'W':
			break;
		case 'D':
		case 'd':
			system("cls");
			cout << "=======================================================================================================================" << endl;
			cout << "\n\tDODANO ARTYKUL DO LISTY.\n\nWcisnij dowolny klawisz aby powrocic do menu.";
			break;
		default:
			break;
		}
		system("PAUSE");
	}
}

int Klient::wypisz_liste_klientow() {
	///wypisuje z pliku txt liste dostepnych klientow do zalogowania sie
	ifstream plik_klient;
	string pom_im, pom_naz;
	int pom_haslo;
	int licznik = 1;
	plik_klient.open("klienci.txt", ios::in | ios::app);
	if (plik_klient.good()) {
		while (!plik_klient.eof()) {
			plik_klient >> pom_im >> pom_naz >> pom_haslo;
			cout << "\t" << licznik << ". " << pom_im << ' ' << pom_naz << endl;
			licznik++;

		}
	}
	return licznik;
}

void Klient::przegladaj_koszyk() {
	///inicjalizacja zmiennych
	int wybor = -1;
	bool dzialanie = true;
	Artykul* art = new Artykul;
	///petla glowna - container
	while (dzialanie) {
		art = koszyk.wypisz_koszyk();
		if (art) {
			system("cls");
			cout << "=======================================================================================================================" << endl;
			cout << "-------------------------------------------------- KOSZYK - KLIENTA ---------------------------------------------------" << endl;
			cout << "-------------------------------- DOSTEPNE - DZIALANIA - DLA - ZNALEZIONEGO - ARTYKULU----------------------------------" << endl;
			cout << "=======================================================================================================================" << endl;
			cout << endl << endl << "Wybierz opcje\n\t0. Wroc do MENU" << endl;
			cin >> wybor;

			switch (wybor) {
			case 0:
				dzialanie = false;
				break;
			default:
				system("cls");
				cout << "=======================================================================================================================" << endl;
				cout << "\n\tNie ma takiego dzialania\nwcisnij dowolny przycisk aby wrocic do MENU...\n";
				system("PAUSE");
				dzialanie = false;
			}
			system("PAUSE");
		}
		dzialanie = false;
	}
}

void Klient::zaplac() {
	///inicjalizacja zmiennych
	ifstream plik;
	string nazwa_art = "";
	string nazwa_dzialu = "";
	float cena_art = 0.;
	int _ilosc = 0;
	plik.open("zakup.txt");
	char decyzja = ' ';
	int i = 0;
	float kwota_do_zaplaty = 0;

	system("cls");
	///graficzne przedstawienie
	cout << "=======================================================================================================================" << endl;
	cout << "------------------------------------------ LISTA - ARTYKULOW - W - KOSZYKU --------------------------------------------" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "=======================================================================================================================" << endl;

	cout << "Lp.   |" << setw(12) << "Dzial |" << setw(32) << "Nazwa artykulu |" << setw(22) << "Cena artykulu |" << setw(20) << "Ilosc [szt] " << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
	///zliczanie sumy koncowej i wypisywanie artykulow
	if (plik.good())
		while (!plik.eof()) {
			plik >> nazwa_dzialu;
			plik >> nazwa_art;
			plik >> cena_art;
			plik >> _ilosc;
			kwota_do_zaplaty = kwota_do_zaplaty + cena_art * ((float)_ilosc);

			cout << setw(5) << i << ".|" << setw(10) << nazwa_dzialu << " |" << setw(30) << nazwa_art << " |" << setw(20) << cena_art << " |" << setw(20) << _ilosc << endl;
			i++;
		}
	plik.close();
	cout << "=======================================================================================================================" << endl;
	cout << "\n\tKWOTA DO ZAPLATY: " << kwota_do_zaplaty << " zl" << endl;
	cout << "\tWcisnij Z aby zatwierdzic..." << endl;
	do {
		cin >> decyzja;

	} while (decyzja != 'z' && decyzja != 'Z');

	cout << "Przejdz do terminala\n";
	system("PAUSE");
}
