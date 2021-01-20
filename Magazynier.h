#pragma once
#include <iostream>
#include <fstream>
#include "Reklamacja.h"

using namespace std;

class Magazynier {
private:
	int haslo;
	string imie, nazwisko;
	Magazynier* next;
public:
	Magazynier() {
		haslo = 0;
		imie = "-";
		nazwisko = "-";
		next = nullptr;
	}

	void menu_magazynier(Dzial& _Dzial) {
		Reklamacja R;
		int opcja = -1;
		bool dzialanie = 1;
		while (dzialanie) {
			system("cls");
			cout << "=======================================================================================" << endl;
			cout << "---------------------------------- MENU - MAGAZYNIER ----------------------------------" << endl;
			cout << "---------------------------------------------------------------------------------------" << endl;
			cout << "\nWybierz opcje:" << endl;
			cout << "\t1. Wyswietl liste artykulow" << endl;
			cout << "\t2. Szukaj artykul" << endl;
			cout << "\t3. Zgloszone reklamacje" << endl;
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
			case 3:
				R.wyswietl_liste_zgloszonych_reklamacji();
				break;
			case 0:
				dzialanie = 0;
				break;
			default:
				cout << "\nNie ma takiej opcji!\n";
			}
		}
	}

	bool logowanie_magazynier(int pom) {
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

	int logowanie() {
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
				plik_magazyn << pom_im << ' ' << pom_naz << ' ' << pom_haslo << endl;
			}

		}
		else {
			if (plik_magazyn.good()) {
				for (int i = 0; i < opcja; i++)
					plik_magazyn >> pom_im >> pom_naz >> pom_haslo;
			}
		}
		plik_magazyn.close();
		return pom_haslo;
	}

	int wypisz_liste_magazynierow() {
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

	void przegladaj_art_m(Dzial& _dzial) {
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

	void szukaj_art_m(Dzial& _dzial) {
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



	/*
	void proces_reklamacyjny() {
		Artykul pom;
		string nazwa;
		cout << "Dla jakiego artykulu chcesz rozpoczac proces reklamacyjny?\n";
		cin >> nazwa;
		pom = pom.wyszukaj_artykul(nazwa);
		cout << "Rozpoczynam proces reklamacyjny\n\n";
		Reklamacja rek(pom);
		int wybor = -1;
		cout << "Co zamierzasz wykonac?\n1) Zwrot pieniedzy\n2) Odrzucenie reklamacji\n3) Wymiana produktu\n";
		cin >> wybor;
		switch (wybor) {
		case 1:
			rek.zwrot_pieniedzy();
			cout << "Wykonano zwrot pieniedzy!";
			break;
		case 2:
			rek.odrzucenie();
			cout << "Odrzucono wniosek!";
			break;
		case 3:
			rek.wymiana();
			cout << "Dokonano wymiany";
			break;
		default:
			cout << "Wybrano nieodpowiednia opcje!";
		}
	}*/
};
