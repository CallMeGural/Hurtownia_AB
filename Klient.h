#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

using namespace std;

class Klient {
private:
	string imie = "", nazwisko = "";
	int haslo = 0;
public:
	bool logowanie_klient(int pom) {
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

	int logowanie() {
		int opcja;
		int pom_haslo, pom_licznik;
		string pom_im, pom_naz;
		cout << "Wybierz dane z listy lub utworz nowego klienta\n\t0. Utworz nowego klienta\n";
		pom_licznik = wypisz_liste_klientow();
		fstream plik_klient;
		plik_klient.open("klienci.txt", ios::in | ios::app);
		do {
			cout << "Podaj numer opcji: ";
			cin >> opcja;
		} while (opcja > pom_licznik);
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
				plik_klient << pom_im << ' ' << pom_naz << ' ' << pom_haslo << endl;
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
	int wypisz_liste_klientow() {
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
};