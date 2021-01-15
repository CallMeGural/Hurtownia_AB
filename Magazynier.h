#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Magazynier {
private:
	int haslo = 0;
	string imie = "", nazwisko = "";
	//Magazynier* next;
public:
	Magazynier() {

	}
	bool logowanie_magazynier(int pom) {
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
				cout << "\t" << licznik << ". " << pom_im << ' ' << pom_naz  << endl;
				licznik++;

			}
		}
		return licznik;
	}


};
